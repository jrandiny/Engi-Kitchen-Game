
#include "space.h"

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
  P_Absis(Posisi(*P)) = 0;
  P_Ordinat(Posisi(*P)) = 0;
  //up
  Karakter(Up(*P)) = CharUndeff;
  Value(Up(*P)) = ValUndeff;
  Deskripsi(Up(*P)) = K_MakeKata("-");
  //down
  Karakter(Down(*P)) = CharUndeff;
  Value(Down(*P)) = ValUndeff;
  Deskripsi(Down(*P)) = K_MakeKata("-");
  //left
  Karakter(Left(*P)) = CharUndeff;
  Value(Left(*P)) = ValUndeff;
  Deskripsi(Left(*P)) = K_MakeKata("-");
  //right
  Karakter(Right(*P)) = CharUndeff;
  Value(Right(*P)) = ValUndeff;
  Deskripsi(Right(*P)) = K_MakeKata("-");
}
void PlacePelayan(Pelayan *P,int x,int y, Matriks M)
/*
  menaruh Pelayan di posisi (x,y) di ruangan di Restoran r
  I.S. Pelayan,x,y,R terdefinisi
  F.S. Pelayan terletak di posisi x,y di ruangan di R Tile bersampingan terupdate
*/
{
  //ALGORITMA
  P_Absis(Posisi(*P)) = x;
  P_Ordinat(Posisi(*P)) = y;
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
void MoveUp(Pelayan *P,Matriks M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat naik
  F.S. Pelayan pindah ke posisi di atasnya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Posisi(*P),-1,0);
  SetUpTile(P,M);
}
void MoveDown(Pelayan *P,Matriks M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat turun
  F.S. Pelayan pindah ke posisi di bawahnya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Posisi(*P),1,0);
  SetDownTile(P,M);
}
void MoveLeft(Pelayan *P,Matriks M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat bergerak ke kiri
  F.S. Pelayan pindah ke posisi di kirinya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Posisi(*P),0,-1);
  SetLeftTile(P,M);
}
void MoveRight(Pelayan *P,Matriks M)
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat bergerak ke kanan
  F.S. Pelayan pindah ke posisi di kanannya dan update semua karakter
*/
{
  //ALGORITMA
  P_Geser(&Posisi(*P),0,1);
  SetRightTile(P,M);
}

// *** BOOLEAN PELAYAN ***
boolean CanMoveUp(Pelayan P,Matriks M)
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
boolean CanMoveDown(Pelayan P,Matriks M)
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
boolean CanMoveLeft(Pelayan P,Matriks M)
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
boolean CanMoveRight(Pelayan P,Matriks M)
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
  x = P_Absis(Posisi(P));
  y = P_Ordinat(Posisi(P));
  flag = false;
  if (Ruangan(R)==1) { //room1
    if ((x==8 && y==5) || (x==5 && y==8)) {
      flag = true;
    }
  } else if (Ruangan(R)==2) { //room2
    if ((x==8 && y==5) || (x==2 && y==1)) {
      flag = true;
    }
  } else if (Ruangan(R)==3) { //room3
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
boolean IsNearTable (Pelayan P, Matriks M)
/*
  fungsi mengembalikan true jika P berada di dekat meja
*/
{
  //KAMUS
  boolean flag;
  //ALGORITMA
  flag = false;
  if (Karakter(Up(P)) == 'c' || Karakter(Up(P)) == 'x'){ //ada meja di atas
    flag = true;
  } else if (Karakter(Down(P)) == 'c' || Karakter(Down(P)) == 'x'){ //ada meja di bawah
    flag = true;
  } else if (Karakter(Left(P)) == 'c' || Karakter(Left(P)) == 'x'){ //ada meja di kiri
    flag = true;
  } else if (Karakter(Right(P)) == 'c' || Karakter(Right(P)) == 'x'){ //ada meja di kanan
    flag = true;
  }
  return flag;
}

// *** Tile Set ***
void SetUpTile(Pelayan *P,Matriks M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Up pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));
  x -= 1;
  if (M_IsIdxValid(x,y)) {
    Karakter(Up(*P)) = Karakter(M_Elmt(M,x,y));
    Value(Up(*P)) = Value(M_Elmt(M,x,y));
    // K_CopyKata(Deskripsi(M_Elmt(M,x,y)),&Deskripsi(Up(*P)));
    Deskripsi(Up(*P)) = Deskripsi(M_Elmt(M,x,y));
  } else {
    Karakter(Up(*P)) = CharUndeff;
    Value(Up(*P)) = ValUndeff;
    Deskripsi(Up(*P)) = K_MakeKata("-");
  }
}
void SetDownTile(Pelayan *P,Matriks M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Down pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));
  x += 1;
  if (M_IsIdxValid(x,y)) {
    Karakter(Down(*P)) = Karakter(M_Elmt(M,x,y));
    Value(Down(*P)) = Value(M_Elmt(M,x,y));
    Deskripsi(Down(*P)) = Deskripsi(M_Elmt(M,x,y));
  } else {
    Karakter(Down(*P)) = CharUndeff;
    Value(Down(*P)) = ValUndeff;
    Deskripsi(Down(*P)) = K_MakeKata("-");
  }
}
void SetLeftTile(Pelayan *P,Matriks M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Left pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));
  y -= 1;
  if (M_IsIdxValid(x,y)) {
    Karakter(Left(*P)) = Karakter(M_Elmt(M,x,y));
    Value(Left(*P)) = Value(M_Elmt(M,x,y));
    Deskripsi(Left(*P)) = Deskripsi(M_Elmt(M,x,y));
  } else {
    Karakter(Left(*P)) = CharUndeff;
    Value(Left(*P)) = ValUndeff;
    Deskripsi(Left(*P)) = K_MakeKata("-");
  }
}
void SetRightTile(Pelayan *P,Matriks M)
/*
  I.S. P dan M terdefinisi
  F.S. Tile Right pada pelayan diisi dengan elemt yang sesuai dengan M
*/
{
  //KAMUS
  int x,y;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));
  y += 1;
  if (M_IsIdxValid(x,y)) {
    Karakter(Right(*P)) = Karakter(M_Elmt(M,x,y));
    Value(Right(*P)) = Value(M_Elmt(M,x,y));
    Deskripsi(Right(*P)) = Deskripsi(M_Elmt(M,x,y));
  } else {
    Karakter(Right(*P)) = CharUndeff;
    Value(Right(*P)) = ValUndeff;
    Deskripsi(Right(*P)) = K_MakeKata("-");
  }
}

// *** RUANGAN ***
void IsiRuang(Restoran *R, int ruangan, Matriks M)
/*
  I.S. R sudah terdeinisi, ruangan dan M juga terdefinisi
  F.S. room ke-(ruangan) di set menjadi seperti M
*/
{
  //ALGORITMA
  switch ((Ruangan(*R))) {
    case 1:
      M_CopyMatriks(M,&Room1(*R));
      break;
    case 2:
      M_CopyMatriks(M,&Room2(*R));
      break;
    case 3:
      M_CopyMatriks(M,&Room3(*R));
      break;
    case 4:
      M_CopyMatriks(M,&Room4(*R));
      break;
  }

}
// void PlaceTable(Restoran *R,int nomorMeja, int jumlahBangku)
// /*
//   I.S. R, nomorMeja, dan jumlahBangku terdefinisi, nomoMeja antara 1-12
//        jumlahBangku antara 2 atau 4
//   F.S. meja dengan nomor nomorMeja terdapat bangku kosong sejumlah jumlahBangku
// */
// {
//
// }

// *** BOOLEAN RUANGAN***
boolean IsTableEmpty(int nomor, Matriks M)
/*
  mengirimkan true jika meja dengan nomor meja nomor adalah kosong dan bisa
  di duduki, mengirimkan false jika tidak
*/
{
  //KAMUS
  boolean tmp;
  Kata cek;
  Point indeks;
  //ALGORITMA
  cek = K_MakeKata("kosong");
  indeks = IndeksMeja(nomor);
  tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,P_Absis(indeks),P_Ordinat(indeks))));
  // switch (nomor%4) {
  //   case 1:
  //     //3,2
  //     tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,3,2)));
  //     break;
  //   case 2:
  //     //2,7
  //     tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,2,7)));
  //     break;
  //   case 3:
  //     //7,2
  //     tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,7,2)));
  //     break;
  //   case 0:
  //     //7,7
  //     tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,7,7)));
  //     break;
  // }
  return tmp;
}
boolean CanPlace(int pelanggan,Pelayan P, Restoran R)
/*
  fungsi menghasilkan true jika jumlah kursi di dekat P dapat diduduki oleh Pelanggan
  P harus sebelah bangku ('x')
*/
{
  //KAMUS
  Matriks M;
  Tile meja;
  boolean flag;
  Kata kosong;
  //ALGORITMA
  flag = false;
  M = GetRuangSekarang(R);
  meja = GetTableTile(P,M);
  kosong = K_MakeKata("kosong");
  if (K_IsKataSama(Deskripsi(meja),kosong)) {
    flag = (pelanggan <= (int)(Karakter(meja)-'0'));
  }
  return flag;
}

// *** ACTION ***
Kata Ordering(Pelayan P,Matriks M)
/*
  fungsi menghasilkan nama makanan yang diambil, P dipastikan dekat meja
*/
{
  //KAMUS
  Kata makanan;
  //ALGORITMA
  if (Karakter(Up(P)) == 'c' || Karakter(Up(P)) == 'x'){ //ada meja di atas
    makanan = Deskripsi(Up(P));
  } else if (Karakter(Down(P)) == 'c' || Karakter(Down(P)) == 'x'){ //ada meja di bawah
    makanan = Deskripsi(Down(P));
  } else if (Karakter(Left(P)) == 'c' || Karakter(Left(P)) == 'x'){ //ada meja di kiri
    makanan = Deskripsi(Left(P));
  } else { //ada meja di kanan
    makanan = Deskripsi(Right(P));
  }
  return makanan;
}
Kata Taking(Pelayan P)
/*
  menghasilkan nama makanan yang diambil dengan syarat di dekat P hanya ada
  satu meja bahan ('m')
*/
{
  //KAMUS
  Kata makanan;
  //ALGORITMA
  if (Karakter(Up(P)) == 'm'){ // 'm' ada di atas
    makanan = Deskripsi(Up(P));
  } else if (Karakter(Down(P)) == 'm'){ // 'm' ada di bawah
    makanan = Deskripsi(Down(P));
  } else if (Karakter(Left(P)) == 'm'){ // 'm' ada di kiri
    makanan = Deskripsi(Left(P));
  } else { //'m' ada di kanan
    makanan = Deskripsi(Right(P));
  }
  return makanan;
}
void Placing(int pelanggan,int waktuOut, Kata menu,Pelayan *P, Matriks *M)
/*
  I.S. pelanggan, Pelayan, retoran terdefinisi, meja sebelah Pelayan adalah kosong
  F.S. pelanggan di tempat di meja sesuai jumlahnya
*/
{
  //KAMUS
  Tile meja;
  int x,y;
  int i,j;
  Kata isi;
  Point indeks;
  int jumlahBangku;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));

  isi = K_MakeKata("isi");
  meja = GetTableTile(*P,*M);
  indeks = IndeksMeja(Value(meja));
  i = P_Absis(indeks);
  j = P_Ordinat(indeks);
  Deskripsi(M_Elmt(*M,i,j)) = isi;
  jumlahBangku = (int) (Karakter(meja)-'0');

  //menaruh minimal 2 pelanggan
  Karakter(M_Elmt(*M,i,j+1)) = 'c';
  Karakter(M_Elmt(*M,i,j-1)) = 'c';
  if (pelanggan == 4) {
    /*jika pelanggannya 4, tambah 2 karakter 'c' lagi
      bukan saat ada 4 jumlahBangku*/
  Karakter(M_Elmt(*M,i+1,j)) = 'c';
  Karakter(M_Elmt(*M,i-1,j)) = 'c';
  }

  //menaruh minial 2 value dan deskripsi
  Value(M_Elmt(*M,i,j+1)) = waktuOut;
  Value(M_Elmt(*M,i,j-1)) = waktuOut;
  Deskripsi(M_Elmt(*M,i,j+1)) = menu;
  Deskripsi(M_Elmt(*M,i,j-1)) = menu;
  if (jumlahBangku==4) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
    Value(M_Elmt(*M,i+1,j)) = waktuOut;
    Value(M_Elmt(*M,i-1,j)) = waktuOut;
    Deskripsi(M_Elmt(*M,i+1,j)) = menu;
    Deskripsi(M_Elmt(*M,i-1,j)) = menu;
  }
  PlacePelayan(P,x,y,*M);

  // if (i+2 == x && j == y) { // nomor meja 2 petak di atas p
  //   Karakter(M_Elmt(*M,i+1,j)) = 'c';
  //   Karakter(M_Elmt(*M,i-1,j)) = 'c';
  //   Karakter(Up(*P)) = 'c';
  //   Value(M_Elmt(*M,i+1,j)) = ValUndeff;
  //   Value(M_Elmt(*M,i-1,j)) = ValUndeff;
  //   Value(Up(*P)) = ValUndeff;
  // } else if (i+1 == x && j-1 == y) { //nomor meja di timur laut p
  //
  // } else if (i == x && j-2 == y) { //nomor meja 2 petak di kanan p
  //
  // } else if (i-1 == x && j-1 == y) { // nomor meja di tenggara p
  //
  // } else if (i-2 == x && j == y) { //nomor meja 2 petak di bawah p
  //
  // } else if (i-1 == x && j+1 == y) { //nomor meja di barat daya p
  //
  // } else if (i== x && j+2 == y) { //nomor meja 2 petak di kiri p
  //
  // } else { //nomor meja di barat laut p
  //
  // }
}
void Giving(Pelayan *P, Matriks *M)
/*
  I.S. P dan M terdefinisi, dipanggil jika give pasti berhasil
  F.S. pelanggan pergi meninggalakan meja, meja menjadi kosong, update tile P
*/
{
  //KAMUS
  Tile meja;
  Point indeks;
  int i,j;
  int x,y;
  int jumlahBangku;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));
  meja = GetTableTile(*P,*M);
  indeks = IndeksMeja(Value(meja));
  i = P_Absis(indeks);
  j = P_Ordinat(indeks);

  jumlahBangku = (int) (Karakter(M_Elmt(*M,i,j))-'0');

  //merubah minimal 2 pelanggan
  Karakter(M_Elmt(*M,i,j+1)) = 'x';
  Karakter(M_Elmt(*M,i,j-1)) = 'x';
  Value(M_Elmt(*M,i,j+1)) = ValUndeff;
  Value(M_Elmt(*M,i,j-1)) = ValUndeff;
  Deskripsi(M_Elmt(*M,i,j+1)) = K_MakeKata("-");
  Deskripsi(M_Elmt(*M,i,j-1)) = K_MakeKata("-");
  if (jumlahBangku==4) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
    Karakter(M_Elmt(*M,i+1,j)) = 'x';
    Karakter(M_Elmt(*M,i-1,j)) = 'x';
    Value(M_Elmt(*M,i+1,j)) = ValUndeff;
    Value(M_Elmt(*M,i-1,j)) = ValUndeff;
    Deskripsi(M_Elmt(*M,i+1,j)) = K_MakeKata("-");
    Deskripsi(M_Elmt(*M,i-1,j)) = K_MakeKata("-");
  }
  Deskripsi(M_Elmt(*M,i,j)) = K_MakeKata("kosong");

  PlacePelayan(P,x,y,*M);
}

// *** LAIN LAIN ***
Tile GetTableTile(Pelayan P, Matriks M)
/*
  mengembalikan nilai meja yang bersebelahan dengan Pelayan
  di sebelah Pelayan hanya ada satu pelanggan atau 2 pelanggan dari meja yang sama
*/
{
  //KAMUS
  Tile tmp;
  int x,y;
  //ALGORITMA
  x = P_Absis(Posisi(P));
  y = P_Ordinat(Posisi(P));
  if (Karakter(Up(P)) != ' ') { //up
    if (Karakter(Left(P)) != ' ') { //depan dan kiri
      tmp = (M_Elmt(M,x-1,y-1));
    } else if (Karakter(Right(P)) != ' ') { //depan dan kanan
      tmp = (M_Elmt(M,x-1,y+1));
    } else { //hanya depan
      if (Karakter(M_Elmt(M,x-2,y)) == 'n') {
        //nomor meja 2 petak di atas
        tmp = (M_Elmt(M,x-2,y));
      } else if (Karakter(M_Elmt(M,x-1,y+1)) == 'n') {
        //nomor meja di samping kanan pelanggan
        tmp = (M_Elmt(M,x-1,y+1));
      } else {
        //nomor meja di samping kiri pelanggan
        tmp = (M_Elmt(M,x-1,y-1));
      }
    }
  } else if (Karakter(Down(P)) != ' ') { //down
    if (Karakter(Left(P)) != ' ') { //bawah dan kiri
      tmp = (M_Elmt(M,x+1,y-1));
    } else if (Karakter(Right(P)) != ' ') { //bawah dan kanan
      tmp = (M_Elmt(M,x+1,y+1));
    } else { //hanya bawah
      if (Karakter(M_Elmt(M,x+2,y)) == 'n') {
        //nomor meja 2 petak di bawah
        tmp = (M_Elmt(M,x+2,y));
      } else if (Karakter(M_Elmt(M,x+1,y+1)) == 'n') {
        //nomor meja di samping kanan pelanggan
        tmp = (M_Elmt(M,x+1,y+1));
      } else {
        //nomor meja di samping kiri pelanggan
        tmp = (M_Elmt(M,x+1,y-1));
      }
    }
  } else if (Karakter(Left(P)) != ' ') { //left
    if (Karakter(M_Elmt(M,x,y-2)) == 'n') {
      //nomor meja 2 petak di kiri
      tmp = (M_Elmt(M,x,y-2));
    } else if (Karakter(M_Elmt(M,x-1,y-1)) == 'n') {
      //nomor meja di sebelah atas pelanggan
      tmp = (M_Elmt(M,x-1,y-1));
    } else {
      //nomor meja di sebelah bawah pelanggan
      tmp = (M_Elmt(M,x+1,y-1));
    }
  } else{ //right
    if (Karakter(M_Elmt(M,x,y+2)) == 'n') {
      //nomor meja 2 petak di kanan
      tmp = (M_Elmt(M,x,y+2));
    } else if (Karakter(M_Elmt(M,x-1,y+1)) == 'n') {
      //nomor meja di sebelah atas pelanggan
      tmp = (M_Elmt(M,x-1,y+1));
    } else {
      //nomor meja di sebelah bawah pelanggan
      tmp = (M_Elmt(M,x+1,y+1));
    }
  }
}
Matriks GetRuangSekarang(Restoran R)
/*
  fungsi mengembalikan suatu matriks yang sedang digunakan berdasarkan Ruangan(R)
*/
{
  //KAMUS
  Matriks M;
  //ALGORITMA
  switch ((Ruangan(R))) {
    case 1:
      M_CopyMatriks(Room1(R),&M);
      break;
    case 2:
      M_CopyMatriks(Room2(R),&M);
      break;
    case 3:
      M_CopyMatriks(Room3(R),&M);
      break;
    case 4:
      M_CopyMatriks(Room4(R),&M);
      break;
  }
  return M;
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
  Point indeks;
  int count;
  int x,y;
  Matriks M;
  //ALGORITMA
  *jumlah = 0;
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));
  SetRoomPelangganKabur(&Room1(*R),waktuNow,&count);
  *jumlah += count;
  SetRoomPelangganKabur(&Room2(*R),waktuNow,&count);
  *jumlah += count;
  SetRoomPelangganKabur(&Room3(*R),waktuNow,&count);
  *jumlah += count;
  M = GetRuangSekarang(*R);
  PlacePelayan(P,x,y,M);
}
void SetRoomPelangganKabur(Matriks *M,int waktuNow, int *jumlah)
/*
  I.S. M dan waktuNow terdefinisi
  F.S. menghasilkan jumlah pelanggan yang waktu keluar == waktuNow, dan mengupdate
      karakter dan value mejanya
*/
{
  //KAMUS
  Point indeks;
  int i,j;
  int jumlahBangku;
  //ALGORITMA
  *jumlah = 0;
  for(int i = 1;i<=3;i++) {
    indeks = IndeksMeja(i);
    i = P_Absis(indeks);
    j = P_Ordinat(indeks);
    if (Value(M_Elmt(*M,i,j))==waktuNow) {
      //saatnya keluar
      *jumlah += 1;
      jumlahBangku = (int) (Karakter(M_Elmt(*M,i,j))-'0');

      //merubah minimal 2 pelanggan
      Karakter(M_Elmt(*M,i,j+1)) = 'x';
      Karakter(M_Elmt(*M,i,j-1)) = 'x';
      Value(M_Elmt(*M,i,j+1)) = ValUndeff;
      Value(M_Elmt(*M,i,j-1)) = ValUndeff;
      Deskripsi(M_Elmt(*M,i,j+1)) = K_MakeKata("-");
      Deskripsi(M_Elmt(*M,i,j-1)) = K_MakeKata("-");
      if (jumlahBangku==4) { //jika bangku ada 4, tambah 2 valur dan deskripsi lagi
        Karakter(M_Elmt(*M,i+1,j)) = 'x';
        Karakter(M_Elmt(*M,i-1,j)) = 'x';
        Value(M_Elmt(*M,i+1,j)) = ValUndeff;
        Value(M_Elmt(*M,i-1,j)) = ValUndeff;
        Deskripsi(M_Elmt(*M,i+1,j)) = K_MakeKata("-");
        Deskripsi(M_Elmt(*M,i-1,j)) = K_MakeKata("-");
      }
      Deskripsi(M_Elmt(*M,i,j)) = K_MakeKata("kosong");
    }
  }
}
Point IndeksMeja(int nomor)
// mengembalikan koordinat dari nomor meja yang diinput. nomor [1..12]
{
  //KAMUS
  Point tmp;
  int i,j;
  //ALGORITMA
  switch (nomor%4) {
    case 1:
      i = 3;
      j = 2;
      break;
    case 2:
      i = 2;
      j = 7;
      break;
    case 3:
      i = 7;
      j = 2;
      break;
    case 0:
      i = 7;
      j = 7;
      break;
  }
  tmp = P_MakePoint(i,j);
  return tmp;
}
