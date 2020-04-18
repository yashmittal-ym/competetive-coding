#include<bits/stdc++.h>
using namespace std;
bool checkpos(int sudoku[][9],int n,int x,int y, int num)
{
    for(int i=0;i<n;i++){
        if((sudoku[x][i]==num)||(sudoku[i][y]==num)){
            return false;
        }
    }
        int xp=(x/3)*3;
        int yp=(y/3)*3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(sudoku[xp+i][yp+j]==num){return false;}
            }
        }
    return true;
}


bool solvesudoku(int sudoku[][9],int n,int x,int y)
{
    //base
    if(x==n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<sudoku[i][j]<<" ";
            }cout<<endl;
        }return true;
    }

    //recursive case
    if(y==n){return solvesudoku(sudoku,n,x+1,0);}
    if(sudoku[x][y]!=0){return solvesudoku(sudoku,n,x,y+1);}
    for (int i = 1; i <=n; i++)
    {
        if(checkpos(sudoku,n,x,y,i)){
           sudoku[x][y]=i;
           if(solvesudoku(sudoku,n,x,y+1))
           {return true;}
           
        }
    }
    sudoku[x][y]=0;//backtracking
    return false;
    

}
int main()
{
    int sudoku[9][9]={{3,0,6,5,0,8,4,0,0},  
                      {5,2,0,0,0,0,0,0,0},  
                      {0,8,7,0,0,0,0,3,1},  
                      {0,0,3,0,1,0,0,8,0},  
                      {9,0,0,8,6,3,0,0,5},  
                      {0,5,0,0,9,0,6,0,0},  
                      {1,3,0,0,0,0,2,5,0},  
                      {0,0,0,0,0,0,0,7,4},  
                      {0,0,5,2,0,6,3,0,0}}; 
    
                      
    bool ans=solvesudoku(sudoku,9,0,0);
    if(!ans){cout<<"the given suduko is incorrect!";}
    return 0;
}