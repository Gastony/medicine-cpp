#include <iostream>
using namespace std;

#include <pthread.h>

class RWMutex
{
public:
    RWMutex();
    ~RWMutex();

    //scoped read lock
    class ScopedReadLock
    {
    public:
        ScopedReadLock(RWMutex & rwLock) : _rwLock(rwLock)
            {
                _rwLock.acquireReadLock();
            }

        ~ScopedReadLock()
            {
                _rwLock.releaseReadLock();
            }
    private:
        RWMutex & _rwLock;
    };

    //scoped write lock
    class ScopedWriteLock
    {
    public:
        ScopedWriteLock(RWMutex & rwLock) : _rwLock(rwLock)
            {
                _rwLock.acquireWriteLock();
            }

        ~ScopedWriteLock()
            {
                _rwLock.releaseWriteLock();
            }
    private:
        RWMutex & _rwLock;
    };
    
private:
    pthread_mutex_t _mutex;

    unsigned int _readers;
    pthread_cond_t _noReaders;

    unsigned int _pendingWriters;
    pthread_cond_t _writerFinished;
    bool _currentWriter;

    void acquireReadLock();
    void acquireWriteLock();
    void releaseReadLock();
    void releaseWriteLock();
};

RWMutex::RWMutex() : _readers(0), _pendingWriters(0), _currentWriter(false)
{
    pthread_mutex_init(&_mutex, NULL);
    pthread_cond_init(&_noReaders, NULL);
    pthread_cond_init(&_writerFinished, NULL);
}

RWMutex::~RWMutex()
{
    pthread_mutex_destroy(&_mutex);
    pthread_cond_destroy(&_noReaders);
    pthread_cond_destroy(&_writerFinished);
}

void RWMutex::acquireReadLock()
{
    pthread_mutex_lock(&_mutex);

    while (_pendingWriters != 0 || _currentWriter)
    {
        pthread_cond_wait(&_writerFinished, &_mutex);
    }
    ++_readers;

    pthread_mutex_unlock(&_mutex);
}

void RWMutex::acquireWriteLock()
{
    pthread_mutex_lock(&_mutex);

    ++_pendingWriters;
    
    while (_readers != 0)
    {
        pthread_cond_wait(&_noReaders, &_mutex);
    }

    while (_currentWriter)
    {
        pthread_cond_wait(&_writerFinished, &_mutex);
    }

    --_pendingWriters;
    _currentWriter = true;
    
    pthread_mutex_unlock(&_mutex);
}

void RWMutex::releaseReadLock()
{
    pthread_mutex_lock(&_mutex);

    --_readers;

    if (_readers == 0)
    {
        pthread_cond_signal(&_noReaders);
    }

    pthread_mutex_unlock(&_mutex);
}

void RWMutex::releaseWriteLock()
{
    pthread_mutex_lock(&_mutex);

    _currentWriter = false;
    pthread_cond_broadcast(&_writerFinished);
    
    pthread_mutex_unlock(&_mutex);
}

int main()
{
    return 0;
}
