#ifndef BUFFER_H_
#define BUFFER_H_ 

#include "NonCopyable.h"
#include <queue>
#include "MutexLock.h"
#include "Condition.h"

class Condition;
class MutexLock;

typedef int Msg;

class Buffer
{
public:
	Buffer(size_t max = 10);
	~Buffer();

	void pushTask(const Msg &msg);
	Msg popTask();

	void setMax(size_t max) { max_ = max; }
private:
	MutexLock mutex_;
	Condition full_;
	Condition empty_;
	size_t max_;
	std::queue<Msg> queue_;
};

#endif  /*BUFFER_H_*/
