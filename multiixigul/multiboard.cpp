#include "multiboard.h"

bool Multiboard::change_real_state(Coordinate point, int value){
    return m_real_board.change_state(point, value);
}

int Multiboard::get_real_state(Coordinate point){
    return m_real_board.get_state(point);
}

void Multiboard::print_multiboard(){
    int line_seperation_size = (m_size + 1) * m_size * m_size + 1;
    for(int i = 0; i < line_seperation_size; i++)
        std::cout << "#";
    std::cout << std::endl;

    for(int i = 0; i < m_size; i++){
        for(int row = 0; row < m_size; row++){
            for(int j = 0; j < m_size; j++){
                if(j == 0) std::cout << "#";
                m_multiboard[i][j].print_row(row);
                std::cout << "#";
            }
            std::cout << std::endl;
        }
        
        for(int i = 0; i < line_seperation_size; i++)
            std::cout << "#";
        std::cout << std::endl;
    }
}

bool Multiboard::change_state_at_board(Coordinate board_num, Coordinate point, int value){
    return m_multiboard[board_num.x][board_num.y].change_state(point, value);
}

bool Multiboard::check_victory_at_board(Coordinate board_num, int state){
    return m_multiboard[board_num.x][board_num.y].check_victory(state);
}

void Multiboard::print_real_board(){
    m_real_board.print_board();
}

bool Multiboard::check_real_victory(int player){
    return m_real_board.check_victory(player);
}