#ifndef ALGORITHMS_HUFFMANNODE_H_
#define ALGORITHMS_HUFFMANNODE_H_

#include "HuffmanNode.h"

class HuffmanNode {
public:
    HuffmanNode *m_left = nullptr;
    HuffmanNode *m_right = nullptr;
    char m_data;
    int m_freq = 0;
    bool isLeaf = false;
};


#endif ALGORITHMS_HUFFMANNODE_H_
