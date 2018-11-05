#include "food.h"

Food F_CreateFood(int id, Kata nama, int harga)
/* Dikembalikan tipe food baru dari id, nama, dan harga terdefinisi */
{
  /* KAMUS LOKAL */
  Food ftemp;

  /* ALGORITMA */
  IDMakanan(ftemp) = id;
  NamaMakanan(ftemp) = nama;
  Harga(ftemp) = harga;

  return ftemp;
}
