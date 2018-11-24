/* Kelompok  : UAS
   Nama file : jam.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : ADT untuk tipe jam*/

   #include "jam.h"

   /* ***************************************************************** */
   /* DEFINISI PRIMITIF                                                 */
   /* ***************************************************************** */
   /* KELOMPOK VALIDASI TERHADAP TYPE                                   */
   /* ***************************************************************** */
   boolean J_IsJamValid (int H, int M, int S)
   /* Mengirim true jika H,M,S dapat membentuk J yang valid */
   /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
   {
     return (((H>=0)&&(H<=23)) && ((M>=0)&&(M<=59)) && ((S>=0)&&(S<=59)));
   }

   /* *** Konstruktor: Membentuk sebuah Jam dari komponen-komponennya *** */
   Jam J_MakeJam (int HH, int MM, int SS)
   /* Membentuk sebuah Jam dari komponen-komponennya yang valid */
   /* Prekondisi : HH, MM, SS valid untuk membentuk Jam */
   {
     /* KAMUS */
     Jam J;
      /* ALGORITMA */
     J_Hour(J) = HH;
     J_Minute(J) = MM;
     J_Second(J) = SS;
      return J;
   }

   /* ***************************************************************** */
   /* KELOMPOK BACA/TULIS                                               */
   /* ***************************************************************** */
   void J_BacaJam (Jam * J)
   /* I.S. : J tidak terdefinisi */
   /* F.S. : J terdefinisi dan merupakan jam yang valid */
   /* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
   /* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
   /* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
      dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
   /* Jika Jam tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
      diulangi hingga didapatkan jam yang valid. */
   /* Contoh:
      60 3 4
      Jam tidak valid
      1 3 4
      --> akan terbentuk Jam <1,3,4> */
   {
     /* KAMUS */
     int H,M,S;
      /* ALGORITMA */
     while(true){
       scanf("%d %d %d",&H,&M,&S);
       if(J_IsJamValid(H,M,S)){
         break;
       }
       printf("Jam tidak valid\n");
     }
     /* IsJamValid(H,M,S)*/
      *J = J_MakeJam(H,M,S);
   }
    void J_TulisJam (Jam J)
   /* I.S. : J sembarang */
   /* F.S. :   Nilai J ditulis dg format HH:MM:SS */
   /* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
      tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
   {
     printf("%02d:%02d:%02d",J_Hour(J),J_Minute(J),J_Second(J));
   }
