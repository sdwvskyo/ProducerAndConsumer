#include "Buffer.h"

using namespace std;

Buffer::Buffer(size_t max)
	: full_(mutex_), empty_(mutex_), max_(max)
{

}

Buffer::~Buffer()
{

}

void Buffer::pushTask(const Msg &msg)
{
	mutex_.lock();
	while(queue_.size() >= max_)
		empty_.wait();
	queue_.push(msg);
	full_.notify();
	mutex_.unlock();
}

Msg Buffer::popTask()
{
	mutex_.lock();
	while(queue_.empty())
		full_.wait();
	Msg msg = queue_.front();
	queue_.pop();
	empty_.notify();
	mutex_.unlock();
	return msg;
}

