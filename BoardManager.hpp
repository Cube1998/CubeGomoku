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
using namespace std;

class Evaluate_pattern {
public:
    bool* Sequence ;
    int score ;
    
    Evaluate_pattern(){
        Sequence = new bool[6];
        score = 0;
    };
    
    Evaluate_pattern(const Evaluate_pattern & copy){
        Sequence = new bool[6];
        for(int i = 0;i<6;i++)Sequence[i] = copy.Sequence[i];
        this->score = copy.score;
    }
    
};

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
