#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "hashTableQuadratic.h"
#include "hashTableDouble.h"


class Executive
{
	private:
		hashTableDouble* doubleTable;
		hashTableQuadratic* quadraticTable;
		double doubleInsertTimes[5];
		double quadraticInsertTimes[5];
		int d_found[5];
		int d_notFound[5];
		int q_found[5];
		int q_notFound[5];
	public:
		Executive();
		~Executive();
		void doubleInsert(double m);
		void quadraticInsert(double m);
		void doubleSearch(double m, int index);
		void quadraticSearch(double m, int index);
};
#endif
