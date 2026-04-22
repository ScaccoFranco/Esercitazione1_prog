#include <ostream>
#include <algorithm> 
#include "sort.hpp"
#include "timecounter.h"
#include "randfiller.hpp"

int main() {
    randfiller rf;
    sort s;
    timecounter tc;

    std::cout << '\n';

    int len = 2;
    while (len <= 8192) {

        std::cout << len << " | ";
        std::vector<int> vi;
        double secs;

        // BUBBLESORT
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        s.bubble(vi);
        secs = tc.toc();
        std::cout << "Bubblesort: " << secs << "s";


        // INSERTIONSORT
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        s.insertion(vi);
        secs = tc.toc();
        std::cout << " | " << "Insertionsort: " << secs << "s";


        // SELECTIONSORT    
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        s.selection(vi);
        secs = tc.toc();
        std::cout << " | " << "Selectionsort: " << secs << "s";


        // MERGESORT
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        s.mergesort(vi, 0, len-1);
        secs = tc.toc();
        std::cout << " | " << "Mergesort: " << secs << "s";


        // QUICKSORT
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        s.mergesort(vi, 0, len-1);
        secs = tc.toc();
        std::cout << " | " << "Quicksort: " << secs << "s";


        // STD::SORT
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        std::sort( vi.begin(), vi.end() );
        secs = tc.toc();
        std::cout << " | " << "std::sort " << secs << "s\n";




        len = len * 2;
    }

}
