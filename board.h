#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>

#define INVALID -1
#define EMPTY 0

struct Coordinate{
public:
    int x;
    int y;
    Coordinate(int x, int y) : x(x), y(y) {} 
};


class Board{
    int m_size;
    int m_win_size;
    std::vector<std::vector<int>> m_board;
    
public:
    Board(int size, int win_size) : m_size(size), m_win_size(win_size), m_board(size, std::vector<int>(size, EMPTY)) {}
    bool is_point_valid(int x, int y);
    bool is_point_valid(Coordinate point);
    int get_state(int x, int y);
    int get_state(const Coordinate point);
    bool change_state(const Coordinate point, int value);
    void print_board();
    int get_size() {return m_size;};
    bool check_row_victory(int row, int state);
    bool check_column_victory(int column, int state);
    bool check_left_diagonal_victory(int state);
    bool check_right_diagonal_victory(int state);
    bool check_victory(int state);
    void print_row(int row);
};


#endif