#include <FreeNOS/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"
#include <ProcessClient.h>

/* ProcessCtl is defined in kernel/API/ProcessCtl.cpp where you can find the Case that takes in WaitPID case. 
Right click on wait and it will take you to kernel/Process.cpp where you can see how the state is set to waiting and the wait ID is
to the given ID */

unsigned int renice(unsigned int pid, unsigned int priority)
{ 
    ProcessClient::Info info;
    const ProcessClient process;
    const ProcessClient::Result result = process.processInfo(id, info);

    if (result != ProcessClient::Success) {
        errno = EIO
        return -1;
    }

    info.priority = priority;
    if (ProcessCtl(pid, ChangePriority, (Address) &info) != API::Success)
    {
        errno = EIO;
        return -1;
    }

    // Done
    return 0;
}