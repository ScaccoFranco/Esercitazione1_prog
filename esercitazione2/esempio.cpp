#include <iostream>

int main() {
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};

	std::cout << "ad:\n";
	for (int i = 0; i < 4; i++) {
		std::cout << &ad[i] << "\n";
	}

	std::cout << "af\n";
	for (int j = 0; j < 8; j++) {
		std::cout << &af[j] << "\n";
	}

	std::cout << "ai\n";
	for (int i = 0; i < 3; i++) {
		std::cout << &ai[i] << "\n";
	}


	std::cout << &ad[0] << "\n" << &ad[1] << "\n";

	int x = 1;
	float y = 1.1;

	std::cout << "x: " << &x <<"\ny: " << &y;

	(&y)[1] = 0;

	
        std::cout << "x: " << &x <<"\ny: " << &y;

	



	std::cout << x << "\n";

	return 0;
}
