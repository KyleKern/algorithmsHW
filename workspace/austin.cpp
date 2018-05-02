#include <iostream>

#include <string>

using namespace std;

int checkMoves(int i, int j, char board[][7], int count){

    cout<<i<<j;

    if(board[i+2][j]=='o'){

        count++;

    }

    if(board[i-2][j]=='o'){

        count++;

    }

    if(board[i][j+2]=='o'){

        count++;

    }

    if(board[i][j-2]=='o'){

        count++;

    }

    return count;

}

int findLocation(char board[][7], int count){

    for(int i=0; i<7; i++){

        for(int j=0; j<7; j++){

            if(board[i][j]== '.'){
                cout<<endl<<i<<j<<endl;
                checkMoves(i, j, board, count);
            }

        }

    }

    return count;

}



int main(){

    int count=0;

    char board[7][7];

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cin>>board[i][j];
        }

    }

   cout<<board[3][3];

    cout<<endl;

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cout<<board[i][j];
        }
        cout<<endl;

    }

    cout<< findLocation(board, count);

    

}