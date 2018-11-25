/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
/* Kelompok  : UAS
   Nama file : mesinkata.c
   Deskripsi : Implementasi mesin kata*/

#include "mesinkar.h"
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void K_IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  while((CC==BLANK)&&(CC!=MARK)){
    K_ADV();
  }
  /* CC == BLANK atau CC == MARK */
}

void K_STARTKATA(char* nama,int *status)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  K_START(nama,status);
  if(*status==1){
    K_IgnoreBlank();
    if(CC == MARK){
      EndKata = true;
    }else{
      EndKata = false;
      K_SalinKata();
    }
  }
}

void K_ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan void K_SalinKata */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  K_IgnoreBlank();
  if(CC == MARK){
    EndKata = true;
  }else{
    K_SalinKata();
    K_IgnoreBlank();
  }

}

void K_SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  i = 1;
  while( (!((CC == MARK)||(CC == BLANK))) ){
    CKata.TabKata[i] = CC;
    K_ADV();

    if(i==NMax){
      break;
    }

    if(!((CC==MARK)||(CC==BLANK))){
      i = i+1;
    }
  }
  CKata.Length = i;
}

Kata K_MakeKata(char* S)
/* Membuat kata dari string */
{
  /* KAMUS LOKAL */
  Kata hasil;
  int i;

  /* ALGORITMA */
  i=0;
  while(S[i]!='\0'){
    hasil.TabKata[i+1]=S[i];
    i++;
  }
  hasil.Length=i;
  return hasil;
}

boolean K_IsKataSama(Kata kata1,Kata kata2)
/*true jika kata1 sama kata2, dan sebaliknya*/
{
  /* KAMUS LOKAL */
  boolean sama;

  /* ALGORITMA */
  if(kata1.Length==kata2.Length){
    sama=true;
    int i=1;
    while(i<=kata1.Length&&sama){
      if(kata1.TabKata[i]!=kata2.TabKata[i]){
        sama=false;
      }else{
        i++;
      }
    }
  }else{
    sama=false;
  }
  return sama;
}

int K_KataToInt(Kata input)
/*mengubah input menjadi tipe integer*/
{
  /* KAMUS LOKAL */
  int hasil;
  int i;
  boolean negatif;

  /* ALGORITMA */
  hasil=0;
  i=1;
  negatif=false;

  while(i<=input.Length){
    if(i==1&&input.TabKata[i]=='-'){
      negatif=true;
    }else{
      hasil=hasil*10+(int)(input.TabKata[i]-'0');
    }
    i++;
  }

  if(negatif){
    hasil*=-1;
  }
  return hasil;
}

Kata K_CopySubKata(Kata input,int idxmulai,int idxakhir)
/*mengcopy sebagian dari input sesuai parameter*/
{
  /* KAMUS LOKAL */
  Kata hasil;
  int i,j;

  /* ALGORITMA */
  hasil.Length=idxakhir-idxmulai+1;
  j=1;
  for(i=idxmulai;i<=idxakhir;i++){
    hasil.TabKata[j]=input.TabKata[i];
    j++;
  }
  return hasil;
}

void K_PrintKata(Kata S)
/* I.S. S valid
   F.S. S terprint di layar dengan tanpa enter di akhir
*/
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i=1;i<=S.Length;i++){
    printf("%c",S.TabKata[i]);
  }
}

char* K_KataToChar(Kata S)
/*mengubah tipe kata menjadi string*/
{
  /* KAMUS LOKAL */
  char* hasil;
  int i;

  /* ALGORITMA */
  hasil=(char*)malloc(S.Length*sizeof(char));
  for(i=1;i<=S.Length;i++){
    hasil[i-1]=S.TabKata[i];
  }
  hasil[i-1]='\0';
  return hasil;
}

Point K_KataToPoint(Kata S)
/*mengubah tipe kata menjadi point*/
{
  /* KAMUS LOKAL */
  Point hasil;
  int pos;

  /* ALGORITMA */
  pos = 1;
  while(S.TabKata[pos]!=','){
    pos++;
  }
  P_Baris(hasil)=K_KataToInt(K_CopySubKata(S,1,pos-1));
  P_Kolom(hasil)=K_KataToInt(K_CopySubKata(S,pos+1,S.Length));
  return hasil;
}

void K_KonkatKata(Kata *kata1, Kata kata2)
/* I.S. kata1, kata2 terdefenisi
   F.S. kata1 berisi hasil konkat kata 1 dan kata 2
*/
{
  /* KAMUS LOKAL */
  int i,j,max;

  /* ALGORITMA */
  max=(*kata1).Length+kata2.Length;
  j=1;
  for(i=(*kata1).Length+1;i<=max;i++){
    (*kata1).TabKata[i]=kata2.TabKata[j];
    j++;
  }
  (*kata1).Length=max;
}


void K_ReplaceSpace(Kata* kata)
/* I.S. kata terdefinisi
   F.S. semua _ yang terdapat di kata diubah menjadi ' '*/
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i=1;i<=(*kata).Length;i++){
    if((*kata).TabKata[i]=='_'){
      (*kata).TabKata[i]=' ';
    }
  }
}

void K_RemoveSpace(Kata* kata)
/* I.S. kata terdefinisi
   F.S. semua ' ' yang terdapat di kata diubah menjadi _*/
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  for(i=1;i<=(*kata).Length;i++){
    if((*kata).TabKata[i]==' '){
      (*kata).TabKata[i]='_';
    }
  }
}

Kata K_JamToKata(Jam jam)
/* mengembalikan tipe kata dari jam*/
{
  /* KAMUS LOKAL */
  Kata hasil;

  /* ALGORITMA */
  hasil.Length = 8;
  hasil.TabKata[1]=(char)(J_Hour(jam)/10)+'0';
  hasil.TabKata[2]=(char)(J_Hour(jam)%10)+'0';
  hasil.TabKata[3]=':';
  hasil.TabKata[4]=(char)(J_Minute(jam)/10)+'0';
  hasil.TabKata[5]=(char)(J_Minute(jam)%10)+'0';
  hasil.TabKata[6]=':';
  hasil.TabKata[7]=(char)(J_Second(jam)/10)+'0';
  hasil.TabKata[8]=(char)(J_Second(jam)%10)+'0';
  return hasil;
}
