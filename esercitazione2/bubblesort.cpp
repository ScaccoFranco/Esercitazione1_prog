#include <iostream>


// bubblesort per interi


void swp (int *a, int *b) { // swap di due interi con i puntatori
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubblesort(int *arr, int length) { // prendo primo valore dell'array e poi la lunghezza
	int swap = 1;
	while (swap) {
		swap = 0;
		for (int i = 0; i < length - 1; i++){
			if (arr[i] > arr[i+1]) {
				swp(&arr[i], &arr[i+1]);
				swap = 1;
			}
		}
	}
	
}

int main() {
	const int N = 10;
	int arr[N] = {1,-3, 3, 4, 5, 6, 7, 8, 9, 0};
	bubblesort(arr, N);
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << "\n";
	}
	
	return 0;

}	
	

