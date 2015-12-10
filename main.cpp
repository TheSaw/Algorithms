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

    Huffman huff;
    std::string out;

    std::vector<char> v;
    utilities::vector_fillRandom(v, 65, 90, 1000000);
    std::string in(v.begin(), v.end());

    huff.encode(in, out);
    
    std::cout << out.size();
    std::cout << "   --  " << out.size() / 8 << " bytes" << std::endl;
  
    //system("PAUSE");
}
