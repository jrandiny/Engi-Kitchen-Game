/*Nama File : main.c */

#include "header/std.h"
#include "header/ADT.h"

void initGame(Kata *new,Kata *exit,Kata *load,Kata *start);
/*
I.S. parameter2 belum berisi
F.S. parameter2 berisi sesuai value awal default
*/


/*Main Progam*/
int main () {

  //KAMUS
  int money;   //jumlah keuntungan dari restoran
  int life;    //nyawa pemain
  int time;    //tik untuk satuan waktu
  Kata input,new,exit,start,load,username;

  //ALGORITMA
    initGame(&new,&exit,&load,&start);
    do{
      input=getInput();
      if(K_IsKataSama(input,new)||K_IsKataSama(input,start)){
        if(K_IsKataSama(input,new)){
            username=getInput();
        }else{
          if(username.Length==0){
            username=getInput();
          }
        }
        initScreen();


      }else if(K_IsKataSama(input,load)){
        K_STARTKATA();
        username.Length = CKata.Length;
        for(i=1;i<=CKata.Length;i++)
        {
          username.TabKata[i]=CKata.TabKata[i];
        }
        K_ADVKATA();

        money = 0;
        while(i<=CKata.Length)
        {
          money *= 10;
          money += (int) CKata.TabKata[i];
        }
        K_ADVKATA();

        life = 0;
        while(i<=CKata.Length)
        {
          life *= 10;
          life += (int) CKata.TabKata[i];
        }
        K_ADVKATA();

        time = 0;
        while(i<=CKata.Length)
        {
          time *= 10;
          time += (int) CKata.TabKata[i];
        }
      }

    }while(!K_IsKataSama(Input,exit))


  return 0;
}

void initGame(Kata *new,Kata *exit,Kata *load,Kata *start)
/*
I.S. parameter2 belum berisi
F.S. parameter2 berisi sesuai value awal default
*/
{
  *new=K_MakeKata("new");
  *exit=K_MakeKata("exit");
  *load=K_MakeKata("load");
  *start=K_MakeKata("start");
}
