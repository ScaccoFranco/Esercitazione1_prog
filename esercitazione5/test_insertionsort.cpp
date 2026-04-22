#include <iostream> // per cout
#include "sort.hpp"
#include "randfiller.hpp"

int main() {
    unsigned int N_TEST = 100; // numero di test
    int MAX_LEN = 100; // massima lunghezzza dei vettori che genero casualmente
    randfiller rf;
    sort s;

    for (unsigned int i = 0; i < N_TEST; i++) {
        unsigned int len = rf.rand_int(0, MAX_LEN);

        std::vector<int> vi;
        vi.resize(len);
        rf.fill(vi, -500, 500); 

        s.insertion(vi);
        if (!s.is_sorted(vi)) {
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> vs = {"ciao", "Ciao", "Ciao a tutti", "Ciaooooooo", "cIAO", "CIAO A TUTTIIIIII"};
    s.insertion(vs);
    s.print(vs);
    if (!s.is_sorted(vs)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
