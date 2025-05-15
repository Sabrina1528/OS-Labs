#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>

#include <time.h>

typedef struct {
int id;
} thread_data;
void *func1(void *ptr);
void *func2(void *ptr);
int main() {
pthread_t thread1, thread2;
int iret1, iret2;
thread_data data1 = {1};

thread_data data2 = {2};
iret1 = pthread_create(&thread1, NULL, func1, (void*)&data1);
iret2 = pthread_create(&thread2, NULL, func2, (void*)&data2);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("Thread 1 returns: %d\n", iret1);
printf("Thread 2 returns: %d\n", iret2);
exit(0);
}

void *func1(void *ptr) {
struct timespec delay;
delay.tv_sec = 1; // 1 second
delay.tv_nsec = 0; // 0 nanoseconds

for (int i = 0; i < 3; i++) {
printf("I in func1\n");
nanosleep(&delay, NULL);

}
pthread_exit(NULL);
}

void *func2(void *ptr) {
sleep(3);
for (int i = 0; i < 3; i++) {
sleep(3);
}
pthread_exit(NULL);
}
