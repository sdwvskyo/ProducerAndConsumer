#ifndef PRODUCER_H_
#define PRODUCER_H_ 

#include "Thread.h"

namespace Tiny
{
	
class Buffer;

class Producer : public Thread
{
	public:
		Producer(Buffer &buffer);
		~Producer();

		void run();
	private:
		Buffer &buffer_;
};
}

#endif  /*PRODUCER_H_*/
