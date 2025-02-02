#include <iostream>
#include <fstream>
#include <string>
#include <map>

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

	if (check_value(attempts_count, target_value))
		return -1;

	// Write new high score to the records table
	{
		std::map<std::string, int> table;

		// We should open the output file in the append mode
		std::fstream in_file{high_scores_filename, std::ios_base::out | std::ios_base::in | std::ios_base::app}; // , std::ios_base::out | std::ios_base::in | std::ios_base::app
		if (!in_file.is_open()) {
			std::cout << "Failed to open file: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::string user_name_in_table;
		int high_score{0};
		while (true) {
			// Read the username
			in_file >> user_name_in_table;
			if (in_file.fail()) 
				break;
			in_file >> high_score;

			table[user_name_in_table] = high_score;

			// Ignore the end of line symbol
			in_file.ignore();
		}

		in_file.close();

		if (table.find(user_name) != table.end()) {
			if (attempts_count < table[user_name])
				table[user_name] = attempts_count;
		}
		else
			table[user_name] = attempts_count;


		
		std::ofstream out_file{high_scores_filename, std::ios_base::trunc};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		typedef std::map<std::string, int>::const_iterator CI;
		for (CI p = table.begin(); p != table.end(); ++p)
			out_file << p->first << '\t' << p->second <<std::endl;
		//
	
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

