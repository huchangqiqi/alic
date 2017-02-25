//
// Created by kalo on 2017/2/24.
//

#pragma once

#define FUNCTION(NAME)\
    Object * NAME(\
        object::Scope *calling_scene,\
        Object *arguments,\
        Ejecta *&ejecta\
    )

#define CAST(TYPE, VALUE) static_cast<object::TYPE *>(VALUE)

#define BEGIN\
    Object *result = NULL;

#define RESULT(VALUE) result = VALUE
#define ERROR(MSG) ejecta = new ejecta::Throw(new object::String(MSG))
#define IF_ERROR(THEN, ELSE)\
    if (ejecta) THEN;\
    else ELSE;

#define EXPRESSION_MODE __pair->car

#define VALUE_MODE eval(calling_scene, EXPRESSION_MODE, ejecta)

#define ARGUMENT(IF_MISSING, OBJ_TYPE, IF_TYPE_MISMATCH, ARG_NAME, ARG_FORM, BODY)\
    if (arguments->type != process->Pair) {\
        IF_MISSING;\
    } else {\
        {\
            object::Pair *__pair = static_cast<object::Pair *>(arguments);\
            Object *__arg = ARG_FORM;\
            if (!ejecta) {\
                if (__arg->type != process->OBJ_TYPE) IF_TYPE_MISMATCH;\
                else {\
                    ARG_NAME = Object::bound(CAST(OBJ_TYPE, __arg));\
                    arguments = __pair->cdr;\
                    BODY;\
                }\
            }\
        }\
    }

#define REQUIRED_ARGUMENT(OBJ_TYPE, IF_TYPE_MISMATCH, ARG_NAME, ARG_FORM, BODY)\
    ARGUMENT(({\
        ERROR("argument error: there are not enough arguments");\
    }), OBJ_TYPE, IF_TYPE_MISMATCH, ARG_NAME, ARG_FORM, BODY)

#define ACCURATE_ARGUMENT(OBJ_TYPE, ARG_NAME, ARG_FORM, BODY)\
    REQUIRED_ARGUMENT(OBJ_TYPE, ({\
        ERROR("type error: type of argument is wrong");\
    }), ARG_NAME, ARG_FORM, BODY)

#define END\
    return result;

