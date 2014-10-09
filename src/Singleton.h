#ifndef SINGLETON_H_
#define SINGLETON_H_ 

#include "MutexLock.h"

//单例模式：确保一个类只有一个实例，且提供全局访问
class Singleton
{
public:
	static Singleton * getInstance();

private:
	Singleton();
	Singleton(const Singleton &);
	void operator=(const Singleton &);

	static Singleton *pInstance_;
	static MutexLock mutex_;
			
};

Singleton *Singleton::pInstance = NULL;
MutexLock Singleton::mutex_;


//Double Check Locking Partern
Singleton *Singleton::getInstance()
{
	if(pInstance_ == NULL) {
		mutex_.lock();
		if (pInstance_ == NULL)
			pInstance_ = new Singleton;
		mutex_.unlock();
	}
	return pInstance_;
}

#endif  /*SINGLETON_H_*/
