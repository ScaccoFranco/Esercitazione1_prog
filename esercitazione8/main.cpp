#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include <iostream>
#include <stdexcept>

int main() {

    // test arco base
    unidirected_edge<int> e1(10, 20);
    unidirected_edge<int> e2(20, 10); // al contrario, deve essere uguale
    std::cout << "from() e to() ok? ";
    if (e1.from() == 10 && e1.to() == 20)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "operator== funziona? ";
    if (e1 == e2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "operator< (equivalenti): ";
    if (!(e1 < e2) && !(e2 < e1))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // controllo che ordini bene quando il from e' uguale
    unidirected_edge<int> e3(1, 3);
    unidirected_edge<int> e4(1, 4);
    std::cout << "operator< (from uguale): ";
    if (e3 < e4)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "operator<<: " << e3 << std::endl; // atteso (1,3)


    // test grafo
    unidirected_graph<int> g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);

    std::cout << "neighbors funziona? ";
    std::set<int> n = g1.neighbors(2);
    if (n.count(1) && n.count(3))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "all_nodes: ";
    if (g1.all_nodes().size() == 3)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "all_edges: ";
    if (g1.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // aggiungo lo stesso arco due volte, non deve duplicarsi
    g1.add_edge(1, 2);
    std::cout << "no duplicati: ";
    if (g1.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


    // test edge_number e edge_at
    unidirected_edge<int> e(1, 2);
    int idx = g1.edge_number(e);
    std::cout << "edge_number: ";
    if (idx >= 0)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "edge_at: ";
    if (g1.edge_at(idx) == e)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // edge_at con indice sbagliato deve tirare eccezione
    std::cout << "edge_at fuori range: ";
    try {
        g1.edge_at(999);
        std::cout << "nop" << std::endl; // non dovrebbe arrivare qui
    } catch (const std::out_of_range&) {
        std::cout << "ok" << std::endl;
    }


    // test operator-
    unidirected_graph<int> GA, GB;
    GA.add_edge(1, 2);
    GA.add_edge(2, 3);
    GA.add_edge(3, 4);
    GB.add_edge(2, 3);
    GB.add_edge(5, 6); // questo non e' in GA, non deve finire nel risultato

    unidirected_graph<int> diff = GA - GB;
    std::cout << "operator- (size): ";
    if (diff.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "operator- (nodo 5 non presente): ";
    if (diff.neighbors(5).empty())
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


    // test costruttore di copia
    unidirected_graph<int> g2(g1);
    g2.add_edge(10, 20); // modifico g2, g1 non deve cambiare
    std::cout << "copy constructor: ";
    if (g1.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


    // test con stringhe per verificare il template
    unidirected_graph<std::string> gs;
    gs.add_edge("Torino", "Milano");
    gs.add_edge("Milano", "Roma");

    std::cout << "template std::string: ";
    if (gs.all_nodes().size() == 3 && gs.neighbors("Milano").count("Torino"))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    return 0;
}