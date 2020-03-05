#include "hashTableQuadratic.h"

hashTableQuadratic::hashTableQuadratic()
{
	quadraticTable = nullptr;
	q_inputSize = 0;
	q_tableSize = 0;
}

hashTableQuadratic::hashTableQuadratic(int inputSize, int tableSize)
{
	q_inputSize= inputSize;
	q_tableSize= tableSize;
	quadraticTable= new int[q_tableSize];
}

hashTableQuadratic::~hashTableQuadratic()
{
	delete [] quadraticTable;
}

int hashTableDouble::hashFunc(int x)
{
	return (x % q_tableSize);
}
