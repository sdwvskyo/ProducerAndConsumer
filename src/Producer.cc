#include "Producer.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace Tiny;

Producer::Producer(Buffer &buffer)
	:buffer_(buffer)
{
	srand(12345);
}

Producer::~Producer()
{

}

void Producer::run() 
{
	while(1) {
		int num = rand() % 100;
		buffer_.push(num);
		printf("push a num: %d\n", num);
		
		sleep(2);
	}
}
