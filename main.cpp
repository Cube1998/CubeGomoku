//
//  main.cpp
//  Gomoku
//
//  Created by 张大方 on 2018/7/8.
//  Copyright © 2018年 Cube. All rights reserved.
//

#include <iostream>

#include "BoardManager.hpp"

int main(int argc, const char * argv[]) {

    boardManager* gamepad;
    board *test_Board = new board();
    
    gamepad->create_pattern();
    gamepad->load_Patterns();
    //gamepad->print();
    
}
