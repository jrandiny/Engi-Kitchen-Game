
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
  Deskripsi(Up(*P)) = K_MakeKata("");
  //down
  Karakter(Down(*P)) = CharUndeff;
  Value(Down(*P)) = ValUndeff;
  Deskripsi(Down(*P)) = K_MakeKata("");
  //left
  Karakter(Left(*P)) = CharUndeff;
  Value(Left(*P)) = ValUndeff;
  Deskripsi(Left(*P)) = K_MakeKata("");
  //right
  Karakter(Right(*P)) = CharUndeff;
  Value(Right(*P)) = ValUndeff;
  Deskripsi(Right(*P)) = K_MakeKata("");
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
    Deskripsi(Up(*P)) = K_MakeKata("");
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
    Deskripsi(Down(*P)) = K_MakeKata("");
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
    Deskripsi(Left(*P)) = K_MakeKata("");
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
    Deskripsi(Right(*P)) = K_MakeKata("");
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
void Placing(int pelanggan,int kesabaran, Kata menu,Pelayan *P, Matriks *M)
/*
  I.S. pelanggan, Pelayan, retoran terdefinisi, meja sebelah Pelayan adalah kosong
  F.S. pelanggan di tempat di meja sesuai jumlahnya
*/
{
  //KAMUS
  Tile tmp;
  int x,y;
  int i,j;
  Kata isi;
  //ALGORITMA
  x = P_Absis(Posisi(*P));
  y = P_Ordinat(Posisi(*P));

  isi = K_MakeKata("isi");
  tmp = GetTableTile(*P,*M);
  switch (Value(tmp)%4) {
    case 1:
      i = 2;
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
    case 4:
      i = 7;
      j = 7;
      break;
  }
  Deskripsi(M_Elmt(*M,i,j)) = isi;
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
boolean IsTableEmpty(int nomor, Matriks M)
/*
  mengirimkan true jika meja dengan nomor meja nomor adalah kosong dan bisa
  di duduki, mengirimkan false jika tidak
*/
{
  //KAMUS
  boolean tmp;
  Kata cek;
  //ALGORITMA
  cek = K_MakeKata("kosong");
  switch (nomor%4) {
    case 1:
      //2,2
      tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,2,2)));
      break;
    case 2:
      //2,7
      tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,2,7)));
      break;
    case 3:
      //7,2
      tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,7,2)));
      break;
    case 0:
      //7,7
      tmp = K_IsKataSama(cek,Deskripsi(M_Elmt(M,7,7)));
      break;
  }
  return tmp;
}
void KesabaranBerkurang(Restoran *R)
/*
  I.S. R terdefinisi
  F.S. untuk setiap tile dengan katakter c, nilai kesabarannya berkurang 1
*/
{

}
int PelangganKabur(Restoran *R)
/*
  fungsi yang mengembalikan jumlah pelanggan yang kesabarannya mencapai 0
  sekaligus mengembalikan status meja menjadi kosong, karakter menjadi x
  deskripsi menjadi "" dan Value menjadi ValUndeff
*/
{
  
}
