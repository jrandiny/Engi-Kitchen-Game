#ifndef EKSTERNAL_H
#define EKSTERNAL_H

#include "../../std.h"
#include "../../ADT.h"
#include "../../ADT/food/food.h"
#include "../../ADT/food/stacktfood.h"
#include "../../ADT/arrOrder/order.h"
#include "../../ADT/arrOrder/arrOrder.h"
#include "../../ADT/space/space.h"

/*Bagian Load File Eksternal*/

void ParserLocate(Kata input,int *pos1, int *pos2);
/*I.S. input valid, pos1 dan pos2 kosong
  F.S. pos1 dan pos2 berisi index letak parse
       jika tidak ditemukan pos berisi -1
*/

Order ParseOrder(Kata Scanned);
/*mengembalikan tipe order dari stack dari hasil parsing kata*/ 

Food ParseTFood(Kata Scanned,boolean* kiri,int* parentID);
/*mengembalikan tipe food dari tree dari hasil parsing kata, kiri berisi apakah ia leaf kiri,parentid berisi id pangkal*/

Food ParseSFood(Kata Scanned);
/*mengembalikan tipe food dari stack dari hasil parsing kata*/ 

Pelayan ParsePelayan(Kata Scanned);
/*mengembalikan tipe pelayan dari hasil parsing kata */

Kata ParseNama(Kata scanned);
/* parsing nama*/

Tile ParseTile(Kata scanned);
/* mengembalikan tipe tile dari hasil parsing kata */

Meja ParseMeja(Kata scanned);
/* mengembalikan tipe meja dari hasil parsing kata */

customer ParseCustomer(Kata scanned);
/* mengembalikan tipe customer dari hasil parsing kata */

Door ParseDoor(Kata scanned);
/* mengembalikan tipe door dari hasil parsing kata */

MatTile TakeMatTile(Kata X);
/*CKata berada di jumlah tile yg akan diambil/X, mengambil X kata berikutnya menjadi elemen MatTile*/

ArrMeja TakeArrMeja(Kata X,MatTile mattile);
/*CKata berada di jumlah meja yg akan diambil/X, mengambil X kata berikutnya menjadi elemen ArrMeja*/

Restoran ParseRestoran();
/*CKata berada di kata restoran*/

GrafRuangan ParseGrafRuangan(Kata X);
/*Ckata berada di jumlah komponen rungan, mengambil X bagian berikutnya menjadi grafruangan*/

PrioQueueCustomer ParsePrioQueue(Kata X);
/*Ckata berada di kata queue*/

TreeFood ParseTreeFood(Kata X);
/*Ckata berada di kata tree*/

StackFood ParseStackFood(Kata X);
/*Ckata berada di kata stackhand atau stacktray*/

ArrOrder ParseArrOrder(Kata X);
/*Ckata berada di kata order*/

void LoadFile(int* status, Kata* nama,int* money, int* life, int* waktu,Restoran* restoran,Pelayan* pelayan,PrioQueueCustomer *prioqueue,StackFood* hand,StackFood* tray,ArrOrder* arrorder);
/*I.S. bebas
  F.S. status memberikan status apakah file berhasil di load(1) atau tidak(0)
  parameter sisanya berisi data sesuai file eksternal
  */


void LoadTree(int* status,TreeFood* TreeFood);
/*I.S. bebas
  F.S. status memberikan status apakah file berhasil di load(1) atau tidak(0)
  parameter sisanya berisi data sesuai file eksternal, treefood berisi sesuai file ex*/

/*Bagian Save File Eksternal*/

void WriteSpace(FILE* namafile);
/* I.S. bebas
   F.S. di namafile tertulis spasi*/

void WriteName(FILE* namafile,Kata name);
/* I.S. namafile dan name terdefinisi
   F.S. tertulis name di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteTile(FILE* namafile,Tile tile);
/* I.S. namafile dan tile terdefinisi
   F.S. tertulis tile di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/


void WriteMeja(FILE* namafile,Meja meja);
/* I.S. namafile dan meja terdefinisi
   F.S. tertulis meja di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteCustomer(FILE* namafile,customer customer);
/* I.S. namafile dan customer terdefinisi
   F.S. tertulis customer di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteDoor(FILE* namafile,Door door);
/* I.S. namafile dan door terdefinisi
   F.S. tertulis door di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteMatriksTile(FILE* namafile,MatTile mattile);
/* I.S. namafile dan mattile terdefinisi
   F.S. tertulis mattile di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteArrayMeja(FILE* namafile,ArrMeja arrmeja);
/* I.S. namafile dan arrmeja terdefinisi
   F.S. tertulis arrmeja di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteFood(FILE* namafile,Food food);
/* I.S. namafile dan food terdefinisi
   F.S. tertulis food di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void WriteOrder(FILE* namafile,Order order);
/* I.S. namafile dan order terdefinisi
   F.S. tertulis order di namafile tanpa diawali atau diakhiri karakter apapun sesuai format*/

void SaveFile(Kata nama,int money, int life, int waktu,Restoran restoran,Pelayan pelayan,PrioQueueCustomer prioqueue,StackFood hand,StackFood tray,ArrOrder arrorder);
/*I.S. bebas
  F.S. data nama,money,dll tersave di file eksternal dengan nama sesuai nama
  */

#endif
