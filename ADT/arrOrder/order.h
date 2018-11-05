//File : order.h
/* merupakan tipe data order */

#ifndef ORDER_H
#define ORDER_H

#include "../mesinkata/mesinkata.h"

typedef struct {
  int idMakanan; //indeks makanan
  Kata namaMakanan; //nama makanan sesuai tree makanan
  int noMeja; //nomor meja
} Order;

// Misal : X adalah variabel bertipe Order
#define O_IDMakanan(X) (X).idMakanan
#define O_NamaMakanan(X) (X).namaMakanan
#define O_NoMeja(X) (X).noMeja

Order O_CreateOrder (int idMakanan, Kata namaMakanan, int noMeja);
/* Fungsi membuat tipe order dari parameter */

#endif