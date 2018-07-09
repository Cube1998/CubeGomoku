//
//  BoardManager.cpp
//  Gomoku
//
//  Created by 张大方 on 2018/7/9.
//  Copyright © 2018年 Cube. All rights reserved.
//

#include "BoardManager.hpp"

void boardManager::create_pattern(){
    
    
    ifstream fin;
    ofstream fout;
    string  cur_Direction = "/Users/cube.z/Documents/CProject/Gomoku/CubeGomoku/";
    string tmp = cur_Direction + "patterns.dat";
    
    //Check if patterns.dat exists; If not , create one
    fin.open(tmp.c_str(),ios::binary|ios::in);
    if(!fin.is_open())
    {
        fin.close();
        cout<<"========================="<<endl;
        cout<<"The file doesn't exists now."<<endl;
        cout<<"Creating patterns.dat...."<<endl;
        fin.open(tmp.c_str(),ios::binary|ios::in);
        fout.open(tmp.c_str(),ios::binary|ios::out|ios::trunc);
        int patterns_num = 0;
        fout.write((char*)&patterns_num, sizeof(int));
        fout.close();
    }
    int numbers;
    fin.read((char*)&numbers, sizeof(int));
    
    //generate temp vector
    vector<Evaluate_pattern> tmp_Vector ;
    
    for(int i = 0;i<numbers;i++)
    {
        Evaluate_pattern k ;
        fin.read((char*)&(k), sizeof(Evaluate_pattern));
        tmp_Vector.push_back(k);
    }
    fin.close();
    
    
    bool exit__ = true;
    while(exit__){
        Evaluate_pattern k ;
        cout<<"Input Your Pattern Sequence:"<<endl;
        for(int m = 0 ;m<6;m++)cin>>k.Sequence[m];
        
        cout<<"Input Score of this Pattern :"<<endl;
        cin>>k.score;
        //push into temporary vector
        tmp_Vector.push_back(k);
        numbers++;
        
        cout<<"Quit?(0 for quit)"<<endl;
        int a;cin>>a;
        exit__ = (a==0)?false:true;
    }
    
    
    //Save in file.
    fout.open(tmp.c_str(),ios::binary|ios::out|ios::trunc);
    fout.write((char*)&numbers, sizeof(int));
    for(int i = 0;i<numbers;i++){
        fout.write((char*)&(tmp_Vector[i]), sizeof(Evaluate_pattern));
    
    }
    fout.close();
    
    
    cout<<"Saved"<<endl;
}

void boardManager::load_Patterns(){
    
    //EPatterns = new vector<Evaluate_pattern>;
    ifstream fin;

    string tmp = "/Users/cube.z/Documents/CProject/Gomoku/CubeGomoku/patterns.dat";
    fin.open(tmp.c_str(),ios::binary|ios::in);
    
    int numbers;
    vector<Evaluate_pattern> tmp_Vector ;
    
    
    fin.read((char*)&numbers, sizeof(int));
    cout<<"----"<<numbers<<"====="<<endl;
    for(int i = 0;i<numbers;i++)
    {
        Evaluate_pattern k ;
        fin.read((char*)&k, sizeof(Evaluate_pattern));
        cout<<"Pattern : ";
        for(int i = 0;i < 6;i++)cout<<k.Sequence[i]<<"  ";
        cout<<endl<<"Score :"<<k.score<<"  "<<endl;
        //this->EPatterns.push_back(k);
        tmp_Vector.push_back(k);
    }
    //this->EPatterns = tmp_Vector;
    vector<Evaluate_pattern>::iterator it = tmp_Vector.begin();
    for(;it!=tmp_Vector.end();++it){
        cout<<"Pattern : ";
        for(int i = 0;i < 6;i++)cout<<(*it).Sequence[i]<<"  ";
        cout<<endl<<"Score :"<<(*it).score<<"  "<<endl;
        EPatterns.push_back((*it));
    }
    //EPatterns = tmp_Vector;
    fin.close();
}

void boardManager::print(){
    vector<Evaluate_pattern>::iterator it = EPatterns.begin();
    for(;it!=EPatterns.end();++it){
        cout<<"Pattern : ";
        for(int i = 0;i < 6;i++)cout<<(*it).Sequence[i]<<"  ";
        cout<<endl<<"Score :"<<(*it).score<<"  "<<endl;
    }
}
