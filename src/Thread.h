#ifndef THREAD_H_
#define THREAD_H_ 

#include "boost/noncopyable.hpp"
#include <pthread.h>
#include <functional>
#include <sys/types.h>

namespace Tiny
{
class Thread : boost::noncopyable
{
public:
	typedef std::function<void ()> ThreadCallback;

	Thread();
	explicit Thread(const ThreadCallback &callback);
	~Thread();

	void setCallback(const ThreadCallback &callback);

	void start();
	void join();

	// virtual void run() = 0;
	
	pthread_t getThreadId() const { return threadId_; }
private:
	//静态函数没有隐士的this指针，可以用作thread函数,但是静态函数没有
	static void * threadFunc(void *arg);

	pthread_t threadId_;
	bool isStarted_;
	ThreadCallback callback_;	//回调函数
};
}

#endif  /*THREAD_H_*/
