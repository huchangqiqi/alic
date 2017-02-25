//
// Created by kalo on 2017/2/24.
//

#pragma once

#include "alic.h"

namespace alpha {
    namespace function {
        FUNCTION(eval);

        namespace constructor {
            FUNCTION(type);

            FUNCTION(null);

            FUNCTION(boolean);

            FUNCTION(number);

            FUNCTION(character);

            FUNCTION(pair);

            FUNCTION(vector);

            FUNCTION(string);

            FUNCTION(identifier);

            FUNCTION(procedure);

            FUNCTION(scope);
        }

        namespace definition {
            FUNCTION(isDefined);

            FUNCTION(isLocallyDefined);

            FUNCTION(define);

            FUNCTION(set);

            FUNCTION(erase);
        }

        namespace data {
            namespace datum {
                FUNCTION(parse);

                FUNCTION(stringify);
            }

            namespace data_hub {
                FUNCTION(tearFloating);

                FUNCTION(tearInteger);

                FUNCTION(booleansAndNatural);

                FUNCTION(naturalAndCharacter);
            }

            namespace logic {
                FUNCTION(not_);

                FUNCTION(or_);

                FUNCTION(xor_);

                FUNCTION(and_);
            }

            namespace order {
                FUNCTION(lt);

                FUNCTION(le);

                FUNCTION(eq);

                FUNCTION(ge);

                FUNCTION(gt);
            }

            namespace math {
                namespace basic {
                    FUNCTION(add);

                    FUNCTION(subtract);

                    FUNCTION(multiply);

                    FUNCTION(divide);
                }
                namespace third_order {
                    FUNCTION(exp);

                    FUNCTION(pow);

                    FUNCTION(root);

                    FUNCTION(lg);

                    FUNCTION(log);
                }
                namespace triangle {
                    FUNCTION(cos);

                    FUNCTION(acos);

                    FUNCTION(cosh);

                    FUNCTION(acosh);

                    FUNCTION(sin);

                    FUNCTION(asin);

                    FUNCTION(sinh);

                    FUNCTION(asinh);

                    FUNCTION(tan);

                    FUNCTION(atan);

                    FUNCTION(tanh);

                    FUNCTION(atanh);
                }
                namespace approx {
                    FUNCTION(floor);

                    FUNCTION(round);

                    FUNCTION(ceil);

                    FUNCTION(trunc);
                }
            }
        }

        namespace structure {
            namespace type {
                FUNCTION(make);

                FUNCTION(makeAccessor);

                FUNCTION(modifyLinearize);

                FUNCTION(modifyStringify);
            }
            namespace pair {
                FUNCTION(car);

                FUNCTION(setCar);

                FUNCTION(cdr);

                FUNCTION(setCdr);
            }
            namespace linear {
                FUNCTION(vectorSize);

                FUNCTION(vectorRef);

                FUNCTION(vectorSet);

                FUNCTION(stringSize);

                FUNCTION(stringRef);

                FUNCTION(stringSet);
            }
        }

        namespace console_io {
            FUNCTION(input);

            FUNCTION(output);
        }

        namespace flow_control {
            FUNCTION(seq);

            FUNCTION(if_);

            FUNCTION(loop);

            FUNCTION(break_);

            FUNCTION(try_);

            FUNCTION(throw_);

            FUNCTION(callWithCurrentContinuation);

            FUNCTION(exit);
        }

        namespace execution {
            FUNCTION(apply);

            FUNCTION(eval);
        }
    }
}
