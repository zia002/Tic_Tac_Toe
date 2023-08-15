/*
Project Name:Tic Tac Toe
Author:Mohammad Zia
Date:15 Aug 2023
Algorithm:Minimax 
*/
#include<bits/stdc++.h>
using namespace std;
//----------Board----------------//
vector<string>ans_board(5);
void print(vector<string>&board){
    for(int i=0;i<5;i++){
        for(int j=0;j<11;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
//---------Check----------------//
bool empty(vector<string>b){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(b[i][j]=='_') return 1;
        }
    }
    return 0;
}
int win(vector<string> b){
    for(int i=0;i<3;i++){
        if(b[i][0]==b[i][1] && b[i][1]==b[i][2] && b[i][2]=='X') return 1;
        else if(b[i][0]==b[i][1] && b[i][1]==b[i][2] && b[i][2]=='O') return -1;
        else if(b[0][i]==b[1][i] && b[1][i]==b[2][i] && b[2][i]=='X') return 1;
        else if(b[0][i]==b[1][i] && b[1][i]==b[2][i] && b[2][i]=='O') return -1;
    }
    if(b[0][0]==b[1][1] && b[1][1]==b[2][2] && b[2][2]=='X') return 1;
    else if(b[0][0]==b[1][1] && b[1][1]==b[2][2] && b[2][2]=='O') return -1;
    else if(b[0][2]==b[1][1] && b[1][1]==b[2][0] && b[0][2]=='X') return 1;
    else if(b[0][2]==b[1][1] && b[1][1]==b[2][0] && b[0][2]=='O') return -1;
    else return 2;
}
int minimax(vector<string> &board, int ai){
  int score = win(board);
	if (score == 1) return score;
	else if (score == -1) return score;
  else if(empty(board)==0) return 0;
	if(ai){
		int best=INT_MIN;
		for (int i = 0; i<3; i++){
			for (int j = 0; j<3; j++){
				if (board[i][j]=='_'){
					board[i][j]='X';
					best=max( best,minimax(board,0));
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
	else{
		int best=INT_MAX;
		for (int i = 0; i<3; i++){
			for (int j = 0; j<3; j++){
				if (board[i][j]=='_'){
					board[i][j]='O';
					best = min(best,minimax(board,1));
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}
void ai(vector<string> &board){
    int score,best=INT_MIN;
    int row,col;
	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			if (board[i][j]=='_'){
				board[i][j] ='X';
				score=minimax(board,0);
				board[i][j] = '_';
				if (score>best){
					row=i,col=j;
                    best=score;
				}
			}
		}
	}
    board[row][col]='X';
    ans_board[2*row][(4*col)+1]='X';
    ans_board[(2*row)][(4*col)+2]='`';
    ans_board[(2*row)][(4*col)]='`';
}
int winner(vector<string> board){
    int res=win(board);
    if(res==1) {
        cout<<"\nYou Lost :("<<endl;
        return 1;
    }
    else if(empty(board)==0) {
        cout<<"\nDraw,You are a Good Player :)"<<endl;
        return 1;
    }
    else if(res==-1){
        cout<<"\nIt's Impossible to Beat AI ,but you did it,How it's Possible *_*"<<endl;
        return 1;
    }
    return 0;
}
int main()
{
    ans_board[0]=".1.|.2.|.3.";
    ans_board[1]="---|---|---";
    ans_board[2]=".4.|.5.|.6.";
    ans_board[3]="---|---|---";
    ans_board[4]=".7.|.8.|.9.";
    vector<string>board;
    string s(3,'_');
    for(int i=0;i<3;i++) board.push_back(s);
    print(ans_board);
    while(1){
        int row,col,position;
        cout<<"Enter Position:";cin>>position;
        row=ceil(position/3.0)-1;
        col=(position%3)-1;
        if(col==-1) col=2;
        if(position>=1 && position<=9 && board[row][col]!='X' && board[row][col]!='O'){
            board[row][col]='O';
            ans_board[2*row][(4*col)+1]='O';
            ans_board[(2*row)][(4*col)+2]='`';
            ans_board[(2*row)][(4*col)]='`';
            system("clear");
            print(ans_board);
            if(winner(board)) break;
            else{
	            ai(board);
                system("clear");
                print(ans_board);
                if(winner(board)) break;
            }
        }
        else cout<<"Enter a Valid Position"<<endl;
    }
	return 0;
}
