#ifndef WORKSHOP_H_
#define WORKSHOP_H_ 

#include "NonCopyable.h"
#include "Buffer.h"
#include <vector>

namespace Tiny
{
	
class Producer;
class Consumer;

class WorkShop : NonCopyable
{
public:
	WorkShop(size_t bufferSize = 5, 
		 	 size_t producerSize = 10, 
			 size_t consumerSize = 15);
	~WorkShop();

	void startWork();
private:
	size_t bufferSize_;
	Buffer buffer_;

	size_t producerSize_;
	size_t consumerSize_;
	std::vector<Producer *> producers_;
	std::vector<Consumer *> consumers_;
};
}
#endif  /*WORKSHOP_H_*/


