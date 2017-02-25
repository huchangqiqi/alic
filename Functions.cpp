//
// Created by kalo on 2017/2/24.
//

#include "Functions.h"

namespace alpha {
    Process *&Functions::process = Process::process;

    FUNCTION(Functions::Constructors::type) {
        FUNCTION_BEGIN
        Object *arg;
        if (arguments->type != process->Pair) {
            ejecta = new ejecta::Throw(
                    new object::String("argument extracting error: there are not enough arguments")
            );
        } else {
            {
                object::Pair *__pair = static_cast<object::Pair *>(arguments);
                arg = Object::bound(__pair->car);
                arguments = Object::bound(__pair->cdr);
                if (Object::release(__pair)) __pair = NULL;
            }

        }
    }
}