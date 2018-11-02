#ifndef UI_H
#define UI_H

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"
// #include "../../ADT/matriks/matriks.h"
// #include "../../ADT/queue/queue.h"
// #include "../../ADT/stack/stackt.h"
#include "../../ADT/mesinkata/arrKata/arrKata.h"
#include "../../ADT/space/matTile/matTile.h"
//#include "../../ADT/listlinier/listlinier.h"
#include <ncurses.h>

/* Definisi GameScreen */
typedef struct{
  WINDOW *mainPanel;
  WINDOW *topPanel1;
  WINDOW *topPanel2;
  WINDOW *topPanel3;
  WINDOW *topPanel4;
  WINDOW *commandPanel;
  WINDOW *waitingPanel;
  WINDOW *handPanel;
  WINDOW *bottomPanel;
  WINDOW *orderPanel;
  WINDOW *foodPanel;

  int mainWidth;
  int mainHeight;
  int sideWidth;
  int sideHeight;
}GameScreen;

/* Notasi akses: Selektor GameScreen */
#define Main_Panel(GS) (GS).mainPanel
#define Top_1_Panel(GS) (GS).topPanel1
#define Top_2_Panel(GS) (GS).topPanel2
#define Top_3_Panel(GS) (GS).topPanel3
#define Top_4_Panel(GS) (GS).topPanel4
#define Command_Panel(GS) (GS).commandPanel
#define Waiting_Panel(GS) (GS).waitingPanel
#define Hand_Panel(GS) (GS).handPanel
#define Order_Panel(GS) (GS).orderPanel
#define Food_Panel(GS) (GS).foodPanel
#define Main_Panel_Width(GS) (GS).mainWidth
#define Main_Panel_Height(GS) (GS).mainHeight
#define Side_Panel_Width(GS) (GS).sideWidth
#define Side_Panel_Height(GS) (GS).sideHeight

#define UIC_Side 30/100;

/* Definisi BorderType untuk gambar persegi panjang */
typedef struct {
	int UL; /* upper left */
	int UR; /* upper right */
	int LL; /* lower left */
  int LR; /* lower right */
} BorderType;

/* Notasi akses: Selektor BorderType*/
#define UL(B) (B).UL
#define UR(B) (B).UR
#define LL(B) (B).LL
#define LR(B) (B).LR


void InitScreen(GameScreen *gs);
/* I.S. : Bebas */
/* F.S. : Terinisialisai layar kosong dengan window diset ke gs */

void QuitScreen(GameScreen *gs);
/* I.S. : gs Terinisialisai */
/* F.S. : semua gs tertutup*/

void refreshLayout(GameScreen *gs);
/* I.S. : gs Terinisialisai screen diresize*/
/* F.S. : layout menyesuaikan*/

/* KELOMPOK BORDER */
void DrawBorders(WINDOW *screen);
/* I.S. : screen sudah diinisialisasi */
/* F.S. : Digambar border pada screen yang dimau, tipe border standar */

void DrawBordersCC(WINDOW *screen,BorderType border);
/* I.S. : Screen sudah diinisialisasi, border terdefinisi */
/* F.S. : Digambar border pada screen yanh dimau, tipe border sesuai input*/

/* Kelompok Refresh*/
void WriteText(GameScreen *gs,ArrKata ak);
/* I.S. : Bebas sudah initScreen, aka terdefinisi */
/* F.S. : Ditulis ke layar main isi ak*/

void RefreshBorder(GameScreen *gs);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Dicetak semua border */

void RefreshWaiter(GameScreen *gs, Point waiter);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar sebuah pelayan pada posisi tertentu di layar */

void RefreshMap(GameScreen *gs, MatTile peta);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar peta sesuai MatTile peta */

// void RefreshWaitingPanel(GameScreen *gs, Queue waitQueue);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar pelanggan menunggu */

//void DrawOrderPanel(GameScreen *gs, List orderList);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar order */

// void RefreshFoodPanel(GameScreen *gs, Stack foodStack);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack makanan */

// void RefreshHandPanel(GameScreen *gs, Stack handStack);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack di tangan */

void RefreshTopPanel(GameScreen *gs, char* name, int money, int life, int time);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel atas */

void RefreshCommandPanel(GameScreen *gs, Kata prompt);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel command */

/* KELOMPOK INPUT */
Kata GetInput(GameScreen *gs,Kata prompt);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Mengembalikan input user (command) dalam huruf besar, jika window diresize, kembalikan RESIZE */

#endif
