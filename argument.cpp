#include <iostream>
#include <string>

int argument(int argc, char** argv, bool& only_print_table) {

	if (argc > 2) {
		std::cout << "Too many parameters!" << std::endl;
		return -1;
	}

	std::string parametr = argv[1];

	if (parametr == "-table") {
		only_print_table = true;
		return 0;
	}
	else {
		std::cout << "Wrong parameter!" << std::endl;
		return -1;
	}
}