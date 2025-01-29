#include <iostream>
#include <fstream>
#include <string>

#include "check_value.hpp"
#include "random_value.hpp"

int game_play(const int& max_value) {

	const std::string high_scores_filename = "high_scores.txt";

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	int attempts_count{0};
	int	target_value = random_value(max_value);

	// FOR TEST
//	std::cout << "target_value = " << target_value << std::endl;
	//

	// FOR TEST
//	std::cout << "max_value = " << max_value << std::endl;
	//


	if (check_value(attempts_count, target_value))
		return -1;

	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << std::endl;

		out_file.close();
	} // end of score here just to mark end of the logic block of code

	return 0;
}

int print_table() {
	// Read the high score file and print all results
	const std::string high_scores_filename = "high_scores.txt";

	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score{0};
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}
	in_file.close();
	return 0;
}