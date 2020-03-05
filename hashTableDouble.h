#ifndef HASHTABLEDOUBLE_H
#define HASHTABLEDOUBLE_H

#include <iostream>
#include <string>

class hashTableDouble
{
	private:
		int* doubleTable;
		int d_tableSize;
	public:
		hashTableDouble();
		hashTableDouble(int d_tableSize);
		~hashTableDouble();
		int hashFunc(int x);
		int hashFunc2(int x);
		void insert(int x);
		bool search(int x);
};
#endif
