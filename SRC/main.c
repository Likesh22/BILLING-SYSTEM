#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/structure.h"
#include"../include/Buyer_Detail.h"
#include"../include/Item_Detail.h"
#include"../include/Bill.h"
#include"../include/Bill_No.h"
#include"../include/Storage.h"

float Fsgst=0, Fcgst=0, Fgst=0, FAmount=0, Ftotal_amount=0;
float Psgst=0, Pcgst=0, Pgst=0, PAmount=0, Ptotal_amount=0;

int bill_no;
char type[20];

Items item[100];
int n;
int i;

int main (){
    int choice;
    do {
        printf("\nMenu: \n1) New Bill  2) List Bills  3) View Bill  4) Edit Bill  0) Exit\n : ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Type of bill\n");
            printf("|P for Pesticides and F for Fertilizers| : ");
            scanf("%s", type);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            
            int Bill_No = BillNumber(type[0]);
            printf("Bill no: %d\n", Bill_No);
                
            buyer();
        
            Item_Detail(type);
            
            Bill(stdout,type, Bill_No) ;
            Save_Bill(type[0], Bill_No);
        
            printf("Signature of Receiver:_______________\t \t Signature of Seller:_______________");
            printf("\n");
            printf("\nThank you for shopping with us!\n");
            printf("\n");

        } else if (choice == 2) {
            char t;
            printf("Type (P/F): ");
            scanf("%c", &t); getchar();
            list_bills(t);
        } else if (choice == 3) {
            char fname[260];
            printf("Enter Bill No: ");
            fgets(fname, sizeof(fname), stdin);
            size_t l = strlen(fname); if (l && fname[l-1]=='\n') fname[l-1]=0;
            view_bill(fname);
        } else if (choice == 4) {
            char fname[260];
            printf("Enter Bill No to edit: ");
            fgets(fname, sizeof(fname), stdin);
            size_t l = strlen(fname); if (l && fname[l-1]=='\n') fname[l-1]=0;
            edit_bill(fname);
        }
    } while (choice != 0);

    return 0;
}