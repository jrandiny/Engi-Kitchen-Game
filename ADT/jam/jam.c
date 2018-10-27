/* Kelompok  : UAS
   Nama file : jam.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : ADT untuk tipe JAM*/

#include "jam.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean J_IsJAMValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
  return (((H>=0)&&(H<=23)) && ((M>=0)&&(M<=59)) && ((S>=0)&&(S<=59)));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM J_MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
  /* KAMUS */
  JAM J;

  /* ALGORITMA */
  J_Hour(J) = HH;
  J_Minute(J) = MM;
  J_Second(J) = SS;

  return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void J_BacaJAM (JAM * J)
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
    if(J_IsJAMValid(H,M,S)){
      break;
    }
    printf("Jam tidak valid\n");
  }
  /* IsJAMValid(H,M,S)*/

  *J = J_MakeJAM(H,M,S);
}

void J_TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
  printf("%02d:%02d:%02d",J_Hour(J),J_Minute(J),J_Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long J_JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
  /* KAMUS */
  long durasi;

  /* ALGORITMA */
  durasi = J_Hour(J) * 3600;
  durasi += J_Minute(J) * 60;
  durasi += J_Second(J);

  return durasi;
}

JAM J_DetikToJAM (long N)
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

  return J_MakeJAM(H,M,S);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean J_JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
  return ((J_Hour(J1) == J_Hour(J2)) && (J_Minute(J1) ==  J_Minute(J2)) && (J_Second(J1) == J_Second(J2)));
}
boolean J_JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
  return ((J_Hour(J1) != J_Hour(J2)) || (J_Minute(J1) !=  J_Minute(J2)) || (J_Second(J1) != J_Second(J2)));
}
boolean J_JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
  /* KAMUS */
  long N1,N2; /* J1 dan J2 dalam detik */

  /* ALGORITMA */
  N1 = J_JAMToDetik(J1);
  N2 = J_JAMToDetik(J2);

  return (N1<N2);
}
boolean J_JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
  /* KAMUS */
  long N1,N2; /* J1 dan J2 dalam detik */

  /* ALGORITMA */
  N1 = J_JAMToDetik(J1);
  N2 = J_JAMToDetik(J2);

  return (N1>N2);
}
/* *** Operator aritmatika JAM *** */
JAM J_NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = J_JAMToDetik(J);

  detik++;

  return J_DetikToJAM(detik);
}
JAM J_NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = J_JAMToDetik(J);

  detik = detik + N;

  return J_DetikToJAM(detik);
}
JAM J_PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = J_JAMToDetik(J);

  detik--;

  return J_DetikToJAM(detik);
}
JAM J_PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
  /* KAMUS */
  long detik; /* J dalam detik*/

  /* ALGORITMA */
  detik = J_JAMToDetik(J);

  detik = detik - N;

  return J_DetikToJAM(detik);
}
/* *** Kelompok Operator Aritmetika *** */
long J_Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
  /* KAMUS */
  long Naw,Nakh; /* Jaw dan Jakh dalam detik */
  long selisih;

  /* ALGORITMA */
  Naw = J_JAMToDetik(JAw);
  Nakh = J_JAMToDetik(JAkh);

  selisih = Nakh - Naw;

  if(selisih<0){
    selisih += 86400;
  }

  return selisih;
}
