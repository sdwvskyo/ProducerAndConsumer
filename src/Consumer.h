#ifndef CONSUMER_H_
#define CONSUMER_H_ 

#include "Thread.h"

namespace Tiny
{
	
class Buffer;

class Consumer : public Thread
{
public:
	Consumer(Buffer &buffer);
	~Consumer();

	void run();
private:
	Buffer &buffer_;
};
}
#endif  /*CONSUMER_H_*/
