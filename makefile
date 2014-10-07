./a.out:./src/main.cc ./src/Condition.cc ./src/MutexLock.cc ./src/Thread.cc ./src/Buffer.cc ./src/Producer.cc ./src/Consumer.cc ./src/WorkShop.cc
	g++ $^ -o $@ -std=c++11
