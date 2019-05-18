//
// Created by Nicolas Haenni on 2019-05-18.
//

#include "Thread.h"

Thread::Thread() = default;

void Thread::run()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true) {
        emit(refresh());
        msleep(20);
    }
#pragma clang diagnostic pop
}
