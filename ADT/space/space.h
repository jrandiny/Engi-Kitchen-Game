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
void InitRestoran(Restoran *R);
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
boolean CanOrder(Pelayan P, Ruangan R);
/*
  fungsi akan bernialai true jika meja dekat p dapat memesan
*/
int IsNearTable (Pelayan P, Ruangan R);
/*
  fungsi mengembalikan nomor jika P berada di dekat meja
  akan mengembalikan 0 jika tidak
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

// *** BOOLEAN RUANGAN ***
boolean IsTableEmpty(int nomorMeja, Ruangan R);
/*
  mengirimkan true jika meja dengan nomor meja nomorMeja adalah kosong dan bisa
  di duduki, mengirimkan false jika tidak
*/
boolean CanPlace(int pelanggan,Pelayan P, Ruangan R);
/*
  fungsi menghasilkan true jika meja di dekat P dapat diduduki oleh Pelanggan
  yaitu jumlah bangkunya <= dan sedang kosong
  P harus sebelah bangku ('x')
*/

// *** ACTION ***
void Ordering(Pelayan P,Ruangan *R, int *idMakanan,int *nomorMeja);
/*
  I.S. P dan *R terdefinisi, dilakukan jika sudah dipastikan dapat order dan P
    dekat Meja
  F.S.
*/
int Taking(Pelayan P);
/*
  menghasilkan id makanan yang diambil dengan syarat di dekat P hanya ada
  satu meja bahan ('m')
*/
void Placing(int pelanggan,int waktuOut, Kata menu,Pelayan *P, Ruangan *R);
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

// *** LAIN LAIN ***
Tile GetTableTile(Pelayan P, Ruangan R);
/*
  mengembalikan Tile meja yang bersebelahan dengan Pelayan
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
Point IndeksMeja(int nomor,Ruangan R);
// mengembalikan koordinat dari nomor meja yang diinput. nomor [1..12]
void SetTableEmpty(int nomorMeja, Ruangan *R);
/*
  I.S. P dan R terdefinisi, dipanggil jika p dekat meja
  F.S. membuat meja dengan nomor meja nomorMeja menjadi kosong
*/

#endif
