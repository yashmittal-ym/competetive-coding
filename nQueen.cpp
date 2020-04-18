#include<bits/stdc++.h>
using namespace std;
//to check if the given position is safe or not?
bool checkpos(int board[][10],int n,int x,int y)
{
    //column check
    for(int i=0;i<=x;i++){
        if(board[i][y]==1){return false;}
    }
    //left diagonal
    int xpos=x;
    int ypos=y;
    while(xpos>=0&&ypos>=0){
        if(board[xpos][ypos]==1){return false;}
        xpos--;ypos--;
    }
    //right diagonal
    xpos=x;
    ypos=y;
    while(xpos>=0&&ypos<n){
        if(board[xpos][ypos]==1){return false;}
        xpos--;ypos++;
    }    
    return true;
}

bool solveNqueen(int board[][10],int n,int x)
{
    //base case
    if(x==n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j]==1){cout<<"Q ";}
                else{cout<<"_ ";}
            }cout<<endl;
        }cout<<endl<<endl;
        return false;//this is a hack for printing all the sequences
    }
    //recursive case
    for (int j = 0; j < n; j++)
    {
       if(checkpos(board,n,x,j)){
            board[x][j]=1;
            if(solveNqueen(board,n,x+1)){return true;}
            board[x][j]=0;//backtracking
        };
    }
    return false;//if there exist no place in the that row acc to the previous assigned positions

}

int main()
{
    int n;
    n=4;
    int board[10][10]={0};
    solveNqueen(board,n,0);
    return 0;

}
