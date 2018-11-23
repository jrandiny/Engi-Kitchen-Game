/* Kelompok : UAS
   Nama File : food.h
   Deskripsi : ADT untuk tipe food */

#ifndef FOOD_H
#define FOOD_H

#include "../mesinkata/mesinkata.h"

/* Definisi struktur */
typedef struct {
  int idMakanan;    /* indeks makanan */
  Kata namaMakanan; /* nama makanan sesuai tree makanan */
  int harga;        /* harga makanan */
}Food;

/* SELEKTOR */
#define F_IDMakanan(F) (F).idMakanan
#define F_NamaMakanan(F) (F).namaMakanan
#define F_Harga(F) (F).harga

Food F_CreateFood(int id, Kata nama, int harga);
/* Dikembalikan tipe food baru dari id, nama, dan harga terdefinisi */

#endif
