/* Kelompok  : UAS
   Nama file : driverPoint.c
   Deskripsi : driver untuk ADT tipe Point*/

#include "point.h"

int main () {
	/* Kamus driver_point */
	Point p1,p2;
	int menu;
	int deltaX, deltaY;

	/* Algoritma driver_point */

  /* Baca tulis */
	printf("Masukkan point pertama : ");
	P_BacaPoint(&p1);
	P_TulisPoint(p1);
	printf("\n");
	printf("Masukkan point kedua : ");
	P_BacaPoint(&p2);
	P_TulisPoint(p2);
	printf("\n");

  do {
    printf("Menu :\n");
    printf("0. Exit\n");
    printf("1. Cek EQ\n");
    printf("2. Cek NEQ\n");
    printf("3. PlusDelta\n");
    printf("4. Geser point sejauh delta\n");

    printf("Choice = ");
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
        printf("Masukkan deltaX : ");
        scanf("%d", &deltaX);
        printf("Masukkan deltaY : ");
        scanf("%d", &deltaY);
        printf("PlusDelta : "); P_TulisPoint(p1); printf(" adalah "); P_TulisPoint(P_PlusDelta(p1,deltaX,deltaY));
        printf("\n");
        printf("PlusDelta : "); P_TulisPoint(p2); printf(" adalah "); P_TulisPoint(P_PlusDelta(p2,deltaX,deltaY));
        printf("\n");
        break;
      case 4 :
        printf("Masukkan deltaX geser : ");
        scanf("%d", &deltaX);
        printf("Masukkan deltaY geser : ");
        scanf("%d", &deltaY);
        P_TulisPoint(p1); printf(" digeser sejauh delta : "); P_Geser(&p1,deltaX,deltaY); P_TulisPoint(p1);
        printf("\n");
        P_TulisPoint(p2); printf(" digeser sejauh delta : "); P_Geser(&p2,deltaX,deltaY); P_TulisPoint(p2);
        printf("\n");
        break;
    };
  } while(menu!=0);

	return 0;
}
