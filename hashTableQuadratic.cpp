#include "hashTableQuadratic.h"

hashTableQuadratic::hashTableQuadratic()
{
	quadraticTable = nullptr;
	q_tableSize = 0;
}

hashTableQuadratic::hashTableQuadratic(int tableSize)
{
	q_tableSize= tableSize;
	quadraticTable= new int[q_tableSize];
	for(int i=0; i < q_tableSize; i++)
	{
		quadraticTable[i] = -1;
	}
}

hashTableQuadratic::~hashTableQuadratic()
{
	delete [] quadraticTable;
}

int hashTableQuadratic::hashFunc(int x, int round)
{
	int j= round;
	if(j > 0)
	{
		return(((x % q_tableSize)+ (j^2)) % q_tableSize);
	}
	else
	{
		return(x % q_tableSize);
	}
}

void hashTableQuadratic::insert(int x)
{
	int index = 0;
	int j=0;
	while(j < 25)
	{
		index= hashFunc(x, j);
		if(quadraticTable[index] == -1)
		{
			quadraticTable[index] = x;
		}
		else
		{
			j++;
		}
	}
}

bool hashTableQuadratic::search(int x)
{
	for(int i=0;i <25; i++)
	{
		if(quadraticTable[hashFunc(x, i)] == x)
		{
			return true;
		}
	}
	return false;
}
