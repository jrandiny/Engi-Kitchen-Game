#include "eksternal.h"

void ParserLocate(Kata input,int *pos1, int *pos2, int *pos3)
/*I.S. input valid, pos1 dan pos2 kosong
  F.S. pos1 dan pos2 berisi index letak parse
       jika tidak ditemukan pos berisi -1
*/
{
  int i=1;
  *pos1=*pos2=*pos3=-1;
  int jumlah=0;
  while(i<=input.Length){
    if(input.TabKata[i]=='/'){
      if(jumlah==0){
        *pos1=i;
      }else if(jumlah==1){
        *pos2=i;
      }else if(jumlah==2){
        *pos3=i;
      }
      jumlah++;
    }
    i++;
  }
}

Tile ParseTile(Kata scanned)
/* mengembalikan tipe tile dari hasil parsing kata */
{
  int pos1,pos2,pos3;
  Tile hasil;
  ParserLocate(scanned,&pos1,&pos2,&pos3);
  Karakter(hasil)=scanned.TabKata[1];
  Value(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,scanned.Length));
  return hasil;
}

customer ParseCostumer(Kata scanned)
/* mengembalikan tipe customer dari hasil parsing kata */
{
  int pos1,pos2,pos3;
  customer hasil;
  ParserLocate(scanned,&pos1,&pos2,&pos3);
  C_Prio(hasil)=K_KataToInt(K_CopySubKata(scanned,1,pos1-1));
  C_Jumlah(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,pos2-1));
  C_Waktu(hasil)=K_KataToInt(K_CopySubKata(scanned,pos2+1,pos3-1));
  C_ID(hasil)=K_KataToInt(K_CopySubKata(scanned,pos3+1,scanned.Length));
  return hasil;
}

Meja ParseMeja(Kata scanned)
/* mengembalikan tipe meja dari hasil parsing kata */
{
  int pos1,pos2,pos3;
  Meja hasil;
  ParserLocate(scanned,&pos1,&pos2,&pos3);
  Bangku(hasil)=K_KataToInt(K_CopySubKata(scanned,1,pos1-1));
  Meja_Posisi(hasil)=K_KataToPoint(K_CopySubKata(scanned,pos1+1,pos2-1));
  Status(hasil)=K_KataToInt(K_CopySubKata(scanned,pos2+1,scanned.Length));
  return hasil;
}

Ruangan ParseRuangan(Kata X)
/*CKata berada di banyak elemen ruangan/x, mengambil X kata berikutnya menjadi Ruangan*/
{
  Ruangan hasil;
  K_ADVKATA();//Ckata menjadi jumlah MatTile
  Room(hasil)=TakeMatTile(CKata);//Ckata berada di tile terakhir
  K_ADVKATA();//Ckata menjadi jumlah arrmeja
  Meja(hasil)=TakeArrMeja(CKata);//Ckata berakhir di jumlah elemen arrmeja terakhir;
  return hasil;
}

MatTile TakeMatTile(Kata X)
/*CKata berada di jumlah tile yg akan diambil/X, mengambil X kata berikutnya menjadi elemen MatTile*/
{
  int i,j;
  MatTile hasil;
  i=1;
  while(i<=(K_KataToInt(X)/8)){
    j=1;
    while(j<=(K_KataToInt(X)/8)){
      K_ADVKATA();
      MT_Elmt(hasil,i,j)=ParseTile(CKata);
      j++;
    }
    i++;
  }
  MT_NBrsEff(hasil)=8;
  MT_NKolEff(hasil)=8;
  return hasil;
}

ArrMeja TakeArrMeja(Kata X)
/*CKata berada di jumlah meja yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrMeja*/
{
  int i;
  ArrMeja hasil;
  for(i=1;i<=K_KataToInt(X);i++){
    K_ADVKATA();
    AM_Elmt(hasil,i)=ParseMeja(CKata);
  }
  AM_Neff(hasil)=K_KataToInt(X);
  return hasil;
}


ArrRuangan TakeArrRuangan(Kata X)
/*CKata berada di jumlah ruangan yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrRuangan*/
{
  ArrRuangan hasil;
  int i;
  for(i=1;i<=K_KataToInt(X);i++){
    K_ADVKATA();//dapat jumlah elemen ruangan
    AR_Elmt(hasil,i)=ParseRuangan(CKata);//Ckata berakhir di komponen elemen arrmeja terakhir
  }
  AR_Neff(hasil)=K_KataToInt(X);
  return hasil;
}

Restoran ParseRestoran()
/*CKata berada di kata restoran*/
{
  Restoran hasil;
  K_ADVKATA();//Ckata menjadi roomnow;
  RoomNow(hasil)=K_KataToInt(CKata);
  K_ADVKATA();//Ckata menjadi jumlah ruangan yg diambil
  Ruangan(hasil)=TakeArrRuangan(CKata);//Ckata menjadi komponen terakhir ruangan
  return hasil;
}

