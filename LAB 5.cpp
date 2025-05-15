#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
sem_t x, y;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;
void *reader(void *param)
{
sem_wait(&x); // Lock the reader count
readercount++;
if (readercount == 1) // First reader locks the writer
sem_wait(&y);
sem_post(&x); // Release the reader count lock
printf("%d reader is inside\n", readercount);
usleep(3); // Simulate reading
sem_wait(&x); // Lock the reader count
readercount--;
if (readercount == 0) // Last reader releases the writer
sem_post(&y);
sem_post(&x); // Release the reader count lock
printf("%d Reader is leaving\n", readercount + 1); // Corrected print
return NULL;
}

void *writer(void *param)
{
printf("Writer is trying to enter\n");
sem_wait(&y); // Lock writer access
printf("Writer has entered\n");
sem_post(&y); // Release writer lock
printf("Writer is leaving\n");
return NULL;
}
int main()
{
int n2, i;
printf("Enter the number of readers:\n");
scanf("%d", &n2);
// Initialize semaphores
sem_init(&x, 0, 1); // Mutex for reader count
sem_init(&y, 0, 1); // Semaphore for writer access
// Create reader and writer threads
for (i = 0; i < n2; i++)
{
pthread_create(&readerthreads[i], NULL, reader, NULL); // Create reader
thread
pthread_create(&writerthreads[i], NULL, writer, NULL); // Create writer thread
}
// Wait for threads to finish
for (i = 0; i < n2; i++)
{
pthread_join(readerthreads[i], NULL);
pthread_join(writerthreads[i], NULL);
}
// Destroy semaphores
sem_destroy(&x);
sem_destroy(&y);
return 0;
}
