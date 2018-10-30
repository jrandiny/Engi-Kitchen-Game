#include "UI.h"
#include <ncurses.h>
#include "../../ADT/point/point.h"


void draw_borders(WINDOW *screen) {
  int x, y, i;

  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "+");
  mvwprintw(screen, y - 1, 0, "+");
  mvwprintw(screen, 0, x - 1, "+");
  mvwprintw(screen, y - 1, x - 1, "+");

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "|");
    mvwprintw(screen, i, x - 1, "|");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "-");
    mvwprintw(screen, y - 1, i, "-");
  }
}

void InitScreen(GameScreen *gs){
  /* KAMUS LOKAL */
  int parentX,parentY;
  int sidePanelWidth;
  int topBarHeight;
  int sidePanelHeight;
  int mainPanelWidth;

  /* ALGORITMA */
  initscr();
  getmaxyx(stdscr, parentY, parentX);

  sidePanelWidth = 20;
  topBarHeight = 3;

  mainPanelWidth = 48;

  sidePanelHeight = 12;

  Top_1_Panel(*gs) = newwin(topBarHeight,sidePanelWidth,0,0);
  Top_2_Panel(*gs) = newwin(topBarHeight,sidePanelWidth,0,sidePanelWidth);
  Top_3_Panel(*gs) = newwin(topBarHeight, mainPanelWidth-sidePanelWidth, 0,2*sidePanelWidth);
  Top_4_Panel(*gs) = newwin(topBarHeight, sidePanelWidth,0,sidePanelWidth+mainPanelWidth);

  Waiting_Panel(*gs) = newwin(sidePanelHeight,sidePanelWidth,topBarHeight,0);
  Food_Panel(*gs) = newwin(sidePanelHeight, sidePanelWidth, topBarHeight, sidePanelWidth+mainPanelWidth);
  Order_Panel(*gs) = newwin(sidePanelHeight,sidePanelWidth,topBarHeight+sidePanelHeight,0);
  Hand_Panel(*gs) = newwin(sidePanelHeight,sidePanelWidth, topBarHeight+sidePanelHeight, sidePanelWidth+mainPanelWidth);

  Command_Panel(*gs) = newwin(topBarHeight, sidePanelWidth*2 + mainPanelWidth, topBarHeight+2*sidePanelHeight, 0);

  Main_Panel(*gs) = newwin(2*sidePanelHeight, mainPanelWidth,topBarHeight, sidePanelWidth);

  draw_borders(Top_1_Panel(*gs));
  draw_borders(Top_2_Panel(*gs));
  draw_borders(Top_3_Panel(*gs));
  draw_borders(Top_4_Panel(*gs));

  draw_borders(Waiting_Panel(*gs));
  draw_borders(Food_Panel(*gs));
  draw_borders(Order_Panel(*gs));
  draw_borders(Hand_Panel(*gs));
  draw_borders(Command_Panel(*gs));
  draw_borders(Main_Panel(*gs));

  wrefresh(Main_Panel(*gs));
  wrefresh(Top_1_Panel(*gs));
  wrefresh(Top_2_Panel(*gs));
  wrefresh(Top_3_Panel(*gs));
  wrefresh(Top_4_Panel(*gs));
  wrefresh(Command_Panel(*gs));
  wrefresh(Waiting_Panel(*gs));
  wrefresh(Hand_Panel(*gs));
  wrefresh(Order_Panel(*gs));
  wrefresh(Food_Panel(*gs));
}



void DrawRectangle(Point orig, int width, int height){
  BorderType standardBorder;

  UL(standardBorder) = ACS_ULCORNER;
  UR(standardBorder) = ACS_URCORNER;
  LL(standardBorder) = ACS_LLCORNER;
  LR(standardBorder) = ACS_LRCORNER;

  DrawRectangleCC(orig, width, height, standardBorder);

}

void DrawRectangleCC(Point orig, int width, int height, BorderType border){
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
