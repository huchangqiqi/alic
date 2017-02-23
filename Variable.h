//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Variable {
    public:
        std::unordered_map<unsigned, Object *> values;

        ~Variable();
    };
}
