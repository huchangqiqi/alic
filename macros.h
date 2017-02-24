//
// Created by kalo on 2017/2/24.
//

#pragma once

#define FUNCTION(NAME) Object * NAME(\
    object::Scope *const &calling_scene,\
    Object *const &arguments,\
    Object *&ejecta\
)
