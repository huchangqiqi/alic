//
// Created by kalo on 2017/2/23.
//

#include "Process.h"

namespace alpha {
    Process *Process::process = NULL;

    Process::Process() :
            object_ng(1),
            variable_ng(1) {
        auto process_backup = useProcess(this);

        Type = Object::bound(new object::Type());
        Procedure = Object::bound(new object::Type());
        Type->constructor = Object::bound(new object::Procedure(NULL));
        Procedure->constructor = Object::bound(new object::Procedure(NULL));

        Null = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Boolean = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Number = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Character = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Pair = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Vector = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        String = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Identifier = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));
        Scope = Object::bound(new object::Type(Object::bound(new object::Procedure(NULL))));

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

        Object::release(Scope);
        Scope = NULL;
        Object::release(Identifier);
        Identifier = NULL;
        Object::release(String);
        String = NULL;
        Object::release(Vector);
        Vector = NULL;
        Object::release(Pair);
        Pair = NULL;
        Object::release(Character);
        Character = NULL;
        Object::release(Number);
        Number = NULL;
        Object::release(Boolean);
        Boolean = NULL;
        Object::release(Null);
        Null = NULL;

        Type->constructor->type = NULL;
        Procedure->constructor->type = NULL;
        Object::release(Type);
        Object::release(Procedure, 3);
        Procedure = NULL;
        Type = NULL;

        rollbackProcess(process_backup);

        std::cout << std::endl << "objects not been destroyed: " << object_statistics.size() << std::endl;
//        for (auto i = object_statistics.begin(); i != object_statistics.end(); i++) {
//            std::cout << i->second->sn << " ";
//        }
//        std::cout << std::endl;
    }
}