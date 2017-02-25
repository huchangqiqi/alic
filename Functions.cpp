//
// Created by kalo on 2017/2/24.
//

#include "Functions.h"

namespace alpha {
    Process *&Functions::process = Process::process;

    FUNCTION(Functions::Constructors::type) {
        if (arguments->type == process->Pair) {
            Object *arg;
            {
                object::Pair *__pair = static_cast<object::Pair *>(arguments);
                arg = Object::bound(__pair->car);
            }
        }
    }
}