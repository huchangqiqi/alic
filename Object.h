//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Object {
    public:
        static Process *&process;

        static inline bool release(Object *, const unsigned &n = 1);

        template<typename T>
        static inline T *bound(T *const &, const unsigned &n = 1);

        unsigned sn;
        object::Type *type;
        unsigned binding_times;

        Object(object::Type *const &);

        virtual ~Object() = 0;

        /**
         * for Type()
         */
        Object();
    };

    namespace object {
        class Type : public Object {

        public:
            Procedure *constructor;

            Type(Procedure *const &);

            ~Type();

            /**
             * for Process::type_type, Process::procedure_type
             */
            Type();
        };

        class Null : public Object {

        public:
            Null();
        };

        class Boolean : public Object {
        public:
            const bool value;

            Boolean(const bool &);
        };

        class Number : public Object {
        public:
            const double value;

            Number(const double &);
        };

        class Character : public Object {
        public:
            const char value;

            Character(const char &);
        };

        class Pair : public Object {
        public:
            Object *car;
            Object *cdr;

            Pair();

            ~Pair();
        };

        class Vector : public Object {
        public:
            std::vector<Object *> value;

            Vector(const unsigned &);

            ~Vector();
        };

        class String : public Object {
        public:
            std::string value;

            String(const unsigned &);
        };

        class Identifier : public Object {
        public:
            const std::string string;

            Variable *variable;

            Identifier(const std::string &);

            ~Identifier();
        };

        class Procedure : public Object {
        public:
            typedef FUNCTION((*const Value));

            const Value value;

            Procedure(const Value &);
        };

        namespace procedure {
            class Custom : public Procedure {
            public:
                Scope *definition_scene;
                Identifier *scene_parameter;
                Identifier *arguments_parameter;
                Object *execution_body;

                Custom(
                        Scope *const &,         //definition scene
                        Identifier *const &,    //scene parameter
                        Identifier *const &,    //arguments parameter
                        Object *const &         //execution body
                );

                Custom(
                        const Value &,
                        Scope *const &,         //definition scene
                        Identifier *const &,    //scene parameter
                        Identifier *const &,    //arguments parameter
                        Object *const &         //execution body
                );

                ~Custom();
            };

            class Accessor : public Custom {
            public:
                Type *target_type;

                Accessor(
                        Scope *const &,
                        Identifier *const &,
                        Identifier *const &,
                        Object *const &,
                        Type *const &           //target type
                );

                ~Accessor();
            };
        }

        class Scope : public Object {
        public:
            Scope *base;
            std::unordered_map<unsigned, Variable *> variables;

            Scope(Scope *const);

            ~Scope();

            /**
             * for global
             */
            Scope();
        };

        class Custom : public Object {
        public:
            Object *const data;

            Custom(Object *const);

            ~Custom();
        };
    }
}
