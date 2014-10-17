#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_ 

#include <pthread.h>
#include "NonCopyable.h"
#include <stdio.h>

//用于pthread系列函数的返回值检查
#define TINY_CHECK(exp) \
	if(!(exp))\
	{ fprintf(stderr, "File:%s, Line:%d Exp:[" #exp "] is true, abort.\n", \
				__FILE__, __LINE__); abort(); }

namespace Tiny
{
class MutexLock : NonCopyable 
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexPtr() { return &mutex_; }
	bool isLocked() const { return isLocked_; }

private:
	pthread_mutex_t mutex_;
	bool isLocked_;
};

class MutexLockGuard : NonCopyable
{
public:
	MutexLockGuard(MutexLock &mutex) : mutex_(mutex)
	{ mutex_.lock(); }
	~MutexLockGuard() { mutex_.unlock(); }
private:
	MutexLock &mutex_;
};
}
#endif  /*MUTEXLOCK_H_*/
