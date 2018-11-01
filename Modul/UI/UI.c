#include "UI.h"
#include <ncurses.h>
#include "../../ADT/point/point.h"
#include "../../boolean.h"


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
  int sideWidth, sideHeight;
  int topBarHeight;
  int mainWidth, mainHeight;
  int top2Width;

  /* ALGORITMA */
  initscr();
  noecho();
  getmaxyx(stdscr, parentY, parentX);

  topBarHeight = 3;

  sideWidth = parentX*UIC_Side;
  sideHeight = (parentY-(2*topBarHeight))/2;
  mainWidth = parentX - (2*sideWidth);
  mainHeight = parentY - 2*topBarHeight;

  top2Width = mainWidth*6/10;

  Top_1_Panel(*gs) = newwin(topBarHeight,sideWidth,0,0);
  Top_2_Panel(*gs) = newwin(topBarHeight,top2Width,0,sideWidth);
  Top_3_Panel(*gs) = newwin(topBarHeight, mainWidth-top2Width, 0,sideWidth+top2Width);
  Top_4_Panel(*gs) = newwin(topBarHeight, sideWidth,0,sideWidth+mainWidth);

  Waiting_Panel(*gs) = newwin(sideHeight,sideWidth,topBarHeight,0);
  Food_Panel(*gs) = newwin(sideHeight, sideWidth, topBarHeight, sideWidth+mainWidth);
  Order_Panel(*gs) = newwin(sideHeight,sideWidth,topBarHeight+sideHeight,0);
  Hand_Panel(*gs) = newwin(sideHeight,sideWidth, topBarHeight+sideHeight, sideWidth+mainWidth);

  Command_Panel(*gs) = newwin(topBarHeight, parentX, topBarHeight+mainHeight, 0);

  Main_Panel(*gs) = newwin(2*sideHeight, mainWidth,topBarHeight, sideWidth);

  Main_Panel_Width(*gs) = mainWidth;
  Main_Panel_Height(*gs) = mainHeight;
  Side_Panel_Width(*gs) = sideWidth;
  Side_Panel_Height(*gs) = sideHeight;

  RefreshBorder(gs);
}

void RefreshBorder(GameScreen *gs)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Dicetak semua border */
{
  wclear(stdscr);

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

void refreshLayout(GameScreen *gs)
/* I.S. : gs Terinisialisai screen diresize*/
/* F.S. : layout menyesuaikan*/
{
  /* KAMUS LOKAL */
  int parentX,parentY;
  int sideWidth, sideHeight;
  int topBarHeight;
  int mainWidth, mainHeight;
  int top2Width;

  /* ALGORITMA */
  getmaxyx(stdscr, parentY, parentX);

  topBarHeight = 3;

  sideWidth = parentX*UIC_Side;
  sideHeight = (parentY-(2*topBarHeight))/2;
  mainWidth = parentX - (2*sideWidth);
  mainHeight = parentY - 2*topBarHeight;

  top2Width = mainWidth*6/10;

  wresize(Top_1_Panel(*gs), topBarHeight, sideWidth);
  wresize(Top_2_Panel(*gs), topBarHeight, top2Width);
  wresize(Top_3_Panel(*gs), topBarHeight, mainWidth-top2Width);
  wresize(Top_4_Panel(*gs), topBarHeight, sideWidth);

  wresize(Waiting_Panel(*gs), sideHeight, sideWidth);
  wresize(Food_Panel(*gs), sideHeight, sideWidth);
  wresize(Order_Panel(*gs), sideHeight, sideWidth);
  wresize(Hand_Panel(*gs), sideHeight, sideWidth);

  wresize(Command_Panel(*gs), topBarHeight, parentX);

  wresize(Main_Panel(*gs), 2*sideHeight, mainWidth);

  mvwin(Top_2_Panel(*gs), 0, sideWidth);
  mvwin(Top_3_Panel(*gs), 0, sideWidth+top2Width);
  mvwin(Top_4_Panel(*gs), 0, sideWidth+mainWidth);

  mvwin(Waiting_Panel(*gs), topBarHeight, 0);
  mvwin(Food_Panel(*gs), topBarHeight,sideWidth+mainWidth);
  mvwin(Order_Panel(*gs),topBarHeight+sideHeight,0);
  mvwin(Hand_Panel(*gs),topBarHeight+sideHeight,sideWidth+mainWidth);

  mvwin(Command_Panel(*gs),topBarHeight+mainHeight,0);

  mvwin(Main_Panel(*gs),topBarHeight,sideWidth);

/*
  Top_1_Panel(*gs) = newwin(topBarHeight,sideWidth,0,0);
  Top_2_Panel(*gs) = newwin(topBarHeight,top2Width,0,sideWidth);
  Top_3_Panel(*gs) = newwin(topBarHeight, mainWidth-top2Width, 0,sideWidth+top2Width);
  Top_4_Panel(*gs) = newwin(topBarHeight, sideWidth,0,sideWidth+mainWidth);

  Waiting_Panel(*gs) = newwin(sideHeight,sideWidth,topBarHeight,0);
  Food_Panel(*gs) = newwin(sideHeight, sideWidth, topBarHeight, sideWidth+mainWidth);
  Order_Panel(*gs) = newwin(sideHeight,sideWidth,topBarHeight+sideHeight,0);
  Hand_Panel(*gs) = newwin(sideHeight,sideWidth, topBarHeight+sideHeight, sideWidth+mainWidth);

  Command_Panel(*gs) = newwin(topBarHeight, parentX, topBarHeight+mainHeight, 0);

  Main_Panel(*gs) = newwin(2*sideHeight, mainWidth,topBarHeight, sideWidth);
*/

  Main_Panel_Width(*gs) = mainWidth;
  Main_Panel_Height(*gs) = mainHeight;
  Side_Panel_Width(*gs) = sideWidth;
  Side_Panel_Height(*gs) = sideHeight;

  RefreshBorder(gs);

}

void WriteText(GameScreen *gs,ArrKata ak)
/* I.S. : Bebas sudah initScreen, aka terdefinisi */
/* F.S. : Ditulis ke layar main isi ak*/
{
  /* KAMUS LOKAL */
  AK_IdxType i;
  int j;

  /* ALGORITMA */
  wclear(Main_Panel(*gs));

  for(i = AK_GetFirstIdx(ak);i<=AK_GetLastIdx(ak);i++){
    for(j=1;j<=AK_Elmt(ak, i).Length;j++){
      mvwaddch(Main_Panel(*gs),2+i,2+j,AK_Elmt(ak,i).TabKata[j]);
    }
  }

  wrefresh(Main_Panel(*gs));
}

void RefreshWaiter(GameScreen *gs, Point waiter)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar sebuah pelayan pada posisi tertentu di layar */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  mvwaddch(Main_Panel(*gs),P_Ordinat(waiter),P_Absis(waiter),'P');

}

// void RefreshMap(GameScreen *gs, Matriks peta)
void RefreshMap(GameScreen *gs)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar peta kosong */
{
  /* KAMUS LOKAL */
  int i;
  int j;
  int maxX;
  int maxY;
  int marginX;
  int marginY;

  /* ALGORITMA */
  wclear(Main_Panel(*gs));
  DrawBorders(Main_Panel(*gs));

  /* Draw tile */
  maxX = 5;
  maxY = 5;

  /* Margin calculation */
  /* (total width - table width)/2 + 1 (border compensation)*/
  marginX = ((Main_Panel_Width(*gs)-((maxX)*5))/2) +1;
  /* (total height - table height)/2 + 1 (border compensation)*/
  marginY = ((Main_Panel_Height(*gs) - maxY*3)/2)+1;


  for(i=1;i<=maxY;i++){
    for(j=1;j<=maxX;j++){
      int posy=i*2 + marginY;
      int posx=j*4 + marginX;

      /* Membentuk
          | P |
          +---+
      */
      /* Lokasi posx dan posy berada di kanan P (kotak isi cell paling kanan) */

      /* Isi */
      mvwaddch(Main_Panel(*gs),posy,posx-1,'P');

      /* Garis bawah */
      if(i!=maxY){
        mvwaddch(Main_Panel(*gs), posy+1, posx, ACS_HLINE);
        mvwaddch(Main_Panel(*gs), posy+1, posx-1, ACS_HLINE);
        mvwaddch(Main_Panel(*gs), posy+1, posx-2, ACS_HLINE);
      }

      /* Garis samping */
      if(j!=maxX){
        mvwaddch(Main_Panel(*gs),posy,posx+1,ACS_VLINE);
      }

      /* Pojok (simbol +) */
      if(i!=maxY && j!=maxX){
        mvwaddch(Main_Panel(*gs),posy+1,posx+1,ACS_PLUS);
      }



    }
  }

  wrefresh(Main_Panel(*gs));

}


// void RefreshWaitingPanel(GameScreen *gs, Queue waitQueue)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar pelanggan menunggu */
// {
//   /* KAMUS LOKAL */
//
//   /* ALGORITMA */
//   wclear(Waiting_Panel(*gs));
//   DrawBorders(Waiting_Panel(*gs));
// }

// void RefreshFoodPanel(GameScreen *gs, Stack foodStack)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack makanan */
// {
//   /* KAMUS LOKAL */
//
//   /* ALGORITMA */
//   wclear(Food_Panel(*gs));
//   DrawBorders(Food_Panel(*gs));
// }

// void RefreshHandPanel(GameScreen *gs, Stack handStack)
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack di tangan */
// {
//   /* KAMUS LOKAL */
//
//   /* ALGORITMA */
//   wclear(Hand_Panel(*gs));
//   DrawBorders(Hand_Panel(*gs));
// }

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
  mvwprintw(Top_2_Panel(*gs),1,2,"Money: %d",money);
  mvwprintw(Top_3_Panel(*gs),1,2,"Life: %d",life);
  mvwprintw(Top_4_Panel(*gs),1,2,"Time: %d",time);

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
/* F.S. : Mengembalikan input user (command) dalam huruf besar, jika window diresize, kembalikan RESIZE*/
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
      if(output.Length>0){
        output.Length--;
      }
    }else if(tempInput == KEY_RESIZE){
      output = K_MakeKata("RESIZE");
      finishReading = true;
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
    }else if(((tempInput>='A')&&(tempInput<='Z'))||((tempInput>='0')&&(tempInput<='9'))){
      output.TabKata[output.Length+1] = tempInput;
      output.Length++;
    }else if((tempInput>='a')&&(tempInput<='z')){
      output.TabKata[output.Length+1] = tempInput-32;
      output.Length++;
    }

  }

  RefreshCommandPanel(gs,prompt);

  return output;
}