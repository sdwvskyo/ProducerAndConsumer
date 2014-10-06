#include "MutexLock.h"
#include <assert.h>

MutexLock::MutexLock()
	: isLocked_(false)
{
	TINY_CHECK(!pthread_mutex_init(&mutex_, NULL));
}

MutexLock::~MutexLock()
{
	//确保已经解锁
	assert(isLocked_ == false);
	TINY_CHECK(!pthread_mutex_destroy(&mutex_));
}

void MutexLock::lock()
{
	TINY_CHECK(pthread_mutex_lock(&mutex_));
	isLocked_ = true;
}

void MutexLock::unlock()
{
	TINY_CHECK(!pthread_mutex_unlock(&mutex_));
	isLocked_ = false;
}

