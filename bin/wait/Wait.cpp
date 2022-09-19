#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv): POSIXApplication(argc, argv) {
    parser().setDescription("Block OS input until Process finishes");
    parser().registerPositional("PID", "ID of the Process to wait for");
}

Wait::~Wait() { }

Wait::Result Wait::exec()
{
    int id = 0;

    // Convert input to seconds
    if ((id = atoi(arguments().get("PID"))) <= 0)
    {
        ERROR("Invalid PID  `" << arguments().get("PID") << "'");
        return InvalidArgument;
    }

    if (wait(id) != 0)
    {
        ERROR("failed to wait: " << strerror(errno));
        return IOError;
    }

    // Done
    return Success;
}
