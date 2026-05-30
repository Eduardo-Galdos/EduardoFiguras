#include <math.h>
#include "../turtlec.h"

void arbolfractal(Turtle* t, float length, int depth){
  if(depth == 0 || length < 5)
    return;
  
  turtleForward(t, length);
  turtleLeft(t, 30);
  arbolfractal(t, length * 0.8, depth - 1);
  turtleRight(t, 60);
  arbolfractal(t, length * 0.8, depth - 1);

  turtleLeft(t, 30);
  turtleBackward(t, length);

}

void CurvaDeLevy(Turtle* t, float length, int depth){
  if(depth == 0){
    turtleForward(t, length);
    return;
  }

  turtleRight(t, 45);
  CurvaDeLevy(t, length / sqrt(2), depth - 1);

  turtleLeft(t, 90);
  CurvaDeLevy(t, length / sqrt(2), depth - 1);
  
  turtleRight(t, 45);

}
void ArbolFractalColoreadoHelper(Turtle* t, float length, int depth, int contraste){
  if(depth == 0 || length < 5 || 0 + contraste * depth > 255 || 255  - contraste * depth < 0)
    return;

  turtleSetColor(t, 0 + contraste * depth, 255 - contraste * depth , 0);
  turtleForward(t, length);

  turtleLeft(t, 30);
  ArbolFractalColoreadoHelper(t, length * 0.8, depth - 1, contraste);

  turtleRight(t, 60);
  ArbolFractalColoreadoHelper(t, length * 0.8, depth - 1, contraste);

  turtlePenUp(t);
  turtleLeft(t, 30);
  turtleBackward(t, length);
  turtlePenDown(t);

}


void ArbolFractalColoreado(Turtle* t, float length, int depth){
  if(depth == 0)
    return;
  
  int contraste = 255 / depth;
  
  ArbolFractalColoreadoHelper(t, length, depth, contraste);
}

int main(void){
  TurtleApp *app = turtleAppCreate(1200, 600, "Test Line");

  if(app == NULL)
    return 1;

  Turtle *t = turtleAppGetTurtle(app);

  turtlePenUp(t);
  turtleGoTo(t, 600.0f, 600.0f);
  turtlePenDown(t);

  turtleSetColor(t, 255, 100, 0);
  turtleSetSpeed(t, 20.0f);
  turtleLeft(t, 90);
  //ArbolFractalColoreado(t, 150, 8);
  arbolfractal(t, 100, 10);
  //CurvaDeLevy(t, 100, 4);
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;
}
