#ifndef HASHTABLEDOUBLE_H
#define HASHTABLEDOUBLE_H

#include <iostream>
#include <string>

class hashTableDouble
{
	private:
		int* doubleHashingTable;
		int d_inputSize;
		int d_tableSize;
	public:
		hashTableDouble();
		hashTableDouble(int d_inputSize, int d_tableSize);
		~hashTableDouble();
		
};
#endif
