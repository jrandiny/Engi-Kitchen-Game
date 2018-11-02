/* File: mesinkar.h */
/* Definisi Mesin Karakter */
/* Kelompok  : UAS
   Nama file : mesinkar.h
   Topik     : Tugas Besar Alstrukdat
   Tanggal   : 25 Oktober 2018
   Deskripsi : Implementasi mesin kata*/

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../std.h"

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

void K_START(char* namafile, int *status);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita
          Jika CC != MARK maka EOP akan padam (false)
          Jika CC = MARK maka EOP akan menyala (true) */

void K_ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK
          Jika  CC = MARK maka EOP akan menyala (true) */

#endif
