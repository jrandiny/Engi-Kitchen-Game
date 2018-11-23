/* Kelompok  : UAS
   Nama file : eksternal.c
   Deskripsi : Implementasi modul eksternal */

#include "eksternal.h"
#include <time.h>


ArrKata GetAllUserName()
/*
mengambil semua username dan jam kemudian dimasukkan ke arrkata
index genap untuk username, index ganjil untuk jam
*/
{
  ArrKata hasil;
  int status=0;
  AK_CreateEmpty(&hasil);
  K_STARTKATA("SaveData/username.dat",&status);//Ckata berada di username
  if(status==1){
    while(!EndKata){
      AK_AddAsLastEl(&hasil,CKata);
      K_ADVKATA();//Ckata berada di jam;
      AK_AddAsLastEl(&hasil,CKata);
      K_ADVKATA();
    }
  }
  return hasil;
}

ArrKata AppendUsername(ArrKata arrkata)
/*
membuat satu indeks arrkata berisi - <namauser> <jam save>, parameter diisikan dari
hasil fungsi getallusername
*/
{
  int i;
  ArrKata hasil;
  Kata hubung = K_MakeKata("- ");
  Kata tab = K_MakeKata("     ");
  AK_CreateEmpty(&hasil);
  for(i=1;i<=AK_Neff(arrkata);i+=2){
    Kata hasilkata=K_MakeKata("");
    K_KonkatKata(&hasilkata,hubung);
    K_KonkatKata(&hasilkata,AK_Elmt(arrkata,i));
    K_KonkatKata(&hasilkata,tab);
    K_KonkatKata(&hasilkata,AK_Elmt(arrkata,i+1));
    AK_AddAsLastEl(&hasil,hasilkata);
  }
  return hasil;
}

/*Bagian Load File Eksternal*/

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

Order ParseOrder(Kata Scanned)
/*mengembalikan tipe order dari stack dari hasil parsing kata*/
{
  Order hasil;
  int pos1,pos2;
  ParserLocate(Scanned,&pos1,&pos2);
  O_IDMakanan(hasil)=K_KataToInt(K_CopySubKata(Scanned,1,pos1-1));
  O_NamaMakanan(hasil)=K_CopySubKata(Scanned,pos1+1,pos2-1);
  K_ReplaceSpace(&(O_NamaMakanan(hasil)));
  O_NoMeja(hasil)=K_KataToInt(K_CopySubKata(Scanned,pos2+1,Scanned.Length));
  return hasil;
}

Food ParseTFood(Kata Scanned,boolean* kiri,int* parentID)
/*mengembalikan tipe food dari hasil parsing kata, kiri berisi apakah ia leaf kiri,parentid berisi id pangkal*/
{
  Food hasil;
  int pos1,pos2,posu;
  ParserLocate(Scanned,&pos1,&pos2);
  posu=1;
  while(Scanned.TabKata[posu]!='_'){
    posu++;
  }
  if((Scanned.TabKata[1])=='L'){
    *kiri=true;
  }else{
    *kiri=false;
  }
  *parentID=K_KataToInt(K_CopySubKata(Scanned,2,posu-1));
  F_IDMakanan(hasil)=K_KataToInt(K_CopySubKata(Scanned,posu+1,pos1-1));
  F_NamaMakanan(hasil)=K_CopySubKata(Scanned,pos1+1,pos2-1);
  K_ReplaceSpace(&(F_NamaMakanan(hasil)));
  F_Harga(hasil)=K_KataToInt(K_CopySubKata(Scanned,pos2+1,Scanned.Length));
  return hasil;
}

Food ParseSFood(Kata Scanned)
/*mengembalikan tipe food dari stack dari hasil parsing kata*/
{
  Food hasil;
  int pos1,pos2;
  ParserLocate(Scanned,&pos1,&pos2);
  F_IDMakanan(hasil)=K_KataToInt(K_CopySubKata(Scanned,1,pos1-1));
  F_NamaMakanan(hasil)=K_CopySubKata(Scanned,pos1+1,pos2-1);
  K_ReplaceSpace(&(F_NamaMakanan(hasil)));
  F_Harga(hasil)=K_KataToInt(K_CopySubKata(Scanned,pos2+1,Scanned.Length));
  return hasil;
}

Pelayan ParsePelayan(Kata Scanned)
/*mengembalikan tipe pelayan dari hasil parsing kata,Ckata berada di kata pelayan */
{
  Pelayan hasil;
  K_ADVKATA();//Ckata berada di posisi pelayan
  Pelayan_Posisi(hasil)=K_KataToPoint(CKata);
  K_ADVKATA();//ckata berada di up
  Up(hasil)=ParseTile(CKata);
  K_ADVKATA();//ckata berada di down
  Down(hasil)=ParseTile(CKata);
  K_ADVKATA();//ckata berada di left
  Left(hasil)=ParseTile(CKata);
  K_ADVKATA();//ckata berada di right
  Right(hasil)=ParseTile(CKata);
  return hasil;
}


Kata ParseNama(Kata scanned)
/* parsing nama,Ckata berada di Kata name*/
{
  Kata hasil;
  K_ADVKATA();//Ckata berada di namanya;
  hasil=CKata;
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
  if (scanned.TabKata[1] == '-')
    Karakter(hasil)= ' ';
  else Karakter(hasil)=scanned.TabKata[1];
  Value(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,scanned.Length));
  return hasil;
}

Customer ParseCustomer(Kata scanned)
/* mengembalikan tipe Customer dari hasil parsing kata */
{
  int pos1,pos2;
  Customer hasil;
  ParserLocate(scanned,&pos1,&pos2);
  C_Prio(hasil)=K_KataToInt(K_CopySubKata(scanned,1,pos1-1));
  C_Jumlah(hasil)=K_KataToInt(K_CopySubKata(scanned,pos1+1,pos2-1));
  C_Waktu(hasil)=K_KataToInt(K_CopySubKata(scanned,pos2+1,scanned.Length));
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

ArrMeja TakeArrMeja(Kata X,MatTile mattile)
/*CKata berada di jumlah meja yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrMeja*/
{
  int index,i,x,y;
  ArrMeja hasil;
  Meja temp;
  AM_CreateEmpty(&hasil);
  for(i=1;i<=K_KataToInt(X);i++){
    K_ADVKATA();
    temp=ParseMeja(CKata);
    P_GetXY(Meja_Posisi(temp),&x,&y);
    index=Value(MT_Elmt(mattile,x,y));
    AM_AddEli(&hasil,temp,index);
  }
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
    Meja(tempR)=TakeArrMeja(CKata,Room(tempR));//ckata berada di meja terakhir
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

PrioQueueCustomer ParsePrioQueue(Kata X)
/*Ckata berada di kata queue*/
{
  int i,jumlah;
  PrioQueueCustomer hasil;
  K_ADVKATA();//ckata berada di jumlah queue
  jumlah=K_KataToInt(CKata);
  PQC_CreateEmpty(&hasil);
  for(i=1;i<=jumlah;i++){
    K_ADVKATA();
    PQC_Add(&hasil,ParseCustomer(CKata));
  }
  return hasil;
}


TreeFood ParseTreeFood(Kata X)
/*Ckata berada di kata tree*/
{
  Food tempfood;
  int jumlah,i,parentid;
  boolean kiri;
  TreeFood hasil;
  TF_address temptf;
  TF_CreateEmpty(&hasil);
  K_ADVKATA();//Ckata berada di jumlah node tree
  jumlah=K_KataToInt(CKata);
  for(i=1;i<=jumlah;i++){
    K_ADVKATA();//Ckata berada di food
    tempfood=ParseTFood(CKata,&kiri,&parentid);
    temptf=TF_Alokasi(tempfood);
    if(parentid==0){
      hasil=temptf;
    }else{
      TF_AddLeafS(&hasil,parentid,kiri,tempfood);
    }
  }
  return hasil;
}

StackFood ParseStackFood(Kata X)
/*Ckata berada di kata stackhand atau stacktray*/
{
  StackFood hasil;
  int jumlah,i;
  if(K_IsKataSama(X,K_MakeKata("stackhand"))){
    SF_CreateEmpty(&hasil,5);
  }else{//ckata bernilai stacktray
    SF_CreateEmpty(&hasil,10);
  }
  K_ADVKATA();//Ckata berada di jumlah stack
  jumlah=K_KataToInt(CKata);
  for(i=1;i<=jumlah;i++){
    K_ADVKATA();
    SF_Push(&hasil,ParseSFood(CKata));
  }
  //ckata berakhir di komponen terakhir
  hasil=SF_ReversStack(hasil);
  return hasil;
}

ArrOrder ParseArrOrder(Kata X)
/*Ckata berada di kata order*/
{
  ArrOrder hasil;
  int i,jumlah;
  K_ADVKATA();//Ckata berada di jumlah order
  jumlah=K_KataToInt(CKata);
  AO_CreateEmpty(&hasil);
  for(i=1;i<=jumlah;i++){
    K_ADVKATA();
    AO_AddAsLastEl(&hasil,ParseOrder(CKata));
  }
  //Ckata berada di order terakhir
  return hasil;
}

void LoadFile(int* status, Kata* nama,int* money, int* life, int* waktu,Restoran* restoran,Pelayan* pelayan,PrioQueueCustomer* prioqueue,StackFood* hand,StackFood* tray,ArrOrder* arrorder)
/*I.S. bebas
  F.S. status memberikan status apakah file berhasil di load(1) atau tidak(0)
  parameter sisanya berisi data sesuai file eksternal
  */
{
  Kata namafile=K_MakeKata("SaveData/");
  K_KonkatKata(&namafile,*nama);
  K_KonkatKata(&namafile,K_MakeKata(".sav"));
  K_STARTKATA(K_KataToChar(namafile),status);//Ckata berada di kata FILE_EKSTERNAL
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
      }else if(K_IsKataSama(CKata,K_MakeKata("pelayan"))){
        //Ckata berada di kata pelayan
        *pelayan=ParsePelayan(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("queue"))){
        //Ckata berada di kata queue
        *prioqueue=ParsePrioQueue(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("stackhand"))){
        //Ckata berada di kata stackhand
        *hand=ParseStackFood(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("stacktray"))){
        //Ckata berada di kata stacktray
        *tray=ParseStackFood(CKata);
      }else if(K_IsKataSama(CKata,K_MakeKata("order"))){
        //Ckata berada di kata order
        *arrorder=ParseArrOrder(CKata);
      }
    }
  }
}

void LoadTree(int* status,TreeFood* TreeFood)
/*I.S. bebas
  F.S. status memberikan status apakah file berhasil di load(1) atau tidak(0)
  parameter sisanya berisi data sesuai file eksternal, treefood berisi sesuai file ex*/
{
  Kata namafile=K_MakeKata("SaveData/TreeFood.sav");
  K_STARTKATA(K_KataToChar(namafile),status);
  //Ckata berada di kata tree
  *TreeFood=ParseTreeFood(CKata);
}

/*Bagian Save File Eksternal*/

void WriteSpace(FILE* namafile)
/* I.S. bebas
   F.S. di namafile tertulis spasi*/
{
  fprintf(namafile," ");
}

void WriteName(FILE* namafile,Kata name)
/* I.S. namafile dan name terdefinisi
   F.S. tertulis name di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  fprintf(namafile,"%s",K_KataToChar(name));
}

void WriteTile(FILE* namafile,Tile tile)
/* I.S. namafile dan tile terdefinisi
   F.S. tertulis tile di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  fprintf(namafile,"%c/%d",(Karakter(tile)==' ')?'-':Karakter(tile),Value(tile));
}

void WriteMeja(FILE* namafile,Meja meja)
/* I.S. namafile dan meja terdefinisi
   F.S. tertulis meja di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  fprintf(namafile,"%d/%d,%d/%d",Bangku(meja),P_Baris(Meja_Posisi(meja)),P_Kolom(Meja_Posisi(meja)),Status(meja));
}

void WriteCustomer(FILE* namafile,Customer customer)
/* I.S. namafile dan customer terdefinisi
   F.S. tertulis customer di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  fprintf(namafile,"%d/%d/%d",C_Prio(customer),C_Jumlah(customer),C_Waktu(customer));
}

void WriteDoor(FILE* namafile,Door door)
/* I.S. namafile dan door terdefinisi
   F.S. tertulis door di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  fprintf(namafile,"%d,%d/%d/%d", P_Baris(DoorLocation(door)),P_Kolom(DoorLocation(door)) ,DoorDirection(door),DoorRoomID(door));
}

void WriteMatriksTile(FILE* namafile,MatTile mattile)
/* I.S. namafile dan mattile terdefinisi
   F.S. tertulis mattile di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  int i,j;
  fprintf(namafile,"%d",MT_NBrsEff(mattile)*MT_NKolEff(mattile));
  for(i=1;i<=MT_NBrsEff(mattile);i++){
    for(j=1;j<=MT_NKolEff(mattile);j++){
      WriteSpace(namafile);
      WriteTile(namafile,MT_Elmt(mattile,i,j));
    }
  }
}

void WriteArrayMeja(FILE* namafile,ArrMeja arrmeja)
/* I.S. namafile dan arrmeja terdefinisi
   F.S. tertulis arrmeja di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  int i;
  fprintf(namafile,"%d",AM_Neff(arrmeja));
  for(i=AM_GetFirstIdx(arrmeja);i<=AM_GetLastIdx(arrmeja);i++){
    WriteSpace(namafile);
    WriteMeja(namafile,AM_Elmt(arrmeja,i));
 }
}

void WriteFood(FILE* namafile,Food food)
/* I.S. namafile dan food terdefinisi
   F.S. tertulis food di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  K_RemoveSpace(&(F_NamaMakanan(food)));
  fprintf(namafile,"%d/%s/%d",F_IDMakanan(food),K_KataToChar(F_NamaMakanan(food)),F_Harga(food));
}

void WriteOrder(FILE* namafile,Order order)
/* I.S. namafile dan order terdefinisi
   F.S. tertulis order di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  K_RemoveSpace(&(O_NamaMakanan(order)));
  fprintf(namafile,"%d/%s/%d",O_IDMakanan(order),K_KataToChar(O_NamaMakanan(order)),O_NoMeja(order));
}

void WriteUsername(FILE* namafile,ArrKata arrkata)
/* I.S. namafile dan arrkata terdefinisi
   F.S. tertulis arrkata di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/
{
  int i;
  for(i=AK_GetFirstIdx(arrkata);i<=AK_Neff(arrkata);i+=2){
    fprintf(namafile,"%s ",K_KataToChar(AK_Elmt(arrkata,i)));
    fprintf(namafile,"%s ",K_KataToChar(AK_Elmt(arrkata,i+1)));
  }
  fprintf(namafile,".");
}

void SaveFile(Kata nama,int money, int life, int waktu,Restoran restoran,Pelayan pelayan,PrioQueueCustomer prioqueue,StackFood hand,StackFood tray,ArrOrder arrorder)
/*I.S. bebas
  F.S. data nama,money,dll tersave di file eksternal dengan nama sesuai nama
  */
{
  ArrKata allUserName;
  FILE* fu;
  Jam timesaved;
  time_t raw;
  struct tm * now;
  boolean found=false;
  int indeks=1;
  time(&raw);
  now = localtime(&raw);
  J_Hour(timesaved) = now->tm_hour;
  J_Minute(timesaved) = now->tm_min;
  J_Second(timesaved) = now->tm_sec;
  allUserName=GetAllUserName();
  // for(indeks=1;indeks<=AK_Neff(allUserName);indeks++){
  //   K_PrintKata(AK_Elmt(allUserName,indeks));
  // }
  indeks=1;
  while(indeks<=AK_Neff(allUserName)&&!found){
    if(K_IsKataSama(AK_Elmt(allUserName,indeks),nama)){
      found=true;
    }else{
      indeks++;
    }
  }
  if(found){
    AK_Elmt(allUserName,indeks+1)=K_JamToKata(timesaved);
  }else{
    AK_AddAsLastEl(&allUserName,nama);
    AK_AddAsLastEl(&allUserName,K_JamToKata(timesaved));
  }
  fu=fopen("SaveData/username.dat","w+");
  WriteUsername(fu,allUserName);
  fclose(fu);
  ///////////////////////////////////////////////////////////
  FILE* fw;
  Kata namafile=K_MakeKata("SaveData/");
  K_KonkatKata(&namafile,nama);
  K_KonkatKata(&namafile,K_MakeKata(".sav"));
  GR_address GR=Nil;
  GRD_address GD=Nil;
  Customer customer;
  Food food;
  ///////////////////////////////////////////////////////////
  fw=fopen(K_KataToChar(namafile),"w+");
  fprintf(fw,"FILE_EKSTERNAL");
  WriteSpace(fw);
  //Tulis bagian nama
  fprintf(fw,"name ");
  WriteName(fw,nama);
  WriteSpace(fw);
  //Tulis bagian money
  fprintf(fw,"money %d",money);
  WriteSpace(fw);
  //Tulis bagian life
  fprintf(fw,"life %d",life);
  WriteSpace(fw);
  //Tulis bagian time
  fprintf(fw,"time %d",waktu);
  WriteSpace(fw);
  //Tulis bagian restoran
  fprintf(fw,"restoran ");
  fprintf(fw,"%d",RoomNow(restoran));
  fprintf(fw," 4 ");
  GR=GR_First(Ruangan(restoran));
  while(GR!=Nil){
    fprintf(fw,"%d ",RoomID(GR_Info(GR)));
    WriteMatriksTile(fw,Room(GR_Info(GR)));
    WriteSpace(fw);
    WriteArrayMeja(fw,Meja(GR_Info(GR)));
    WriteSpace(fw);
    GR=GR_Next(GR);
  }
  fprintf(fw," 4");
  ////////////////////////////////////
  //bagian writing vertex
  GR=GR_First(Ruangan(restoran));
  GRD_address temp[9];
  int n=0,i;
  while(GR!=Nil){
    GD=GR_Doors(GR);
    while(GD!=Nil){
      found=false;
      i=1;
      while((i<=n)&&!found){
        if(GD==temp[i]){
          found=true;
        }else{
          i++;
        }
      }
      if(!found){
        WriteSpace(fw);
        WriteDoor(fw,GRD_Info(GD));
        n++;
        temp[n]=GD;
        GD=GRD_To(GD);
        WriteSpace(fw);
        WriteDoor(fw,GRD_Info(GD));
        n++;
        temp[n]=GD;
        GD=temp[n-1];
      }
      GD=GRD_Next(GD);
    }
    GR=GR_Next(GR);
  }
  ////////////////////////////////////
  //tulis bagian pelayan
  fprintf(fw," pelayan ");
  fprintf(fw,"%d,%d",P_Baris(Pelayan_Posisi(pelayan)),P_Kolom(Pelayan_Posisi(pelayan)));
  WriteSpace(fw);
  WriteTile(fw,Up(pelayan));
  WriteSpace(fw);
  WriteTile(fw,Down(pelayan));
  WriteSpace(fw);
  WriteTile(fw,Left(pelayan));
  WriteSpace(fw);
  WriteTile(fw,Right(pelayan));
  //tulis bagian priorqueue
  fprintf(fw," queue ");
  fprintf(fw,"%d",PQC_NBElmt(prioqueue));
  n=PQC_NBElmt(prioqueue);
  for(i=1;i<=n;i++){
    WriteSpace(fw);
    PQC_Del(&prioqueue,&customer);
    WriteCustomer(fw,customer);
  }
  //tulis bagian stackhand
  fprintf(fw," stackhand ");
  fprintf(fw,"%d",SF_Top(hand));
  while(!SF_IsEmpty(hand)){
    SF_Pop(&hand,&food);
    WriteSpace(fw);
    WriteFood(fw,food);
  }
  //tulis bagian stacktray
  fprintf(fw," stacktray ");
  fprintf(fw,"%d",SF_Top(tray));
  while(!SF_IsEmpty(tray)){
    SF_Pop(&tray,&food);
    WriteSpace(fw);
    WriteFood(fw,food);
  }
  //tulis bagian order
  fprintf(fw," order ");
  fprintf(fw,"%d",AO_Neff(arrorder));
  for(i=AO_GetFirstIdx(arrorder);i<=AO_GetLastIdx(arrorder);i++){
    WriteSpace(fw);
    WriteOrder(fw,AO_Elmt(arrorder,i));
  }
  /////////////////////////////////
  fprintf(fw,".");
  fclose(fw);
}
