#include <string>
#include <iostream>

#include "multiboard.h"

Coordinate get_coordinate(){
    int x, y;
    std::cout << "type ur coordinates: " << std::endl;
    std::cin >> x;
    std::cin >> y;
    Coordinate point(x - 1, y - 1);
    return point;
}

Coordinate get_wanted_board(){
    std::cout << "To select a board, ";
    return get_coordinate();
}

void print_victory_message(int player){
    std::cout << "We have a winner! ";
    std::cout << player;
    std::cout << " won!" << std::endl;
}

Coordinate play_turn(Multiboard& multiboard, Coordinate board_num, int player){
    while(multiboard.get_real_state(board_num) != EMPTY)
        board_num = get_wanted_board();
    std::cout << "Playing at board: " << board_num.x + 1 << board_num.y + 1 << std::endl;    

    Coordinate point = get_coordinate();
    while(!multiboard.change_state_at_board(board_num, point, player)){
        std::cout << "Invalid input" << std::endl;
        point = get_coordinate();
    }

    if(multiboard.check_victory_at_board(board_num, player)){
        multiboard.change_real_state(board_num, player);
    }

    multiboard.print_multiboard();
    multiboard.print_real_board();

    if(multiboard.check_real_victory(player)){
        print_victory_message(player);
        exit(0);
    }

    return point;
}

int main(int argc, char** argv){
    int size = 2;
    if(argc >= 2) size = atoi(argv[1]);
    if(size < 2) size = 2;

    int win_size = 3;
    if(argc >= 3) win_size = atoi(argv[2]);
    if(win_size > size || win_size <= 0) win_size = 3;

    int player_num = 2;
    if(argc == 4) player_num = atoi(argv[3]);
    if(player_num <= 0) player_num = 2;

    Multiboard multiboard(size, win_size);
    
    Coordinate board_num = get_wanted_board();

    while(true){
        for(int player = 1; player <= player_num; player++){
            board_num = play_turn(multiboard, board_num, player);
        }
    }

    return 0;
}