#include <iostream>
#include "thread.h"

// init _thr_current
THREAD_LOCAL_DECL Thread* Thread::_thr_current = NULL;

Thread* Thread::get_thread_current(){
    if(_thr_current == NULL)
        _thr_current = this;
    return _thr_current;
}
