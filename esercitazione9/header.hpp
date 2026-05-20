#pragma once

#include <queue>
#include <stack>
#include <ostream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept> 
#include <limits>

#include <fstream> // per generar .dot files


// VECCHIA ESERCITAZIONE

template<typename T>
class unidirected_edge 
{

private:
    T from_;
    T to_;


public:
    unidirected_edge(T t1, T t2) {
        if (t1 < t2) {
            from_ = t1;
            to_ = t2;
        } else {
            from_ = t2;
            to_ = t1;
        }
    }

    // OUTPUT delle varibaili private
    T from() const {
        return from_;
    }

    T to() const {
        return to_;
    }

    bool operator<(const unidirected_edge& other) const {
        if (from_ != other.from_) return from_ < other.from_;
        return to_ < other.to_;
    }

    bool operator==(const unidirected_edge& other) const {
        if (from_ == other.from() && to_ == other.to()) {
            return true;
        } else {
            return false;
        }
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& other) 
{
    os << '(' << other.from() << ',' << other.to() << ')';

    return os;
}



template<typename T>
class unidirected_graph
{

private:
    // Matrice o mappa di adiacenza
    // in pratica è una mappa di insiemi, ogni insieme sono i nodi di adiacenza
    // serve a trovare i vicini
    std::map<T, std::set<T>> adj_;

    // vettore per memorizzare e numerare gli archi, sennò non ci posso accedere
    std::vector<unidirected_edge<T>> edges_;


public:
    unidirected_graph() = default; // inizializza tutto vuoto (set, vector ecc)

    unidirected_graph(const unidirected_graph& other) : adj_(other.adj_), edges_(other.edges_) {}

    std::set<T> neighbors(T node) const {
        if (adj_.count(node)) return adj_.at(node);
        return {};
    }

    void add_edge(T u, T v) {
        unidirected_edge<T> new_edge(u, v);

        // controllo se esiste o meno
        if (adj_[u].find(v) == adj_[u].end()) {
            adj_[u].insert(v);
            adj_[v].insert(u);
            edges_.push_back(new_edge); // aggiungo alla fine del vettore.
        }
    }

    std::set<unidirected_edge<T>> all_edges() const {
        return std::set<unidirected_edge<T>>(edges_.begin(), edges_.end()); // converto vector in set
    }

    std::set<T> all_nodes() const {
        std::set<T> nodes;

        for (auto it = edges_.begin(); it != edges_.end(); it++) {
            nodes.insert(it->from()); 
            nodes.insert(it->to()); // se uguale non aggiungono
        }
        return nodes;
    }

    int edge_number(unidirected_edge<T> edge) const {
        for (int i = 0; i < edges_.size(); i++) { 
            if (edges_[i] == edge) return i;
        } 

        return -1;
    }

    unidirected_edge<T> edge_at(int index) const {
        if (index < 0 || index >= edges_.size()) throw std::out_of_range("Indice fuori limite");

        return edges_[index];
    }
    
    // differenza tra grafi
    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph G;
        for (const auto& e : this->edges_) { // for alternativo in forma simil python
            // Se l'arco non è presente nell'altro grafo, lo aggiungiamo a G
            bool trovato = false;
            for (const auto& other_e : other.all_edges()) {
                if (e == other_e) {
                    trovato = true;
                    break;
                }
            }
            if (!trovato) G.add_edge(e.from(), e.to());
        }
        return G;
    }

};


// NUOVA ESERCITAZIONE

template<typename T>
class fifo
{
private:
    std::queue<T> q;

public:
    void put(T x) {
        q.push(x); 
    }
    T get() { 
        T x = q.front(); 
        q.pop(); return x; 
    }
    bool empty() { 
        return q.empty(); 
    }
};

template<typename T>
class lifo
{
private:
    std::stack<T> s;
    
public:
    void put(T x) { 
        s.push(x); 
    }
    T get() { 
        T x = s.top(); 
        s.pop(); return x; 
    }
    bool empty() { 
        return s.empty(); 
    }
};

/*
BFS(LA, v, n (stessi di sotto)) {
inizializzo reached[n] a falso
q.enqueue(v) 
while(!q.empty)
u = q.dequeue()
reached[u] = true
foreach(w in LA[u]) {
    if(!reached[w])
        q.enqueue(w)
}
}




DFS(LA lista adiacenza, v nodo iniziale vista, n numero di nodi) USO PILA (STACK)
1. inizializzo un array reached[n] a falso
2. p.push(v) (uso pila?)
while(1p.empty) {
u = p.pop()
if (reached[u]) continue
reached[u] = true
foreach (w in LA[u])
    p.push(w)
}


faccio prima a usare reached cme set a cui aggiungo sempre roba
*/

template<typename T, typename Contenitore>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, T sorgente, Contenitore contenitore)
{
    unidirected_graph<T> albero;  // grafo risultante (l'albero di visita)
    std::set<T> visitati; // nodi già visitati, uso set e non array di booleani, più semplice (ma piu spazio ma vabbe)

    contenitore.put(sorgente);
    visitati.insert(sorgente);

    while (!contenitore.empty())
    {

        T nodo = contenitore.get();    // estrae dalla testa (fifo) o dalla cima (lifo), vista in ampiezza o profondità

        for (const T& vicino : G.neighbors(nodo))
        {
            if (visitati.find(vicino) == visitati.end())  // se non ancora visitato
            {
                visitati.insert(vicino);
                contenitore.put(vicino);
                albero.add_edge(nodo, vicino); // arco dell'albero di visita
            }
        }
    }

    return albero;
}


// uso stessa lgica del dfs iterativo ma uso la ricorsione per i vicini dei vicini ecc

// dentro la funzione
template<typename T>
void ricorsione(const unidirected_graph<T>& G, T nodo, std::set<T>& visitati, unidirected_graph<T>& albero)
{
    // ogni nodo che viene passato alla funzione diventa visitato e si cerca tra tutti i vicini che vengono ricorsivamente passati alla funzione.

    visitati.insert(nodo);
    for (const T& vicino : G.neighbors(nodo))
    {
        if (visitati.find(vicino) == visitati.end())  // se non visitato
        {
            albero.add_edge(nodo, vicino); // arco dell'albero
            ricorsione(G, vicino, visitati, albero); // chiamata ricorsiva
        }
    }
}

// da chiamare
template<typename T>
unidirected_graph<T> recursive_dfs (const unidirected_graph<T>& G, T sorgente)
{
    unidirected_graph<T> albero;
    std::set<T> visitati;
    ricorsione(G, sorgente, visitati, albero);
    return albero;
}


// djkastra seve a trovare il cammino più corto, la mia classe non ha i pesi sugli archi, quindi li faccio tutti = 1
// faccio quindi in modo che stampi output nodo - distanza, non albero
template<typename T>
std::map<T, int> dijkstra(const unidirected_graph<T>& G, T sorgente)
{
    // usando tutti i pesi uguali equivale a BSF e guardare quanti nodi di distanza hanno i nodi dalla sorgente....
    std::map<T, int> dist;
    for (const T& nodo : G.all_nodes())
        dist[nodo] = std::numeric_limits<int>::max();
    dist[sorgente] = 0;

    // set di coppie (distanza, nodo) ordinato automaticamente per distanza
    std::set<std::pair<int, T>> da_visitare;
    da_visitare.insert({0, sorgente});

    while (!da_visitare.empty())
    {
        // il primo elemento è sempre quello con distanza minore
        auto [d, u] = *da_visitare.begin();
        da_visitare.erase(da_visitare.begin());

        for (const T& vicino : G.neighbors(u))
        {
            int nuova_dist = d + 1;

            if (nuova_dist < dist[vicino])
            {
                // rimuovi il vecchio valore e inserisci quello aggiornato
                da_visitare.erase({dist[vicino], vicino});
                dist[vicino] = nuova_dist;
                da_visitare.insert({nuova_dist, vicino});
            }
        }
    }

    return dist;
}


template<typename T>
void to_dot(const unidirected_graph<T>& G, const std::string& filename)
{
    std::ofstream file(filename);
    file << "graph {" << std::endl;
    for (const auto& e : G.all_edges())
        file << "    " << e.from() << " -- " << e.to() << ";" << std::endl;
    file << "}" << std::endl;
}