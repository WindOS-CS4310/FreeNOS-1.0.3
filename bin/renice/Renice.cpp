#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Renice.h"
#include <ProcessClient.h>

Renice::Renice(int argc, char **argv): POSIXApplication(argc, argv) {
    parser().setDescription("Change the priority of processes");
    parser().registerFlag('n', "priority", "Priority Number");
    parser().registerPositional("Pri", "The priority to change to");
    parser().registerPositional("PID", "The processes ID to change");
}

Renice::Result Renice::exec() {
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

    const ProcessClient process;
    ProcessClient::Info info;
    const ProcessClient::Result result = process.processInfo(id, info);
    if (result == ProcessClient::Success) {
        printf("Priority is %2d", info.priority);
    }

    return Success;
}
