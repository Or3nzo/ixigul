#ifndef MULTIBOARD_H_
#define MULTIBOARD_H_

#include "../board.h"
#include <vector>

class Multiboard{
    int m_size;
    int m_win_size;
    std::vector<std::vector<Board>> m_multiboard;
    Board m_real_board;
public:
    Multiboard(int size, int win_size) : m_size(size), m_win_size(win_size),
            m_multiboard(size, std::vector<Board>(size, Board(size, win_size))), m_real_board(size, win_size) {}
    bool change_real_state(Coordinate point, int value);
    int get_real_state(Coordinate point);
    void print_multiboard();
    bool change_state_at_board(Coordinate board_num, Coordinate point, int value);
    bool check_victory_at_board(Coordinate board_num, int state);
    void print_real_board();
    bool check_real_victory(int player);
    
};

#endif