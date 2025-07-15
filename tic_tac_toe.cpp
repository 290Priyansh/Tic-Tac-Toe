#include <iostream>
using namespace std;
char space[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
bool tie = false;
char tokken ='X';
string n1 = " ";
string n2 = " ";


int initials(){

cout<<"      |     |      \n";
cout<<"  "<<space[0][0]<<"   |  "<<space[0][1]<<"  |   "<<space[0][2]<<"      \n";
cout<<"______|_____|______\n";
cout<<"      |     |      \n";
cout<<"  "<<space[1][0]<<"   |  "<<space[1][1]<<"  |   "<<space[1][2]<<"      \n";
cout<<"______|_____|______\n";
cout<<"      |     |      \n";
cout<<"  "<<space[2][0]<<"   |  "<<space[2][1]<<"  |   "<<space[2][2]<<"      \n";
cout<<"      |     |      \n";
};


void conditions()
{
    int digit;
    if(tokken =='X')
    {   cout<<n1<<" please enter digit"<<endl;
        cin>>digit;
    }

if(tokken =='O')
    {   cout<<n2<<" please enter digit"<<endl;
        cin>>digit;
    }

   if (digit==1){row=0;column =0;}
    else if (digit==2){row=0;column =1;}
     else if (digit==3){row=0;column =2;}
      else if (digit==4){row=1;column =0;}
       else if (digit==5){row=1;column =1;}
        else if (digit==6){row=1;column =2;}
         else if (digit==7){row=2;column =0;}
          else if (digit==8){row=2;column =1;}
            else if (digit==9){row=2;column =2;}
    else if (digit <1 || digit>9){cout<<"invalid entry \n";}
    if(tokken=='X' && space[row][column]!='X'&& space[row][column]!='O'){
    space[row][column]='X';
    tokken = 'O';}
    else if(tokken=='O'&& space[row][column]!='X'&& space[row][column]!='O'){
    space[row][column]='O';
    tokken = 'X';}
    else {cout<<"there is no empty space"<<endl;
    conditions();}
    initials();
 }

 bool winning_conditions()
 {
    for (int i=0 ;i<3 ;i++)
    {
        if (space[i][0]==space[i][1] && space[i][0]==space[i][2]  || space[0][i]==space[1][i] && space[0][i] == space[2][i])
        {return true;}
    }
    if(space[0][0]==space[1][1] && space[0][0]==space[2][2]){ return true;}

    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (space[i][j]!='X' && space[i][j]!='O')
          {  return false;}
            
        }
    }
tie = true;
return true ;
}

int main()
{
         cout<<"enter the name of the first person \n";
         getline(cin,n1);
         cout<<"enter the name of the second person \n";
         getline(cin,n2);         
         cout<<n1 <<" is player 1 \n";
         cout<<n2 <<" is player 2 \n";

    while(! winning_conditions())
    {
        initials();
        conditions();
        winning_conditions();
        
    }

    if (tokken=='X' && tie == false)
    {
        cout<<n2<<" Wins!!"<<endl;
    }
    else if (tokken=='O' && tie == false)
    {
        cout<<n1<<" Wins!!"<<endl;
    }
    else{cout<<"its a draw!"<<endl;}


}
