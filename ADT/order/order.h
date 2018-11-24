/* Kelompok  : UAS
   Nama file : order.h
   Deskripsi : ADT untuk tipe order makanan */


#ifndef ORDER_H
#define ORDER_H

#include "../mesinkata/mesinkata.h"

typedef struct {
  int idMakanan; /* ID makanan pada order*/
  Kata namaMakanan; /* Nama makanan */
  int noMeja; /* Nomor meja order */
} Order;

/* Misal : X adalah variabel bertipe Order */
#define O_IDMakanan(X) (X).idMakanan
#define O_NamaMakanan(X) (X).namaMakanan
#define O_NoMeja(X) (X).noMeja

Order O_CreateOrder (int idMakanan, Kata namaMakanan, int noMeja);
/* Fungsi membuat tipe order dari parameter */

#endif
