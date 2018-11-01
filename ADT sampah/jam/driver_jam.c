/* Kelompok  : UAS
   Nama file : driver_jam.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : driver untuk ADT tipe Jam*/

#include "jam.h"

int main() {
	/* Kamus driver_jam */
	Jam j1, j2;
	long detik;
	int n;

	/* Algoritma driver_jam */

	// baca tulis jam
	printf("Masukkan jam pertama : ");
	J_BacaJam(&j1);
	J_TulisJam(j1);
	printf("\n");
	printf("Masukkan jam kedua : ");
	J_BacaJam(&j2);
	J_TulisJam(j2);
	printf("\n");

	// konversi detik ke jam
	printf("Masukkan detik : ");
	scanf("%ld", &detik);
	printf("Hasil konversi ke jam : ");
	J_TulisJam(J_DetikToJam(detik));
	printf("\n");

	// operator relasional
	printf("Hasil cek JEQ : ");
	if (J_JEQ(j1,j2)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}
	printf("Hasil cek JNEQ : ");
	if (J_JNEQ(j1,j2)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}
	printf("Hasil cek JLT : ");
	if (J_JLT(j1,j2)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}
	printf("Hasil cek JGT : ");
	if (J_JGT(j1,j2)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}

	// operator aritmatika

	// tes J_NextDetik
	printf("satu detik setelah "); J_TulisJam(j1); printf(" adalah "); J_TulisJam(J_NextDetik(j1));
	printf("\n");

	// tes J_NextNDetik
	printf("masukkan n (detik) : ");
	scanf("%d", &n);
	printf("%d detik setelah ", n); J_TulisJam(j1); printf(" adalah "); J_TulisJam(J_NextNDetik(j1,n));
	printf("\n");

	//tes J_PrevDetik
	printf("satu detik sebelum "); J_TulisJam(j1); printf(" adalah "); J_TulisJam(J_PrevDetik(j1));
	printf("\n");

	// tes J_PrevNDetik
	printf("masukkan n (detik) : ");
	scanf("%d", &n);
	printf("%d detik sebelum ", n); J_TulisJam(j1); printf(" adalah "); J_TulisJam(J_PrevNDetik(j1, n));
	printf("\n");

	// tes J_Durasi
	printf("perbedaan antara jam "); J_TulisJam(j1); printf(" dan jam "); J_TulisJam(j2); printf(" adalah %ld detik atau ", J_Durasi(j1,j2)); J_TulisJam(J_DetikToJam(J_Durasi(j1,j2)));
	printf("\n");

	return 0;
}
