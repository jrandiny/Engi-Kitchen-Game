#include "stacktfood.h"

int main() {
    int menu,idmkn;
    SF_infotype X;
    StackFood F;

    SF_CreateEmpty(&F);
    printf("MENU STACK FOOD\n");
    printf("1. IsEmpty\n");
    printf("2. IsFull\n");
    printf("3. Push\n");
    printf("4. Pop\n");

    printf("Masukkan pilihan menu : ");
    scanf("%d", &menu);

    while ((menu>0) && (menu<=4))
    {
        switch (menu) {
            case 1 :
            {
                if (SF_IsEmpty(F))
                {
                    printf("kosong\n");
                } else {
                    printf("isi\n");
                }
            }
            break;
            case 2 :
            {
                if (SF_IsFull(F))
                {
                    printf("penuh\n");
                } else{
                    printf("tidak penuh\n");
                }
            }
            break;
            case 3 :
            {
                printf("id makanan : ");
                scanf("%d", &idmkn);
                SF_IDMakanan(X) = idmkn;
                SF_Push(&F,X);
            }
            break;
            case 4 :
            {
                SF_Pop(&F,&X);
                printf("Pop : %d\n", SF_IDMakanan(X));
            }
            break;
        }
        printf("Masukkan pilihan menu : ");
        scanf("%d", &menu);
    }
    return 0;
}