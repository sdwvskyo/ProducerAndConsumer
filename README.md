ProducerAndConsumer
==========

#运行方式  

$ make
$ ./a.out

#主要功能
用线程池实现实现生产者消费者问题

#运用技术
1. 利用RAII编写了MutexLockGuard，实现了mutex的自动加锁和解锁
2. Thread的封装运用了动态绑定
3. Buffer中的mutex声明为mutable类型，在const成员函数中仍可改变，是mutex的一种标准实践，

