/* Kelompok  : UAS
   Nama file : space.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 1 November 2018
   Deskripsi : ADT untuk tipe space*/

#include "space.h"
#include "../../std.h"
#include "../point/point.h"
#include "../arrInt/arrInt.h"
#include "matTile/matTile.h"
#include "arrMeja/arrMeja.h"
#include "grafRuangan/grafRuangan.h"
#include "pelayan.h"
#include "restoran.h"

void PlacePelayan(Pelayan *P,int x,int y, MatTile M)
/*
  menaruh Pelayan di posisi (x,y) di ruangan di Restoran r
  I.S. Pelayan,x,y,R terdefinisi
  F.S. Pelayan terletak di posisi x,y di ruangan di R Tile bersampingan terupdate
*/
{
  //ALGORITMA
  P_SetXY(&Pelayan_Posisi(*P),x,y); //merubah posisi
  SetTile(P,M,1); //mengecek karakter di atasnya
  SetTile(P,M,2); //mengencek karakter di kanannya
  SetTile(P,M,3); //mengecek karakter di bawahnya
  SetTile(P,M,4); //mengecek karakter di kirinya
}

// *** PINDAH ***
void Move(Pelayan *P,Restoran *R, int code, boolean *status,boolean *justMove)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayang dapat bergerak ke arah code
  F.S. Pelayan pindah ke posisi sesuai code dan update semua karakter
  code: 1 = Up
        2 = Right
        3 = Down
        4 = Left
*/
{
  //KAMUS
  int x,y;
  int i,j;
  boolean found;
  GR_address p,p1;
  GRD_address pt,door;
  Door pintu;
  Point tujuan;
  int arah,nomorRuangBaru;
  MatTile M;
  //ALGORITMA
  //cek apakah sekarang pelayan ada di pintu
  found = false;
  p = GR_First(Ruangan(*R)); //GR_address dari ruangan pertama
  while (p!=Nil && !found) { //diulang hingga ketemu atau sudah di cek semua ruangan
    if (RoomID(GR_Info(p))==RoomNow(*R)){
      //mencari room id di ruangan yang sama dengan ruangan sekarang
      pt = GR_Doors(p); //pt adalah address untuk list door
      door = GRD_Search(pt,Pelayan_Posisi(*P)); //searching pintu di posisi pelayan
      if (door != Nil) { //ketemu pintu di posisi pelayan
        found = true;
      } else { //tidak ketemu, cek ruangan selanjutnya
        p = GR_Next(p);
      }
    } else { //ruangannya tidak sama jadi lanjut ke ruangan selanjutnya
      p = GR_Next(p);
    }
  } //found == true || p == nil

  if (found) { //ketemu pintu
    pintu = GRD_Info(door);
    arah = DoorDirection(pintu); //mengambil arah dari pintu

    tujuan = DoorLocation(GRD_Info(GRD_To(door)));
    P_GetXY(tujuan,&i,&j); //mengambil posisi pintu yang dituju

    nomorRuangBaru = RoomID(GR_Info(GRD_Parent(GRD_To(door))));
    p1 = GR_Search(Ruangan(*R),nomorRuangBaru);
    M = Room(GR_Info(p1)); //mengambil layout ruangan yang dituju
  }

  *status = false;
  *justMove = false;
  P_GetXY(Pelayan_Posisi(*P),&x,&y);
  switch (code) { //move pelayan sesuai kode
    case 1: //atas
      if (Karakter(Up(*P))==' ') { //lantai atas kosong
        *status =true;
        x-=1;
        PlacePelayan(P,x,y,GetMatTileSekarang(*R));
      } else if (found) { //di pintu bisa naik
        if (arah==code) {
          *status =true;
          *justMove = true;
          PlacePelayan(P,i,j,M);
          RoomNow(*R) = nomorRuangBaru;
        }
      }
      break;
    case 2: //kanan
      if (Karakter(Right(*P))==' ') { //lantai kanan kosong
        *status =true;
        y+=1;
        PlacePelayan(P,x,y,GetMatTileSekarang(*R));
      } else if (found) { //di pintu bisa naik
        if (arah==code) {
          *status =true;
          *justMove = true;
          PlacePelayan(P,i,j,M);
          RoomNow(*R) = nomorRuangBaru;
        }
      }
      break;
    case 3: //bawah
      if (Karakter(Down(*P))==' ') { //lantai bawah kosong
        *status =true;
        x+=1;
        PlacePelayan(P,x,y,GetMatTileSekarang(*R));
      } else if (found) { //di pintu bisa naik
        if (arah==code) {
          *status =true;
          *justMove = true;
          PlacePelayan(P,i,j,M);
          RoomNow(*R) = nomorRuangBaru;
        }
      }
      break;
    case 4: //kiri
      if (Karakter(Left(*P))==' ') { //lantai kiri kosong
        *status =true;
        y-=1;
        PlacePelayan(P,x,y,GetMatTileSekarang(*R));
      } else if (found) { //di pintu bisa naik
        if (arah==code) {
          *status =true;
          *justMove = true;
          PlacePelayan(P,i,j,M);
          RoomNow(*R) = nomorRuangBaru;
        }
      }
      break;
  };
}

// *** BOOLEAN PELAYAN ***
boolean CanOrder(Pelayan P, Ruangan R)
/*
  fungsi akan bernialai true jika meja dekat p dapat memesan
*/
{
  //KAMUS
  int nomorMeja;
  //ALGORITMA
  nomorMeja = GetTableNumber(P,R);
  //bisa order jika status mejanya adalah 1, sudah duduk dan
  return Status(AM_Elmt(Meja(R),nomorMeja)) ==  1;
}
boolean CanTake(Pelayan P)
/*
  fungsi bernilai true jika di dekat P ada M yang bisa diambil idnya
*/
{
  //KAMUS
  boolean up,down,left,right;
  //ALGORITMA
  //jika karakter di dekatnya adalah 'm'
  up = Karakter(Up(P)) == 'm';
  down = Karakter(Down(P)) == 'm';
  left = Karakter(Left(P)) == 'm';
  right = Karakter(Right(P)) == 'm';
  return up||down||left||right;
}
boolean CanPut(Pelayan P)
/*
  fungsi bernilai true jika di dekat P ada t yang bisa diput
*/
{
  //KAMUS
  boolean up,down,left,right;
  //ALGORITMA
  //jika karakter di dekatnya adalah 'm'
  up = Karakter(Up(P)) == 't';
  down = Karakter(Down(P)) == 't';
  left = Karakter(Left(P)) == 't';
  right = Karakter(Right(P)) == 't';
  return up||down||left||right;
}

// *** Tile Set ***
void SetTile(Pelayan *P,MatTile M, int kode)
/*
  I.S. P, M, kode terdefinisi
  F.S. Tile pada pelayan diisi dengan elemt yang sesuai dengan M menurut kode
*/
{
  //KAMUS
  int x,y;
  Tile tmp;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);
  switch (kode) {
    case 1:
      x -= 1;
      if (MT_IsIdxEff(M,x,y)) {
        //jika merupakan indeks efektif berarti masih dalam ruangan
        tmp = MT_Elmt(M,x,y);
        Up(*P) = MT_CreateTile(Karakter(tmp),Value(tmp));
      } else {
        Up(*P) = MT_CreateTile(CharUndeff,ValUndeff);
      }
    case 2:
      y += 1;
      if (MT_IsIdxEff(M,x,y)) {
        //jika merupakan indeks efektif berarti masih dalam ruangan
        tmp = MT_Elmt(M,x,y);
        Right(*P) = MT_CreateTile(Karakter(tmp),Value(tmp));
      } else {
        Right(*P) = MT_CreateTile(CharUndeff,ValUndeff);
      }
    case 3:
      x += 1;
      if (MT_IsIdxEff(M,x,y)) {
        //jika merupakan indeks efektif berarti masih dalam ruangan
        tmp = MT_Elmt(M,x,y);
        Down(*P) = MT_CreateTile(Karakter(tmp),Value(tmp));
      } else {
        Down(*P) = MT_CreateTile(CharUndeff,ValUndeff);
      }
    case 4:
      y -= 1;
      if (MT_IsIdxEff(M,x,y)) {
        //jika merupakan indeks efektif berarti masih dalam ruangan
        tmp = MT_Elmt(M,x,y);
        Left(*P) = MT_CreateTile(Karakter(tmp),Value(tmp));
      } else {
        Left(*P) = MT_CreateTile(CharUndeff,ValUndeff);
      }
  };
}

// *** BOOLEAN RUANGAN***
boolean IsTableEmpty(int nomorMeja, Ruangan R)
/*
  mengirimkan true jika meja dengan nomor meja nomor adalah kosong dan bisa
  di duduki, mengirimkan false jika tidak
*/
{
  //ALGORITMA
  //empty jika status mejanya 0
  return Status(AM_Elmt(Meja(R),nomorMeja)) ==  0;
}
boolean CanPlace(int pelanggan,Pelayan P, Ruangan R)
/*
  fungsi menghasilkan true jika meja di dekat P dapat diduduki oleh Pelanggan
  yaitu jumlah bangkunya <= dan sedang kosong
  P harus sebelah bangku ('x')
*/
{
  //KAMUS
  boolean empty;
  int jumlahBangku;
  int nomorMeja;
  //ALGORITMA
  nomorMeja = GetTableNumber(P,R);
  jumlahBangku = Bangku(AM_Elmt(Meja(R),nomorMeja));
  empty = IsTableEmpty(nomorMeja,R);
  //bisa di-place jika jumlah bangku cukup dan statusnya empty
  return (empty && (jumlahBangku>=pelanggan && pelanggan != 0));
}

// *** ACTION ***
void Ordering(Pelayan P,Ruangan *R, int *idMakanan,int *nomorMeja)
/*
  I.S. P dan *R terdefinisi, dilakukan jika sudah dipastikan dapat order dan P
    dekat Meja
  F.S.
*/
{
  //ALGORITMA
  //merandom id makanan dari -1 - -8
  *idMakanan = (rand()%8-8); //[-1..-8]
  *nomorMeja = GetTableNumber(P,*R);
  Status(AM_Elmt(Meja(*R),*nomorMeja)) = 2; //merubah status meja menjadi 2, sudah order
}
int Taking(Pelayan P)
/*
  menghasilkan id makanan yang diambil dengan syarat di dekat P hanya ada
  satu meja bahan ('m')
*/
{
  //KAMUS
  int makanan;
  //ALGORITMA
  if (Karakter(Up(P)) == 'm'){ // 'm' ada di atas
    makanan = Value(Up(P));
  } else if (Karakter(Down(P)) == 'm'){ // 'm' ada di bawah
    makanan = Value(Down(P));
  } else if (Karakter(Left(P)) == 'm'){ // 'm' ada di kiri
    makanan = Value(Left(P));
  } else { //'m' ada di kanan
    makanan = Value(Right(P));
  }
  return makanan;
}
void Placing(int pelanggan,int waktuOut,Pelayan *P, Ruangan *R)
/*
  I.S. pelanggan,waktuOut,Pelayan, retoran terdefinisi,
      meja sebelah Pelayan adalah kosong
      pelanggan merupakan jumlah pelanggan yang akan duduk
      waktuOut merupakan waktu pelanggan pergi
      hanya dipanggil jika yakin pelanggan bisa diletakkan
  F.S. pelanggan di tempatkan di meja sesuai jumlahnya
      karakter jadi 'c', value jadi waktuOut
*/
{
  //KAMUS
  int nomorMeja;
  int x,y;
  int i,j;
  int jumlahBangku;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);

  nomorMeja = GetTableNumber(*P,*R);
  P_GetXY(IndeksMeja(nomorMeja,*R),&i,&j);
  Status(AM_Elmt(Meja(*R),nomorMeja)) = 1;
  jumlahBangku = Bangku(AM_Elmt(Meja(*R),nomorMeja));

  //menaruh minimal 2 pelanggan
  MT_Elmt(Room(*R),i,j+1) = MT_CreateTile('c',waktuOut);
  MT_Elmt(Room(*R),i,j-1) = MT_CreateTile('c',waktuOut);
  if (pelanggan == 4) {
    /*jika pelanggannya 4, tambah 2 karakter 'c' lagi
      bukan saat ada 4 jumlahBangku*/
    MT_Elmt(Room(*R),i+1,j) = MT_CreateTile('c',waktuOut);
    MT_Elmt(Room(*R),i-1,j) = MT_CreateTile('c',waktuOut);
  }
  if (jumlahBangku==4 && pelanggan==2) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
    MT_Elmt(Room(*R),i+1,j) = MT_CreateTile('x',waktuOut);
    MT_Elmt(Room(*R),i-1,j) = MT_CreateTile('x',waktuOut);
  }
  PlacePelayan(P,x,y,Room(*R)); //update semua karakter pelayan
}

// *** LAIN LAIN ***
Tile GetTableTile(Pelayan P, Ruangan R)
/*
  mengembalikan nilai meja yang bersebelahan dengan Pelayan
*/
{
  //KAMUS
  int nomor;
  int i,j;
  //ALGORITMA
  nomor = GetTableNumber(P,R);
  P_GetXY(IndeksMeja(nomor,R),&i,&j);
  return MT_Elmt(Room(R),i,j);
}
MatTile GetMatTileSekarang(Restoran R)
/*
  fungsi mengembalikan suatu matriks yang sedang digunakan berdasarkan Ruangan(R)
*/
{
  //KAMUS
  GR_address P;
  //ALGORITMA
  P = GR_Search(Ruangan(R),RoomNow(R));
  return (Room(GR_Info(P)));
}
Ruangan* GetRuanganSekarang(Restoran R)
/*
  fungsi mengembalikan suatu tipe Ruangan yang sedang digunakan berdasarkan Ruangan(R)
*/
{
  return &(GR_Info(GR_Search(Ruangan(R),RoomNow(R))));
}
void PelangganKabur(int waktuNow,Pelayan *P,Restoran *R, int *jumlah,ArrInt *arrinteger)
/*
  I.S. waktuNow, P, R terdefinisi
  F.S. jumlah berisi jumlah pelanggan yang waktu keluarnya sudah sama
    dengan waktuNow sekaligus mengembalikan status meja menjadi kosong, karakter
    menjadi x deskripsi menjadi "-" dan Value menjadi ValUndeff
*/
{
  //KAMUS
  int x,y;
  int a,b;
  int nomorMeja;
  Ruangan *tmp;
  Ruangan room;
  GR_address p1;
  //ALGORITMA
  *jumlah = 0;
  p1 = GR_First(Ruangan(*R));
  AI_CreateEmpty(arrinteger);
  while (p1!=Nil) {
    room = GR_Info(p1);
    for(int i = AM_GetFirstIdx(Meja(room));i<=AM_GetLastIdx(Meja(room));i++) {
        P_GetXY(IndeksMeja(i,room),&a,&b);
        if (Value(MT_Elmt(Room(room),a,b+1))==waktuNow) {
          //saatnya keluar
          *jumlah += 1;
          nomorMeja = Value(MT_Elmt(Room(room),a,b));
          AI_AddAsLastEl(arrinteger,nomorMeja);
          SetTableEmpty(i,&GR_Info(p1));
        }
    }
    p1= GR_Next(p1);
  }
  if (*jumlah > 0) { //hanya dilakukan jika ada pelanggan kabur
    P_GetXY(Pelayan_Posisi(*P),&x,&y);
    tmp = GetRuanganSekarang(*R);
    PlacePelayan(P,x,y,Room(*tmp));
  }
}
Point IndeksMeja(int nomor,Ruangan R)
// mengembalikan koordinat dari nomor meja yang diinput. nomor [1..12]
{
  //ALGORITMA
  return Meja_Posisi(AM_Elmt(Meja(R),nomor));
}
void SetTableEmpty(int nomorMeja, Ruangan *R)
/*
  I.S. P dan R terdefinisi, dipanggil jika p dekat meja
  F.S. membuat meja dengan nomor meja nomorMeja menjadi kosong
*/
{
  //KAMUS
  int i,j;
  int jumlahBangku;
  //ALGORITMA
  P_GetXY(IndeksMeja(nomorMeja,*R),&i,&j);
  jumlahBangku = Bangku(AM_Elmt(Meja(*R),nomorMeja));

  //merubah minimal 2 pelanggan
  MT_Elmt(Room(*R),i,j+1) = MT_CreateTile('x',ValUndeff);
  MT_Elmt(Room(*R),i,j-1) = MT_CreateTile('x',ValUndeff);
  if (jumlahBangku==4) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
    MT_Elmt(Room(*R),i+1,j) = MT_CreateTile('x',ValUndeff);
    MT_Elmt(Room(*R),i-1,j) = MT_CreateTile('x',ValUndeff);
  }
  Status(AM_Elmt(Meja(*R),nomorMeja)) = 0;
}
int GetTableNumber (Pelayan P, Ruangan R)
/*
  fungsi mengembalikan nomor jika P berada di dekat meja
  akan mengembalikan 0 jika tidak
*/
{
  //KAMUS
  ArrMeja arrmeja;
  Meja meja;
  int x,y;
  int i;
  int a,b;
  boolean found;
  int tmp;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(P),&x,&y);
  arrmeja = Meja(R);
  found = false;
  i = AM_GetFirstIdx(arrmeja);
  while (!found && i <=AM_GetLastIdx(arrmeja)) {
    meja = AM_Elmt(arrmeja,i);
    P_GetXY(Meja_Posisi(meja),&a,&b);
    //cek semua kemungkinan posisi meja terhadap pelayan
    if (a == x && b-2 ==y) {
      found = true;
    } else if (a-1 == x && b-1 ==y) {
      found = true;
    } else if (a-1 == x && b+1 ==y) {
      found = true;
    } else if (a == x && b+2 ==y) {
      found = true;
    } else if (a+1 == x && b+1 ==y) {
      found = true;
    } else if (a+1 == x && b-1 ==y) {
      found = true;
    } else if (Bangku(meja)==2) {
      if (a-1 == x && b ==y) {
        found = true;
      } else if (a+1 == x && b ==y) {
        found = true;
      } else i++;
    } else if (Bangku(meja)==4) {
      if (a-2 == x && b ==y) {
        found = true;
      } else if (a+2 == x && b ==y) {
        found = true;
      } else i++;
    } else i++;
  } //found == true || i > AM_GetLastIdx(arrmeja)
  if (!found) {
    tmp = 0;
  } else {
    tmp = Value(MT_Elmt(Room(R),a,b));
  }
  return tmp;
}
