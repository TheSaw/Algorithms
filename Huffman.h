#ifndef ALGORITHMS_HUFFMAN_H_
#define ALGORITHMS_HUFFMAN_H_

#include <set>
#include <string>
#include <vector>

#include "HuffmanNode.h"

class Huffman
{
public:
    bool encode(const std::string &in, std::string &out);
    bool decode(const std::string &in, std::string &out);

private:
    HuffmanNode* root = nullptr;

    void Build(const std::string &chars);
    void Build(const char *chars, int length);
    bool hasTree() { return root != nullptr; };
    bool compNodes(HuffmanNode *lhs, HuffmanNode *rhs);

};

void Huffman::Build(const char *chars, int length)
{
    std::vector<int> table;
    table.resize(256, 0);
    const char *c = chars;

    for (int i = 0; i < length; ++i)
    {
        unsigned int idx = (unsigned int)*c;
        ++table[idx];
        ++c;
    }

    std::function<bool(HuffmanNode *lhs, HuffmanNode *rhs)> comparator = &Huffman::compNodes;
    std::set<HuffmanNode, comparator> trees;

    for (int i = 0; i < 256; ++i)
    {
        if (table[i] != 0)
        {
            
        }
    }
}

void Huffman::Build(const std::string &chars)
{
    Build(chars.c_str(), chars.size());
}

bool Huffman::encode(const std::string &in, std::string &out)
{
    Build(in);
    return true;
}


#endif ALGORITHMS_HUFFMAN_H_