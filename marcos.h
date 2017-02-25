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

#define READ_ARGUMENT(VAR_NAME,THEN,ELSE)\

