//
// Created by Nicolas Haenni on 2019-05-18.
//

#include "Thread.h"

Thread::Thread(): running(false)
{

}

void Thread::run()
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(this->running) {
        emit(refresh());
        msleep(35);
    }
#pragma clang diagnostic pop
    this->exit();
}

void Thread::resume()
{
    if (!this->running) this->running = true;
}

void Thread::pause()
{
    if (this->running) this->running = false;
}
