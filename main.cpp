#include <iostream>
#include <vector>
#include <string>

#include "BinaryTree.h"
#include "select.h"
#include "sort.h"
#include "utils.h"
#include "timer.h"
#include "list.h"
#include "hashtable.h"

int main()
{
    Timer t;

    std::vector<int> v = { 10, 11, 7, 3, 9, 6, 12, 5, 4 };

    
    binaryTree<int> tree;

    for (auto i : v) {
        tree.insert(i);
    }

    std::cout << tree.minimum()->data << std::endl;

  
}
