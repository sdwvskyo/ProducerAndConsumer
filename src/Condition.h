#ifndef CONDITION_H_
#define CONDITION_H_ 

#include <pthread.h>
#include "NonCopyable.h"

namespace Tiny
{
	
class MutexLock;

class Condition : NonCopyable
{
public:
	Condition(MutexLock &mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

private:
	MutexLock &mutex_;
	pthread_cond_t cond_;	
};
}
#endif  /*CONDITION_H_*/
