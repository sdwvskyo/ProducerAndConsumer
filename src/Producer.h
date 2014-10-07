#ifndef PRODUCER_H_
#define PRODUCER_H_ 

#include "Thread.h"

class Buffer;

class Producer : public Thread
{
	public:
		Producer(Buffer &buffer);
		~Producer() override;

		void run() override;
	private:
		Buffer &buffer_;
};

#endif  /*PRODUCER_H_*/
