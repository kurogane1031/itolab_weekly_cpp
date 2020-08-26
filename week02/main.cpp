#include <iostream>
#include "include/timer.h"

int main()
{
  Timer timer;
  int count = 0;
  for (int i = 0; i < 100000; i++)
    {
      timer.iteration();
      count++;
    }
  std::cout << "Itolab." << count << "\n";
}
