/* Kelompok  : UAS
   Nama file : driver_matriks.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 27-10-2018
   Deskripsi : driver untuk ADT tipe Matriks*/

#include "matTile.h"

int main () {
	// Kamus driver_matriks
	MatTile M1,M2,MCopy;
	int menu;
	indeks NB,NK,IdxBrs,IdxKol;

	printf("Input matriks M1\n");
	printf("Masukkan NB matriks : ");
	scanf("%d", &NB);
	printf("Masukkan NK matriks : ");
	scanf("%d", &NK);
	MT_BacaMatriks(&M1,NB,NK);

	// Algoritma driver_matriks
	while(true) {
		MT_TulisMatriks(M1);
		printf("\nMENU :\n");
		printf("1. MT_IsIdxValid\n");
		printf("2. MT_GetFirstIdxBrs\n");
		printf("3. MT_GetFirstIdxKol\n");
		printf("4. MT_GetLastIdxBrs\n");
		printf("5. MT_GetLastIdxKol\n");
		printf("6. MT_IsIdxEff\n");
		printf("7. MT_CopyMatriks\n");
		printf("8. MT_NBElmt\n");

		printf("Masukkan pilihan menu : ");
		scanf("%d", &menu);

		switch (menu) {
			case 1 :
			{
				printf("Masukkan indeks :");
				scanf("%d %d", &IdxBrs, &IdxKol);
				if (MT_IsIdxValid(IdxBrs,IdxKol)){
					printf("VALID");
				} else {
					printf("TIDAK VALID");
				}
				printf("\n");
			}
			break;
			case 2 :
			{
				printf("Indeks baris pertama matriks M1 : %d", MT_GetFirstIdxBrs(M1));
				printf("\n");
			}
			break;
			case 3 :
			{
				printf("Indeks kolom pertama matriks M1 : %d", MT_GetFirstIdxKol(M1));
				printf("\n");
			}
			break;
			case 4 :
			{
				printf("Indeks baris terakhir matriks M1 : %d", MT_GetLastIdxBrs(M1));
				printf("\n");
			}
			break;
			case 5 :
			{
				printf("Indeks kolom terakhir matriks M1 : %d", MT_GetLastIdxKol(M1));
				printf("\n");
			}
			break;
			case 6 :
			{
				printf("Masukkan indeks :");
				scanf("%d %d", &IdxBrs, &IdxKol);
				if (MT_IsIdxEff(M1,IdxBrs,IdxKol)){
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
				MT_CopyMatriks(M1,&MCopy);
				MT_TulisMatriks(MCopy);
			}
			break;

			case 8 :
			{
				printf("jumlah elemen matriks M1 : %d\n", MT_NBElmt(M1));
			}
			break;

		};
	}

	return 0;
}
