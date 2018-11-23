#include "../../ADT.h"
#include "../../std.h"
#include "eksternal.h"

int main(){
  /* KAMUS */
  int status=0;
  Kata nama;
  int money,life,waktu;
  Restoran restoran;
  Pelayan pelayan;
  PrioQueueCustomer prioqueue;
  ArrOrder arrorder;
  StackFood hand,tray;
  char inputTemp[50];
  int i;
  ArrKata temparr;

  /* ALGORITMA */
  /* Cetak list username */
  temparr=AppendUsername(GetAllUserName());

  if(AK_Neff(temparr)>0){
    for(i=AK_GetFirstIdx(temparr);i<=AK_Neff(temparr);i++){
        K_PrintKata(AK_Elmt(temparr,i));
        printf("\n");
    }

    printf("Load username = ");
    scanf("%s",inputTemp);
    nama=K_MakeKata(inputTemp);
    LoadFile(&status,&nama,&money,&life,&waktu,&restoran,&pelayan,&prioqueue,&hand,&tray,&arrorder);

    printf("Save username = ");
    scanf("%s",inputTemp);
    nama=K_MakeKata(inputTemp);
    SaveFile(nama,money,life,waktu,restoran,pelayan,prioqueue,hand,tray,arrorder);

  }else{
    printf("No save\n");
  }




  return 0;
}
