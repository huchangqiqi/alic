//
// Created by kalo on 2017/2/23.
//

#include "Object.h"

namespace alpha {
    bool Object::release(Object *object, unsigned const &n) {
        if (object) {
            if (object->binding_times) object->binding_times -= n;
            if (object->binding_times) return false;
            else {
                if (object->sn) {
                    delete object;
                    object = NULL;
                }
                return true;
            }
        } else return false;
    }

    template<typename T>
    T *Object::bound(T *const &object, const unsigned int &n) {
        object->binding_times += n;
        return object;
    }

    Object::Object(object::Type *const &type) :
            sn(process->object_ng.generate()),
            type(type),
            binding_times(0) {}

    Object::~Object() {
        process->object_ng.recycle(sn);
        sn = 0;
        if (release(type)) type = NULL;
    }

    namespace object {
        Type::Type(Procedure *const &constructor) :
                Object(bound(process->type_type)),
                constructor(constructor) {}

        Type::~Type() {
            if (release(constructor)) constructor = NULL;
        }

        Null::Null() :
                Object(bound(process->null_type)) {}

        Boolean::Boolean(const bool &value) :
                Object(bound(process->boolean_type)),
                value(value) {}

        Number::Number(const double &value) :
                Object(bound(process->number_type)),
                value(value) {}

        Character::Character(const char &value) :
                Object(bound(process->character_type)),
                value(value) {}

        Pair::Pair() :
                Object(bound(process->pair_type)),
                car(bound(process->null)),
                cdr(bound(process->null)) {}

        Pair::~Pair() {
            if (release(car)) car = NULL;
            if (release(cdr)) cdr = NULL;
        }

        Vector::Vector(const unsigned &size) :
                Object(bound(process->vector_type)),
                value(std::vector<Object *>(size, process->null)) {
            bound(process->null, size);
        }

        Vector::~Vector() {
            for (auto i = value.begin(); i != value.end(); i++) {
                if (release(*i)) *i = NULL;
            }
        }

        String::String(const unsigned &size) :
                Object(process->string_type),
                value(std::string(size, static_cast<char>(0))) {}

        Identifier::Identifier(const std::string &string) :
                Object(process->identifier_type),
                string(std::move(string)),
                variable(NULL) {}

        Identifier::~Identifier() {
            if (variable) {
                variable->identifier_binding_times--;
                if (Variable::release(variable)) variable = NULL;
            }
        }

        Procedure::Procedure(const Value &value) :
                Object(bound(process->procedure_type)),
                value(value) {}

        namespace procedure {
            Custom::Custom(Scope *const &definition_scene, Identifier *const &scene_parameter, Identifier *const &arguments_parameter, Object *const &execution_body) :
                    Procedure(NULL),
                    definition_scene(definition_scene),
                    scene_parameter(bound(scene_parameter)),
                    arguments_parameter(bound(arguments_parameter)),
                    execution_body(bound(execution_body)) {}

            Custom::Custom(const Value &value, Scope *const &definition_scene, Identifier *const &scene_parameter, Identifier *const &arguments_parameter, Object *const &execution_body) :
                    Procedure(value),
                    definition_scene(definition_scene),
                    scene_parameter(bound(scene_parameter)),
                    arguments_parameter(bound(arguments_parameter)),
                    execution_body(bound(execution_body)) {}

            Custom::~Custom() {
                if (release(definition_scene)) definition_scene = NULL;
                if (release(scene_parameter)) scene_parameter = NULL;
                if (release(arguments_parameter)) arguments_parameter = NULL;
                if (release(execution_body)) execution_body = NULL;
            }

            Accessor::Accessor(Scope *const &definition_scene, Identifier *const &scene_parameter, Identifier *const &arguments_parameter, Object *const &execution_body, Type *const &target_type) :
                    Custom(NULL, definition_scene, scene_parameter, arguments_parameter, execution_body),
                    target_type(target_type) {}

            Accessor::~Accessor() {
                if (release(target_type)) target_type = NULL;
            }
        }

        Scope::Scope(Scope *const base) :
                Object(process->scope_type),
                base(base) {}

        Scope::~Scope() {
            for (auto i = variables.begin(); i != variables.end(); i++) {
                auto variable = i->second;
                auto j = variable->values.find(sn);
                release(j->second);
                j->second = NULL;
                variable->values.erase(j);
                if (Variable::release(variable)) {
                    variable = NULL;
                    i->second = NULL;
                }
            }
        }
    }
}