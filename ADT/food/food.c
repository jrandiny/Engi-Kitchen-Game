#include "food.h"

Food F_CreateFood(int id, Kata nama, int harga)
/* Dikembalikan tipe food baru dari id, nama, dan harga terdefinisi */
{
  /* KAMUS LOKAL */
  Food ftemp;

  /* ALGORITMA */
  F_IDMakanan(ftemp) = id;
  F_NamaMakanan(ftemp) = nama;
  F_Harga(ftemp) = harga;

  return ftemp;
}
