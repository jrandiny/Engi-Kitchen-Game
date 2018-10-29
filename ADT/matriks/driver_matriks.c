/* Kelompok  : UAS
   Nama file : driver_matriks.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 27-10-2018
   Deskripsi : driver untuk ADT tipe Matriks*/

#include "matriks.h"

int main () {
	// Kamus driver_matriks
	Matriks M1,M2,MCopy;
	int menu;
	indeks NB,NK,IdxBrs,IdxKol;

	// Algoritma driver_matriks
	printf("MENU :\n");
	printf("1. M_IsIdxValid\n");
	printf("2. M_GetFirstIdxBrs\n");
	printf("3. M_GetFirstIdxKol\n");
	printf("4. M_GetLastIdxBrs\n");
	printf("5. M_GetLastIdxKol\n");
	printf("6. M_IsIdxEff\n");
	printf("7. M_CopyMatriks\n");
	printf("8. M_EQ\n");
	printf("9. M_NEQ\n");
	printf("10. M_NBElmt\n");

	printf("Masukkan pilihan menu : ");
	scanf("%d", &menu);

	printf("Input matriks M1\n");
	printf("Masukkan NB matriks : ");
	scanf("%d", &NB);
	printf("Masukkan NK matriks : ");
	scanf("%d", &NK);
	M_BacaMatriks(&M1,NB,NK);

	switch (menu) {
		case 1 :
		{
			printf("Masukkan indeks :");
			scanf("%d %d", &IdxBrs, &IdxKol);
			if (M_IsIdxValid(IdxBrs,IdxKol)){
				printf("VALID");
			} else {
				printf("TIDAK VALID");
			}
			printf("\n");
		}
		break;
		case 2 :
		{
			printf("Indeks baris pertama matriks M1 : %d", M_GetFirstIdxBrs(M1));
			printf("\n");
		}
		break;
		case 3 :
		{
			printf("Indeks kolom pertama matriks M1 : %d", M_GetFirstIdxKol(M1));
			printf("\n");
		}
		break;
		case 4 :
		{
			printf("Indeks baris terakhir matriks M1 : %d", M_GetLastIdxBrs(M1));
			printf("\n");
		}
		break;
		case 5 :
		{
			printf("Indeks kolom terakhir matriks M1 : %d", M_GetLastIdxKol(M1));
			printf("\n");
		}
		break;
		case 6 :
		{
			printf("Masukkan indeks :");
			scanf("%d %d", &IdxBrs, &IdxKol);
			if (M_IsIdxEff(M1,IdxBrs,IdxKol)){
				printf("TRUE");
			} else {
				printf("FALSE");
			}
			printf("\n");
		}
		break;

		case 7 :
		{
			printf("Salinan matriks M1 : \n");
			M_CopyMatriks(M1,&MCopy);
			M_TulisMatriks(MCopy);
		}
		break;

		case 8 :
		{
			printf("Input matriks M2");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMatriks(&M2,NB,NK);
			if (M_EQ(M1,M2)) {
				printf("EQUAL");
			} else {
				printf("NOT EQUAL");
			}
		}
		break ;
		case 9 :
		{
			printf("Input matriks M2");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMatriks(&M2,NB,NK);
			if (M_NEQ(M1,M2)) {
				printf("NOT EQUAL");
			} else {
				printf("EQUAL");
			}
		}
		break;

		case 10 :
		{
			printf("jumlah elemen matriks M1 : %d", M_NBElmt(M1));
		}
		break;

	};
	return 0;
}
