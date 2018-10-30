//File: space.h
/*merupakan implementasi bentuk lokasi ruangan dengan map dan matriks dan posisi
  pelayan dengan menggunakan point */

#ifndef SPACE_H
#define SPACE_H

#include "../../header/std.h"
#include "../../ADT/matriks/matriks.h"
#include "../../ADT/point/point.h"
#include "../../ADT/listlinier/multilist.h"

typedef struct {
  int ruangan; //nomor ruangan yang sedang digunakan [1..4]
  MATRIKS room1; //data ruangan pertama
  MATRIKS room2; //data ruangan kedua
  MATRIKS room3; //data ruangan ketiga
  MATRIKS room4; //data ruangan keempat/ dapur
  List hubungan; //mapping
} restoran;
//tipe restoran dengan 4 ruangan berukuran 8x8
// dengan terdapat 4 pintu yang menghubungkan keempat ruangan tersebut
/*
  room1 (5,8) -> (2,1) room2
  room1 (8,5) -> (1,5) room4
  room2 (8,5) -> (1,5) room3
  room3 (2,1) -> (5,8) room4
*/

#define Ruangan(R) (R).ruangan
#define Room1(R) (R).room1
#define Room2(R) (R).room2
#define Room3(R) (R).room3
#define Room4(R) (R).room4

typedef struct {
  Point posisi; //posisi pelayan mengikuti baris dan kolom matriks
  char up;      // menyatakan karakter di posisi atas pelayan
  char down;    // menyatakan karakter di posisi bawah pelayan
  char left;    // menyatakan karakter di posisi kiri pelayan
  char right;   // menyatakan karakter di posisi kanan pelayan
} pelayan;
//merupakan tipe pelayan dengan posisi dan karakter disekitarnya


/* up down left right akan bernilai
    '' kosong jika dia lantai kosong
    x jika bangku kosong
    c jika ada pelanggan
    m jika meja
    t jika nampan
    '\0' jika dekat pintu atau tembok
*/
// *** SELEKTOR ***
#define Posisi(P) (P).posisi
#define Up(P) (P).up
#define Down(P) (P).down
#define Left(P) (P).left
#define Right(P) (P).right

// *** KONSTRUKTOR ***
void InitPelayan(pelayan *P);
/* membuat pelayan baru
  I.S. Sembarang
  F.S. terbentuk pelayan dengan posisi di 1,1 dan karakter lain '\0' */
void PlacePelayan(pelayan *P,float x,float y, restoran R);
/*
  menaruh pelayan di posisi (x,y) di ruangan di restoran r
  I.S. pelayan,x,y,R terdefinisi
  F.S. pelayan terletak di posisi x,y di ruangan di R
*/
void InitRuangan(restoran *R);
/*
  menyiapkan ruangan kosong dan menghubungkan semua ruangan
  I.S. R Sembarang
  F.S. setiap room terisi karakter kosong, lokasi pusat meja sudah ada nomornya
      ruangan berniali 0
      hubungan telah menghubungkan semua ruangan.
*/

// *** PINDAH ***
void MoveUp(pelayan *P,restoran R);
/*
  I.S. pelayan dan restoran terdifinsi, pelayan masih dapat naik
  F.S. pelayan pindah ke posisi di atasnya dan update semua karakter
*/
void MoveDown(pelayan *P,restoran R);
/*
  I.S. pelayan dan restoran terdifinsi, pelayan masih dapat turun
  F.S. pelayan pindah ke posisi di bawahnya dan update semua karakter
*/
void MoveLeft(pelayan *P,restoran R);
/*
  I.S. pelayan dan restoran terdifinsi, pelayan masih dapat bergerak ke kiri
  F.S. pelayan pindah ke posisi di kirinya dan update semua karakter
*/
void MoveRight(pelayan *P,restoran R);
/*
  I.S. pelayan dan restoran terdifinsi, pelayan masih dapat bergerak ke kanan
  F.S. pelayan pindah ke posisi di kanannya dan update semua karakter
*/

// *** RUANGAN ***
void IsiRuang(restoran *R, int ruangan, MATRIKS M);
/*
  I.S. R sudah terdeinisi, ruangan dan M juga terdefinisi
  F.S. room ke-(ruangan) di set menjadi seperti M
*/
void PlaceTable(restoran *R,int nomorMeja, int jumlahBangku);
/*
  I.S. R, nomorMeja, dan jumlahBangku terdefinisi, nomoMeja antara 1-12
       jumlahBangku antara 2 atau 4
  F.S. meja dengan nomor nomorMeja terdapat bangku kosong sejumlah jumlahBangku
*/

// *** LAIN LAIN ***
int GetTableNumber(pelayan P, restoran R);
/*
  mengembalikan nilai meja yang bersebelahan dengan pelayan
  di sebelah pelayan hanya ada satu pelanggan atau 2 pelanggan dari meja yang sama
*/
void Placing(int pelanggan,pelayan P, restoran *R);
/*
  I.S. pelanggan, pelayan, retoran terdefinisi, meja sebelah pelayan adalah kosong
  F.S. pelanggan di tempat di meja sesuai jumlahnya
*/

#endif
