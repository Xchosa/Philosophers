




#include "../inc/philo.h"



#define NUM_THREADS 10
#define NUM_INCREMENTS 1000000

int global_counter = 0;
pthread_mutex_t mutex;

void *increment_counter(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        // Lock the mutex before modifying the shared variable
        pthread_mutex_lock(&mutex);
        global_counter++;
        // Unlock the mutex after modification
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

// int main()
{
    pthread_t threads[NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads to execute the increment_counter function
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Join the threads to ensure completion
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display the final counter value
    printf("Final counter value: %d\n", global_counter);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
// // intialize mutex
// phtread_mutex_intit();
// // destroy
// pthread_mutex_destroy();

// //lock the mutex before accessing the shared resource
// pthread_mutex_lock();

// pthread_mutex_unlock()