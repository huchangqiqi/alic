//
// Created by kalo on 2017/2/23.
//

#include "process.h"

namespace alpha {
    Process *Process::process = NULL;

    Process::Process() {
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

    Process::~Process() {}
}