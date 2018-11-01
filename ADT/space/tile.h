//File : tile.h
/* merupakan tipe data tile */

#ifndef TILE_H
#define TILE_H

#include "../mesinkata/mesinkata.h"

typedef struct {
	char karakter; //merupakan karakter yang ditampilkan di layar
	int value;
	/* angka kesabaran untuk pengunjung duduk, ValUndeff untuk tile, nomor meja
	dan nampan, id makanan untuk meja di dapur
	*/
	Kata deskripsi; //berisi nama makanan|| customer|| nomor meja|| lantai|| nampan
} Tile;
/*
	karakter bernilai
		' '(spasi) kosong jika dia lantai kosong
		x jika bangku kosong
		c jika ada pelanggan
		m jika meja
		2||4 jika nomor meja
		t jika nampan
		CharUndeff jika dekat pintu atau tembok
	value bernilai (bergantung karakter)
		waktu keluar pelanggan
		id makanan
		[1..12] jika nomor meja
		ValUndeff untuk sisanya
	Deskripsi bernilai (bergantung karakter)
		"-" jika lantai, pintu, atau tembok
		nama makanan berdasarkan id makanan untuk meja makanan
		makanan pilihan customer jika pelanggan
		isi||kosong jika nomor meja
		nampan jika karakter==t
*/
#define Karakter(M) (M).karakter
#define Value(M) (M).value
#define Deskripsi(M) (M).deskripsi

#endif
