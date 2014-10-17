#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_ 

namespace Tiny
{
class NonCopyable 
{	
//将构造函数和析构函数设为protected，是为了作为基类时防止生成此类对象
protected:
	NonCopyable() {  }
	~NonCopyable() {  }

//将拷贝构造函数和赋值构造函数设为私有以防止对象复制
private:
	NonCopyable(const NonCopyable &);
	NonCopyable & operator= (const NonCopyable &);

};
}
#endif  /*NONCOPYABLE_H_*/
