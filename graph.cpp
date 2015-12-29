#include <set>
#include <stack>
#include <queue>

#include "graph.h"

std::list<std::pair<int, int>> graph::Kruskal()
{
    std::set < std::pair<int, std::pair<int, int>>> edges;
    getEdges(edges);

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
    int cnt_edge = 0;
    std::list<edge> MST;
    std::vector<bool> visited(adj_matrix.size(), false);
    std::priority_queue<std::pair<int, edge>, std::vector<std::pair<int, edge>>, compareEdge> Q;

    Q.push({ 0, edge(0, 0) });

    while (!Q.empty())
    {
        std::pair<int, edge> cheapest = Q.top();
        Q.pop();        

        if (!visited[cheapest.second.to])
        {
            visited[cheapest.second.to] = true;
            MST.push_back(cheapest.second);
            ++cnt_edge;

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

void graph::getEdges(std::set<std::pair<int, std::pair<int, int>>>& edges)
{
    if (!adj_list.empty())
    {
        for (int i = 0; i < adj_list.size(); ++i)
        {
            for (auto connection : adj_list[i])
            {
                edges.insert({ adj_matrix[i][connection],
                    std::make_pair(std::min(i, connection), std::max(i, connection)) });
            }
        }
    }
}

void graph::addEdge(int A, int B, int cost)
{
    if (!adj_list.empty())
    {
        adj_list[A].push_back(B);
        adj_list[A].sort();
    }

    if (!adj_matrix.empty())
    {
        adj_matrix[A][B] = cost;
        adj_matrix[B][A] = cost;
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
    if (!adj_list.empty())
    {
        toMatrix(adj_list);
    }

    // minimum distance from source to each other node
    std::vector<int> dist(adj_matrix.size(), INT_MAX);
    dist[from] = 0;

    // vertices which are not yet finished processing
    std::set<std::pair<int, int>> vertices;
    vertices.insert({ from, 0 });

    while (!vertices.empty())
    {
        int current = vertices.begin()->first;
        if (current == to)
        {
            return vertices.begin()->second;
        }

        vertices.erase(vertices.begin());

        for (int i = 0; i < adj_matrix[current].size(); ++i)
        {
            int edge = adj_matrix[current][i];
            if (edge != INT_MAX && dist[current] + edge < dist[edge])
            {
                vertices.erase({ i, dist[edge] });
                dist[edge] = dist[current] + edge;
                vertices.insert({ i, dist[edge] });
            }
        }
    }

    return INT_MAX;
}