#ifndef THREAD_H_
#define THREAD_H_ 

#include "NonCopyable.h"
#include <pthread.h>
#include <functional>
#include <sys/types.h>

class Thread : NonCopyable
{
public:
	Thread();
	~Thread();

	void start();
	void join();

	virtual void run();

private:
	//静态函数没有隐士的this指针，可以用作thread函数,但是静态函数没有
	static void * threadFunc(void *);

	pthread_t threadId_;
	bool isStarted_;
};

#endif  /*THREAD_H_*/
