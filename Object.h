//
// Created by kalo on 2017/2/23.
//

#pragma once

#include "alic.h"

namespace alpha {
    namespace object {
        class Type;

        class Null;

        class Boolean;

        //class Byte;

        class Number;

        class Character;

        class Pair;

        //class ByteVector;

        class Vector;

        class String;

        class Identifier;

        class Procedure;

        namespace procedure {
            class Custom;

            class Accessor;
        }

        class Scope;

        class Custom;
    }

    class Object {
    public:
        Process *const process;
        const unsigned sn;
        object::Type *const type;
        unsigned referred_times;


        Object(Process *const &, object::Type *const &);

        virtual ~Object() = 0;
    };

    namespace object {
        class Type : public Object {
        public:
            Procedure *const constructor;

            Type(Process *const &, Procedure *const &);

            ~Type();
        };

        class Null : public Object {
        public:
            Null(Process *const &);
        };

        class Boolean : public Object {
        public:
            const bool value;

            Boolean(Process *const &, const bool &);
        };

        class Number : public Object {
        public:
            const double value;

            Number(Process *const, const double &);
        };

        class Character : public Object {
        public:
            const char value;

            Character(Process *const &, const char &);
        };

        class Pair : public Object {
        public:
            Object *car;
            Object *cdr;

            Pair(Process *const);

            ~Pair();
        };

        class Vector : public Object {
        public:
            std::vector<Object *> vector;

            Vector(Process *const &, const unsigned &);

            ~Vector();
        };

        class String : public Object {
        public:
            std::string value;

            String(Process *const &, const unsigned &);

            ~String();
        };

        class Identifier : public Object {
        public:
            const std::string string;
            Variable *variable;

            Identifier(Process *const &, const std::string &);
        };

        class Procedure : public Object {
        public:
            typedef Object *(*Value)(
                    Process *const &,
                    Scope *const &,     //caller scene
                    Object *const &,    //arguments
                    Object *&           //ejected object
            );

            const Value value;

            Procedure(Process *const &, const Value &);
        };

        namespace procedure {

            class Custom : public Procedure {
            public:
                Scope *const definition_scene;
                Identifier *const scene_parameter;
                Identifier *const arguments_parameter;
                Object *const execution_body;

                Custom(
                        Process *const &,
                        Scope *const &,         //definition scene
                        Identifier *const &,    //scene parameter
                        Identifier *const &,    //arguments parameter
                        Object *const &         //execution body
                );

                ~Custom();
            };

            class Accessor : public Custom {
            public:
                Type *const target_type;

                Accessor(
                        Process *const &,
                        Scope *const &,
                        Identifier *const &,
                        Identifier *const &,
                        Object *const &,
                        Type *const *&            //target type
                );

                ~Accessor();
            };
        }

        class Scope : public Object {
        public:
            Scope *const base;

            Scope(Process *const &, Scope *const);

            ~Scope();
        };

        class Custom : public Object {
        public:
            Object *const data;

            Custom(Process *const &, Object *const);

            ~Custom();
        };
    }
}
