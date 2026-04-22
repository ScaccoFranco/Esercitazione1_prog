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

    int len = 100;
    while (len <= 250) {

        std::cout << len << " | ";
        std::vector<int> vi;
        double secs;


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


        // STD::SORT
        vi.resize(len);
        rf.fill(vi, -500, 500);
        tc.tic();
        std::sort( vi.begin(), vi.end() );
        secs = tc.toc();
        std::cout << " | " << "std::sort " << secs << "s\n";




        len = len + 1;
    }

}



