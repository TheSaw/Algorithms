#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "BinaryTree.h"
#include "dynamicP.h"
#include "graph.h"
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

    std::vector<std::list<int>> adj_list = { {}, {2,7,8}, {1,3,6}, {2,4,5}, {3}, {3}, {2}, {1}, {1,9,12}, {8,10,11}, {9}, {9}, {8} };

    graph G;
    G.initMatrix(12);
    G.addEdge(0, 1, 2);
    G.addEdge(0, 6, 5);
    G.addEdge(0, 7, 6);
    G.addEdge(1, 2, 1);
    G.addEdge(1, 5, 3);
    G.addEdge(2, 3, 1);
    G.addEdge(2, 4, 7);
    //G.addEdge(4, 9, 1);
    G.addEdge(5, 8, 2);
    G.addEdge(7, 8, 3);
    G.addEdge(7, 11, 4);
    G.addEdge(8, 9, 4);
    G.addEdge(8, 10, 5);

    std::cout << "Distance:\t" << G.BellmanFord(0, 10) << std::endl;

//    system("PAUSE");
}
