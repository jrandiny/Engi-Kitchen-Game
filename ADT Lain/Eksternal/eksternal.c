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
  hasil.karakter=scanned.TabKata[1];
  hasil.value=K_KataToInt(K_CopySubKata(scanned,pos1+1,pos2-1));
  hasil.deskripsi=K_CopySubKata(scanned,pos2+1,scanned.Length);
  return hasil;
}

/*
customer ParseCostumer(Kata buffer){
  //menunggu tipe customer jadi sehingga belum direalisasi
}
*/
