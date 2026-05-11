#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include <iostream>

int main() {
    unidirected_graph<int> g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);

    // Test neighbors
    std::cout << "funzione neighbors funziona?";
    std::set<int> n = g1.neighbors(2);
    if (n.count(1) && n.count(3)) 
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


    // Test numerazione
    std::cout << "La funzione edge_at funziona?" ;
    unidirected_edge<int> e(1, 2);
    if (g1.edge_at(g1.edge_number(e)) == e)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


    // Test differenza
    std::cout << "Controllo semplice per sottrazione:" << std::endl;
    unidirected_graph<int> g2;
    g2.add_edge(1, 2);
    unidirected_graph<int> diff = g1 - g2;
    if (diff.all_edges().size() == 1)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


    // Test: Un arco deve essere uguale a se stesso anche se inserito al contrario
    unidirected_edge<int> e1(10, 20);
    unidirected_edge<int> e2(20, 10);

    if (e1 == e2) {
        std::cout << "Test Arco Simmetrico ok" << std::endl;
    }
    if (!(e1 < e2) && !(e2 < e1)) {
        std::cout << "Test Arco Ordinamento ok (e1 e e2 sono equivalenti)" << std::endl;
    }

    unidirected_graph<int> GA, GB;
    // GA ha 1-2, 2-3, 3-4
    GA.add_edge(1, 2);
    GA.add_edge(2, 3);
    GA.add_edge(3, 4);

    // GB ha 2-3, 5-6
    GB.add_edge(2, 3);
    GB.add_edge(5, 6);

    diff = GA - GB;

    // Il risultato deve avere solo 1-2 e 3-4 (perché 2-3 era in comune)
    if (diff.all_edges().size() == 2) {
        std::cout << "Test operator- (dimensione): ok" << std::endl;
    }

    // Verifica che un nodo di GB che non era in GA non sia finito nel risultato
    if (diff.neighbors(5).empty()) {
        std::cout << "Test operator- (isolamento): ok" << std::endl;
    }


    // TEST SULLE STRINGHE
    unidirected_graph<std::string> gs;
    gs.add_edge("Torino", "Milano");
    gs.add_edge("Milano", "Roma");

    if (gs.all_nodes().size() == 3) {
        std::cout << "Test Template (std::string): ok" << std::endl;
    }

    if (gs.neighbors("Milano").count("Torino")) {
        std::cout << "Test Vicini Stringhe: ok" << std::endl;
    }


    return 0;
}