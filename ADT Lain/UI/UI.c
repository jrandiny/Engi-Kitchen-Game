#include "UI.h"
#include <ncurses.h>
#include "../../ADT/point/point.h"


void DrawBorders(WINDOW *screen){
  BorderType standardBorder;

  UL(standardBorder) = ACS_ULCORNER;
  UR(standardBorder) = ACS_URCORNER;
  LL(standardBorder) = ACS_LLCORNER;
  LR(standardBorder) = ACS_LRCORNER;

  DrawBordersCC(screen, standardBorder);
}

void DrawBordersCC(WINDOW *screen, BorderType border) {
  /* KAMUS LOKAL */
  int x, y, i;

  /* ALGORITMA */
  getmaxyx(screen, y, x);

  // Pojok
  mvwaddch(screen, 0, 0, UL(border));
  mvwaddch(screen, y - 1, 0, LL(border));
  mvwaddch(screen, 0, x - 1, UR(border));
  mvwaddch(screen, y - 1, x - 1, LR(border));

  // sisi
  for (i = 1; i < (y - 1); i++) {
    mvwaddch(screen, i, 0, ACS_VLINE);
    mvwaddch(screen, i, x - 1, ACS_VLINE);
  }

  // atas bawah
  for (i = 1; i < (x - 1); i++) {
    mvwaddch(screen, 0, i, ACS_HLINE);
    mvwaddch(screen, y - 1, i, ACS_HLINE);
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

  DrawBorders(Top_1_Panel(*gs));
  DrawBorders(Top_2_Panel(*gs));
  DrawBorders(Top_3_Panel(*gs));
  DrawBorders(Top_4_Panel(*gs));

  DrawBorders(Waiting_Panel(*gs));
  DrawBorders(Food_Panel(*gs));
  DrawBorders(Order_Panel(*gs));
  DrawBorders(Hand_Panel(*gs));
  DrawBorders(Command_Panel(*gs));
  DrawBorders(Main_Panel(*gs));

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
