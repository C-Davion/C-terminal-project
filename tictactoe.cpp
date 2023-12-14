#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
void swap(int &a, int  &b ){ // classical swap function with the addresses
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void circle(int x, int y, int c[11][11]){// add circle to the terrain
    int x2=x+2;
    int y2=y+2; 
    for(int loop1=x;loop1<=x2;loop1++){
        c[loop1][y]=4;
        c[loop1][y+1]=6;
        c[loop1][y+2]=5;
        
    }
    for(int loop2=y;loop2<=y2;loop2++){
        c[x+1][loop2]=0;
    }
    swap(c[x][y],c[x][y+2]);
}
void square(int x, int y, int c[11][11]){ //add square to the terrain
    int x2=x+2;
    int y2=y+2;
    for(int loop1=x;loop1<=x2;loop1++){
        for(int loop2=y;loop2<=y2;loop2++){
            c[loop1][loop2]=7;
        }
    }
    for(int loop2=y;loop2<=y2;loop2++){
        c[x+1][loop2]=1;
    }
    c[x+1][y+1]=6;
}
int gamewin(int a[3][3]){ //check if three symbols are aligned
  // check the line
   for(int i=1;i<=2;i++){
    for(int k=0;k<=2;k++){
        if(a[k][0]==i&&a[k][1]==i&&a[k][2]==i){ 
            return i;
      }
   }
   } //check the colums
   for(int i=1;i<=2;i++){
    for(int l=0;l<=2;l++){
        if(a[0][l]==i&&a[1][l]==i&&a[2][l]==i){
         return i;
      }
   }
   }
   //check the diag
   for(int i=1;i<=2;i++){
        if(a[0][0]==i&&a[1][1]==i&&a[2][2]==i){
           return i;
        }      
   }
   for(int i=1;i<=2;i++){
       if(a[2][0]==i&&a[1][1]==i&&a[0][2]==i){
         return i;
       } 
   } 
   return 0;
}
int main (){
    int i=0,j=0;
    int temp1=0, temp2=0;
    int row=0,col=0;
    int wingame=0;
    int flag=1;
    int player=1;
    int win[3][3]={0}; //parmeters to check if 3 are align
    int played[3][3]={0}; //parameters of played grid
    int count=0;
    int terrain[11][11]= //draws the terrain
    { 0,0,0,1,0,0,0,1,0,0,0,
      0,0,0,1,0,0,0,1,0,0,0,
      0,0,0,1,0,0,0,1,0,0,0,
      2,2,2,3,2,2,2,3,2,2,2,
      0,0,0,1,0,0,0,1,0,0,0,
      0,0,0,1,0,0,0,1,0,0,0,
      0,0,0,1,0,0,0,1,0,0,0,
      2,2,2,3,2,2,2,3,2,2,2,
      0,0,0,1,0,0,0,1,0,0,0,
      0,0,0,1,0,0,0,1,0,0,0,
      0,0,0,1,0,0,0,1,0,0,0,
       }  ;
    while(flag==1){ //gameloop
    count++;
    input:
    cout<<"player "<<player<<" input row and colum number ";
    cin>>i>>j;
    temp1=i;
    temp2=j;
    row=(i-1)*4;
    col=(j-1)*4;
    if(played[--i][--j]==1){ // security 
        puts("location already played"); 
        goto input;
    }
    else{
        played[i][j]++;
    }
    cout<<"player "<<player<<" played row "<<temp1<<" and colum "<<temp2<<endl;
    if(player==1){ //adds the symbol to terrain
        square(row,col,terrain);
        player++;
        win[i][j]++;
        wingame=gamewin(win);
    }
    else{
        circle(row,col,terrain);
        player--;
        win[i][j]+=2;
        wingame=gamewin(win);
    }
   for (int i = 0; i <= 10; i++) { //output
        for (int j = 0; j<=10; j++)
        {
            if(terrain[i][j]==0) cout<<"   ";
            if(terrain[i][j]==1) cout<<"|";
            if(terrain[i][j]==2) cout<<"___";
            if(terrain[i][j]==3) cout<<"+";
            if(terrain[i][j]==4) cout <<"\\";
            if(terrain[i][j]==5) cout<<"/";  
            if(terrain[i][j]==6) cout<<"       ";    
            if(terrain[i][j]==7) cout<<"---";    
        }
       cout<<'\n'; 
    }
     
    if(wingame!=0||count==9) flag=0; //end game 
    }
    if(count==9) cout<<"draw"<<endl;
    else if(player==1){
        player++;
        cout<<"player "<<player<<"has won"<<endl;
    } else {
        player--;
        cout<<"player "<<player<<" has won"<< endl;
    }
    puts("game has ended");
return 0;
}
