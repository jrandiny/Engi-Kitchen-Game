/* Kelompok : UAS
   Nama File : jam.h
   Deskripsi : ADT untuk tipe jam */


#ifndef JAM_H
#define JAM_H

#include "../../std.h"

/* *** Definisi TYPE Jam <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} Jam;

/* *** Notasi Akses: selektor Jam *** */
#define J_Hour(J) (J).HH
#define J_Minute(J) (J).MM
#define J_Second(J) (J).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean J_IsJamValid (int H, int M, int S);
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
 /* *** Konstruktor: Membentuk sebuah Jam dari komponen-komponennya *** */
Jam J_MakeJam (int HH, int MM, int SS);
/* Membentuk sebuah Jam dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk Jam */
 /* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void J_BacaJam (Jam * J);
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika Jam tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk Jam <1,3,4> */
 void J_TulisJam (Jam J);
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/


#endif
