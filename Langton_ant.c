#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#include "include/gfx.h"

#define WIDTH	500
#define HEIGHT	500

#define ITERATIONS 1000

#define MOVE        \
switch(rot){      \
 case 0: i = (i - 1) % WIDTH; break;                         \
 case 1: j = (j + 1) % WIDTH; break;                         \
 case 2: i = (i + 1) % WIDTH; break;                         \
 case 3: j = (j - 1) % WIDTH; break;                         \
}

int main(void){
  gfx_open(WIDTH,HEIGHT,"Langton ant");
  gfx_color(255,255,255);

  int screen[WIDTH][HEIGHT];

  srand(time(NULL));

  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      screen[i][j] = ((double)rand()/RAND_MAX > 0.5 ? 1 : 0);
    }
  }

  int i,j;
  scanf("%d %d",&i,&j);
  int rot = 0;
  for(int z = 0; true; i++){
    if(screen[i][j] == 0){
      rot = (rot + 1) % 4;
      screen[i][j] = 1;

      MOVE;

    }else{
      rot = abs((rot - 1)) % 4;
      screen[i][j] = 0;

      MOVE;
    }

    if((z % ITERATIONS) == 0){
      for(int a = 0; a <= WIDTH; a++){
        for(int b = 0; b <= HEIGHT; b++){
          screen[a][b] ? gfx_point(a,b) : 0;
        }
      }

      gfx_flush();
      getchar();
    }


  }

}
