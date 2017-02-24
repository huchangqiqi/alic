//
// Created by kalo on 2017/2/23.
//

#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "number-generator/number_generator.hpp"

namespace alpha {
    class Process;

    Process *process;

    class Object;
    namespace object {
        class Type;

        class Null;

        class Boolean;

        //class Byte;

        class Number;

        class Character;

        class Pair;

        //class ByteVector;

        class Vector;

        class String;

        class Identifier;

        class Procedure;

        namespace procedure {
            class Custom;

            class Accessor;
        }

        class Scope;

        class Custom;
    }

    class Variable;
}

#include "Variable.h"
#include "Object.h"
#include "Process.h"
