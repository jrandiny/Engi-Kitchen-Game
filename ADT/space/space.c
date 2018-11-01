/* Kelompok  : UAS
   Nama file : space.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 1 November 2018
   Deskripsi : ADT untuk tipe space*/

#include "space.h"
#include "../../std.h"
#include "../point/point.h"
// #include "../../ADT/listlinier/multilist.h"
#include "arrRuangan/arrRuangan.h"
#include "matTile/matTile.h"
#include "arrMeja/arrMeja.h"
#include "pelayan.h"
#include "restoran.h"

// *** KONSTRUKTOR ***
void InitPelayan(Pelayan *P)
/* membuat Pelayan baru
  I.S. Sembarang
  F.S. terbentuk Pelayan dengan posisi di 0,0
      semua karakter bernilai CharUndeff
      semua value bernilai ValUndeff
      semua deskripsi berniali ""
*/
{
  //ALGORITMA
  //posisi
  P_SetXY(&Pelayan_Posisi(*P),0,0);
  //up
  Up(*P) = MT_SetTile(CharUndeff,ValUndeff);
  //down
  Down(*P) = MT_SetTile(CharUndeff,ValUndeff);
  //left
  Left(*P) = MT_SetTile(CharUndeff,ValUndeff);
  //right
  Right(*P) = MT_SetTile(CharUndeff,ValUndeff);
}
void PlacePelayan(Pelayan *P,int x,int y, MatTile M)
/*
  menaruh Pelayan di posisi (x,y) di ruangan di Restoran r
  I.S. Pelayan,x,y,R terdefinisi
  F.S. Pelayan terletak di posisi x,y di ruangan di R Tile bersampingan terupdate
*/
{
  //ALGORITMA
  P_SetXY(&Pelayan_Posisi(*P),x,y);
  SetUpTile(P,M);
  SetDownTile(P,M);
  SetLeftTile(P,M);
  SetRightTile(P,M);
}
void InitRuangan(Restoran *R)
/*
  menyiapkan ruangan kosong dan menghubungkan semua ruangan
  I.S. R Sembarang
  F.S. setiap room.karakter terisi "",
      room.value berisi ValUndeff
      room.deskripsi berisi ""
      lokasi pusat meja sudah ada nomornya,
      ruangan berniali 0,
      hubungan telah menghubungkan semua ruangan.
*/
{

}

// *** PINDAH ***
void MoveUp(Pelayan *P,MatTile M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat naik
  F.S. Pelayan pindah ke posisi di atasnya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Pelayan_Posisi(*P),-1,0);
  SetUpTile(P,M);
}
void MoveDown(Pelayan *P,MatTile M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat turun
  F.S. Pelayan pindah ke posisi di bawahnya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Pelayan_Posisi(*P),1,0);
  SetDownTile(P,M);
}
void MoveLeft(Pelayan *P,MatTile M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat bergerak ke kiri
  F.S. Pelayan pindah ke posisi di kirinya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Pelayan_Posisi(*P),0,-1);
  SetLeftTile(P,M);
}
void MoveRight(Pelayan *P,MatTile M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat bergerak ke kanan
  F.S. Pelayan pindah ke posisi di kanannya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Pelayan_Posisi(*P),0,1);
  SetRightTile(P,M);
}

// *** BOOLEAN PELAYAN ***
boolean CanMoveUp(Pelayan P,MatTile M)
/*
  fungsi bernilai true jika pelayan dapat MoveUp dan P bukan di pintu
*/
{
  //KAMUS
  boolean flag;
  //ALGORITMA
  flag = false;
  if (Karakter(Up(P))==' ') {
    flag = true;
  }
  return flag;
}
boolean CanMoveDown(Pelayan P,MatTile M)
/*
  fungsi bernilai true jika pelayan dapat MoveDown dan P bukan di pintu
*/
{
  //KAMUS
  boolean flag;
  //ALGORITMA
  flag = false;
  if (Karakter(Down(P))==' ') {
    flag = true;
  }
  return flag;
}
boolean CanMoveLeft(Pelayan P,MatTile M)
/*
  fungsi bernilai true jika pelayan dapat MoveLeft dan P bukan di pintu
*/
{
  //KAMUS
  boolean flag;
  //ALGORITMA
  flag = false;
  if (Karakter(Left(P))==' ') {
    flag = true;
  }
  return flag;
}
boolean CanMoveRight(Pelayan P,MatTile M)
/*
  fungsi bernilai true jika pelayan dapat MoveRight dan P bukan di pintu
*/
{
  //KAMUS
  boolean flag;
  //ALGORITMA
  flag = false;
  if (Karakter(Right(P))==' ') {
    flag = true;
  }
  return flag;
}
boolean IsOnDoor(Pelayan P, Restoran R)
/*
  fungsi mengambalikan true jika P berada di pintu
*/
{
  //KAMUS
  int x,y;
  boolean flag;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(P),&x,&y);
  flag = false;
  if (RoomNow(R)==1) { //room1
    if ((x==8 && y==5) || (x==5 && y==8)) {
      flag = true;
    }
  } else if (RoomNow(R)==2) { //room2
    if ((x==8 && y==5) || (x==2 && y==1)) {
      flag = true;
    }
  } else if (RoomNow(R)==3) { //room3
    if ((x==1 && y==5) || (x==2 && y==1)) {
      flag = true;
    }
  } else { //room4
    if ((x==1 && y==5) || (x==5 && y==8)) {
      flag = true;
    }
  }
  return flag;
}
boolean CanOrder(Pelayan P, Ruangan R)
/*
  fungsi akan bernialai true jika meja dekat p dapat memesan
*/
{
  //KAMUS
  int nomorMeja;
  //ALGORITMA
  nomorMeja = IsNearTable(P,R);
  return Status(AM_Elmt(Meja(R),nomorMeja)) ==  1;
}
int IsNearTable (Pelayan P, Ruangan R)
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
    if (a-1 == x && b ==y) {
      found = true;
    } else if (a+1 == x && b ==y) {
      found = true;
    } else if (a-2 == x && b ==y) {
      found = true;
    } else if (a+2 == x && b ==y) {
      found = true;
    } else if (a == x && b ==y-2) {
      found = true;
    } else if (a == x && b ==y+2) {
      found = true;
    } else if (a-1 == x && b ==y+1) {
      found = true;
    } else if (a-1 == x && b ==y-1) {
      found = true;
    } else if (a+1 == x && b ==y+1) {
      found = true;
    } else if (a+1 == x && b ==y-1) {
      found = true;
    } else i++;
  } //found == true || i > AM_GetLastIdx(arrmeja)
  if (!found) {
    tmp = 0;
  } else {
    tmp = Value(MT_Elmt(Room(R),a,b));
  }
  return tmp;
}

// *** Tile Set ***
void SetUpTile(Pelayan *P,MatTile M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Up pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  Tile tmp;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);
  x -= 1;
  if (MT_IsIdxValid(x,y)) {
    tmp = MT_Elmt(M,x,y);
    Up(*P) = MT_SetTile(Karakter(tmp),Value(tmp));
  } else {
    Up(*P) = MT_SetTile(CharUndeff,ValUndeff);
  }
}
void SetDownTile(Pelayan *P,MatTile M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Down pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  Tile tmp;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);
  x += 1;
  if (MT_IsIdxValid(x,y)) {
    tmp = MT_Elmt(M,x,y);
    Down(*P) = MT_SetTile(Karakter(tmp),Value(tmp));
  } else {
    Down(*P) = MT_SetTile(CharUndeff,ValUndeff);
  }
}
void SetLeftTile(Pelayan *P,MatTile M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Left pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  Tile tmp;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);
  y -= 1;
  if (MT_IsIdxValid(x,y)) {
    tmp = MT_Elmt(M,x,y);
    Left(*P) = MT_SetTile(Karakter(tmp),Value(tmp));
  } else {
    Left(*P) = MT_SetTile(CharUndeff,ValUndeff);
  }
}
void SetRightTile(Pelayan *P,MatTile M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Right pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  Tile tmp;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);
  y += 1;
  if (MT_IsIdxValid(x,y)) {
    tmp = MT_Elmt(M,x,y);
    Right(*P) = MT_SetTile(Karakter(tmp),Value(tmp));
  } else {
    Right(*P) = MT_SetTile(CharUndeff,ValUndeff);
  }
}

// *** RUANGAN ***
void IsiRuang(Restoran *R, int ruangan, MatTile M)
/*
  I.S. R sudah terdeinisi, ruangan dan M juga terdefinisi
  F.S. room ke-(ruangan) di set menjadi seperti M
*/
{
  //ALGORITMA
  MT_CopyMatriks(M,&Room(AR_Elmt(Ruangan(*R),ruangan)));
}

// *** BOOLEAN RUANGAN***
boolean IsTableEmpty(int nomorMeja, Ruangan R)
/*
  mengirimkan true jika meja dengan nomor meja nomor adalah kosong dan bisa
  di duduki, mengirimkan false jika tidak
*/
{
  //ALGORITMA
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
  Tile table;
  int jumlahBangku;
  //ALGORITMA
  table = GetTableTile(P,R);
  jumlahBangku = Bangku(AM_Elmt(Meja(R),Value(table)));
  empty = IsTableEmpty(Value(table),R);
  return empty && (jumlahBangku<=pelanggan);
}

// *** ACTION ***
void Ordering(Pelayan P,Ruangan *R, int *idMakanan,int *nomorMeja)
/*
  I.S. P dan *R terdefinisi, dilakukan jika sudah dipastikan dapat order dan P
    dekat Meja
  F.S.
*/
{
  //KAMUS
  Tile table;
  time_t t;
  //ALGORITMA
  srand((unsigned) time(&t)); //inisialisasi rnd()
  *idMakanan = (rand()%24+1);
  *nomorMeja = IsNearTable(P,*R);
  Status(AM_Elmt(Meja(*R),*nomorMeja)) = 2;
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
void Placing(int pelanggan,int waktuOut, Kata menu,Pelayan *P, Ruangan *R)
/*
  I.S. pelanggan, Pelayan, retoran terdefinisi, meja sebelah Pelayan adalah kosong
  F.S. pelanggan di tempat di meja sesuai jumlahnya
*/
{
  //KAMUS
  int nomorMeja;
  int x,y;
  int i,j;
  int jumlahBangku;
  //ALGORITMA
  P_GetXY(Pelayan_Posisi(*P),&x,&y);

  nomorMeja = IsNearTable(*P,*R);
  P_GetXY(IndeksMeja(nomorMeja,*R),&i,&j);
  Status(AM_Elmt(Meja(*R),nomorMeja)) = 1;
  jumlahBangku = Bangku(AM_Elmt(Meja(*R),nomorMeja));

  //menaruh minimal 2 pelanggan
  MT_Elmt(Room(*R),i,j+1) = MT_SetTile('c',waktuOut);
  MT_Elmt(Room(*R),i,j-1) = MT_SetTile('c',waktuOut);
  if (pelanggan == 4) {
    /*jika pelanggannya 4, tambah 2 karakter 'c' lagi
      bukan saat ada 4 jumlahBangku*/
    MT_Elmt(Room(*R),i+1,j) = MT_SetTile('c',waktuOut);
    MT_Elmt(Room(*R),i-1,j) = MT_SetTile('c',waktuOut);
  }
  if (jumlahBangku==4) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
    MT_Elmt(Room(*R),i+1,j) = MT_SetTile('x',waktuOut);
    MT_Elmt(Room(*R),i-1,j) = MT_SetTile('x',waktuOut);
  }
  PlacePelayan(P,x,y,Room(*R));
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
  nomor = IsNearTable(P,R);
  P_GetXY(IndeksMeja(nomor,R),&i,&j);
  return MT_Elmt(Room(R),i,j);
}
MatTile GetRuangSekarang(Restoran R)
/*
  fungsi mengembalikan suatu matriks yang sedang digunakan berdasarkan Ruangan(R)
*/
{
  //ALGORITMA
  return (Room(AR_Elmt(Ruangan(R),RoomNow(R))));
}
void PelangganKabur(int waktuNow,Pelayan *P,Restoran *R, int *jumlah)
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
  Ruangan tmp;
  //ALGORITMA
  *jumlah = 0;
  for (int j= AR_GetFirstIdx(Ruangan(*R));j<AR_GetLastIdx(Ruangan(*R));j++) {
    tmp = AR_Elmt(Ruangan(*R),j);
    for(int i = AM_GetFirstIdx(Meja(tmp));i<=AM_GetLastIdx(Meja(tmp));i++) {
      P_GetXY(IndeksMeja(i,tmp),&a,&b);
      if (Value(MT_Elmt(Room(tmp),a,b+1))==waktuNow) {
        //saatnya keluar
        *jumlah += 1;
        SetTableEmpty(i,&AR_Elmt(Ruangan(*R),i));
      }
    }
  }
  if (*jumlah > 0) { //hanya dilakukan jika ada pelanggan kabur
    P_GetXY(Pelayan_Posisi(*P),&x,&y);
    PlacePelayan(P,x,y,Room(AR_Elmt(Ruangan(*R),RoomNow(*R))));
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
  MT_Elmt(Room(*R),i,j+1) = MT_SetTile('x',ValUndeff);
  MT_Elmt(Room(*R),i,j-1) = MT_SetTile('x',ValUndeff);
  if (jumlahBangku==4) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
    MT_Elmt(Room(*R),i+1,j) = MT_SetTile('x',ValUndeff);
    MT_Elmt(Room(*R),i-1,j) = MT_SetTile('x',ValUndeff);
  }
  Status(AM_Elmt(Meja(*R),nomorMeja)) = 0;
}
