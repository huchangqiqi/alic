//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Process {
    public:
        NumberGenerator object_ng, variable_ng;

        object::Type
                *const type_type,
                *const null_type,
                *const boolean_type,
                *const number_type,
                *const character_type,
                *const pair_type,
                *const vector_type,
                *const string_type,
                *const identifier_type,
                *const procedure_type,
                *const scope_type;
        object::Null *const null;
        object::Boolean *const true_, *const false_;
        object::Scope *const global;

        std::unordered_map<std::string, Variable *> variables;

        Process();

        ~Process();
    };
}
