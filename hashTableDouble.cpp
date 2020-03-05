#include "hashTableDouble.h"


hashTableDouble::hashTableDouble()
{
	doubleTable = nullptr;
	d_tableSize = 0;
}

hashTableDouble::hashTableDouble(int tableSize)
{
	d_tableSize= tableSize;
	doubleTable= new int[d_tableSize];
	for(int i= 0 ; i<d_tableSize; i++)
	{
		doubleTable[i] = -1;
	}
}

hashTableDouble::~hashTableDouble()
{
	delete [] doubleTable;
}

int hashTableDouble::hashFunc(int x)
{
	return (x % d_tableSize);
}

int hashTableDouble::hashFunc2(int x)
{
	return(733 - (x % 733));
}

void hashTableDouble::insert(int x)
{
	int index = 0;
	index= hashFunc(x);
	if(doubleTable[index] != -1)
	{
		int index2 = 0;
		index2= hashFunc2(x);
		int i = 1;
		while(i <= 25)
		{
			int newIndex = 0;
			newIndex= (index + (i * index2)) % d_tableSize;
			if(doubleTable[newIndex] == -1)
			{
				doubleTable[newIndex] = x;
				return;
			}
			i++;
		}
	}
	else
	{
		doubleTable[index] = x;
	}
}

bool hashTableDouble::search(int x)
{
	for(int i= 0;i<25 ;i++)
	{
		if(doubleTable[(hashFunc(x)+(i*(hashFunc2(x)))) % d_tableSize] == x)
		{
			return true;
		}
	}
	return false;
}
