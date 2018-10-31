/* ********** Definisi TYPE Matriks dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "../../header/std.h"
#include "../mesinkata/mesinkata.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 8
#define KolMin 1
#define KolMax 8

typedef int indeks; /* indeks baris, kolom */
typedef struct {
	char karakter; //merupakan karakter yang ditampilkan di layar
	int value;
	/* angka kesabaran untuk pengunjung duduk, ValUndeff untuk tile, nomor meja
	dan nampan, id makanan untuk meja di dapur
	*/
	Kata deskripsi; //berisi nama makanan|| customer|| nomor meja|| lantai|| nampan
} Tile;
/*
	karakter bernilai
		' '(spasi) kosong jika dia lantai kosong
		x jika bangku kosong
		c jika ada pelanggan
		m jika meja
		2||4 jika nomor meja
		t jika nampan
		CharUndeff jika dekat pintu atau tembok
	value bernilai (bergantung karakter)
		waktu keluar pelanggan
		id makanan
		[1..12] jika nomor meja
		ValUndeff untuk sisanya
	Deskripsi bernilai (bergantung karakter)
		"-" jika lantai, pintu, atau tembok
		nama makanan berdasarkan id makanan untuk meja makanan
		makanan pilihan customer jika pelanggan
		isi||kosong jika nomor meja
		nampan jika karakter==t
*/

typedef struct {
	Tile Mem[BrsMax+1][KolMax+1];
  int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matriks;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void M_MakeMatriks (int NB, int NK, Matriks * M);
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define M_NBrsEff(M) (M).NBrsEff
#define M_NKolEff(M) (M).NKolEff
#define M_Elmt(M,i,j) (M).Mem[(i)][(j)]

#define Karakter(M) (M).karakter
#define Value(M) (M).value
#define Deskripsi(M) (M).deskripsi

/* *** Selektor "DUNIA Matriks" *** */
boolean M_IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks M_GetFirstIdxBrs (Matriks M);
/* Mengirimkan indeks baris terkecil M */
indeks M_GetFirstIdxKol (Matriks M);
/* Mengirimkan indeks kolom terkecil M */
indeks M_GetLastIdxBrs (Matriks M);
/* Mengirimkan indeks baris terbesar M */
indeks M_GetLastIdxKol (Matriks M);
/* Mengirimkan indeks kolom terbesar M */
boolean M_IsIdxEff (Matriks M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

/* ********** Assignment  Matriks ********** */
void M_CopyMatriks (Matriks MIn, Matriks * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
// void M_BacaMatriks (Matriks * M, int NB, int NK);
// /* I.S. IsIdxValid(NB,NK) */
// /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
// /* Proses: Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
// /* Selanjutnya membaca nilai elemen per baris dan kolom */
// /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
// 1 2 3
// 4 5 6
// 8 9 10
// */
// void M_TulisMatriks (Matriks M);
// /* I.S. M terdefinisi */
// /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
//    dipisahkan sebuah spasi */
// /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
// /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10
// */


// /* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matriks ********** */
// boolean M_EQ (Matriks M1, Matriks M2);
// /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
// /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
// /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
//    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
// boolean M_NEQ (Matriks M1, Matriks M2);
// /* Mengirimkan true jika M1 tidak sama dengan M2 */

/* ********** Operasi lain ********** */
int M_NBElmt (Matriks M);
/* Mengirimkan banyaknya elemen M */


#endif
