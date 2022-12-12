#include<iostream>
#include<conio.h>
#include<windows.h>  
//  #include<graphics.h>          // for using sleep function because in fastcomputers the game excutes
                                //    faster which means the snake will move  fast
using namespace std;
bool gameOver;
const int width =30;
const int hieght =20;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100] ;
int nTail;

enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};    //direction of snake mov.
eDirection dir;



void setup()
{

    gameOver = false;
    dir = STOP;
    x = width/2;
    y = hieght/2;
    fruitX= rand() % width;     // perc. for width -1 no. choose in randum
     fruitY= rand() % hieght;     // perc. for hieght -1 no. choose in randum
     score =0;




}

void draw()
{
   system("cls");                                         //system("clear");
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;                                      // Printing  hollow recctangle
 
    for (int i = 0; i < hieght; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)                         // Printing The snake head position
                cout << "O";         
                                                       
                                                      
                                                        
            else if (i == fruitY && j == fruitX)                                                        
                cout << "F";                               //Printing The fruit position
            else {
                 bool print = false;
                for(int k=0; k<nTail;k++)
                {
                     
                    if(tailX[k] == j && tailY[k] ==i){
                        cout<<"o";
                        print = true;
                    }
                }
                   if(!print)
                    cout<<" ";
            }
            
                 
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
 
    for (int i = 0; i < width+2; i++) 
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

     


void input()
{
    if(_kbhit()) 
    {
        switch(_getch())
    { 
        case 'a':
             dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;                                 //giving directions
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            gameOver = true;
            break;

        }
    }

}

void logic()
{      
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1 ; i<nTail ;i++){

        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY =  prev2Y;


    } 

   switch(dir)
   
   {

       case LEFT:
              x--;                       //coordinates changes  of head when direction change
              break;
       case RIGHT:  
              x++;
              break;
       case UP:
              y--;
              break;
       case DOWN:
              y++;
              break;
       default:
          break;
   }
    
     if( x ==fruitX && y ==fruitY){
  
         fruitX= rand() % width;                        // fruit eat and new random fruit coordinate occuring
         fruitY= rand() % hieght;
         score += 1;
         nTail++;                                        //When fruit eat tail increase

     }
     if(x>width || x<0 || y>hieght || y<0){              // Game (terminates ) over when it touches boundary  

            gameOver = true;
            cout<<"\n Your Game is Over(   by  hitting the wall)";
     }   


    //  if( x>=width){
    //      x =0;
    //  }
    //  else if(x<0){
        //  x = width -1;                   // for moving throught the wall without overing the game
    //  }

    // if( y>=width){
    //      y =0;
    //  }
    //  else if(y<0){
    //      y= width -1;
    //  }


     for( int i=0; i<nTail; i++){
         if( tailX[i]==x && tailY[i] == y){
             gameOver =true;
             cout<<" Your Game is Over(  by hitting yourself)";
         
         }
     }
     
}
 
int main(){

   setup();
   while(!gameOver){

     draw();
     input();
     logic();
     Sleep(20);

 }
    
    return 0;
}
