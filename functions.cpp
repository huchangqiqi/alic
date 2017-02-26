//
// Created by kalo on 2017/2/24.
//

#include "functions.h"

namespace alpha {
    namespace function {
        auto &process = Process::process;

        FUNCTION(eval) {}

        namespace constructor {
            FUNCTION(type) {
                BEGIN;
                object::Procedure *constructor;
                ACCURATE_ARGUMENT(Procedure, constructor, VALUE_MODE, ({
                    RESULT(new object::Type(constructor));
                    Object::release(constructor);
                }));
                END;
            }
        }

        namespace data {
            namespace datum {
                FUNCTION(parse) {}

                FUNCTION(stringify);
            }
        }
    }
}