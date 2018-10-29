/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../../header/std.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 8
#define KolMin 1
#define KolMax 8

typedef int indeks; /* indeks baris, kolom */
typedef char ElType;
typedef struct {
	ElType Mem[BrsMax+1][KolMax+1];
  int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void M_MakeMATRIKS (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define M_NBrsEff(M) (M).NBrsEff
#define M_NKolEff(M) (M).NKolEff
#define M_Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean M_IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks M_GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks M_GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks M_GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks M_GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean M_IsIdxEff (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** Assignment  MATRIKS ********** */
void M_CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void M_BacaMATRIKS (MATRIKS * M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void M_TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean M_EQ (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean M_NEQ (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 tidak sama dengan M2 */

/* ********** Operasi lain ********** */
int M_NBElmt (MATRIKS M);
/* Mengirimkan banyaknya elemen M */


#endif
