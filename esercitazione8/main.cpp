#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include <iostream>
#include <stdexcept>

int main() {

    // Test unidirected_edge 

    // Il costruttore deve sempre mettere il nodo minore in from()
    unidirected_edge<int> e1(10, 20);
    unidirected_edge<int> e2(20, 10); // inserito al contrario
    std::cout << "Costruttore (from < to): ";
    if (e1.from() == 10 && e1.to() == 20)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // Un arco inserito al contrario deve essere uguale all'originale
    std::cout << "operator== (simmetria): ";
    if (e1 == e2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // Due archi uguali non devono ordinarsi l'uno prima dell'altro
    std::cout << "operator< (archi equivalenti): ";
    if (!(e1 < e2) && !(e2 < e1))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // Archi diversi con stesso from: si ordina per to
    unidirected_edge<int> e3(1, 3);
    unidirected_edge<int> e4(1, 4);
    std::cout << "operator< (stesso from, to diverso): ";
    if (e3 < e4 && !(e4 < e3))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // Stampa di un arco con operator<<
    std::cout << "operator<< (atteso '(1,3)'): " << e3 << std::endl;



    //  Test unidirected_graph - base 

    unidirected_graph<int> g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);

    std::cout << "neighbors (nodo interno): ";
    std::set<int> n = g1.neighbors(2);
    if (n.count(1) && n.count(3))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "neighbors (nodo assente): ";
    if (g1.neighbors(99).empty())
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "all_nodes (3 nodi): ";
    if (g1.all_nodes().size() == 3)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "all_edges (2 archi): ";
    if (g1.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;



    //  Test archi duplicati 

    unidirected_graph<int> g_dup;
    g_dup.add_edge(1, 2);
    g_dup.add_edge(2, 1); // stesso arco al contrario
    g_dup.add_edge(1, 2); // stesso arco di nuovo
    std::cout << "add_edge (no duplicati): ";
    if (g_dup.all_edges().size() == 1)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;



    //  Test edge_number e edge_at 

    unidirected_edge<int> e(1, 2);
    int idx = g1.edge_number(e);
    std::cout << "edge_number (arco esistente): ";
    if (idx >= 0)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "edge_at (recupero arco): ";
    if (g1.edge_at(idx) == e)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "edge_number (arco assente -> -1): ";
    unidirected_edge<int> e_missing(7, 8);
    if (g1.edge_number(e_missing) == -1)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // edge_at fuori range deve lanciare un'eccezione
    std::cout << "edge_at (indice fuori range): ";
    bool eccezione = false;
    try {
        g1.edge_at(999);
    } catch (const std::out_of_range&) {
        eccezione = true;
    }
    if (eccezione)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;



    //  Test operator- 

    unidirected_graph<int> GA, GB;
    GA.add_edge(1, 2);
    GA.add_edge(2, 3);
    GA.add_edge(3, 4);
    GB.add_edge(2, 3); // in comune con GA
    GB.add_edge(5, 6); // non in GA

    unidirected_graph<int> diff = GA - GB;

    // devono rimanere solo 1-2 e 3-4
    std::cout << "operator- (dimensione risultato): ";
    if (diff.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // 5-6 era solo in GB, non deve comparire nel risultato
    std::cout << "operator- (nodo di GB non compare): ";
    if (diff.neighbors(5).empty())
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // GA - GA deve dare un grafo vuoto
    std::cout << "operator- (con se stesso -> vuoto): ";
    if ((GA - GA).all_edges().empty())
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;



    //  Test costruttore di copia 

    unidirected_graph<int> g2(g1); // copia di g1
    std::cout << "Costruttore di copia (stessi archi): ";
    if (g2.all_edges() == g1.all_edges())
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    // modificare g2 non deve cambiare g1
    g2.add_edge(5, 6);
    std::cout << "Costruttore di copia (indipendenza): ";
    if (g1.all_edges().size() == 2)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;


        
    //  Test template con std::string 

    unidirected_graph<std::string> gs;
    gs.add_edge("Torino", "Milano");
    gs.add_edge("Milano", "Roma");

    std::cout << "Template std::string (3 nodi): ";
    if (gs.all_nodes().size() == 3)
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    std::cout << "Template std::string (neighbors): ";
    if (gs.neighbors("Milano").count("Torino") && gs.neighbors("Milano").count("Roma"))
        std::cout << "ok" << std::endl;
    else
        std::cout << "nop" << std::endl;

    return 0;
}