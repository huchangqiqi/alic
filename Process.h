//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Process {
    public:
        static Process *process;

        NumberGenerator object_ng, variable_ng;

        object::Type
                *type_type,
                *null_type,
                *boolean_type,
                *number_type,
                *character_type,
                *pair_type,
                *vector_type,
                *string_type,
                *identifier_type,
                *procedure_type,
                *scope_type;
        object::Null *null;
        object::Boolean *true_, *false_;
        object::Scope *global;

        std::unordered_map<std::string, Variable *> variables;

        /**
         * Monitor the life cycle
         */
        std::unordered_map<unsigned, Object *> object_statistics;
        std::unordered_map<std::string, Variable *> variable_statistics;
    public:
        Process();

        ~Process();
    };
}
