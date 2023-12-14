#include <stdio.h>
#include<iostream>
#include<windows.h>
using namespace std;
// All the negative random negative intergers are to parameter the output.
struct player //global struct with all the ships
    {
        int cruiser[3]={0};
        int cruiserlife =3;
        int destroyer[2]={0};
        int destroyerlife=2;
        int  carrier[4]={0};
        int carrierlife=4;
        int  defboard[11][11]={0};
        int atckboard[11][11]={0};
        int lives=3;
        bool isdead=false;
    };

void outputdef( player a, int turn){ // output the defence board of a player.
   cout<<"player "<< turn<<" this is your defence board"<<endl;
    for(int i=0;i<=9;i++){
        for (int j=0;j<=10;j++){
            if (a.defboard[i][j]==-1) cout<<'~'<<"  ";
            else if (a.defboard[i][j]==-2) cout<<'X'<<"  ";
               else if (a.defboard[i][j]==0||a.defboard[i][j]==-4||a.defboard[i][j]==-8) cout<<"@"<<"  ";
                  else if (a.defboard[i][j]==-10||a.defboard[i][j]==-5||a.defboard[i][j]==-9) cout<<"#"<<"  ";
                     else cout<<a.defboard[i][j]<<"  ";
            
        }
        cout<<endl;
    }
    cout<<a.defboard[10][0]<<" ";
    for (int i=1;i<=10;i++){
         if (a.defboard[10][i]==-1) cout<<"~"<<"  ";
         else if (a.defboard[10][i]==-2) cout<<'X'<<" ";
            else if (a.defboard[10][i]==0||a.defboard[10][i]==4||a.defboard[10][i]==8) cout<<"@"<<"  ";
                  else if (a.defboard[10][i]==1||a.defboard[10][i]==5||a.defboard[10][i]==9) cout<<"#"<<"  ";
    }
   cout<<endl;
    
}
void outputatck(player a, int turn){ // output the attack board of a player
   cout<<"player"<<turn<<" this is your attack board"<<endl;
   for(int i=0;i<=9;i++){
      for(int j=0;j<=10;j++){
         if(a.atckboard[i][j]==0) cout<<'*'<<"  ";
         else if(a.atckboard[i][j]==-1) cout<<'X'<<"  ";
            else if(a.atckboard[i][j]==-2) cout<<'$'<<"  ";
               else cout<<a.atckboard[i][j]<<"  ";
      };
      cout<<endl;
   }
   cout<<a.atckboard[10][0]<<" ";
   for (int i=1;i<=10;i++){
      if (a.atckboard[10][i]==-1) cout<<"X"<<" ";
      else if (a.atckboard[10][i]==-2) cout<<'$'<<"  ";
      else cout<<"*"<<"  ";
   }
   cout<<endl;
}
void intialize( player a[2]){  //initialize the game to the waned format
    for(int k=0;k<=1;k++){
        for (int j=0;j<=10;j++){
            a[k].defboard[j][0]=j;
        }
        for (int j=0;j<=10;j++){
            a[k].defboard[0][j]=j;
        }
        for(int i=1;i<=10;i++){
           for (int j=1;j<=10;j++){
              a[k].defboard[i][j]=-1;
           }
        }
        for (int i=0;i<=10;i++){
        a[k].atckboard[i][0]=i;
        }
        for (int i=0;i<=10;i++){
        a[k].atckboard[0][i]=i;
        }
        for(int i=1;i<=10;i++){
           for (int j=1;j<=10;j++){
              a[k].atckboard[i][j]=0;
           }
        }
       Sleep(3000);
    } 
} 
player setupcruiser(player b){ // the other two are identical
    int row,colum, orientation;
   cin>>row>>colum;
   b.defboard[row][colum]=0; //head of the ship
   cout<<"based of the head, choose the direction 1 for west, 2 for east, 3 for south, 4 for north :";
   cin>>orientation; 
   switch (orientation)  { // parameters the orientation
   case 1:
      for (int i=row-1; i>=row-(sizeof(b.cruiser)/sizeof(int)-1);i--){
         b.defboard[row][i]=-10;
      }
      break; 
   case 2:
      for(int i=row+1;i<=row+(sizeof(b.cruiser)/sizeof(int)-1);i++){
         b.defboard[row][i]=-10;
      }
      break; 
   case 3: 
      for(int i=colum-1;i>=colum-(sizeof(b.cruiser)/sizeof(int)-1);i--){
         b.defboard[i][colum]=-10;
      }
      break;
   case 4:
      for(int i=colum+1;i<=colum+(sizeof(b.cruiser)/sizeof(int)-1);i++){
         b.defboard[i][colum]=-10;
      } 
      break; 
   }
   return b;
}
player setupdestroyer(player b){
   int row,colum, orientation;
   cin>>row>>colum;
   b.defboard[row][colum]=-4;
   cout<<"based of the head, choose the direction 1 for west, 2 for east, 3 for south, 4 for north :";
   cin>>orientation; 
   switch (orientation)
   {
   case 1:
      for (int i=row-1; i>=row-(sizeof(b.destroyer)/sizeof(int)-1);i--){
         b.defboard[row][i]=-5;
      }
      break; 
   case 2:
      for(int i=row+1;i<=row+(sizeof(b.destroyer)/sizeof(int)-1);i++){
         b.defboard[row][i]=-5;
      }
      break; 
   case 3: 
      for(int i=colum-1;i>=colum-(sizeof(b.destroyer)/sizeof(int)-1);i--){
         b.defboard[i][colum]=-5;
      }
   break;
   case 4:
      
      for(int i=colum+1;i<=colum+(sizeof(b.destroyer)/sizeof(int)-1);i++){
         b.defboard[i][colum]=-5;
      } 
      break; 


   }
   return b;

}

player setupcarrier(player b){
   int row,colum, orientation;
   cin>>row>>colum;
   b.defboard[row][colum]=-8;
   cout<<"based of the head, choose the direction 1 for west, 2 for east, 3 for south, 4 for north :";
   cin>>orientation; 
   switch (orientation)
   {
   case 1:
      for (int i=row-1; i>=row-(sizeof(b.carrier)/sizeof(int)-1);i--){
         b.defboard[row][i]=-9;
      }
      break; 
   case 2:
      for(int i=row+1;i<=row+(sizeof(b.carrier)/sizeof(int)-1);i++){
         b.defboard[row][i]=-9;
      }
      break; 
   case 3: 
      for(int i=colum-1;i>=colum-(sizeof(b.carrier)/sizeof(int)-1);i--){
         b.defboard[i][colum]=-9;
      }
   break;
   case 4:
      
      for(int i=colum+1;i<=colum+(sizeof(b.carrier)/sizeof(int)-1);i++){
         b.defboard[i][colum]=-9;
      } 
      break; 


   }
   return b;

}
player setup (player b,int turn){ // places the ship on the defence board
   cout<<"player "<< turn<<" place your ship"<<endl;
    cout<<"input the location of the head of the cruiser  ";
    b=setupcruiser(b);
    outputdef(b, turn);
    cout<<"input the location of the head of the destroyer  ";
    b=setupdestroyer(b);
    outputdef(b,turn);
    cout<<"input the location of the head of the carrier  ";
    b=setupcarrier(b);
    outputdef(b,turn);
    return b;
}

void attack(player b[2], int turn){ // attack funtion: 
    int coord1, coord2;
   int noturn;
   if(turn==0) noturn=1; // to get the other players denomination
   if(turn ==1) noturn=0;
   cout<<"player "<<turn<<" input the coordinates of the strike point: ";
   cin>>coord1>>coord2;
   if(b[noturn].defboard[coord1][coord2]==0||b[noturn].defboard[coord1][coord2]==-10){ // check if it hits a ship
      b[turn].atckboard[coord1][coord2]=-2; // marks the attack location
      b[noturn].defboard[coord1][coord2]=-2;//changes the value of this element on the def board of the other player.
      b[noturn].cruiserlife--;
   }  else if(b[noturn].defboard[coord1][coord2]==-4||b[noturn].defboard[coord1][coord2]==-5){
      b[turn].atckboard[coord1][coord2]=-2;
      b[noturn].defboard[coord1][coord2]=-2;
      b[noturn].destroyerlife--;
   }  else if(b[noturn].defboard[coord1][coord2]==-8||b[noturn].defboard[coord1][coord2]==-9){
      b[turn].atckboard[coord1][coord2]=-2;
      b[noturn].defboard[coord1][coord2]=-2;
      b[noturn].carrierlife--;
   }  else b[turn].atckboard[coord1][coord2]=-1;
   
}
bool check(player b){ // check if the player is alive or not
   if (b.cruiserlife==0) b.lives--;
   if (b.destroyerlife==0) b.lives--;
   if(b.carrierlife==0) b.lives--;
   if(b.lives==0) return true;
   else return false;
}

int main(){
    
    player plyr[2]; //two players

    bool gamecontinue=true;
    int turn=0;
    int temp=0; 
    // introduction
    cout<<"Welcome to the terminal version of battleship."<<endl; 
    cout<<"The player denomination are 0 and 1."<<endl;
    cout<<"Each player would receive an attack board and defense board."<<endl;
    cout<<"On the defense board : @ means its the ship head"<<endl;
    cout<<" On the attack board: X means its a miss, '$' means its a hit"<<endl;
    cout<<"Every input follows the row/colum format"<<endl<<endl<<endl;
    //Sleep(10000);
    intialize(plyr);
    for (int i=0;i<=1;i++){ // this loop prevents the next player of seeing the previous one's board.
       plyr[i]=setup(plyr[i],temp);
         for (int j=0;j<=15;j++){
            cout<<endl;
         }
       temp++;
    }
    while(gamecontinue){ // game loop
      turn=0;
      outputdef(plyr[turn],turn);
      outputatck(plyr[turn],turn);
      attack(plyr,turn);
      cout<<"your turn has ended"<<endl;
      Sleep(3000);
      for (int j=0;j<=15;j++){
            cout<<endl;
         }
      turn=1;
      plyr[turn].isdead=check(plyr[turn]); 
      outputdef(plyr[turn],turn);
      outputatck(plyr[turn],turn);
      attack(plyr,turn);
      cout<<"your turn has ended"<<endl;
      Sleep(3000);
      for (int j=0;j<=15;j++){
            cout<<endl;
         }
      turn=0;
      plyr[turn].isdead=check(plyr[turn]);
      if(plyr[0].isdead==true) {
         cout<<"player one has won the game"<<endl;
         break;
      }
      else if (plyr[1].isdead==true){
          cout<<"player zero has one the game."<<endl;
         break;
      } else if(plyr[0].isdead==true&&plyr[1].isdead==true){// to balance the turn numbers.
            cout<<"draw"<<endl;
            break;
      }else continue;
      }
    cout<<"game has ended ";
return 0;
}

   