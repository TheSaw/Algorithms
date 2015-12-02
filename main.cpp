#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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

    std::vector<int> v;
    utilities::vector_fillRandom(v, 1, 100, 1000);

    int best = bestCut(v, v.size());
    std::cout << best;
  
    system("PAUSE");
}
