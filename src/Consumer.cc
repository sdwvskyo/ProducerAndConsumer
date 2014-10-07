#include "Consumer.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdio.h>

Consumer::Consumer(Buffer &buffer)
	: buffer_(buffer)
{

}

Consumer::~Consumer() 
{

}

void Consumer::run()
{
	while(1) {
		int num = buffer_.pop();
		printf("pop a num: %d\n", num);
		sleep(2);
	}
}
