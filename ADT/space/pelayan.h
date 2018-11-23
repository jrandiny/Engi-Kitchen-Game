/* Kelompok  : UAS
   Nama file : pelayan.h
   Deskripsi : ADT untuk tipe pelayan */
/* merupakan tipe data pelayan */

#ifndef PELAYAN_H
#define PELAYAN_H

#include "../point/point.h"
#include "matTile/matTile.h"

/* merupakan tipe Pelayan dengan posisi dan karakter disekitarnya */

/* Definisi struktur */
typedef struct {
  Point posisi; /* posisi Pelayan mengikuti baris dan kolom matriks */
  Tile up;      /* menyatakan Tile di posisi atas Pelayan */
  Tile down;    /* menyatakan Tile di posisi bawah Pelayan */
  Tile left;    /* menyatakan Tile di posisi kiri Pelayan */
  Tile right;   /* menyatakan Tile di posisi kanan Pelayan */
} Pelayan;


/* up down left right akan bernilai
    sesuai dengan definisi Tile di matRoom.h
*/
/* *** SELEKTOR *** */
#define Pelayan_Posisi(P) (P).posisi
#define Up(P) (P).up
#define Down(P) (P).down
#define Left(P) (P).left
#define Right(P) (P).right

#endif
