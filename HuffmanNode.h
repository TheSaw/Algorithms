#ifndef ALGORITHMS_HUFFMANNODE_H_
#define ALGORITHMS_HUFFMANNODE_H_

#include "HuffmanNode.h"

class HuffmanNode {
public:
    HuffmanNode(bool Leaf);

    HuffmanNode *m_left = nullptr;
    HuffmanNode *m_right = nullptr;
    char m_data;
    int m_freq = 0;
    bool isLeaf = false;

    void insert(HuffmanNode *newNode);
};

HuffmanNode::HuffmanNode(bool Leaf)
    :isLeaf(Leaf)
{

}

void HuffmanNode::insert(HuffmanNode *node)
{
    if (isLeaf && node->isLeaf)
    {
        HuffmanNode *right = new HuffmanNode(node);

    }
}


#endif ALGORITHMS_HUFFMANNODE_H_
