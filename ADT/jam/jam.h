/* File	  : jam.h */
/* Tanggal: 26 Oktober 2018 */
/* Definisi ADT JAM */

#ifndef JAM_H
#define JAM_H

#include "../../std.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define J_Hour(J) (J).HH
#define J_Minute(J) (J).MM
#define J_Second(J) (J).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean J_IsJAMValid (int H, int M, int S);
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM J_MakeJAM (int HH, int MM, int SS);
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void J_BacaJAM (JAM * J);
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

void J_TulisJAM (JAM J);
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long J_JAMToDetik (JAM J);
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM J_DetikToJAM (long N);
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean J_JEQ (JAM J1, JAM J2);
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean J_JNEQ (JAM J1, JAM J2);
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean J_JLT (JAM J1, JAM J2);
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean J_JGT (JAM J1, JAM J2);
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM J_NextDetik (JAM J);
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM J_NextNDetik (JAM J, int N);
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM J_PrevDetik (JAM J);
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM J_PrevNDetik (JAM J, int N);
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
long J_Durasi (JAM JAw, JAM JAkh);
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */

#endif
