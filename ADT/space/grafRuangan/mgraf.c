#include "grafRuangan.h"
#include <stdio.h>

void printGraf(GrafRuangan GR);

int main(){
  /* KAMUS */
  GrafRuangan GR;
  int opsi;
  GR_infotype grinfo;
  GRD_infotype grdinfo;

  int opsi2;
  int opsi3;

  /* ALGORITMA */
  do {
    printf("0) Exit\n1) GR_InsVFirst\n2)GRD_InsVFirst");
    scanf("%d",&opsi);

    switch (opsi) {
      case 1:
        break;
      case 2:
        break;
    }


  } while(opsi!=0);
  GR_CreateEmpty(&GR);


  return 0;
}

void printGraf(GrafRuangan GR)
{
  /* KAMUS LOKAL */
  GR_address pt;

  /* ALGORITMA */
  if(GR_IsEmpty(GR)){
    printf("Kosong \n");
  }else{
    pt = GR_First(GR);
    printf("");
  }

}
