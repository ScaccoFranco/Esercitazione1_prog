#include <ostream>
#include <algorithm> 
#include "sort.hpp"
#include "timecounter.h"
#include "randfiller.hpp"

int main() {
    randfiller rf;
    sort s;
    timecounter tc;
    std::vector<int> vi;

    std::cout << '\n';

    
    for (int i = 0; i < 30; i++) {
        double secs_selectionsort = 0.0;
        double secs_insertionsort = 0.0;
        double secs_mergesort = 0.0;
        double secs_quicksort = 0.0;
        double secs_stdsort = 0.0;
        double secs_opt_quicksort = 0.0;


        int len = 10 * i;


        for (int j = 0; j < 100; j++) { // per ogni dimensione 100 iterazioni per minimizzare errore

            // SELECTIONSORT    
            vi.resize(len);
            rf.fill(vi, -500, 500);
            tc.tic();
            s.selection(vi);
            secs_selectionsort += tc.toc();

            // SELECTIONSORT    
            vi.resize(len);
            rf.fill(vi, -500, 500);
            tc.tic();
            s.insertion(vi);
            secs_insertionsort += tc.toc();


            // QUICKSORT   
            vi.resize(len);
            rf.fill(vi, -500, 500);
            tc.tic();
            s.quicksort(vi, 0, len-1);
            secs_quicksort += tc.toc();

            // MergeSORT   
            vi.resize(len);
            rf.fill(vi, -500, 500);
            tc.tic();
            s.mergesort(vi, 0, len-1);
            secs_mergesort += tc.toc();

            // std::sort  
            vi.resize(len);
            rf.fill(vi, -500, 500);
            tc.tic();
            std::sort(vi.begin(), vi.end());
            secs_stdsort += tc.toc();

            // opt-quicksort  
            vi.resize(len);
            rf.fill(vi, -500, 500);
            tc.tic();
            s.opt_quicksort(vi);
            secs_opt_quicksort += tc.toc();
        }

        std::cout << len << " | ";
        
        std::cout << " | " << "Selectionsort: " << secs_selectionsort / (double) len << "s";
        std::cout << " | " << "Insertionsort: " << secs_insertionsort / (double) len << "s";

        std::cout << " | " << "Mergesort: " << secs_mergesort / (double) len << "s";
        std::cout << " | " << "Quicksort: " << secs_quicksort / (double) len << "s\n";


        std::cout << " | " << "std::sort " << secs_stdsort / (double) len << "s";
        std::cout << " | " << "opt-qs: " << secs_opt_quicksort / (double) len << "s\n";
    }

}



