//
// Created by kalo on 2017/2/24.
//

#include "Ejecta.h"

namespace alpha {
    Ejecta::Ejecta(const Type &type) :
            type(type) {}

    namespace ejecta {
        Break::Break(const unsigned &scope_sn, Object *const &object) :
                Ejecta(Type::BREAK),
                scope_sn(scope_sn),
                object(Object::bound(object)) {}

        Break::~Break() {
            if (Object::release(object)) object = NULL;
        }

        Throw::Throw(Object *const &object) :
                Ejecta(Type::THROW),
                object(Object::bound(object)) {}

        Throw::~Throw() {
            if (Object::release(object)) object = NULL;
        }

        Return::Return(const unsigned &procedure_sn, Object *const &object) :
                Ejecta(Type::RETURN),
                procedure_sn(procedure_sn),
                object(object) {}

        Return::~Return() {
            if (Object::release(object)) object = NULL;
        }

        Exit::Exit(Object *const &object) :
                Ejecta(Type::EXIT),
                object(Object::bound(object)) {}

        Exit::~Exit() {
            if (Object::release(object)) object = NULL;
        }
    }
}