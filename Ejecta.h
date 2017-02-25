//
// Created by kalo on 2017/2/24.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Ejecta {
    public:
        enum Type {
            Break, Throw, Return, Exit
        };
        const Type type;

        Ejecta(const Type &);
    };

    namespace ejecta {
        class Break : public Ejecta {
        public:
            const unsigned scope_sn;
            Object *object;

            Break(const unsigned &, Object *const &);

            ~Break();
        };

        class Throw : public Ejecta {
        public:
            Object *object;

            Throw(Object *const &);

            ~Throw();
        };

        class Return : public Ejecta {
        public:
            const unsigned procedure_sn;
            Object *object;

            Return(const unsigned &, Object *const &);

            ~Return();
        };

        class Exit : public Ejecta {
        public:
            Object *object;

            Exit(Object *const &);

            ~Exit();
        };
    }
}
