/* Kelompok  : UAS
   Nama file : UI.h
   Deskripsi : modul UI */

#ifndef UI_H
#define UI_H

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkata/arrKata/arrKata.h"
#include "../../ADT/space/matTile/matTile.h"
#include "../../ADT/customer/prioQueueCustomer.h"
#include "../../ADT/food/stackFood/stacktfood.h"
#include "../../ADT/food/treeFood/treeFood.h"
#include "../../ADT/order/arrOrder/arrOrder.h"
#include <ncurses.h>

/* Definisi GameScreen */
typedef struct{
  WINDOW *mainPanel;      /* Window utama (peta dan menu) */
  WINDOW *topPanel1;      /* Window atas 1 (nama) */
  WINDOW *topPanel2;      /* Window atas 2 (uang) */
  WINDOW *topPanel3;      /* Window atas 3 (nyawa) */
  WINDOW *topPanel4;      /* Window atas 4 (Waktu) */
  WINDOW *commandPanel;   /* Window command */
  WINDOW *waitingPanel;   /* Window antrian pelanggan */
  WINDOW *handPanel;      /* Window stack di tangan */
  WINDOW *orderPanel;     /* Window daftar order */
  WINDOW *foodPanel;      /* Window stack di nampan */
  WINDOW *tooltipPanel;   /* Window tooltip */

  int mainWidth;  /* Ukuran lebar main window */
  int mainHeight; /* Ukuran tinggi main window */
  int sideWidth;  /* Ukuran lebar sidebar */
  int sideHeight; /* Ukuran tinggi satu sidebar */
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
#define Tooltip_Panel(GS) (GS).tooltipPanel
#define Main_Panel_Width(GS) (GS).mainWidth
#define Main_Panel_Height(GS) (GS).mainHeight
#define Side_Panel_Width(GS) (GS).sideWidth
#define Side_Panel_Height(GS) (GS).sideHeight

/* Fraksi lebar sidebar */
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

void RefreshMap(GameScreen *gs, MatTile peta,Point waiter);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar peta sesuai MatTile peta dan waiter */

void RefreshWaitingPanel(GameScreen *gs, PrioQueueCustomer waitQueue);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar pelanggan menunggu */

void RefreshOrderPanel(GameScreen *gs, ArrOrder orderList);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar order */

void RefreshFoodPanel(GameScreen *gs, StackFood foodStack);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack makanan */

void RefreshHandPanel(GameScreen *gs, StackFood handStack);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack di tangan */

void RefreshTopPanel(GameScreen *gs, char* name, int money, int life, int time);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel atas */

void RefreshCommandPanel(GameScreen *gs, Kata prompt);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel command */

void RefreshTooltipPanel(GameScreen *gs, Kata tooltip);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel tooltip */

void ShowTree(GameScreen *gs, TreeFood tf);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar tree makanan di bagian main, kontrol diambil alih hingga q ditekan */

void PrintGrafRekursif(GameScreen *gs,TreeFood tf, int xOrig, int yOrig, int depthX, int depthY, int *lastY);
/* I.S. : Sudah menyiapkan main untuk ditulis, x dan y lokasi corner atas layar */
/* F.S. : Tercetak tree sesuai posisi */

/* KELOMPOK INPUT */
Kata GetInput(GameScreen *gs,Kata prompt);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Mengembalikan input user (command) dalam huruf besar, jika window diresize, kembalikan RESIZE */

#endif
