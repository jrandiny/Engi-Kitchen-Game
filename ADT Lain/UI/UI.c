#include "UI.h"
#include <ncurses.h>
#include "../../ADT/point/point.h"
#include "../../header/boolean.h"


void DrawBorders(WINDOW *screen)
/* I.S. : screen sudah diinisialisasi */
/* F.S. : Digambar border pada screen yang dimau, tipe border standar */
{
  BorderType standardBorder;

  UL(standardBorder) = ACS_ULCORNER;
  UR(standardBorder) = ACS_URCORNER;
  LL(standardBorder) = ACS_LLCORNER;
  LR(standardBorder) = ACS_LRCORNER;

  DrawBordersCC(screen, standardBorder);
}

void DrawBordersCC(WINDOW *screen, BorderType border)
/* I.S. : Screen sudah diinisialisasi, border terdefinisi */
/* F.S. : Digambar border pada screen yanh dimau, tipe border sesuai input*/
{
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

void InitScreen(GameScreen *gs)
/* I.S. : Bebas */
/* F.S. : Terinisialisai layar kosong dengan window diset ke gs */
{
  /* KAMUS LOKAL */
  int parentX,parentY;
  int sidePanelWidth;
  int topBarHeight;
  int sidePanelHeight;
  int mainPanelWidth;

  /* ALGORITMA */
  initscr();
  noecho();
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

void RefreshWaiter(GameScreen *gs, Point waiter)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar sebuah pelayan pada posisi tertentu di layar */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  mvwaddch(Main_Panel(*gs),P_Ordinat(waiter),P_Absis(waiter),'P');

}

void RefreshMap(GameScreen *gs, Matriks peta)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar peta kosong */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  wclear(Main_Panel(*gs));
  DrawBorders(Main_Panel(*gs));
}


void RefreshWaitingPanel(GameScreen *gs, Queue waitQueue)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar pelanggan menunggu */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  wclear(Waiting_Panel(*gs));
  DrawBorders(Waiting_Panel(*gs));
}

void RefreshFoodPanel(GameScreen *gs, Stack foodStack)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack makanan */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  wclear(Food_Panel(*gs));
  DrawBorders(Food_Panel(*gs));
}

void RefreshHandPanel(GameScreen *gs, Stack handStack)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack di tangan */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  wclear(Hand_Panel(*gs));
  DrawBorders(Hand_Panel(*gs));
}

void RefreshTopPanel(GameScreen *gs, Kata name, int money, int life, int time)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel atas */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  wclear(Top_1_Panel(*gs));
  wclear(Top_2_Panel(*gs));
  wclear(Top_3_Panel(*gs));
  wclear(Top_4_Panel(*gs));

  DrawBorders(Top_1_Panel(*gs));
  DrawBorders(Top_2_Panel(*gs));
  DrawBorders(Top_3_Panel(*gs));
  DrawBorders(Top_4_Panel(*gs));

  mvwprintw(Top_1_Panel(*gs),1,2,"nama","Aa");
  mvwprintw(Top_2_Panel(*gs),1,2,"Money: ",money);
  mvwprintw(Top_3_Panel(*gs),1,2,"Life: ",life);
  mvwprintw(Top_4_Panel(*gs),1,2,"Time: ",time);

  wrefresh(Top_1_Panel(*gs));
  wrefresh(Top_2_Panel(*gs));
  wrefresh(Top_3_Panel(*gs));
  wrefresh(Top_4_Panel(*gs));

}

void RefreshCommandPanel(GameScreen *gs,Kata prompt)
/* I.S. : Bebas sudah initScreen */
/* F.S. : DigambarKata panel command */
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  wclear(Command_Panel(*gs));
  DrawBorders(Command_Panel(*gs));
  for(i = 1;i<=prompt.Length;i++){
    mvwaddch(Command_Panel(*gs),1,2+i,prompt.TabKata[i]);
  }
  wrefresh(Command_Panel(*gs));
}

Kata GetInput(GameScreen *gs,Kata prompt)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Mengembalikan input user (command) dalam huruf besar */
{
  /* KAMUS LOKAL */
  Kata output;
  int tempInput;
  boolean finishReading;
  int kataLength;
  int i;

  /* ALGORITMA */
  finishReading = false;

  keypad(Command_Panel(*gs),true);

  output.Length = 0;

  while(!finishReading){
    RefreshCommandPanel(gs,prompt);
    i = 1;
    while(i<=output.Length){
      mvwaddch(Command_Panel(*gs),1,prompt.Length+2+i,output.TabKata[i]);
      i++;
    }

    tempInput = wgetch(Command_Panel(*gs));

    if((tempInput==13)||(tempInput==10)||(tempInput==KEY_ENTER)){
      finishReading =true;
    }else if(tempInput == KEY_BACKSPACE){
      output.Length--;
    }else if(tempInput == KEY_UP){
      output = K_MakeKata("GU");
      finishReading = true;
    }else if(tempInput == KEY_DOWN){
      output = K_MakeKata("GD");
      finishReading = true;
    }else if(tempInput == KEY_LEFT){
      output = K_MakeKata("GL");
      finishReading = true;
    }else if(tempInput == KEY_RIGHT){
      output = K_MakeKata("GR");
      finishReading = true;
    }else if((tempInput>=65)&&(tempInput<=90)){
      output.TabKata[output.Length+1] = tempInput;
      output.Length++;
    }else if((tempInput>=97)&&(tempInput<=122)){
      output.TabKata[output.Length+1] = tempInput-32;
      output.Length++;
    }

  }

  RefreshCommandPanel(gs,prompt);

  return output;
}
