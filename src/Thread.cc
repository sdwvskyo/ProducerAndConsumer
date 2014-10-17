#include "Thread.h"
#include <unistd.h>
#include <assert.h>
#include "MutexLock.h"

using namespace Tiny;

Thread::Thread()
	: threadId_(0), 
	  isStarted_(false)
{
	
}

Thread::Thread(const ThreadCallback &callback)
	: threadId_(0),
	  isStarted_(false),
	  callback_(callback)
{
	
}

Thread::~Thread()
{
	if(isStarted_) {
		TINY_CHECK(!pthread_detach(threadId_));
	}
}

void Thread::setCallback(const ThreadCallback &callback)
{
	callback_ = callback;
}

void Thread::start()
{
	//使用线程作为线程执行函数，但是静态函数没有自己的数据成员，必须传入this指针操作数据
	TINY_CHECK(!pthread_create(&threadId_, NULL, Thread::threadFunc, (void *)this));
	isStarted_ = true;
}

void Thread::join()
{
	assert(isStarted_);
	TINY_CHECK(!pthread_join(threadId_, NULL));
	isStarted_ = false;
}


void * Thread::threadFunc(void * arg)
{
	Thread *pt = static_cast<Thread *>(arg);
	assert(pt->callback_);
	pt->callback_();
	return NULL;
}

