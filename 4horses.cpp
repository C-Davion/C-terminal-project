#include <iostream>
#include<time.h>

using namespace std;

int main(){
int board[4][21]={0};
 for(int i=0;i<=3;i+=3){
  for(int j=0;j<=20;j++){
      (j%2==0) ? board[i][j]=1 : board[i][j]=2;
  }  
 }
 for(int i=1;i<=2;i++){
   for(int j=0;j<=20;j++){
     (j%2==0) ? board[i][j]=3 : board[i][j]=4;
   }
 }
 board[0][11]=board[3][11]=5;
 for(int i=0;i<=3;i++){
   for(int j=0;j<=20;j++){
     if(board[i][j]==1) cout<<"-";
     if(board[i][j]==2) cout<<"----";
     if(board[i][j]==3) cout<<"|";
     if(board[i][j]==4) cout<<"    ";
     if(board[i][j]==5) cout<<"$$$$";
   }
   cout<<endl;
 }
    
}
