#ifndef HASHTABLEQUADRATIC_H
#define HASHTABLEQUADRATIC_H

#include <iostream>
#include <string>
#include <math.h>

class hashTableQuadratic
{
	private:
		int* quadraticTable;
		int q_inputSize;
		int q_tableSize;
	public:
		hashTableQuadratic();
		hashTableQuadratic(int q_inputSize, int q_tableSize);
		~hashTableQuadratic();
		
};
#endif
