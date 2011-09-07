#include <iostream>
#include <pthread.h>

class ScopedLock
{
public:
    ScopedLock(pthread_mutex_t& mutex);
    ~ScopedLock();

    void lock();
    void unlock();
    bool isLocked();
    
private:
    pthread_mutex_t& _mutex;
    bool _locked;
};

ScopedLock::ScopedLock(pthread_mutex_t& mutex) : _mutex(mutex) // references can only be initialized here
{
    //pthread_mutex_init(&_mutex, NULL);
    //_mutex = mutex;
    pthread_mutex_lock(&_mutex);
    std::cout << "acquired mutex\n";
    _locked = true;
}

ScopedLock::~ScopedLock()
{
    pthread_mutex_unlock(&_mutex);
    std::cout << "destroyed mutex\n";
    _locked = false;
}

void ScopedLock::lock()
{
    if (_locked) return;

    pthread_mutex_lock(&_mutex);
    _locked = true;
}

void ScopedLock::unlock()
{
    if (!_locked) return;
    pthread_mutex_unlock(&_mutex);
    _locked = false;
}

bool ScopedLock::isLocked()
{
    return _locked;
}

int count = 0;

class Test
{
public:
    Test() { pthread_mutex_init(&new_mutex, NULL); }
    ~Test() {}

    void * compute(void * data);
private:
    pthread_mutex_t new_mutex;
};

void * Test::compute(void * data)
{
    int id = (int)data;
    std::cout << "my thread id:" << id << "|" << pthread_self() <<
        std::endl;
    std::cout << "before mutex count = " << count << "|" << id << std::endl;
    ScopedLock sl(new_mutex);
    sleep(3);
    std::cout << "after sleep mutex count = " << count << "|" << id << std::endl;
    ++count;
    std::cout << "after Inc mutex count = " << count << "|" << id << std::endl;
}

template <class T>
class Launcher
{
public:
    Launcher(T * obj, void * (T::*mfpt) (void *), void * arg) : myobj(obj), fpt(mfpt), myarg(arg) {}
    ~Launcher() {}

    void launch() { (*myobj.*fpt)(myarg);}
private:
    T* myobj;
    void* myarg;
    void * (T::*fpt) (void *); //Member function pointer 
};

template <class T>
void * LaunchMemberFunction(void * obj)
{
    Launcher<T> * l = reinterpret_cast<Launcher<T>*>(obj);
    l->launch();
}

int main()
{
    pthread_t threads[3];
    Launcher<Test> * larray[3];
    Test t;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "In main: creating thread " << i << std::endl;
        
        larray[i] = new Launcher<Test>(&t, &Test::compute, (void*)i);
        std::cout << "address of l is " << larray[i] << std::endl;
        int rc = pthread_create(&threads[i], NULL, LaunchMemberFunction<Test>, larray[i]);
        if (rc)
        {
            std::cout << "Error: return code from pthread_create() is "
                      << rc << " i= " << i << "\n";
            exit(-1);
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    std::cout << "main thread count = " << count << std::endl;

    //delete [] larray;
    for (int i = 0; i < 3; ++i)
    {
        delete larray[i]; //cannot do delete [] larray here because larray has not been created by new
    }
    
    pthread_exit(NULL);
}
    
