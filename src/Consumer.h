#ifndef CONSUMER_H_
#define CONSUMER_H_ 

#include "Thread.h"

class Buffer;

class Consumer : public Thread
{
	public:
		Consumer(Buffer &buffer);
		~Consumer();

		void run() override;
	private:
		Buffer &buffer_;
};

#endif  /*CONSUMER_H_*/
