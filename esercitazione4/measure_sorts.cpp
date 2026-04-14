#include <ostream>
#include <algorithm> 
#include "sort.hpp"
#include "timecounter.h"
#include "randfiller.hpp"

int main() {
    randfiller rf;
    sort s;
    timecounter tc;


    // BUBBLESORT
    std::cout << "Bubblesort:\n";
    int len = 2;
    while (len <= 8192) {
        tc.tic();

        std::vector<int> vi;
        vi.resize(len);
        rf.fill(vi, -500, 500);

        s.bubble(vi);
        double secs = tc.toc();

        std::cout << len << " - " << secs << "s\n";

        len = len * 2;
    }


    // INSERTION SORT
    std::cout << "\nInsertion Sort:\n";
    len = 2;
    while (len <= 8192) {
        tc.tic();

        std::vector<int> vi;
        vi.resize(len);
        rf.fill(vi, -500, 500);

        s.insertion(vi);
        double secs = tc.toc();

        std::cout << len << " - " << secs << "s\n";

        len = len * 2;
    }


    // SELECTIONSORT
    std::cout << "\nSelection Sort:\n";
    len = 2;
    while (len <= 8192) {
        tc.tic();

        std::vector<int> vi;
        vi.resize(len);
        rf.fill(vi, -500, 500);

        s.selection(vi);
        double secs = tc.toc();

        std::cout << len << " - " << secs << "s\n";

        len = len * 2;
    }



    // std::sort
    std::cout << "\nstd::sort:\n";
    len = 2;
    while (len <= 8192) {
        tc.tic();

        std::vector<int> vi;
        vi.resize(len);
        rf.fill(vi, -500, 500);

        std::sort( vi.begin(), vi.end() );
        double secs = tc.toc();

        std::cout << len << " - " << secs << "s\n";

        len = len * 2;
    }
}
