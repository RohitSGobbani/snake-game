#include<curses.h>
#include<stdlib.h>
#include<unistd.h>


#define MAX_LEN 100
void main(){
   WINDOW* win = initscr();
   keypad(win, true);
   nodelay(win, true);
   // int posX = 0;
   // int posY = 0;
   int snakeX[MAX_LEN];
   int snakeY[MAX_LEN];
   int snakeLen = 1;
   int foodX = rand() % 20;
   int foodY = rand() % 20;
   int dirX = 1;
   int dirY = 0;
   int score = 0;

   snakeX[0] = 0;
   snakeY[0] = 0;
   while(true){
     int pressed = wgetch(win);
     if(pressed == KEY_LEFT){
        dirX = -1;
	     dirY = 0;
     }
     if(pressed == KEY_RIGHT){
        dirX = 1;
	     dirY = 0;
     }
     if(pressed == KEY_UP){
        dirX = 0;
	     dirY = -1;
     }
     if(pressed == KEY_DOWN){
        dirX = 0;
	     dirY = 1;
     }
   //   posX += dirX;
   //   posY += dirY;
   for(int i = snakeLen-1; i > 0; i--){
      snakeX[i] = snakeX[i-1];
      snakeY[i] = snakeY[i-1];
   }
   snakeX[0] += dirX;
   snakeY[0] += dirY;
     erase();
   //   mvaddstr(posY, posX, "*");
   for(int i =0; i < snakeLen; i++){
      mvaddstr(snakeY[i], snakeX[i], "*");
   }
     mvaddstr(foodY, foodX, "&");
   //   if(foodX == posX && foodY == posY){
   //     foodX = rand() % 20;
   //     foodY = rand() % 20;
   //   }
   if(snakeX[0] == foodX && snakeY[0] == foodY){
      snakeLen++;
      foodX = rand() % 20;
      foodY = rand() % 20;
      score += 10;
   }
   mvprintw(0, 25, "Score: %d", score);

     usleep(100000);
    
   }
   endwin();
}
