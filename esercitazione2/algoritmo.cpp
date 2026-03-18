#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	static const int N = 10;
	double arr[N] = {1.1, 0.3, 20.3, 4.3, 234.3, -102.4, 2.3, 0.98, 5.345, 5.432};
	double dmax = arr[0];
	double dmin = arr[0];
	

	int deviazione_std = 0;
        
	for (int i = 0; i < N; i++) {
		deviazione_std += arr[i]*arr[i];
		if (arr[i] > dmax) {
			dmax = arr[i];
		}
		if (arr[i] < dmin) {
			dmin = arr[i];
		}
	}	

	deviazione_std = sqrt(deviazione_std/N);
	cout << "Max:\t" << dmax << "\nMin:\t" << dmin << "\n";
	cout << "Deviazione standard:\t" << deviazione_std << "\n";

	return 0;
}
