#ifndef ALGORITHMS_HUFFMAN_H_
#define ALGORITHMS_HUFFMAN_H_

#include <queue>
#include <string>
#include <unordered_map>
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
    HuffmanNode * joinNodes(HuffmanNode *lhs, HuffmanNode *rhs);
    void createCodeTables(HuffmanNode *root, std::string &code);

    std::unordered_map<char, std::string> table_encode;
    std::unordered_map<std::string, char> table_decode;
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

    std::function<bool(HuffmanNode *lhs, HuffmanNode *rhs)> comparator = std::bind(&Huffman::compNodes, this, std::placeholders::_1, std::placeholders::_2);
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, std::function<bool(HuffmanNode *lhs, HuffmanNode *rhs)>> forest(comparator);

    for (int i = 0; i < 256; ++i)
    {
        if (table[i] != 0)
        {
            HuffmanNode *node = new HuffmanNode(true);
            node->m_data = (char)i;
            node->m_freq = table[i];
            forest.push(node);
        }
    }

    while (forest.size() > 1)
    {
        HuffmanNode *min1 = forest.top();
        forest.pop();
        HuffmanNode *min2 = forest.top();
        forest.pop();

        forest.push(joinNodes(min1, min2));
    }

    table_encode.clear();
    createCodeTables(forest.top(), std::string());
}

bool Huffman::compNodes(HuffmanNode *lhs, HuffmanNode *rhs)
{
    return lhs->m_freq > rhs->m_freq;
}

void Huffman::createCodeTables(HuffmanNode *root, std::string &code)
{
    if (root->isLeaf)
    {
        table_encode.insert(std::make_pair(root->m_data, code));        
        table_decode.insert(std::make_pair(code, root->m_data));
        return;
    }
    else
    {
        if (root->m_left != nullptr)
        {
            code += '0';
            createCodeTables(root->m_left, code);
            code.pop_back();
        }

        if (root->m_right != nullptr)
        {
            code += '1';
            createCodeTables(root->m_right, code);
            code.pop_back();
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
    for (auto c : in)
    {
        auto got = table_encode.find(c);
        if (got != table_encode.end())
        {
            out += got->second;
        }
    }
    return true;
}

HuffmanNode * Huffman::joinNodes(HuffmanNode *lhs, HuffmanNode *rhs)
{
    HuffmanNode *newnode = new HuffmanNode(false);
    newnode->m_freq = lhs->m_freq + rhs->m_freq;
    newnode->m_left = lhs;
    newnode->m_right = rhs;
    return newnode;
}


#endif ALGORITHMS_HUFFMAN_H_