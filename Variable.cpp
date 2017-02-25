//
// Created by kalo on 2017/2/23.
//

#include "Variable.h"

namespace alpha {
    Process *&Variable::process = Process::process;

    bool Variable::release(Variable *variable) {
        if (variable->identifier_binding_times || variable->values.size())return false;
        else {
            if (variable->sn) {
                delete variable;
                variable = NULL;
            }
            return true;
        }
    }

    Variable::Variable(const std::string &name) :
            sn(process->variable_ng.generate()),
            process_variables_iterator(
                    process->variables.insert(
                            std::make_pair<std::string, Variable *>(
                                    static_cast<std::string>(name),
                                    static_cast<Variable *>(this)
                            )
                    ).first
            ),
            identifier_binding_times(0) {}

    Variable::~Variable() {
        process->variable_ng.recycle(sn);
        sn = 0;
        process->variables.erase(process_variables_iterator);
    }
}