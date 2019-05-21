#include "Thread.h"

Thread::Thread() {
    this->active = true;
}

void Thread::run() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (this->active) {
        emit(refresh());
        msleep(35);
    }
#pragma clang diagnostic pop
}

void Thread::pause() {
    this->active = false;
}

void Thread::resume() {

    this->active = true;
}

bool Thread::isActive() const {
    return this->active;
}
