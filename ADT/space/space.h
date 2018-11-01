//File: space.h
/*merupakan implementasi bentuk lokasi ruangan dengan map dan matriks dan posisi
  Pelayan dengan menggunakan point */

#ifndef SPACE_H
#define SPACE_H

#include "../../std.h"
#include "../point/point.h"
// #include "../../ADT/listlinier/multilist.h"
#include "arrRuangan/arrRuangan.h"
#include "matTile/matTile.h"
#include "arrMeja/arrMeja.h"
#include "pelayan.h"
#include "restoran.h"

// *** KONSTRUKTOR ***
void InitPelayan(Pelayan *P);
/* membuat Pelayan baru
  I.S. Sembarang
  F.S. terbentuk Pelayan dengan posisi di 0,0
      semua karakter bernilai CharUndeff
      semua value bernilai ValUndeff
      semua deskripsi berniali ""
*/
void PlacePelayan(Pelayan *P,int x,int y, MatTile M);
/*
  menaruh Pelayan di posisi (x,y) di ruangan di Restoran r
  I.S. Pelayan,x,y,R terdefinisi
  F.S. Pelayan terletak di posisi x,y di ruangan R semua sisi terupdate
*/
void InitRuangan(Restoran *R);
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

// *** PINDAH ***
void MoveUp(Pelayan *P,MatTile M);
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat naik
  F.S. Pelayan pindah ke posisi di atasnya dan update semua karakter
*/
void MoveDown(Pelayan *P,MatTile M);
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat turun
  F.S. Pelayan pindah ke posisi di bawahnya dan update semua karakter
*/
void MoveLeft(Pelayan *P,MatTile M);
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat bergerak ke kiri
  F.S. Pelayan pindah ke posisi di kirinya dan update semua karakter
*/
void MoveRight(Pelayan *P,MatTile M);
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayan masih dapat bergerak ke kanan
  F.S. Pelayan pindah ke posisi di kanannya dan update semua karakter
*/

// *** BOOLEAN PELAYAN ***
boolean CanMoveUp(Pelayan P,MatTile M);
/*
  fungsi bernilai true jika pelayan dapat MoveUp dan P bukan di pintu
*/
boolean CanMoveDown(Pelayan P,MatTile M);
/*
  fungsi bernilai true jika pelayan dapat MoveDown dan P bukan di pintu
*/
boolean CanMoveLeft(Pelayan P,MatTile M);
/*
  fungsi bernilai true jika pelayan dapat MoveLeft dan P bukan di pintu
*/
boolean CanMoveRight(Pelayan P,MatTile M);
/*
  fungsi bernilai true jika pelayan dapat MoveRight dan P bukan di pintu
*/
boolean IsOnDoor(Pelayan P, Restoran R);
/*
  fungsi mengambalikan true jika P berada di pintu
*/
boolean IsNearTable (Pelayan P, MatTile M);
/*
  fungsi mengembalikan true jika P berada di dekat meja
*/

// *** Tile Set ***
void SetUpTile(Pelayan *P,MatTile M);
/*
  I.S. P dan M terdefinisi
  F.S. Tile Up pada pelayan diisi dengan elemt yang sesuai dengan M
*/
void SetDownTile(Pelayan *P,MatTile M);
/*
  I.S. P dan M terdefinisi
  F.S. Tile Down pada pelayan diisi dengan elemt yang sesuai dengan M
*/
void SetLeftTile(Pelayan *P,MatTile M);
/*
  I.S. P dan M terdefinisi
  F.S. Tile Left pada pelayan diisi dengan elemt yang sesuai dengan M
*/
void SetRightTile(Pelayan *P,MatTile M);
/*
  I.S. P dan M terdefinisi
  F.S. Tile Right pada pelayan diisi dengan elemt yang sesuai dengan M
*/

// *** RUANGAN ***
void IsiRuang(Restoran *R, int ruangan, MatTile M);
/*
  I.S. R sudah terdeinisi, ruangan dan M juga terdefinisi
  F.S. room ke-(ruangan) di set menjadi seperti M
*/
// void PlaceTable(Restoran *R,int nomorMeja, int jumlahBangku);
// /*
//   I.S. R, nomorMeja, dan jumlahBangku terdefinisi, nomoMeja antara 1-12
//        jumlahBangku antara 2 atau 4
//   F.S. meja dengan nomor nomorMeja terdapat bangku kosong sejumlah jumlahBangku
// */

// *** BOOLEAN RUANGAN ***
boolean IsTableEmpty(int nomor, MatTile M);
/*
  mengirimkan true jika meja dengan nomor meja nomor adalah kosong dan bisa
  di duduki, mengirimkan false jika tidak
*/
boolean CanPlace(int pelanggan,Pelayan P, Restoran R);
/*
  fungsi menghasilkan true jika jumlah kursi di dekat P dapat diduduki oleh Pelanggan
  P harus sebelah bangku ('x')
*/

// *** ACTION ***
Kata Ordering(Pelayan P,MatTile M);
/*
  fungsi menghasilkan nama makanan yang diambil, P dipastikan dekat meja
*/
Kata Taking(Pelayan P);
/*
  menghasilkan nama makanan yang diambil dengan syarat di dekat P hanya ada
  satu meja bahan ('m')
*/
void Placing(int pelanggan,int waktuOut, Kata menu,Pelayan *P, MatTile *M);
/*
  I.S. pelanggan,kesabaran,menu, Pelayan, retoran terdefinisi,
      meja sebelah Pelayan adalah kosong
      pelanggan merupakan jumlah pelanggan yang akan duduk
      waktuOut merupakan waktu pelanggan pergi
      menu merupakan nama makanan yang akan dipesan
      hanya dipanggil jika yakin pelanggan bisa diletakkan
  F.S. pelanggan di tempatkan di meja sesuai jumlahnya deskripsi akan bernilai menu
      karakter jadi 'c', value jadi kesabaran, deskripsi nomor meja berubah dari
      kosong menjadi isi
*/
void Giving(Pelayan *P, MatTile *M);
/*
  I.S. P dan M terdefinisi, dipanggil jika give pasti berhasil
  F.S. pelanggan pergi meninggalakan meja, meja menjadi kosong, update tile P
*/

// *** LAIN LAIN ***
Tile GetTableTile(Pelayan P, MatTile M);
/*
  mengembalikan Tile meja yang bersebelahan dengan Pelayan
  di sebelah Pelayan hanya ada satu pelanggan atau 2 pelanggan dari meja yang sama
*/

MatTile GetRuangSekarang(Restoran R);
/*
  fungsi mengembalikan suatu matriks yang sedang digunakan berdasarkan Ruangan(R)
*/
void PelangganKabur(int waktuNow,Pelayan *P,Restoran *R, int *jumlah);
/*
  I.S. waktuNow, P, R terdefinisi
  F.S. jumlah berisi jumlah pelanggan yang waktu keluarnya sudah sama
    dengan waktuNow sekaligus mengembalikan status meja menjadi kosong, karakter
    menjadi x deskripsi menjadi "-" dan Value menjadi ValUndeff
*/
void SetRoomPelangganKabur(MatTile *M,int waktuNow, int *jumlah);
/*
  I.S. M dan waktuNow terdefinisi
  F.S. jumlah berisi jumlah pelanggan yang waktu keluarnya sudah sama
    dengan waktuNow sekaligus mengembalikan status meja menjadi kosong, karakter
    menjadi x deskripsi menjadi "-" dan Value menjadi ValUndeff
*/
Point IndeksMeja(int nomor);
// mengembalikan koordinat dari nomor meja yang diinput. nomor [1..12]


#endif
