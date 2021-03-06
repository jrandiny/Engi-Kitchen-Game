/* File: mesinkar.c */
/* Implementasi Mesin Karakter */
/* Kelompok  : UAS
   Nama file : mesinkar.c
   Deskripsi : Implementasi mesin karakter*/

#include "mesinkar.h"

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void K_START(char* namafile,int* status) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka EOP akan padam (false).
          Jika CC = MARK maka EOP akan menyala (true)
          status 1 jika file ada, 0 jika tidak ada*/


	/* Algoritma */
	pita = fopen(namafile,"r");
      if(pita!=Nil){
            *status=1;
            K_ADV();
      }else{
            *status=0;
      }

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
