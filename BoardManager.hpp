//
//  BoardManager.hpp
//  Gomoku
//
//  Created by 张大方 on 2018/7/9.
//  Copyright © 2018年 Cube. All rights reserved.
//

#ifndef BoardManager_hpp
#define BoardManager_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Board.hpp"
#include "pattern.h"
using namespace std;



class boardManager{
private:
    
    vector<Evaluate_pattern>* EP = NULL;
    
    //Current Game
    board* gamepad;
    

public:
    //All patterns
    vector<Evaluate_pattern> EPatterns;
    boardManager(){
        gamepad =new board;
    }
    
    //Loading Evaluate Patterns from patterns.dat
    void load_Patterns();
    
    void print();
    
    //create pattern;
    void create_pattern();
    
    //Evalute board;
    int Evaluate(board*);
    
    
    
    
    

    
};

#endif /* BoardManager_hpp */
