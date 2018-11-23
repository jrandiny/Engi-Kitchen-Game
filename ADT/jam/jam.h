/* Kelompok : UAS
   Nama File : jam.h
   Deskripsi : ADT untuk tipe Jam */


#ifndef JAM_H
#define JAM_H

#include "../../std.h"

/* *** Definisi TYPE Jam <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} Jam;

/* *** Notasi Akses: selektor Jam *** */
#define J_Hour(J) (J).HH
#define J_Minute(J) (J).MM
#define J_Second(J) (J).SS

#endif
