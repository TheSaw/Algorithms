#include <iostream>
#include <vector>
#include <string>

#include "select.h"
#include "sort.h"
#include "utils.h"
#include "timer.h"
#include "list.h"

int main()
{
	Timer t;
  
  std::vector<int> v;
	utilities::vector_fillRandom(v, 0, 9999, 5);

  t.start();
  list<int> l;
  for (int i = 0; i < 1000000; ++i) {
      l.push_back(i);
  }
  
  t.stop("added elements \n");

  l.clear();
  std::cout << l.size() << std::endl;

  int i = l.search('b');
}
