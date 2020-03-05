#include "hashTableDouble.h"


hashTableDouble::hashTableDouble()
{
	hashTableDouble = nullptr;
	q_inputSize = 0;
	q_tableSize = 0;
}

hashTableDouble::hashTableDouble(int inputSize, int tableSize)
{
	q_inputSize= inputSize;
	q_tableSize= tableSize;
	hashTableDouble= new int[q_tableSize];
}

hashTableDouble::~hashTableDouble()
{
	delete [] hashTableDouble;
}
