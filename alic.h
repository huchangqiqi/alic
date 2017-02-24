/**
 * Alpha interpreter based on C++
 */

#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "number-generator/number_generator.hpp"

#include "macros.h"

namespace alpha {
    class Process;

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

    class Functions;

    inline Process *useProcess(Process *const &);

    inline void rollbackProcess(Process *const &);
}

#include "Functions.h"
#include "Variable.h"
#include "Object.h"
#include "Process.h"
