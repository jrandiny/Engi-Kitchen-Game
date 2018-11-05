//File : food.h
/* merupakan tipe data restoran */

#ifndef FOOD_H
#define FOOD_H

#include "../mesinkata/mesinkata.h"

typedef struct {
  int idMakanan; //indeks makanan
  Kata namaMakanan; //nama makanan sesuai tree makanan
  int harga; //harga makanan
} Food;

#define IDMakanan(F) (F).idMakanan
#define NamaMakanan(F) (F).namaMakanan
#define Harga(F) (F).harga

#endif