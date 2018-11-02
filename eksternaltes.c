#include "ADT.h"
#include "std.h"
#include "Modul/eksternal/eksternal.h"

int main(){
    int status=0;
    Restoran R;
    Tile T;
    customer c;
    char tes[100];
    Meja m;
    // scanf("%s",tes);
    // T=ParseTile(K_MakeKata(tes));
    // printf("%c %d\n",Karakter(T),Value(T));
    // scanf("%s",tes);
    // c=ParseCostumer(K_MakeKata(tes));
    // printf("%d %d %d %d\n",C_Prio(c),C_Jumlah(c),C_Waktu(c),C_ID(c));
    // scanf("%s",tes);
    // m=ParseMeja(K_MakeKata(tes));
    // printf("%d ",Bangku(m));P_TulisPoint(Meja_Posisi(m));printf(" %d\n",Status(m));

    do{
        K_STARTKATA("filetes.txt",&status);
        // printf("%d\n",status);
    }while(status!=1);
     //while(!EndKata){
    //     K_PrintKata(CKata);printf(" ");
    //     T=ParseTile(CKata);
    //     printf("%c %d\n",Karakter(T),Value(T));
    //     K_ADVKATA();
    // }
        if(K_IsKataSama(CKata,K_MakeKata("restoran"))){
            R=ParseRestoran();
            printf("berhasil\n");
        }else{
            printf("gagal\n");
        }
    //}
    return 0;
}
