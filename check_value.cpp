#include <iostream>

int check_value(int& attempts_count, int target_value) {

	int current_value{0};
//	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;
		if (std::cin.fail()) {
			std::cout << "Bad value!" << std::endl;
			return -1;
		}

		attempts_count++;

		if (current_value < target_value) {
			std::cout << "less than desired" << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than desired" << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl << std::endl;
			break;
		}

	} while(true);

	return 0;
}