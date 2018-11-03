#include "eksternal.h"

void ParserLocate(Kata input,int *pos1, int *pos2)
/*I.S. input valid, pos1 dan pos2 kosong
  F.S. pos1 dan pos2 berisi index letak parse
       jika tidak ditemukan pos berisi -1
*/
{
  int i=1;
  *pos1=*pos2=-1;
  int jumlah=0;
  while(i<=input.Length){
    if(input.TabKata[i]=='/'){
      if(jumlah==0){
        *pos1=i;
      }else if(jumlah==1){
        *pos2=i;
      }
      jumlah++;
    }
    i++;
  }
}

Kata ParseNama(Kata scanned)
/* parsing nama,Ckata berada di Kata name*/
{
  Kata hasil;
  int jumlah,i;
  K_ADVKATA();//Ckata berada di jumlah kata nama
  jumlah=K_KataToInt(CKata);
  K_ADVKATA();//Ckata berada di kata pertama;
  hasil=CKata;
  for(i=2;i<=jumlah;i++){
    K_ADVKATA();
    K_KonkatKata(&hasil,K_MakeKata(" "));
    K_KonkatKata(&hasil,CKata);
  }
  return hasil;
  //Ckata berakhir di kata terkahir nama
}

Door ParseDoor(Kata scanned)
/* mengembalikan tipe door dari hasil parsing kata */
{
  Door hasil;
  int pos1,pos2;
  ParserLocate(scanned,&pos1,&pos2);
  DoorLocation(hasil)=K_KataToPoint(K_CopySubKata(scanned,1,pos1-1));
  DoorDirection(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,pos2-1));
  DoorRoomID(hasil)=K_KataToInt(K_CopySubKata(scanned,pos2+1,scanned.Length));
  return hasil;
}

Tile ParseTile(Kata scanned)
/* mengembalikan tipe tile dari hasil parsing kata */
{
  int pos1,pos2;
  Tile hasil;
  ParserLocate(scanned,&pos1,&pos2);
  Karakter(hasil)=scanned.TabKata[1];
  Value(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,scanned.Length));
  return hasil;
}

customer ParseCostumer(Kata scanned)
/* mengembalikan tipe customer dari hasil parsing kata */
{
  int pos1,pos2;
  customer hasil;
  ParserLocate(scanned,&pos1,&pos2);
  PQC_Prio(hasil)=K_KataToInt(K_CopySubKata(scanned,1,pos1-1));
  PQC_Jumlah(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,pos2-1));
  PQC_Waktu(hasil)=K_KataToInt(K_CopySubKata(scanned,pos2+1,scanned.Length));
  return hasil;
}

Meja ParseMeja(Kata scanned)
/* mengembalikan tipe meja dari hasil parsing kata */
{
  int pos1,pos2;
  Meja hasil;
  ParserLocate(scanned,&pos1,&pos2);
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

Restoran ParseRestoran()
/*CKata berada di kata restoran*/
{
  Restoran hasil;
  K_ADVKATA();//Ckata menjadi roomnow;
  RoomNow(hasil)=K_KataToInt(CKata);
  K_ADVKATA();//Ckata menjadi jumlah komponen ruangan yg diambil
  Ruangan(hasil)=ParseGrafRuangan(CKata);
  return hasil;
}

MatTile TakeMatTile(Kata X)
/*CKata berada di jumlah tile yg akan diambil/X, mengambil X kata berikutnya menjadi elemen MatTile*/
{
  int i,j;
  MatTile hasil;
  MT_MakeMatriks(8,8,&hasil);
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
  return hasil;
}

ArrMeja TakeArrMeja(Kata X)
/*CKata berada di jumlah meja yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrMeja*/
{
  int i;
  ArrMeja hasil;
  AM_CreateEmpty(&hasil);
  for(i=1;i<=K_KataToInt(X);i++){
    K_ADVKATA();
    AM_Elmt(hasil,i)=ParseMeja(CKata);
  }
  AM_Neff(hasil)=K_KataToInt(X);
  return hasil;
}

GrafRuangan ParseGrafRuangan(Kata X)
/*Ckata berada di jumlah komponen rungan, mengambil X bagian berikutnya menjadi grafruangan*/
{
  GrafRuangan hasil;
  Ruangan tempR;
  Door tempD1,tempD2;
  GR_address GR1,GR2;
  int i,j,jumlahdoor;
  GR_CreateEmpty(&hasil);
  for(i=1;i<=K_KataToInt(X);i++){
    K_ADVKATA();//Ckata menjadi idruangan
    RoomID(tempR)=K_KataToInt(CKata);
    K_ADVKATA();//Ckata menjadi banyak tile yg akan diambil
    Room(tempR)=TakeMatTile(CKata);//ckata berada di tile terakhir
    K_ADVKATA();//Ckata berada di banyak meja
    Meja(tempR)=TakeArrMeja(CKata);//ckata berada di meja terakhir
    GR_InsVFirst(&hasil,tempR);
  }    

  //di akhir iterasi for Ckata berada di meja dari ruangan terakhir;
  //saat mencapai sini, semua ruangan sudah menjadi node, namun belum ada door
  K_ADVKATA();//Ckata berada di banyak pasangan door
  jumlahdoor=K_KataToInt(CKata);
  for(j=1;j<=jumlahdoor;j++){
      K_ADVKATA();
      tempD1=ParseDoor(CKata);
      K_ADVKATA();
      tempD2=ParseDoor(CKata);
      GR1=GR_Search(hasil,DoorRoomID(tempD1));
      GR2=GR_Search(hasil,DoorRoomID(tempD2));
      GRD_InsertVDoors(&GR1,&GR2,tempD1,tempD2);
  }
  //Ckata berada di door terakhir
  //saat mencapai sini, semua node dan vertex sudah terbentuk
  return hasil;
}

void LoadFile(char* namafile,int* status, Kata* nama,int* money, int* life, int* waktu,Restoran* restoran)
/*I.S. namafile berisi namafile diikuti .txt
  F.S. status memberikan status apakah file berhasil di load atau tidak
  parameter sisanya berisi data sesuai file eksternal
  */
{ 
  K_STARTKATA(namafile,status);//Ckata berada di kata FILE_EKSTERNAL
  if(*status==1){
    while(!EndKata){
      K_ADVKATA();
      if(K_IsKataSama(CKata,K_MakeKata("name"))){
        *nama=ParseNama(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("money"))){
        K_ADVKATA();//Ckata berada di value money
        *money=K_KataToInt(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("life"))){
        K_ADVKATA();//Ckata berada di value life
        *life=K_KataToInt(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("time"))){
        K_ADVKATA();//Ckata berada di value life
        *waktu=K_KataToInt(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("restoran"))){
        //Ckata berada di kata restoran
        *restoran=ParseRestoran();
      }
    }
  }
}