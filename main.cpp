//
//  main.cpp
//  Gomoku
//
//  Created by 张大方 on 2018/7/8.
//  Copyright © 2018年 Cube. All rights reserved.
//

#include <iostream>
#include "Board.hpp"

int main(int argc, const char * argv[]) {

    board *test_Board = new board();
    for(int i = 0;i<6;i++)
    test_Board->setPiece(rand()%15, rand()%15);
    
}
