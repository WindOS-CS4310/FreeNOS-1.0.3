#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include "ProcessManager.h"

Renice::Renice(int argc, char **argv): POSIXApplication(argc, argv) {
    parser().setDescription("Change the priority of processes");
    parser().registerFlag('n', "priority", "Priority Number");
    parser().registerPositional("Pri", "The priority to change to");
    parser().registerPositional("PID", "The processes ID to change");
}

Renice::Result Renice::exec() {
    const ProcessClient process;

    int priority = 0;
    if ((priority = atoi(arguments().get("Pri"))) <= 0) {
        ERROR("Invalid Priority!");
        return InvalidArgument;
    }
    
    int id = 0;
    if ((id = atoi(arguments().get("PID"))) <= 0)
    {
        ERROR("Invalid PID  `" << arguments().get("PID") << "'");
        return InvalidArgument;
    }

    Process* p = ProcessManager::get(id);
    if (p != null) {
        printf("Priority of process is %2d", p->getPriority());
    }

    return Success;
}
