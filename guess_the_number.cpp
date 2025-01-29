#include "argument.hpp"
#include "game_play_and_print_table.hpp"

int main(int argc, char** argv) {

    bool only_print_table{false};
    int max_value{100};

    if (argc > 1) {
        if (argument(argc, argv, only_print_table, max_value) != 0)
            return -1;
    }

    if (!only_print_table)
        if (game_play(max_value) != 0)
            return -1;

    if (print_table() != 0)
        return -1;

   return 0;
}