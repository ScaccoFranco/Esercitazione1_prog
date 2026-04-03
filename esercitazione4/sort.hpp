#pragma once

#include <vector>
#include <ostream>

class sort {
    private:
        template <typename T>
        void swap(std::vector<T>&vec, unsigned int i, unsigned int j){
            T swp = vec[i];
            vec[i] = vec[j];
            vec[j] = swp;
        }

    public:
        template <typename T>
        void bubble(std::vector<T>& vec){
            if (vec.empty()) return; 

            for (unsigned int i = 0; i < vec.size() - 1; i++) {
                for (int j = i+1; j < vec.size(); j++) {
                    if (vec[i] > vec [j]) {
                        swap(vec, i, j);
                    }
                }
            }
        }

        template <typename T>
        void insertion(std::vector<T>& vec) {
            if (vec.empty()) return; 

            for (unsigned int i = 1; i < vec.size(); i++) {
                T key = vec[i];
                int j = i - 1;
                while(j >= 0 && vec[j] > key) {
                    vec[j+1] = vec[j];
                    j = j - 1;
                }
                vec[j+1] = key;
            }
        }

        template <typename T>
        void selection(std::vector<T>& vec) {
            if (vec.empty()) return; 

            for (unsigned int i = 0; i < vec.size()-1; i++) {
                unsigned int min = i;
                for (int j = i+1; j < vec.size(); j++) {
                    if (vec[j] < vec[min]) {
                        min = j;
                    }
                }
                swap(vec, i, min);
            }
        }

        template <typename T>
        bool is_sorted(std::vector<T>& vec) {
            if (vec.empty()) {
                return true;
            }

            for (int i = 0; i < vec.size()-1; i++) {
                if (vec[i] > vec[i+1]) {
                    return false;
                }
            }
            return true;
        }

        template <typename T>
        void print(std::vector<T>& vec) {
            
            for (int i = 0; i < vec.size(); i++) {
                std::cout << vec[i] << '\n';
            }
        }
};
