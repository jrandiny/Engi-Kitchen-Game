/* Kelompok  : UAS
   Nama file : driver_matriks.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 27-10-2018
   Deskripsi : driver untuk ADT tipe MATRIKS*/

#include "matriks.h"

int main () {
	// Kamus driver_matriks
	MATRIKS M1,M2,MCopy;
	int menu;
	indeks NB,NK,IdxBrs,IdxKol,IdxDiag;
	ElType konstanta;
	
	// Algoritma driver_matriks
	printf("MENU :\n");
	printf("1. M_IsIdxValid\n");
	printf("2. M_GetFirstIdxBrs\n");
	printf("3. M_GetFirstIdxKol\n");
	printf("4. M_GetLastIdxBrs\n");
	printf("5. M_GetLastIdxKol\n");
	printf("6. M_IsIdxEff\n");
	printf("7. M_GetElmtDiagonal\n");
	printf("8. M_CopyMATRIKS\n");
	printf("9. M_TambahMATRIKS\n");
	printf("10. M_KurangMATRIKS\n");
	printf("11. M_KaliMATRIKS\n");
	printf("12. fungsi M_KaliKons\n");
	printf("13. prosedur M_PKaliKons\n");
	printf("14. M_EQ\n");
	printf("15. M_NEQ\n");
	printf("16. M_EQSize\n");
	printf("17. M_NBElmt\n");
	printf("18. M_IsBujurSangkar\n");
	printf("19. M_IsSimetri\n");
	printf("20. M_IsSatuan\n");
	printf("21. M_IsSparse\n");
	printf("22. M_Inverse1\n");
	printf("23. M_Determinan\n");
	printf("24. M_PInverse1\n");
	printf("25. M_Transpose\n");
	
	printf("Masukkan pilihan menu : ");
	scanf("%d", &menu);
	
	printf("Input matriks M1\n");
	printf("Masukkan NB matriks : ");
	scanf("%d", &NB);
	printf("Masukkan NK matriks : ");
	scanf("%d", &NK);
	M_BacaMATRIKS(&M1,NB,NK);
	
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
			printf("Masukkan indeks :");
			scanf("%d", &IdxDiag);
			printf("Elemen diagonal matriks M1 indeks %d adalah %d", IdxDiag, M_GetElmtDiagonal(M1,IdxDiag));
			printf("\n");
		}
		break;
		case 8 :
		{
			printf("Salinan matriks M1 : \n");
			M_CopyMATRIKS(M1,&MCopy);
			M_TulisMATRIKS(MCopy);
		}
		break;
		case 9 :
		{
			printf("Input matriks M2\n");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMATRIKS(&M2,NB,NK);
			printf("M1 + M2 = \n");
			M_TulisMATRIKS(M_TambahMATRIKS(M1,M2));
		}
		break;
		case 10 :
		{
			printf("Input matriks M2\n");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMATRIKS(&M2,NB,NK);
			printf("M1 - M2 = \n");
			M_TulisMATRIKS(M_KurangMATRIKS(M1,M2));
		}
		break;
		case 11 :
		{
			printf("Input matriks M2\n");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMATRIKS(&M2,NB,NK);
			printf("M1 * M2 = \n");
			M_TulisMATRIKS(M_KaliMATRIKS(M1,M2));
		}
		break;
		case 12 :
		{
			printf("Masukkan nilai konstanta :");
			scanf("%d", &konstanta);
			printf("M1 * konstanta = \n");
			M_TulisMATRIKS(M_KaliKons(M1,konstanta));
		}
		break;
		case 13 :
		{
			printf("Masukkan nilai konstanta :");
			scanf("%d", &konstanta);
			printf("M1 * konstanta = \n");
			M_PKaliKons(&M1, konstanta);
			M_TulisMATRIKS(M1);
		}
		break;
		case 14 :
		{
			printf("Input matriks M2");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMATRIKS(&M2,NB,NK);
			if (M_EQ(M1,M2)) {
				printf("EQUAL");
			} else {
				printf("NOT EQUAL");
			}
		}
		break ;
		case 15 :
		{
			printf("Input matriks M2");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMATRIKS(&M2,NB,NK);
			if (M_NEQ(M1,M2)) {
				printf("NOT EQUAL");
			} else {
				printf("EQUAL");
			}
		}
		break;
		case 16 :
		{
			printf("Input matriks M2");
			printf("Masukkan NB matriks : ");
			scanf("%d", &NB);
			printf("Masukkan NK matriks : ");
			scanf("%d", &NK);
			M_BacaMATRIKS(&M2,NB,NK);
			if (M_EQSize(M1,M2)) {
				printf("EQUAL IN SIZE");
			} else {
				printf("NOT EQUAL SIZE");
			}
		}
		break;
		case 17 :
		{
			printf("jumlah elemen matriks M1 : %d", M_NBElmt(M1));
		}
		break;
		case 18 :
		{
			if (M_IsBujurSangkar(M1)) {
				printf("M1 adalah matriks bujur sangkar");
			} else {
				printf("M1 bukan matriks bujur sangkar");
			}
		}
		break;
		case 19 :
		{
			if (M_IsSimetri(M1)) {
				printf("M1 adalah matriks simetri");
			} else {
				printf("M1 bukan matriks simetri");
			}
		}
		break;
		case 20 :
		{
			if (M_IsSatuan(M1)) {
				printf("M1 adalah matriks satuan");
			} else {
				printf("M1 bukan matriks satuan");
			}
		}
		break;
		case 21 :
		{
			if (M_IsSparse(M1)) {
				printf("M1 adalah matriks sparse");
			} else {
				printf("M1 bukan matriks sparse");
			}
		}
		break;
		case 22 :
		{
			printf("Invers matriks M1 : \n");
			M_TulisMATRIKS(M_Inverse1(M1));
		}
		break;
		case 23 :
		{
			printf("Determinan matriks M1 : %.2f", M_Determinan(M1));
		}
		break;
		case 24 :
		{
			printf("Invers matriks M1 : \n");
			M_PInverse1(&M1);
			M_TulisMATRIKS(M1);
		}
		break;
		case 25 :
		{
			printf("Transpose matriks M1 : \n");
			M_Transpose(&M1);
			M_TulisMATRIKS(M1);
		}
		break;
	};
	return 0;
}
