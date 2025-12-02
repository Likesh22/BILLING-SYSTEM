#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/structure.h"
#include"../include/buyer.h"
#include"../include/Item_Detail.h"
#include"../include/bill.h"

float Fsgst=0, Fcgst=0, Fgst=0, FAmount=0, Ftotal_amount=0;
float Psgst=0, Pcgst=0, Pgst=0, PAmount=0, Ptotal_amount=0;
int bill_no;
Items item[100];
int n;
int i;

int main (){

    char type[20];
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Type of bill\n");
    printf("|P for Pesticides and F for Fertilizers| : ");
    scanf("%s", type);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Bill no: ");
    scanf("%d", &bill_no);
        
    buyer();

    Item_Detail(type);
    
    Bill(type);
    
    printf("Signature of Receiver:_______________\t \t Signature of Seller:_______________");
    printf("\n");
    printf("\nThank you for shopping with us!\n");
    printf("\n");
    return 0;
}