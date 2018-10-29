/* Kelompok  : UAS
   Nama file : driver_point.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : driver untuk ADT tipe Point*/

#include "point.h"

int main () {
	/* Kamus driver_point */
	Point p1,p2;
	int menu;
	int deltaX, deltaY;

	/* Algoritma driver_point */
	// baca tulis point
	printf("Masukkan point pertama : ");
	P_BacaPoint(&p1);
	P_TulisPoint(p1);
	printf("\n");
	printf("Masukkan point kedua : ");
	P_BacaPoint(&p2);
	P_TulisPoint(p2);
	printf("\n");

	printf("MENU :\n");
	printf("1. Cek EQ\n");
	printf("2. Cek NEQ\n");
	printf("3. NextX point\n");
	printf("4. NextY point\n");
	printf("5. PlusDelta\n");
	printf("6. Geser point sejauh delta\n");

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
			printf("NextX "); P_TulisPoint(p1); printf(" adalah "); P_TulisPoint(P_NextX(p1));
			printf("\n");
			printf("NextX "); P_TulisPoint(p2); printf(" adalah "); P_TulisPoint(P_NextX(p2));
			printf("\n");
		}
		break;
		case 4 :
		{
			printf("NextY "); P_TulisPoint(p1); printf(" adalah "); P_TulisPoint(P_NextY(p1));
			printf("\n");
			printf("NextY "); P_TulisPoint(p2); printf(" adalah "); P_TulisPoint(P_NextY(p2));
			printf("\n");
		}
		break;
		case 5 :
		{
			printf("Masukkan deltaX : ");
			scanf("%d", &deltaX);
			printf("Masukkan deltaY : ");
			scanf("%d", &deltaY);
			printf("PlusDelta : "); P_TulisPoint(p1); printf(" adalah "); P_TulisPoint(P_PlusDelta(p1,deltaX,deltaY));
			printf("\n");
			printf("PlusDelta : "); P_TulisPoint(p2); printf(" adalah "); P_TulisPoint(P_PlusDelta(p2,deltaX,deltaY));
			printf("\n");
		}
		break;
		case 6 :
		{
			printf("Masukkan deltaX geser : ");
			scanf("%d", &deltaX);
			printf("Masukkan deltaY geser : ");
			scanf("%d", &deltaY);
			P_TulisPoint(p1); printf(" digeser sejauh delta : "); P_Geser(&p1,deltaX,deltaY); P_TulisPoint(p1);
			printf("\n");
			P_TulisPoint(p2); printf(" digeser sejauh delta : "); P_Geser(&p2,deltaX,deltaY); P_TulisPoint(p2);
			printf("\n");
		}
		break;
	};
	return 0;
}
