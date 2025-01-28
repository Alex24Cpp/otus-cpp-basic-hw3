#include "argument.hpp"
#include "game_play_and_print_table.hpp"

int main(int argc, char** argv) {

    int max_value = 10;

 //   if (argument(argc, argv) != 0)
 //       return -1;

    if (game_play(max_value) != 0)
        return -1;

    if (print_table() != 0)
        return -1;

   return 0;
}