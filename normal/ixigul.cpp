#include <string>
#include <iostream>

#include "../board.h"

Coordinate get_coordinate(){
    int x, y;
    std::cout << "type ur coordinates: " << std::endl;
    std::cin >> x;
    std::cin >> y;
    Coordinate point(x - 1, y - 1);
    return point;
}

void print_victory_message(int state){
    std::cout << "We have a winner! ";
    std::cout << state;
    std::cout << " won!" << std::endl;
}

void play_turn(Board& board, int state){
    while(!board.change_state(get_coordinate(), state)){
        std::cout << "Invalid input" << std::endl;
    }
    board.print_board();
    if(board.check_victory(state)){
        print_victory_message(state);
        exit(0);
    }
}

int main(int argc, char** argv){
    int size = 3;
    if(argc >= 3) size = atoi(argv[1]);
    if(size < 3) size = 3;

    int win_size = 3;
    if(argc >= 3) win_size = atoi(argv[2]);
    if(win_size > size || win_size <= 0) win_size = size;

    int player_num = 2;
    if(argc == 4) player_num = atoi(argv[3]);
    if(player_num <= 0) player_num = 2;

    Board board(size, win_size);
    board.print_board();
    while(true){
        for(int player = 1; player <= player_num; player++){
            play_turn(board, player);
        }
    }

    return 0;
}