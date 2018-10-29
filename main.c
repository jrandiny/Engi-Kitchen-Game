/*Nama File : main.c */

#include "header/std.h"
#include "header/ADT.h"


/*Main Progam*/
int main () {

  //KAMUS
  int money;   //jumlah keuntungan dari restoran
  int life;    //nyawa pemain
  int time;    //tik untuk satuan waktu
  Kata input,new,exit,start,load,username;

  //ALGORITMA
  new.Length=3;
  new.TabKata[1]='N';
  new.TabKata[1]='E';
  new.TabKata[1]='W';
  exit.Length=4;
  exit.TabKata[1]='E';
  exit.TabKata[2]='X';
  exit.TabKata[3]='I';
  exit.TabKata[4]='T';
  start.Length=5;
  start.TabKata[1]='S';
  start.TabKata[1]='T';
  start.TabKata[1]='A';
  start.TabKata[1]='R';
  start.TabKata[1]='T';
  load.Length=4;
  load.TabKata[1]='L';
  load.TabKata[2]='O';
  load.TabKata[3]='A';
  load.TabKata[4]='D';

    input=getInput();
    do{
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
