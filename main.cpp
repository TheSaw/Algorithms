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
#include "Huffman.h"

int main()
{
    Timer t;

    std::vector<int> v;
    utilities::vector_fillRandom(v, -100, 100, 10);

    maxValueSequence(v);

}
