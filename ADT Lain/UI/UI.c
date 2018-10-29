#include "UI.h"
#include <ncurses.h>
#include "../../ADT/point/point.h"

void initScreen(){
  initscr();
}

void drawRectangle(Point orig, int width, int height){
  BorderType standardBorder;

  UL(standardBorder) = ACS_ULCORNER;
  UR(standardBorder) = ACS_URCORNER;
  LL(standardBorder) = ACS_LLCORNER;
  LR(standardBorder) = ACS_LRCORNER;

  drawRectangleCC(orig, width, height, standardBorder);

}

void drawRectangleCC(Point orig, int width, int height, BorderType border){
  /* KAMUS LOKAL */
  int i,j;

  /* ALGORITMA */
  /* corner */
  mvaddch(P_Ordinat(orig), P_Absis(orig), UL(border));
  mvaddch(P_Ordinat(orig),P_Absis(orig)+width,UR(border));
  mvaddch(P_Ordinat(orig)+height, P_Absis(orig), LL(border));
  mvaddch(P_Ordinat(orig)+height,P_Absis(orig)+width,LR(border));

  /* upper line and lower line */
  move(P_Ordinat(orig),P_Absis(orig)+1);
  hline(ACS_HLINE,width-1);
  move(P_Ordinat(orig)+height,P_Absis(orig)+1);
  hline(ACS_HLINE,width-1);

  /* line */
  for(i = P_Ordinat(orig)+1;i<=P_Ordinat(orig)+height-1;i++){
    mvaddch(i,P_Absis(orig),ACS_VLINE);
    mvaddch(i,P_Absis(orig)+width,ACS_VLINE);
  }
}
