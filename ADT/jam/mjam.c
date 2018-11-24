/* Kelompok  : UAS
   Nama file : mjam.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : driver untuk ADT tipe Jam*/

 #include "jam.h"

int main (){

  /* Kamus */
  Jam j1;

  /* Algoritma */

  // baca tulis jam
	printf("Masukkan jam : ");
	J_BacaJam(&j1);
	J_TulisJam(j1);
	printf("\n");

  return 0;
}
