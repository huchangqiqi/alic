//
// Created by kalo on 2017/2/23.
//

#include "Process.cpp"
#include "Object.cpp"
#include "Variable.cpp"

namespace alpha {
    Process *useProcess(Process *const &new_process) {
        auto process_backup = Process::process;
        Process::process = new_process;
        return process_backup;
    }

    void rollbackProcess(Process *const &process_backup) {
        Process::process = process_backup;
    }
}

#include "macros.cpp"