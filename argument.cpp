#include <iostream>
#include <string>

int argument(int argc, char** argv, bool& only_print_table, int& max_value) {

	if (argc > 3) {
		std::cout << "Too many parameters!" << std::endl;
		return -1;
	}

	std::string parametr = argv[1];
	
	if (parametr == "-table") {
		if (argc > 2) {
			std::cout << "Too many parameters!" << std::endl;
			return -1;
		}
		only_print_table = true;
		return 0;
	}
	if (parametr == "-max") {
		if (argc <= 2) {
			std::cout << "Wrong parameter!" << std::endl;
			return -1;
		}

		int b = std::atoi(argv[2]);
		if (b != 0) {
			max_value = b;
			return 0;
		}
		else {
			std::cout << "Wrong parameter!" << std::endl;
			return -1;
		}
	}
	if (parametr == "-level") {
		if (argc <= 2) {
			std::cout << "Wrong parameter!" << std::endl;
			return -1;
		}
		int b = std::atoi(argv[2]);
		switch (b) {
			case 1:
				max_value = 10;
				return 0;
			case 2:
				max_value = 50;
				return 0;
			case 3:
				max_value = 100;
				return 0;
			default:
				std::cout << "Wrong parameter!" << std::endl;
				return -1;
		}
	}

	std::cout << "Wrong parameter!" << std::endl;
	return -1;
}