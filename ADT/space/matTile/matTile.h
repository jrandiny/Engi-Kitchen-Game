/* ********** Definisi TYPE MatTile dengan indeks dan elemen integer ********** */

#ifndef MATRIKSROOM_H
#define MATRIKSROOM_H

#include "../../../std.h"
#include "../../mesinkata/mesinkata.h"
#include "../tile.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 8
#define KolMin 1
#define KolMax 8

typedef int indeks; /* indeks baris, kolom */

typedef struct {
	Tile Mem[BrsMax+1][KolMax+1];
  int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatTile;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatTile *** */
void MT_MakeMatriks (int NB, int NK, MatTile * M);
/* Membentuk sebuah MatTile "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori MatTile yang dibuat */
/* F.S. MatTile M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define MT_NBrsEff(M) (M).NBrsEff
#define MT_NKolEff(M) (M).NKolEff
#define MT_Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MatTile" *** */
boolean MT_IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk MatTile apa pun */

/* *** Selektor: Untuk sebuah MatTile M yang terdefinisi: *** */
indeks MT_GetFirstIdxBrs (MatTile M);
/* Mengirimkan indeks baris terkecil M */
indeks MT_GetFirstIdxKol (MatTile M);
/* Mengirimkan indeks kolom terkecil M */
indeks MT_GetLastIdxBrs (MatTile M);
/* Mengirimkan indeks baris terbesar M */
indeks MT_GetLastIdxKol (MatTile M);
/* Mengirimkan indeks kolom terbesar M */
boolean MT_IsIdxEff (MatTile M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** Assignment  MatTile ********** */
void MT_CopyMatriks (MatTile MIn, MatTile * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
// void MT_BacaMatTile (MatTile * M, int NB, int NK);
// /* I.S. IsIdxValid(NB,NK) */
// /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
// /* Proses: Melakukan MakeMatTile(M,NB,NK) dan mengisi nilai efektifnya */
// /* Selanjutnya membaca nilai elemen per baris dan kolom */
// /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi MatTile :
// 1 2 3
// 4 5 6
// 8 9 10
// */
// void MT_TulisMatTile (MatTile M);
// /* I.S. M terdefinisi */
// /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
//    dipisahkan sebuah spasi */
// /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
// /* Contoh: menulis MatTile 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10
// */


// /* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatTile ********** */
// boolean MT_EQ (MatTile M1, MatTile M2);
// /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
// /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
// /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
//    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
// boolean MT_NEQ (MatTile M1, MatTile M2);
// /* Mengirimkan true jika M1 tidak sama dengan M2 */

/* ********** Operasi lain ********** */
int MT_NBElmt (MatTile M);
/* Mengirimkan banyaknya elemen M */


#endif
