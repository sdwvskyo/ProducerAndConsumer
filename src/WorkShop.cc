#include "WorkShop.h"
#include "Producer.h"
#include "Consumer.h"

using namespace std;

WorkShop::WorkShop(size_t bufferSize,
				   size_t producerSize,
				   size_t consumerSize)
	: bufferSize_(bufferSize),
	  buffer_(bufferSize_),
	  producerSize_(producerSize),
	  consumerSize_(consumerSize),
	  producers_(producerSize_, NULL),
	  consumers_(consumerSize_, NULL)
{
	//创建线程
	for(vector<Producer *>::iterator it = producers_.begin();
		it != producers_.end();
		++it)
	{
		*it = new Producer(buffer_);
	}
	for(vector<Consumer *>::iterator it = consumers_.begin();
		it != consumers_.end();
		++it)
	{
		*it = new Consumer(buffer_);
	}
}
WorkShop::~WorkShop()
{
	for(vector<Producer *>::iterator it = producers_.begin();
		it != producers_.end();
		++it)
	{
		delete *it;
	}
	for(vector<Consumer *>::iterator it = consumers_.begin();
		it != consumers_.end();
		++it)
	{
		delete *it;
	}
}

void WorkShop::startWork()
{	
	for(vector<Producer *>::iterator it = producers_.begin();
		it != producers_.end();
		++it)
	{
		(*it)->start();
	}
	for(vector<Consumer *>::iterator it = consumers_.begin();
		it != consumers_.end();
		++it)
	{
		(*it)->start();
	}
	for(vector<Producer *>::iterator it = producers_.begin();
		it != producers_.end();
		++it)
	{
		(*it)->join();
	}
	for(vector<Consumer *>::iterator it = consumers_.begin();
		it != consumers_.end();
		++it)
	{
		(*it)->join();
	}
}
