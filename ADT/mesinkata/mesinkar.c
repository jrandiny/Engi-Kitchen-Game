K_ADV/* File: mesinkar.c */
/* Implementasi Mesin Karakter */
/* Kelompok  : UAS
   Nama file : mesinkar.c
   Topik     : Tugas Besar Alstrukdat
   Tanggal   : 25 Oktober 2018
   Deskripsi : Implementasi mesin kata*/

#include "mesinkar.h"

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void K_START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	pita = fopen("pitakar.txt","r");
	K_ADV();
}

void K_ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela =
          CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama,
          CC mungkin = MARK.
		  Jika  CC = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == MARK);
	if (EOP) {
       fclose(pita);
 	}
}