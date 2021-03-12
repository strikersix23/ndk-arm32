#ifndef __JAVATHREAD_H__
#define __JAVATHREAD_H__

#include "thread.h"

class JavaThread {

public:
    // This method is implemented in threadLS_linux_aarch64.s
    static Thread *aarch64_get_thread_helper();
};

#endif /* __JAVATHREAD_H__ */

