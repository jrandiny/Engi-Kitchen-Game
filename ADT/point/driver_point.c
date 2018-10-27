/* Kelompok  : UAS
   Nama file : driver_point.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : driver untuk ADT tipe POINT*/

#include "point.h"

int main () {
	/* Kamus driver_point */
	POINT p1,p2,psalin1,psalin2;
	int menu;
	float deltaX, deltaY, sudut;
	char sumbu;
	boolean SbX;
	
	/* Algoritma driver_point */
	// baca tulis point
	printf("Masukkan point pertama : ");
	P_BacaPOINT(&p1);
	P_TulisPOINT(p1);
	printf("\n");
	printf("Masukkan point kedua : ");
	P_BacaPOINT(&p2);
	P_TulisPOINT(p1);
	printf("\n");
	
	printf("MENU :\n");
	printf("1. Cek EQ\n");
	printf("2. Cek NEQ\n");
	printf("3. Cek IsOrigin\n");
	printf("4. Cek IsOnSbX\n");
	printf("5. Cek IsOnSbY\n");
	printf("6. Kuadran point\n");
	printf("7. NextX point\n");
	printf("8. NextY point\n");
	printf("9. PlusDelta\n");
	printf("10. MirrorOf\n");
	printf("11. Jarak ke titik O\n");
	printf("12. Panjang garis antara point p1 dan p2\n");
	printf("13. Geser point sejauh delta\n");
	printf("14. GeserKeSbX\n");
	printf("15. GeserKeSbY\n");
	printf("16. Mirror\n");
	printf("17. Putar\n");
	
	printf("Mau yang mana? \n");
	printf("Masukkan pilihan menu : ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1 :
			if (P_EQ(p1,p2)) {
				printf("EQ = TRUE\n");
			} else {
				printf("EQ = FALSE\n");
			}
		break;
		case 2 :
			if (P_NEQ(p1,p2)) {
				printf("NEQ = TRUE\n");
			} else {
				printf("NEQ = FALSE\n");
			}
		break;
		case 3 :
		{
			if (P_IsOrigin(p1)) {
				P_TulisPOINT(p1); printf("berada di titik origin.");
			} else {
				P_TulisPOINT(p1); printf("bukan di titik origin.");
			}
			printf("\n");
			if (P_IsOrigin(p2)) {
				P_TulisPOINT(p2); printf("berada di titik origin.");
			} else {
				P_TulisPOINT(p2); printf("bukan di titik origin.");
			}
			printf("\n");
		}
		break;
		case 4 :
		{
			if (P_IsOnSbX(p1)) {
				P_TulisPOINT(p1); printf("berada di sumbu X.");
			} else {
				P_TulisPOINT(p1); printf("bukan di sumbu X.");
			}
			printf("\n");
			if (P_IsOnSbY(p2)) {
				P_TulisPOINT(p2); printf("berada di sumbu X.");
			} else {
				P_TulisPOINT(p2); printf("bukan di sumbu X");
			}
			printf("\n");
		}
		break;
		case 5 :
		{
			if (P_IsOnSbY(p1)) {
				P_TulisPOINT(p1); printf("berada di sumbu Y.");
			} else {
				P_TulisPOINT(p1); printf("bukan di sumbu Y.");
			}
			printf("\n");
			if (P_IsOnSbY(p2)) {
				P_TulisPOINT(p2); printf("berada di sumbu Y.");
			} else {
				P_TulisPOINT(p2); printf("bukan di sumbu Y.");
			}
			printf("\n");
		}
		break;
		case 6 :
		{
			P_TulisPOINT(p1); printf("berada di kuadran %d.", P_Kuadran(p1));
			printf("\n");
			P_TulisPOINT(p2); printf("berada di kuadran %d.", P_Kuadran(p2));
			printf("\n");
		}
		break;
		case 7 :
		{
			printf("NextX "); P_TulisPOINT(p1); printf(" adalah "); P_TulisPOINT(P_NextX(p1));
			printf("\n");
			printf("NextX "); P_TulisPOINT(p2); printf(" adalah "); P_TulisPOINT(P_NextX(p2));
			printf("\n");
		}
		break;
		case 8 :
		{
			printf("NextY "); P_TulisPOINT(p1); printf(" adalah "); P_TulisPOINT(P_NextY(p1));
			printf("\n");
			printf("NextY "); P_TulisPOINT(p2); printf(" adalah "); P_TulisPOINT(P_NextY(p2));
			printf("\n");
		}
		break;
		case 9 :
		{
			printf("Masukkan deltaX : ");
			scanf("%f", &deltaX);
			printf("Masukkan deltaY : ");
			scanf("%f", &deltaY);
			printf("PlusDelta : "); P_TulisPOINT(p1); printf(" adalah "); P_TulisPOINT(P_PlusDelta(p1,deltaX,deltaY));
			printf("\n");
			printf("PlusDelta : "); P_TulisPOINT(p1); printf(" adalah "); P_TulisPOINT(P_PlusDelta(p2,deltaX,deltaY));
			printf("\n");
		}
		break;
		case 10 :
		{ 
			printf("Mirror terhadap sumbu : ");
			scanf("%c", &sumbu);
			if (sumbu = 'X') {
				SbX = true;
			} else {
				SbX = false;
			}
			printf("Mirror "); P_TulisPOINT(p1); printf(" terhadap sumbu %c", sumbu); printf(" adalah "); P_TulisPOINT(P_MirrorOf(p1,SbX));
			printf("\n");
			printf("Mirror "); P_TulisPOINT(p2); printf(" terhadap sumbu %c", sumbu); printf(" adalah "); P_TulisPOINT(P_MirrorOf(p2,SbX));
			printf("\n");
		}
		break;
		case 11 :
		{
			printf("Jarak titik "); P_TulisPOINT(p1); printf(" ke titik O adalah %.2f", P_Jarak0(p1));
			printf("\n");
			printf("Jarak titik "); P_TulisPOINT(p2); printf(" ke titik O adalah %.2f", P_Jarak0(p2));
			printf("\n");
		}
		break;
		case 12 :
		{
			printf("panjang garis antara "); P_TulisPOINT(p1); printf(" dan "); P_TulisPOINT(p2); printf(" adalah %.2f", P_Panjang(p1,p2));
			printf("\n");
		}
		break;
		case 13 :
		{
			printf("Masukkan deltaX geser : ");
			scanf("%f", &deltaX);
			printf("Masukkan deltaY geser : ");
			scanf("%f", &deltaY);
			P_TulisPOINT(p1); printf(" digeser sejauh delta : "); P_Geser(&p1,deltaX,deltaY); P_TulisPOINT(p1);
			printf("\n");
			P_TulisPOINT(p2); printf(" digeser sejauh delta : "); P_Geser(&p2,deltaX,deltaY); P_TulisPOINT(p2);
			printf("\n");
		}
		break;
		case 14 :
		{
			P_GeserKeSbX(&p1);
			P_TulisPOINT(p1);
			printf("\n");
			P_GeserKeSbX(&p2);
			P_TulisPOINT(p2);
			printf("\n");
		}
		break;
		case 15 :
		{
			P_GeserKeSbY(&p1);
			P_TulisPOINT(p1);
			printf("\n");
			P_GeserKeSbY(&p2);
			P_TulisPOINT(p2);
			printf("\n");
		}
		break;
		case 16 :
		{
			printf("Mirror terhadap sumbu : ");
			scanf("%c", &sumbu);
			if (sumbu = 'X') {
				SbX = true;
			} else {
				SbX = false;
			}
			printf("Mirror "); P_TulisPOINT(p1); printf(" terhadap sumbu %c", sumbu); printf(" adalah "); P_Mirror(&p1,SbX); P_TulisPOINT(p1);
			printf("\n");
			printf("Mirror "); P_TulisPOINT(p2); printf(" terhadap sumbu %c", sumbu); printf(" adalah "); P_Mirror(&p2,SbX); P_TulisPOINT(p2);
			printf("\n");
		}
		break;
		case 17 :
		{
			printf("Masukkan sudut putar : ");
			scanf("%f", &sudut);
			P_Putar(&p1,sudut);
			P_Putar(&p2,sudut);
			P_TulisPOINT(p1);
			printf("\n");
			P_TulisPOINT(p2);
			printf("\n");
		}
		break;
	};
	return 0;
}
