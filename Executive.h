#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include "hashTableQuadratic.h"
#include "hashTableDouble.h"


class Executive
{
	private:
		hashTableDouble *doubleTable;
		hashTableQuadratic *quadraticTable;
	public:
		Executive(std::string fileName);
		~Executive();
		void run();
};
#endif
