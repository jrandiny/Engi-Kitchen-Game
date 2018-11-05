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

#define O_IDMakanan(O) (O).idMakanan
#define O_NamaMakanan(O) (O).namaMakanan
#define O_NoMeja(O) (O).noMeja

Order O_CreateOrder (int idMakanan, Kata namaMakanan, int noMeja);
/* 
Fungsi membuat tipe order dari parameter
*/

#endif