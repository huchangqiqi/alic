/**
 * Alpha interpreter based on C++
 */

#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "number-generator/number_generator.hpp"

#include "marcos.h"

namespace alpha {
    class Process;

    class Object;
    namespace object {
        using Object=Object;

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

    class Ejecta;
    namespace ejecta {
        class Break;

        class Throw;

        class Return;

        class Exit;
    }

    inline Process *useProcess(Process *const &);

    inline void rollbackProcess(Process *const &);
}

#include "Process.h"
#include "Object.h"
#include "Variable.h"
#include "Ejecta.h"
#include "functions.h"
