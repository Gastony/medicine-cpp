#include <iostream>
#include <pthread.h>

#define NUM_THREADS 3

int count = 0;
#define LIMIT 10

pthread_mutex_t count_mutex;
pthread_cond_t count_cv;

void * Increase(void * data)
{
    int id = (int)data;
    std::cout << "Badge: thread id = " << id <<  std::endl;
    std::cout << "my thread id:" << id << "|" << pthread_self() <<  std::endl;

    for (int i = 0; i < LIMIT; ++i)
    {
        pthread_mutex_lock(&count_mutex);
        
        if (count == LIMIT)
        {
            std::cout << "thread id:" << id << " LIMIT count = " << count << std::endl;
            pthread_cond_signal(&count_cv);

            pthread_mutex_unlock(&count_mutex);
            pthread_exit(NULL);
        }
        else
        {
            ++count;
            std::cout << "thread id:" << id << " count = " << count <<
            std::endl;
        }
        pthread_mutex_unlock(&count_mutex);

        sleep(1);
    }
    
    pthread_exit(NULL);
}

void * Watch(void * data)
{
    int id = (int)data;
    std::cout << "Badge: thread id = " << id <<  std::endl;
    std::cout << "my thread id:" << id << "|" << pthread_self() <<  std::endl;

    pthread_mutex_lock(&count_mutex);

    std::cout << "thread id:" << id << " Watch before while count = " << count << std::endl;
    while (count < LIMIT)
    {
        std::cout << "thread id:" << id << " Watch in while count = " << count << std::endl;
        pthread_cond_wait(&count_cv, &count_mutex);
        std::cout << "thread id:" << id << " Watch post wait while count = " << count << std::endl;
    }

    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&count_mutex, NULL);
    pthread_cond_init(&count_cv, NULL);

    for (int i = 0; i < NUM_THREADS -1; ++i)
    {
        std::cout << "In main: creating thread " << i << std::endl;
        int rc = pthread_create(&threads[i], NULL, Increase, (void*)i);
        if (rc)
        {
            std::cout << "Error: return code from pthread_create() is "
                      << rc << " i= " << i << "\n";
            exit(-1);
        }
    }

    int id = 2;
    int rc = pthread_create(&threads[2], NULL, Watch, (void*)id);
    if (rc)
    {
        std::cout << "Error: return code from pthread_create() is "
                  << rc << " i= " << id << "\n";
        exit(-1);
    }

    std::cout << "main thread id " << pthread_self() <<  std::endl;

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    std::cout << "main thread count = " << count << std::endl;
    
    pthread_exit(NULL);
}
