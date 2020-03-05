#include "Executive.h"
#include <iomanip>
Executive::Executive()
{
  doubleTable = new hashTableDouble(1000003);
  quadraticTable = new hashTableQuadratic(1000003);
  for(int i= 0;i < 5 ;i++)
  {
    d_found[i] = 0;
    d_notFound[i] = 0;
    q_found[i] = 0;
    q_notFound[i] = 0;
  }
  for(double m = 0.1; m < 0.6 ; m += 0.1)
  {
    srand(time(NULL));
    doubleInsert(m);
    quadraticInsert(m);
    doubleSearch(m, int(m*10.0 - 1.0));
    quadraticSearch(m, int(m*10.0 - 1.0));
  }
  std::cout<<"\n\n\n";
  std::cout<<std::setw(15)<<"Quadratic Hashing"<<std::setw(15)<<std::endl;
  std::cout<<"-----------------------------------------------------------------------";
  std::cout<<std::endl;
  std::cout<<std::setw(3) << "Input Size" << std::setw(16);
    for(int i=0;i < 5; i++)
    {
      std::cout<< 100000*(i+1)<<"|" << std::setw(10);
    }
    std::cout<< "\n";
    std::cout<<std::setw(3) << "Build(s)" << std::setw(18);
    for(int i=0;i < 5; i++)
    {
      std::cout<< quadraticInsertTimes[i]<<"|" << std::setw(10);
    }
    std::cout<< "\n";
    std::cout<<std::setw(3) << "# of items found" << std::setw(10);
    for(int i=0;i < 5; i++)
    {
      std::cout<< q_found[i]<<"|" << std::setw(10);
    }
    std::cout<< "\n";
    std::cout<<std::setw(3) << "# of items not found" << std::setw(6);
    for(int i=0;i < 5; i++)
    {
      std::cout<< q_notFound[i]<<"|"<< std::setw(10);
    }
    std::cout<< "\n";
    std::cout<<"-----------------------------------------------------------------------\n\n\n";
    std::cout<<std::setw(15)<<"Double Hashing"<<std::setw(15)<<std::endl;
    std::cout<<"-----------------------------------------------------------------------";
    std::cout<<std::endl;
    std::cout<<std::setw(3) << "Input Size" << std::setw(16);
      for(int i=0;i < 5; i++)
      {
        std::cout<< 100000*(i+1)<<"|" << std::setw(10);
      }
      std::cout<< "\n";
      std::cout<<std::setw(3) << "Build(s)" << std::setw(18);
      for(int i=0;i < 5; i++)
      {
        std::cout<< doubleInsertTimes[i]<<"|" << std::setw(10);
      }
      std::cout<< "\n";
      std::cout<<std::setw(3) << "# of items found" << std::setw(10);
      for(int i=0;i < 5; i++)
      {
        std::cout<< d_found[i]<<"|" << std::setw(10);
      }
      std::cout<< "\n";
      std::cout<<std::setw(3) << "# of items not found" << std::setw(6);
      for(int i=0;i < 5; i++)
      {
        std::cout<< d_notFound[i]<<"|"<< std::setw(10);
      }
      std::cout<< "\n";
      std::cout<<"-----------------------------------------------------------------------\n\n\n";

}

Executive::~Executive()
{

}

void Executive::doubleInsert(double m)
{
  clock_t start, finish;
  start = clock();
  for(int i=0; i < int(1000003.0 * m); i++)
  {
    int value= 0;
    value= (rand() % 5000000 + 1);
    doubleTable->insert(value);
  }
  finish = clock();
  double time = double(finish - start)/CLOCKS_PER_SEC;
  doubleInsertTimes[int(m*10.0) - 1] = time;
}

void Executive::quadraticInsert(double m)
{
  clock_t start, finish;
  start = clock();
  for(int i = 0; i < int(1000003.0 * m); i++)
  {
    int value = 0;
    value= (rand() % 5000000 + 1);
    quadraticTable->insert(value);
  }
  finish = clock();
  double time = double(finish - start)/CLOCKS_PER_SEC;
  quadraticInsertTimes[int(m*10.0) - 1] = time;
}

void Executive::doubleSearch(double m, int index)
{
  int array[int(floor(1000003.0 * m))];
  for(int i = 0 ; i < int(1000003.0 * m); i++)
  {
    array[i] = rand() % 5000000 + 1;
  }
  for(int i= 0 ; i < int(1000003.0 * m); i++)
  {
    bool found = false;
    found = doubleTable->search(array[i]);
    if(found == true)
    {
      d_found[index]++;
    }
    else
    {
      d_notFound[index]++;
    }
  }
}

void Executive::quadraticSearch(double m, int index)
{
  int array[int(1000003.0 * m)];
  for(int i = 0 ; i < int(1000003.0 * m); i++)
  {
    array[i] = rand() % 5000000 + 1;
  }
  for(int i= 0 ; i < int(1000003.0 * m); i++)
  {
    bool found = false;
    found = quadraticTable->search(array[i]);
    if(found == true)
    {
      q_found[index]++;
    }
    else
    {
      q_notFound[index]++;
    }
  }
}
