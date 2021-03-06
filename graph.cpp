#include <set>
#include <stack>
#include <queue>

#include "graph.h"

std::list<std::pair<int, int>> graph::Kruskal()
{
    std::set < std::pair<int, std::pair<int, int>>> edges;

    std::list<std::set<int>> forest;

    for (int vertex = 0; vertex < adj_list.size(); ++vertex)
    {
        if (!adj_list[vertex].empty())
        {
            std::set<int> V = { vertex };
            forest.push_back(V);
        }
    }

    for (auto edge : edges)
    {
        
    }


    return {};
}

std::list<edge> graph::Prim()
{
    const int start_node = 0;
    std::list<edge> MST;
    std::vector<bool> visited(adj_matrix.size(), false);
    std::priority_queue<std::pair<int, edge>, std::vector<std::pair<int, edge>>, compareEdge> Q;

    Q.push({ start_node, edge(0, 0) });

    while (!Q.empty())
    {
        std::pair<int, edge> cheapest = Q.top();
        Q.pop();        

        if (!visited[cheapest.second.to])
        {
            visited[cheapest.second.to] = true;
            MST.push_back(cheapest.second);

            for (int i = 0; i < adj_matrix[cheapest.second.to].size(); ++i)
            {
                if (!visited[i] && adj_matrix[i][cheapest.second.to] < INT_MAX)
                {
                    Q.push({ adj_matrix[cheapest.second.to][i], edge(cheapest.second.to, i) });
                }
            }
        }
    }

    return MST;
}

void graph::initMatrix(int nrNodes)
{
    adj_matrix.clear();
    adj_matrix.resize(nrNodes);

    for (int i = 0; i < nrNodes; ++i)
    {
        adj_matrix[i].resize(nrNodes, INT_MAX);
    }
}

graph::graph()
{
}

std::list<edge> graph::getEdges()
{
    std::list<edge> edges;

    for (int i = 0; i < adj_matrix.size(); ++i)
    {
        for (int j = 0; j < adj_matrix[i].size(); ++j)
        {
            if (adj_matrix[i][j] != INT_MAX)
            {
                edges.push_back(edge(i, j));
            }
        }
    }

    return edges;
}

void graph::addEdge(int A, int B, int cost, bool bidirectional)
{
    if (!adj_list.empty())
    {
        adj_list[A].push_back(B);
        adj_list[A].sort();
    }

    if (!adj_matrix.empty())
    {
        adj_matrix[A][B] = cost;
        if (bidirectional)
        {
            adj_matrix[B][A] = cost;
        }        
    }
}

void graph::toMatrix(const std::vector<std::list<int>>& adj_list)
{
    adj_matrix.clear();
    adj_matrix.resize(adj_list.size());

    for (int i = 0; i < adj_list.size(); ++i)
    {
        adj_matrix[i].resize(adj_list.size(), INT_MAX);

        for (int j : adj_list[i])
        {
            adj_matrix[i][j] = 1;
        }
    }
}

void graph::toList(const std::vector<std::vector<int>>& adj_matrix)
{

}

std::list<int> graph::DFS(int origin)
{
    std::list<int> trav;
    std::stack<int> S;
    std::vector<int> visited;
    visited.resize(100, 0);
    int current = origin;
    S.push(origin);

    while (!S.empty())
    {
        current = S.top();
        S.pop();

        if (!visited[current])
        {
            visited[current] = 1;
            trav.push_back(current);

            for (auto it = adj_list[current].end(); it != adj_list[current].begin(); )
            {
                --it;
                S.push(*it);
            }
        }

    }

    return trav;
}

std::list<int> graph::BFS(int origin)
{
    std::list<int> trav;
    std::queue<int> Q;
    std::vector<int> visited;
    visited.resize(100, 0);
    int current = origin;
    Q.push(origin);

    while (!Q.empty())
    {
        current = Q.front();
        Q.pop();
        if (!visited[current])
        {
            visited[current] = 1;
            trav.push_back(current);
            for (auto a : adj_list[current])
            {
                Q.push(a);
            }
        }
    }

    return trav;
}



int graph::Dijkstra(int from, int to)
{
    const int size = adj_matrix.size();
    std::vector<bool> visited(size, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comparePair> Q;
    std::vector<int> dist(size, INT_MAX);

    Q.push({ 0, from });
    dist[from] = 0;

    while (!Q.empty())
    {
        std::pair<int, int> cheapest = Q.top();
        Q.pop();

        if (!visited[cheapest.second])
        {
            for (int i = 0; i < size; ++i)
            {
                if (adj_matrix[cheapest.second][i] != INT_MAX)
                {
                    dist[i] = std::min(dist[i], dist[cheapest.second] + adj_matrix[cheapest.second][i]);
                    Q.push({ dist[i], i });
                }
            }

            visited[cheapest.second] = true;
        }        
    }

    return dist[to];
}

int graph::BellmanFord(int from, int to)
{
    std::vector<int> dist(adj_matrix.size(), INT_MAX);
    std::vector<int> prev(adj_matrix.size(), -1);

    dist[from] = 0;

    for (int iter = 0; iter < adj_matrix.size() - 1; ++iter)
    {
        for (int i = 0; i < adj_matrix.size(); ++i)
        {
            for (int j = 0; j < adj_matrix[i].size(); ++j)
            {
                if (adj_matrix[i][j] != INT_MAX)
                {
                    dist[j] = std::min(adj_matrix[i][j] + dist[i], dist[j]);
                }                
            }
        }
    }

    return dist[to];
}
