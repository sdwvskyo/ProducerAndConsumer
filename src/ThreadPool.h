#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <boost/noncopyable.hpp>
#include "MutexLock.h"
#include "Condition.h"
#include "Thread.h"
#include <queue>
#include <vector>
#include <functional>
#include <memory>

namespace Tiny
{
class ThreadPool : boost::noncopyable
{
public:
	typedef std::function<void ()> Task;

	ThreadPool(size_t queueSize = 10, size_t threadNum = 5);
	~ThreadPool();

	void start();
	void stop();

	void addTask(const Task &task);
	Task getTask();

	bool isStarted() const { return isStarted_; }

	void runInThread();
private:
	mutable MutexLock mutex_;
	Condition empty_;
	Condition full_;

	size_t queueSize_;
	std::queue<Task> queue_;

	const size_t threadNum_;
	std::vector<std::unique_ptr<Thread>> threads_;
	bool isStarted_; 
};
}



#endif	//THREADPOOL_H_ 