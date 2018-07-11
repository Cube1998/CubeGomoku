#include <QCoreApplication>
#include "cubeai.h"
#include "judgetment.h"
#include <iostream>
using namespace std;

#define Player1 '1'
#define Player2 '2'

struct ChessBoard{
    char chessboard[15][15];
};

struct Platform{
    ChessBoard* gamepad = NULL;
    int total_round;
    int Player1_win_round = 0;
    int Player2_win_round = 0;

};

void Print(char ChessBoard[15][15]){
    for(int i = 0;i<31;i++)
        cout<<"=";
    for(int k = 14;k>-1;k--){
        cout<<"|";
        for (int m = 0;m<15;m++)
            cout<<ChessBoard[k][m]<<" ";
        cout<<"|";
        cout<<endl;
    }
    for(int i = 0;i<31;i++)
        cout<<"=";



}

int main(int argc, char *argv[])
{

    Platform Game;

    cout<<"How many round do you want?"<<endl;
    cin>>Game.total_round;

    cout<<"total games' num  is :"<<Game.total_round<<endl;
    cout<<"AI is provided by Cube"<<endl;

    bool Player1_to_go = true;
    char ME = Player1;

    int counter = 0;

    for(int i = 0;i<Game.total_round;i++){
        Game.gamepad = new ChessBoard;
        for(int m = 0 ;m<15;m++ )
            for(int l = 0 ;l<15;l++)
                Game.gamepad->chessboard[m][l] = EMPTY;

        while(1){
            if(Player1_to_go)ME = Player1;
            else ME = Player2;

            CubeAI* CubeAI =new CubeAI(3,6,Game.gamepad->chessboard);
            CubeAI-> alphaBetaSearch(1,-INIT_MAX,INIT_MAX,ME);

            int xx = CubeAI->bestMove.x;
            int yy = CubeAI->bestMove.y;

            Game.gamepad->chessboard[xx][yy] = ME;

            Print(Game.gamepad->chessboard);

            if(win(Game.gamepad->chessboard,xx,yy,ME)){
                if(ME == Player1){
                    Game.Player1_win_round++;
                    counter++;
                    cout<<"Round "<<counter<<": "<<"Player1 Wins"<<endl;

                    break;
                }
                else if (ME == Player2){
                    Game.Player2_win_round++;
                    counter++;
                    cout<<"Round "<<counter<<": "<<"Player2 Wins"<<endl;

                    break;
                }
            }
            delete CubeAI;

            Player1_to_go = !Player1_to_go;



        }
        delete Game.gamepad;
        Game.gamepad = NULL;
    }

    cout<<"All Done"<<endl;
    cout<<"Player1 Wins "<<Game.Player1_win_round<<endl;
    cout<<"Player2 Wins "<<Game.Player2_win_round<<endl;




}
