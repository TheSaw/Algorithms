#include <iostream>
#include <vector>
#include <string>

#include "BinaryTree.h"
#include "dynamicP.h"
#include "select.h"
#include "sort.h"
#include "utils.h"
#include "timer.h"
#include "list.h"
#include "hashtable.h"

int main()
{
    Timer t;

    t.start();
    std::cout << fib_DP_bottomup(1492);
    t.stop("\nFibonacci ended: ");

    t.start();
    std::cout << fib_DP_memo(1492);
    t.stop("\nFibonacci ended: ");
  
}
