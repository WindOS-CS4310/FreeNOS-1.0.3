#include <FreeNOS/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"
#include <ProcessClient.h>
#include "ProcessCtl.h"

unsigned int renice(unsigned int pid, unsigned int priority)
{ 
    ProcessClient::Info info;
    ProcessInfo i;

    const ProcessClient process;
    const ProcessClient::Result result = process.processInfo(pid, info);
    if (result != ProcessClient::Success) {
        errno = EIO;
        return -1;
    }

    i.priority = priority;
    if (ProcessCtl(pid, ChangePriority, (Address) &i) != API::Success)
    {
        errno = EIO;
        return -1;
    }

    // Done
    return 0;
}