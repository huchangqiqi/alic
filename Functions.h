//
// Created by kalo on 2017/2/24.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Functions {
        virtual ~Functions() = 0;

    public:
        class Constructors {
            virtual ~Constructors() = 0;

        public:
            static FUNCTION(type);
        };

        class Definitions {
            virtual ~Definitions() = 0;

        public:

        };

        class Data;

        class Structures;

        class Controls;

        class Execution;
    };
}
