/* File: listrek.h */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* *** Manajemen Memori *** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address hasil;
    hasil=(address)malloc(sizeof(ElmtList));
    if(hasil!=Nil){
        Info(hasil)=X;
        Next(hasil)=Nil;
    }
    return hasil;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
    return L==Nil;
}
int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
    if(IsEmpty(L)){
        return 0;
    }else{
        return (Next(L)==Nil);
    }
}
/* *** Selektor *** */
infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
    return Info(L);
}
List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
    return (Next(L));
}
/* *** Konstruktor *** */
List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
    address P;
    P=Alokasi(e);
    if(P==Nil){
        return L;
    }else{
        Next(P)=L;
        return P;
    }
}
List KonsB(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
    address P;
    P=Alokasi(e);
    if(P==Nil){
        return L;
    }else{
        if(IsEmpty(L)){
            return P;
        }else{
            Next(L)=KonsB(Tail(L),e);
            return L;
        }
    }
}

/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
{
    if(IsEmpty(L)){
        return Nil;
    }else{
        return Konso(FirstElmt(L),Copy(Tail(L)));
    }
}
void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
    List temp;
    if(IsEmpty(Lin)){
        *Lout=Nil;
    }else{
        MCopy(Tail(Lin),&temp);
        *Lout=Konso(FirstElmt(Lin),temp);
    }
}
List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
    if(IsEmpty(L1)){
        return Copy(L2);
    }else{
        return Konso(FirstElmt(L1),Concat(Tail(L1),L2));
    }
}
void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
    List temp;
    if(IsEmpty(L1)){
        MCopy(L2,LHsl);
    }else{
        MConcat(Tail(L1),L2,&temp);
        *LHsl=Konso(FirstElmt(L1),temp);
    }
}
void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
    if(IsEmpty(L)){
        // {nothing}
    }else{
        printf("%d\n",FirstElmt(L));
        PrintList(Tail(L));
    }
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
    if(IsEmpty(L)){
        return 0;
    }else{
        return 1+NbElmtList(Tail(L));
    }
}
boolean Search (List L, infotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
    if(IsEmpty(L)){
        return false;
    }else{
        if(FirstElmt(L)==X){
            return true;
        }else{
            return Search(Tail(L),X);
        }
    }
}