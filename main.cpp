#include <iostream>
#include <vector>
#include <string>

#include "sorting.h"
#include "utils.h"
#include "timer.h"

int main()
{
	Timer t;
  
  t.start();
  std::vector<int> v;
	utilities::vector_fillRandom(v, 0, 99999999, 50000);
  t.stop("Resize took: ");

  t.start();
  sorting::sort_quick(v, 0, v.size()-1);
  t.stop("radixsort: ");

  std::cout << utilities::vector_checksorted(v) ? "sorted! " : "not sorted!";
}
