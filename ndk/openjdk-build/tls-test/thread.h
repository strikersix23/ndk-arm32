#ifndef __THREAD_H__
#define __THREAD_H__

// clang uses -femulated-tls by default
// add CXXFLAGS -fno-emulated-tls to disable tls supports(__thread)
#ifndef USE_LIBRARY_BASED_TLS_ONLY
#define THREAD_LOCAL_DECL __thread
//#define THREAD_LOCAL_DECL thread_local
#endif

class Thread{

    public:
        Thread* get_thread_current();

    private:
        static THREAD_LOCAL_DECL Thread *_thr_current;
};

#endif // __THREAD_H__
