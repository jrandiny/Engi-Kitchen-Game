/* NIM/Nama  : 13517063/Joshua Christo Randiny
   Nama file : jam.c
   Topik     : Modul Prapraktikum 01
   Tanggal   : 29-08-2018
   Deskripsi : ADT untuk tipe JAM*/

#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
  return (((H>=0)&&(H<=23)) && ((M>=0)&&(M<=59)) && ((S>=0)&&(S<=59)));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
  /* KAMUS */
  JAM J;

  /* ALGORITMA */
  Hour(J) = HH;
  Minute(J) = MM;
  Second(J) = SS;

  return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
  /* KAMUS */
  int H,M,S;

  /* ALGORITMA */
  while(true){
    scanf("%d %d %d",&H,&M,&S);
    if(IsJAMValid(H,M,S)){
      break;
    }
    printf("Jam tidak valid\n");
  }
  /* IsJAMValid(H,M,S)*/

  *J = MakeJAM(H,M,S);
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
  printf("%02d:%02d:%02d",Hour(J),Minute(J),Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
  /* KAMUS */
  long durasi;

  /* ALGORITMA */
  durasi = Hour(J) * 3600;
  durasi += Minute(J) * 60;
  durasi += Second(J);

  return durasi;
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
  /* KAMUS */
  int H,M,S;

  /* ALGORITMA */
  N = N % 86400; /* Mengatasi lebih dari 1 hari */

  H = N / 3600;
  N = N % 3600;

  M = N / 60;
  N = N % 60;

  S = N;

  return MakeJAM(H,M,S);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
  return ((Hour(J1) == Hour(J2)) && (Minute(J1) ==  Minute(J2)) && (Second(J1) == Second(J2)));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
  return ((Hour(J1) != Hour(J2)) || (Minute(J1) !=  Minute(J2)) || (Second(J1) != Second(J2)));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
  /* KAMUS */
  long N1,N2; /* J1 dan J2 dalam detik */

  /* ALGORITMA */
  N1 = JAMToDetik(J1);
  N2 = JAMToDetik(J2);

  return (N1<N2);
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
  /* KAMUS */
  long N1,N2; /* J1 dan J2 dalam detik */

  /* ALGORITMA */
  N1 = JAMToDetik(J1);
  N2 = JAMToDetik(J2);

  return (N1>N2);
}
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = JAMToDetik(J);

  detik++;

  return DetikToJAM(detik);
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = JAMToDetik(J);

  detik = detik + N;

  return DetikToJAM(detik);
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = JAMToDetik(J);

  detik--;

  return DetikToJAM(detik);
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = JAMToDetik(J);

  detik = detik - N;

  return DetikToJAM(detik);
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
  /* KAMUS */
  long Naw,Nakh; /* Jaw dan Jakh dalam detik */
  long selisih;

  /* ALGORITMA */
  Naw = JAMToDetik(JAw);
  Nakh = JAMToDetik(JAkh);

  selisih = Nakh - Naw;

  if(selisih<0){
    selisih += 86400;
  }

  return selisih;
}
