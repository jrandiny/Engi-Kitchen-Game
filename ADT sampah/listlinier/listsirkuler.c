#include "listsirkuler.h"

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean LS_IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return First(L)==Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void LS_CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address LS_Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address pt;
	pt=(address)malloc(sizeof(ElmtList));
	if(pt!=Nil){
		Info(pt)=X;
		Next(pt)=Nil;
	}
	return pt;
}
void LS_Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address LS_Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (LS_IsEmpty(L)){
		return Nil;
	}else{
		address P=First(L);
		while((Info(P)!=X)&&(Next(P)!=First(L))){
			P=Next(P);
		}
		if(Info(P)==X){
			return P;
		}else{
			return Nil;
		}
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void LS_InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P=LS_Alokasi(X);
	if(P!=Nil){
		LS_InsertFirst(L,P);
	}
}
void LS_InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P=LS_Alokasi(X);
	if(P!=Nil){
		LS_InsertLast(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void LS_DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	LS_DelFirst(L,&P);
	*X=Info(P);
	LS_Dealokasi(P);
}
void LS_DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address last;
	LS_DelLast(L,&last);
	*X=Info(last);
	LS_Dealokasi(last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void LS_InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if(LS_IsEmpty(*L)){
		Next(P)=P;
	}else{
		Next(P)=First(*L);
		address pt=First(*L);
		while(Next(pt)!=First(*L)){
			pt=Next(pt);
		}
		Next(pt)=P;
	}	
	First(*L)=P;
}
void LS_InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(LS_IsEmpty(*L)){
		LS_InsertFirst(L,P);
	}else{
		address pt=First(*L);
		while(Next(pt)!=First(*L)){
			pt=Next(pt);
		}
		Next(P)=First(*L);
		Next(pt)=P;		
	}
}
void LS_InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void LS_DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P=First(*L);
	if(Next(*P)==First(*L)){
		First(*L)=Nil;
	}else{
		address pt=First(*L);
		while(Next(pt)!=First(*L)){
			pt=Next(pt);
		}
		First(*L)=Next(*P);
		Next(pt)=First(*L);
	}
	Next(*P)=Nil;
}
void LS_DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	
	address pt=First(*L);
	address prec=Nil;
	while(Next(pt)!=First(*L)){
		prec=pt;
		pt=Next(pt);
	}
	if(prec==Nil){	
		*P=First(*L);
		First(*L)=Nil;
	}else{
		*P=pt;
		//Next(*P)=Nil;
		Next(prec)=First(*L);
	}
}
void LS_DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{

	*Pdel=Next(Prec);
	if(Next(Prec)!=First(*L)){
		Next(Prec)=Next(*Pdel);
		Next(*Pdel)=Nil;
	}else{
		LS_DelFirst(L,Pdel);
	}

}
void LS_DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P,Prec;
	P=First(*L);
	Prec=Nil;
	while((Info(P)!=X)&&(Next(P)!=First(*L))){
		Prec=P;
		P=Next(P);
	}
	if(Info(P)==X){
		if(Prec==Nil){
			LS_DelFirst(L,&P);
		}else{
			LS_DelAfter(L,&P,Prec);
		}
		LS_Dealokasi(P);
	}
}



/****************** PROSES SEMUA ELEMEN LIST ******************/
void LS_PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	if(!LS_IsEmpty(L)){
		address P=First(L);
		while(Next(P)!=First(L)){
			printf("%d,",Info(P));
			P=Next(P);
		}
		printf("%d",Info(P));
	}
	printf("]");
}