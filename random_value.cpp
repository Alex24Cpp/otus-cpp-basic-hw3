#include <cstdlib>
#include <ctime>

int random_value(const int& max_value) {
	
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	const int random_value = std::rand() % max_value;
	return random_value;
}