#include "Thread.h"

Thread::Thread()
{

}

void Thread::run()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true) {
        emit(refresh());
        msleep(35);
    }
#pragma clang diagnostic pop
}
