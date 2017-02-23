//
// Created by kalo on 2017/2/23.
//

#include "Object.h"

namespace alpha {
    Object::Object(Process *const &process, object::Type *const &type) :
            process(process),
            sn(process->object_ng.generate()),
            type(type),
            referred_times(0) {}
}