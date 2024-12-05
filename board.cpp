#include "board.h"


bool Board::is_point_valid(int x, int y){
    return !(x >= m_size || y >= m_size || x < 0 || y < 0);
}

bool Board::is_point_valid(Coordinate point){
    return is_point_valid(point.x, point.y);
}

int Board::get_state(int x, int y){
    if(!is_point_valid(x, y)) return INVALID;
    return m_board[x][y];
}

int Board::get_state(const Coordinate point){
    return get_state(point.x, point.y);
}

bool Board::change_state(const Coordinate point, int value){
    if(!is_point_valid(point)) return false;
    if(m_board[point.x][point.y] != EMPTY) return false;
    m_board[point.x][point.y] = value;
    return true;
}

void Board::print_board(){
    for(auto row : m_board){
        std::cout << std::endl << std::endl;
        for(auto column : row){
            std::cout << "|";
            if(column == EMPTY)
                std::cout << "-";
            else
                std::cout << column;
            std::cout << "| ";
        }
    }
    std::cout << std::endl;
}

bool Board::check_row_victory(int row, int state){
    for(int column = 0; column < m_size; column++){
        for(int j = 0; j < m_win_size; j++){
            if(get_state(row, column + j) != state) break;
            if(j == m_win_size - 1) return true;
        }
    }
    return false;
}

bool Board::check_column_victory(int column, int state){
    for(int row = 0; row < m_size; row++){
        for(int j = 0; j < m_win_size; j++){
            if(get_state(row + j, column) != state) break;
            if(j == m_win_size - 1) return true;
        }
    }
    return false;
}

bool Board::check_left_diagonal_victory(int state){
    for(int row = 0; row < m_size; row++){
        for(int column = 0; column < m_size; column++){
            for(int k = 0; k < m_win_size; k++){
                if(get_state(row + k, column + k) != state) break;
                if(k == m_win_size - 1) return true;
            }
        }
    }
    return false;
}

bool Board::check_right_diagonal_victory(int state){
    for(int row = 0; row < m_size; row++){
        for(int column = 0; column < m_size; column++){
            for(int k = 0; k < m_win_size; k++){
                if(get_state(row - k, column - k) != state) break;
                if(k == m_win_size - 1) return true;
            }
        }
    }
    return false;
}

bool Board::check_victory(int state){
    for(int i = 0; i < m_size; i++){
        if(check_row_victory(i, state) || check_column_victory(i, state)) 
            return true;
    }
    return (check_left_diagonal_victory(state) || check_right_diagonal_victory(state));
}

void Board::print_row(int row){
    for(int i = 0; i < m_size; i++){
        std::cout << "|";
        if(m_board[i][row] == EMPTY)
            std::cout << "-";
        else
            std::cout << m_board[i][row];
        std::cout << "|";
        if(i != m_size - 1)
            std::cout << " ";
    }
}