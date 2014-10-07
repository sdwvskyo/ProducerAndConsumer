#ifndef BUFFER_H_
#define BUFFER_H_ 

#include "NonCopyable.h"
#include <queue>
#include "MutexLock.h"
#include "Condition.h"

typedef int Msg;

class Buffer
{
public:
	Buffer(size_t max = 10);
	~Buffer();

	void push(const Msg &msg);
	Msg pop();

	void setMax(size_t max) { max_ = max; }
	bool isEmpty() const;
	size_t size() const;

private:
	mutable MutexLock mutex_;
	Condition full_;
	Condition empty_;

	size_t max_;
	std::queue<Msg> queue_;
};

#endif  /*BUFFER_H_*/
