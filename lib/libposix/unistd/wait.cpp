#include <FreeNOS/User.h>
#include <Timer.h>
#include "unistd.h"
#include "errno.h"

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