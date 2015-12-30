#ifndef ALGORITHMS_GRAPH_H_
#define ALGORITHMS_GRAPH_H_

#include <list>
#include <set>
#include <vector>

struct edge
{
    edge(int From, int To) : from(From), to(To) {};
    int from;
    int to;
};

struct compareEdge
{
    bool operator()(std::pair<int, edge> left, std::pair<int, edge> right)
    {
        return left.first > right.first;
    }
};

struct comparePair
{
    bool operator()(std::pair<int, int> left, std::pair<int, int> right)
    {
        return left.first > right.first;
    }
};

class graph
{
public:
    std::list<int> DFS(int origin);
    std::list<int> BFS(int origin);
    void setGraph(const std::vector<std::list<int>> &graph);
    void setGraph(const std::vector<std::vector<int>> &graph);
    void toMatrix(const std::vector<std::list<int>> &adj_list);
    void toList(const std::vector<std::vector<int>> &adj_matrix);
    void addEdge(int A, int B, int cost, bool bidirectional = true);
    int Dijkstra(int from, int to);
    int BellmanFord(int from, int to);
    std::list<std::pair<int, int>> Kruskal();
    std::list<edge> Prim();
    void initMatrix(int nrNodes);

    graph();

private:
    std::list<edge> getEdges();
    
    std::vector<std::list<int>> adj_list;
    std::vector<std::vector<int>> adj_matrix;
};

inline void graph::setGraph(const std::vector<std::list<int>>& graph)
{
    adj_list = graph;
}

inline void graph::setGraph(const std::vector<std::vector<int>>& graph)
{
    adj_matrix = graph;
}


#endif ALGORITHMS_GRAPH_H_
