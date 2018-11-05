#include "ADT.h"
#include "std.h"
#include "Modul/eksternal/eksternal.h"

int main(){
    char tes[100];
    Door temp;
    Meja temp2;
    int status=0;
    Kata nama;
    int money,life,waktu;
    Restoran restoran;
    Pelayan pelayan;
    PrioQueueCustomer prioqueue;
    customer customer;
    nama=K_MakeKata("filetes");
    LoadFile(&status,&nama,&money,&life,&waktu,&restoran,&pelayan,&prioqueue);

    
    K_PrintKata(nama);printf("\n");
    printf("money=%d\n",money);
    printf("life=%d\n",life);
    printf("time=%d\n",waktu);
    printf("jumlah queue=%d\n",PQC_NBElmt(prioqueue));
    // int i,n=PQC_NBElmt(prioqueue);
    // for(i=1;i<=n;i++){
    //     printf("%d ",i);
    //     PQC_Del(&prioqueue,&customer);
    //     printf("%d\n",PQC_Prio(customer));
    // }
    SaveFile(nama,money,life,waktu,restoran,pelayan,prioqueue);
    LoadFile(&status,&nama,&money,&life,&waktu,&restoran,&pelayan,&prioqueue);
    printf("jumlah queue=%d\n",PQC_NBElmt(prioqueue));
    nama=K_MakeKata("tessave");
    SaveFile(nama,money,life,waktu,restoran,pelayan,prioqueue);
    return 0;
}
    // scanf("%s",tes);
    // T=ParseTile(K_MakeKata(tes));
    // printf("%c %d\n",Karakter(T),Value(T));
    // scanf("%s",tes);
    // c=ParseCostumer(K_MakeKata(tes));
    // printf("%d %d %d %d\n",C_Prio(c),C_Jumlah(c),C_Waktu(c),C_ID(c));
    // scanf("%s",tes);
    // m=ParseMeja(K_MakeKata(tes));
    // printf("%d ",Bangku(m));P_TulisPoint(Meja_Posisi(m));printf(" %d\n",Status(m));

    // do{
    //     K_STARTKATA("filetes.txt",&status);
    //     // printf("%d\n",status);
    // }while(status!=1);
    //  while(!EndKata){
    //     K_PrintKata(CKata);printf("\n");
    // //     T=ParseTile(CKata);
    // //     printf("%c %d\n",Karakter(T),Value(T));
    //     K_ADVKATA();
    // // }
    //     // if(K_IsKataSama(CKata,K_MakeKata("restoran"))){
    //     //     R=ParseRestoran();
    //     //     printf("berhasil\n");
    //     // }else{
    //     //     printf("gagal\n");
    //     // }
    // }
        
    // scanf("%s",tes);
    // temp2=ParseMeja(K_MakeKata(tes));
    // printf("bangku:%d status:%d",Bangku(temp2),Status(temp2));
    // P_TulisPoint(Meja_Posisi(temp2));
    
    
    
    // temp=ParseDoor(K_MakeKata(tes));
    // printf("lokasi:\n");
    // P_TulisPoint(DoorLocation(temp));
    // printf("direction:%d roomid: %d\n",DoorDirection(temp),DoorRoomID(temp));
    
    // K_STARTKATA("filetes.txt",&status);
    // if(status==1){
    //     // while(!EndKata){
    //     printf("masuk if\n");
    //     // K_ADVKATA();
    //     // if(K_IsKataSama(CKata,K_MakeKata("name"))){
    //     //     nama=ParseNama(CKata);
    //     // }else if(K_IsKataSama(CKata,K_MakeKata("money"))){
    //     //     K_ADVKATA();//Ckata berada di value money
    //     //     money=K_KataToInt(CKata);
    //     // }else if(K_IsKataSama(CKata,K_MakeKata("life"))){
    //     //     K_ADVKATA();//Ckata berada di value life
    //     //     life=K_KataToInt(CKata);
    //     // }else if(K_IsKataSama(CKata,K_MakeKata("time"))){
    //     //     K_ADVKATA();//Ckata berada di value life
    //     //     waktu=K_KataToInt(CKata);
    //     if(K_IsKataSama(CKata,K_MakeKata("restoran"))){
    //         //Ckata berada di kata restoran
    //         restoran=ParseRestoran();
    //         printf("mungkin berhasil\n");
    //     }
    // }