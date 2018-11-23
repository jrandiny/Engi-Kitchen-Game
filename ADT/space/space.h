/* Kelompok  : UAS
   Nama file : space.h
   Deskripsi : ADT untuk tipe space */
/*merupakan implementasi bentuk lokasi ruangan dengan map dan matriks dan posisi
  Pelayan dengan menggunakan point */

#ifndef SPACE_H
#define SPACE_H

#include "../../std.h"
#include "../point/point.h"
#include "../arrInt/arrInt.h"
#include "matTile/matTile.h"
#include "arrMeja/arrMeja.h"
#include "grafRuangan/grafRuangan.h"
#include "pelayan.h"
#include "restoran.h"

void PlacePelayan(Pelayan *P,int x,int y, MatTile M);
/*
  menaruh Pelayan di posisi (x,y) di ruangan di Restoran r
  I.S. Pelayan,x,y,R terdefinisi
  F.S. Pelayan terletak di posisi x,y di ruangan R semua sisi terupdate
*/

/* *** PINDAH *** */
void Move(Pelayan *P,Restoran *R, int code, boolean *status, boolean *justMove);
/*
  I.S. Pelayan dan Restoran terdifinsi, Pelayang dapat bergerak ke arah code
  F.S. Jika bershasil, maka Pelayan pindah ke posisi sesuai code dan
      update semua karakter lalu status bernilai true.
      jika tidak, status bernilai false
      justMove berniali true jika pindah ruangan, false jika tidak
  code: 1 = Up
        2 = Right
        3 = Down
        4 = Left
*/

/* *** BOOLEAN PELAYAN *** */
boolean CanOrder(Pelayan P, Ruangan R);
/*
  fungsi akan bernialai true jika meja dekat p dapat memesan
*/
boolean CanTake(Pelayan P);
/*
  fungsi bernilai true jika di dekat P ada m yang bisa diambil idnya
*/
boolean CanPut(Pelayan P);
/*
  fungsi bernilai true jika di dekat P ada t yang bisa diput
*/

/* *** Tile Set *** */
void SetTile(Pelayan *P,MatTile M, int kode);
/*
  I.S. P, M, kode terdefinisi
  F.S. Tile pada pelayan diisi dengan elemt yang sesuai dengan M menurut kode
*/

/* *** BOOLEAN RUANGAN *** */
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

/* *** ACTION *** */
void Ordering(Pelayan P,Ruangan *R, int *idMakanan,int nomorMeja);
/*
  I.S. P dan *R terdefinisi, dilakukan jika sudah dipastikan dapat order dan P
    dekat Meja
  F.S. status meja menajadi sudah order, idMakanan berisi id makanan yang dirandom
    nomorMeja berisi nomor meja yang memesan
*/
int Taking(Pelayan P);
/*
  menghasilkan id makanan yang diambil dengan syarat di dekat P hanya ada
  satu meja bahan ('m')
*/
void Placing(int pelanggan,int waktuOut, Pelayan *P, Ruangan *R);
/*
  I.S. pelanggan,waktuOut,Pelayan, retoran terdefinisi,
      meja sebelah Pelayan adalah kosong
      pelanggan merupakan jumlah pelanggan yang akan duduk
      waktuOut merupakan waktu pelanggan pergi
      hanya dipanggil jika yakin pelanggan bisa diletakkan
  F.S. pelanggan di tempatkan di meja sesuai jumlahnya
      karakter jadi 'c', value jadi waktuOut
*/

/* *** LAIN LAIN *** */
Tile GetTableTile(Pelayan P, Ruangan R);
/*
  mengembalikan Tile meja yang bersebelahan dengan Pelayan
*/
MatTile GetMatTileSekarang(Restoran R);
/*
  fungsi mengembalikan suatu tipe MatTile yang sedang digunakan berdasarkan Ruangan(R)
*/
Ruangan* GetRuanganSekarang(Restoran R);
/*
  fungsi mengembalikan suatu tipe Ruangan yang sedang digunakan berdasarkan Ruangan(R)
*/
void PelangganKabur(int waktuNow,Pelayan *P,Restoran *R, int *jumlah,ArrInt *arrinteger);
/*
  I.S. waktuNow, P, R, arrinteger terdefinisi
  F.S. jumlah berisi jumlah pelanggan yang waktu keluarnya sudah sama
    dengan waktuNow sekaligus mengembalikan status meja menjadi kosong, karakter
    menjadi x deskripsi menjadi "-" dan Value menjadi ValUndeff
*/
Point IndeksMeja(int nomor,Ruangan R);
/* mengembalikan koordinat dari nomor meja yang diinput. nomor [1..12] */

void SetTableEmpty(int nomorMeja, Ruangan *R);
/*
  I.S. P dan R terdefinisi, dipanggil jika p dekat meja
  F.S. membuat meja dengan nomor meja nomorMeja menjadi kosong
*/
int GetTableNumber (Pelayan P, Ruangan R);
/*
  fungsi mengembalikan nomor jika P berada di dekat meja
  akan mengembalikan 0 jika tidak
*/

#endif
