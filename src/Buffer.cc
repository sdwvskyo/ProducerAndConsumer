#include "Buffer.h"

using namespace std;

Buffer::Buffer(size_t max)
	: full_(mutex_), empty_(mutex_), max_(max)
{

}

Buffer::~Buffer()
{

}

void Buffer::push(const Msg &msg)
{
	{
		MutexLockGuard lock(mutex_);
		while(queue_.size() >= max_)
			empty_.wait();
		queue_.push(msg);
	}
	full_.notify();
}

Msg Buffer::pop()
{
	Msg msg;
	{
		MutexLockGuard lock(mutex_);
		while(queue_.empty())
			full_.wait();
		msg = queue_.front();
		queue_.pop();
	}
	empty_.notify();
	return msg;
}

bool Buffer::isEmpty() const 
{
	MutexLockGuard lock(mutex_);
	return queue_.empty(); 
}

size_t Buffer::size() const 
{ 
	MutexLockGuard lock(mutex_);
	return queue_.size(); 
}
