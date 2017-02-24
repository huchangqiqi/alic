//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    class Object {
    public:
        static inline bool release(Object *, const unsigned &n = 1);

        template<typename T>
        static inline T *bound(T *const &, const unsigned &n = 1);

    protected:
        unsigned sn;
        object::Type *type;
        unsigned binding_times;
    public:
        Object(object::Type *const &);

        virtual ~Object() = 0;
    };

    namespace object {
        class Type : public Object {
        protected:
            Procedure *constructor;
        public:
            Type(Procedure *const &);

            ~Type();
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
        protected:
            Object *car;
            Object *cdr;
        public:
            Pair();

            ~Pair();
        };

        class Vector : public Object {
        protected:
            std::vector<Object *> value;
        public:
            Vector(const unsigned &);

            ~Vector();
        };

        class String : public Object {
        protected:
            std::string value;
        public:
            String(const unsigned &);
        };

        class Identifier : public Object {
        public:
            const std::string string;
        protected:
            Variable *variable;
        public:
            Identifier(const std::string &);

            ~Identifier();
        };

        class Procedure : public Object {
        public:
            typedef Object *(*const Value)(
                    Scope *const &,     //caller scene
                    Object *const &,    //arguments
                    Object *&           //ejected object
            );

            const Value value;

            Procedure(const Value &);
        };

        namespace procedure {
            class Custom : public Procedure {
            protected:
                Scope *definition_scene;
                Identifier *scene_parameter;
                Identifier *arguments_parameter;
                Object *execution_body;
            public:
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
            protected:
                Type *target_type;
            public:
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
        protected:
            Scope *base;
            std::unordered_map<unsigned, Variable *> variables;
        public:
            Scope(Scope *const);

            ~Scope();
        };

        class Custom : public Object {
        public:
            Object *const data;

            Custom(Object *const);

            ~Custom();
        };
    }
}
