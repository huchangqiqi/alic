//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Variable {
        friend class object::Scope;

        friend class object::Identifier;

    public:
        static inline bool release(Variable *);

    protected:
        unsigned sn;
        std::unordered_map<std::string, Variable *>::iterator process_variables_iterator;
        unsigned identifier_binding_times;
        std::unordered_map<unsigned, Object *> values;

    public:
        Variable(const std::string &);

        ~Variable();
    };
}
