#ifndef UI_H
#define UI_H

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/matriks/matriks.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/stack/stackt.h"
#include "../../ADT/listlinier/listlinier.h"


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

void initScreen();
/* I.S. : Bebas */
/* F.S. : Terinisialisai layar kosong */

/* KEOMPOK GAMBAR */
void drawRectangle(Point orig, int width, int height);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar persegi denga origin point (kiri atas) pada orig
          lebar width, tinggi height, border standar (kotak)*/

void drawRectangleCC(Point orig, int width, int height, BorderType border);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar persegi denga origin point (kiri atas) pada orig
          lebar width, tinggi height, border bisa diubah */

void drawWaiter(Point waiter);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar sebuah pelayan pada posisi tertentu di layar */

void drawMap(Matriks peta);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar peta kosong */

void drawWaitingPanel(Queue waitQueue);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar pelanggan menunggu */

void drawOrderPanel(List orderList);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel daftar order */

void drawFoodPanel(Stack foodStack);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack makanan */

void drawHandPanel(Stack handStack);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel stack di tangan */

void drawTopPanel(Kata name, int money, int life, int time);
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel atas */

void drawBottomPanel();
/* I.S. : Bebas sudah initScreen */
/* F.S. : Digambar panel bawah*/

/* KELOMPOK INPUT */
Kata getInput();
/* I.S. : Bebas sudah initScreen */
/* F.S. : Mengembalikan input user (command), mengembalikan ARROW jika
          yang ditekan adalah arrow key */

Kata ARROW();
/* I,S  : Bebas */
/* F.S. : Mengembalikan kata ARROR, untuk mengecek apakah input merupakan
          arrow key*/





#endif
