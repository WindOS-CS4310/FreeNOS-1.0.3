#include <FreeNOS/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"
#include <ProcessClient.h>

unsigned int renice(unsigned int pid, unsigned int priority)
{ 
    ProcessClient::Info info;

    const ProcessClient process;
    const ProcessClient::Result result = process.processInfo(pid, info);
    if (result != ProcessClient::Success) {
        errno = EIO;
        return -1;
    }

    info.priority = priority;
    if (ProcessCtl(pid, ChangePriority, (Address) &priority) != API::Success)
    {
        errno = EIO;
        return -1;
    }

    // Done
    return 0;
}