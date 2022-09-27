#include <FreeNOS/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"

/* ProcessCtl is defined in kernel/API/ProcessCtl.cpp where you can find the Case that takes in WaitPID case. 
Right click on wait and it will take you to kernel/Process.cpp where you can see how the state is set to waiting and the wait ID is
to the given ID */

unsigned int wait(unsigned int pid)
{
    Timer::Info info;

    if (ProcessCtl(pid, WaitPID, (Address) &info) != API::Success)
    {
        errno = EIO;
        return -1;
    }

    // Done
    return 0;
}