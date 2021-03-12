#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "thread.h"
#include "JavaThread.h"

// test __thread if works?
__thread int var = 5;

void* worker1(void* arg){
    printf("thread worker1 var = %d\n", ++var); // output 6
    return NULL;
}

void* worker2(void* arg){
    sleep(2); // sleeping 2s
    printf("thread worker2 var = %d\n", ++var); // output 6
    return NULL;
}

int main(int argc, char *argv[]){

    Thread mThread;
    JavaThread jThread;

    printf("mThread addr: %p\n", mThread.get_thread_current());
    
    printf("jThread addr: %p\n", JavaThread::aarch64_get_thread_helper());

    pthread_t pid1, pid2;
    
    pthread_create(&pid1, NULL, worker1, NULL);
    pthread_create(&pid2, NULL, worker2, NULL);
    
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    printf("android tls test success!\n");
    
    return 0;
}
