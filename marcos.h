//
// Created by kalo on 2017/2/24.
//

#pragma once

#define FUNCTION(NAME)\
    Object * NAME(\
        object::Scope *const &calling_scene,\
        Object *const &arguments,\
        Ejecta *&ejecta\
    )

#define FUNCTION_BEGIN\
    Object::bound(calling_scene);\
    Object::bound(arguments);\
    Object *result;


#define EXTRACT_ARGUMENT(IF_MISSING,ARG_NAME,BODY)\
    if (arguments->type != process->Pair) {\
        ejecta = new ejecta::Throw(\
            new object::String("argument extracting error: there are not enough arguments")\
        );\
    } else {\
        {\
            object::Pair *__pair = static_cast<object::Pair *>(arguments);\
            arg = Object::bound(__pair->car);\
            arguments = Object::bound(__pair->cdr);\
            if (Object::release(__pair)) __pair = NULL;\
        }\
        \
    }

