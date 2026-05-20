#include <iostream>
#include "header.hpp"

int main()
{
    // grafo test
    unidirected_graph<int> G;

    // 
    G.add_edge(1,2);
    G.add_edge(1,3);
    G.add_edge(1,4);
    G.add_edge(1,6);
    G.add_edge(2,4);
    G.add_edge(2,5);
    G.add_edge(2,7);
    G.add_edge(3,6);
    G.add_edge(4,6);
    G.add_edge(4,7);
    G.add_edge(5,7);
    G.add_edge(6,7);
    G.add_edge(6,8);
    G.add_edge(7,9);
    G.add_edge(8,9);


    // BFS
    std::cout << " BFS " << std::endl;
    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q);
    for (const auto& e : bfsG.all_edges())
        std::cout << e << std::endl;

    // DFS iterativa
    std::cout << " DFS iterativa " << std::endl;
    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
    for (const auto& e : dfsG.all_edges())
        std::cout << e << std::endl;

    // DFS ricorsiva
    std::cout << " DFS ricorsiva " << std::endl;
    auto rdfsG = recursive_dfs(G, 1);
    for (const auto& e : rdfsG.all_edges())
        std::cout << e << std::endl;

    // Dijkstra
    std::cout << " Dijkstra " << std::endl;
    auto dist = dijkstra(G, 1);
    for (const auto& [nodo, d] : dist)
        std::cout << "Distanza da 1 a " << nodo << " = " << d << std::endl;


    to_dot(bfsG, "bfs.dot");
    to_dot(dfsG, "dfs.dot");
    to_dot(rdfsG, "rdfs.dot");
    to_dot(G, "iniziale.dot");

    return 0;
}