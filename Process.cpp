//
// Created by kalo on 2017/2/23.
//

#include "process.h"

namespace alpha {
    Process *Process::process = NULL;

    Process::Process() :
            object_ng(1),
            variable_ng(1) {
        auto process_backup = useProcess(this);

        type_type = Object::bound(new object::Type());
        procedure_type = Object::bound(new object::Type());
        type_type->constructor = Object::bound(new object::Procedure(NULL));
        procedure_type->constructor = Object::bound(new object::Procedure(NULL));

        null_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        boolean_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        number_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        character_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        pair_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        vector_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        string_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        identifier_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        scope_type = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));

        null = Object::bound(new object::Null());
        true_ = Object::bound(new object::Boolean(true));
        false_ = Object::bound(new object::Boolean(false));
        global = Object::bound(new object::Scope());

        rollbackProcess(process_backup);
    }

    Process::~Process() {
        auto process_backup = useProcess(this);

        Object::release(global);
        global = NULL;
        Object::release(false_);
        false_ = NULL;
        Object::release(true_);
        true_ = NULL;
        Object::release(null);
        null = NULL;

        Object::release(scope_type);
        scope_type = NULL;
        Object::release(identifier_type);
        identifier_type = NULL;
        Object::release(string_type);
        string_type = NULL;
        Object::release(vector_type);
        vector_type = NULL;
        Object::release(pair_type);
        pair_type = NULL;
        Object::release(character_type);
        character_type = NULL;
        Object::release(number_type);
        number_type = NULL;
        Object::release(boolean_type);
        boolean_type = NULL;
        Object::release(null_type);
        null_type = NULL;

        type_type->constructor->type = NULL;
        procedure_type->constructor->type = NULL;
        Object::release(type_type);
        Object::release(procedure_type, 3);
        procedure_type = NULL;
        type_type = NULL;

        rollbackProcess(process_backup);

        std::cout << object_statistics.size() << std::endl;
        for (auto i = object_statistics.begin(); i != object_statistics.end(); i++) {
            std::cout << i->second->sn << " ";
        }
        std::cout << std::endl;
    }
}