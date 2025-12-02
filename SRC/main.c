#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../include/structure.h"
#include"../include/buyer.h"
#include"../include/Item_Detail.h"
#include"../include/bill.h"

// struct Items{ 
// 	char product_name[50];
// 	int quantity;
// 	float rate;
// 	int no_of_items;
// 	float amount;
// };
float Fsgst=0, Fcgst=0, Fgst=0, FAmount=0, Ftotal_amount=0;
float Psgst=0, Pcgst=0, Pgst=0, PAmount=0, Ptotal_amount=0;

Items item[100];
int n;
int i;

int main ()
{
char type[20];
printf("Type of bill\n");
printf("|P for Pesticides and F for Fertilizers| : ");
scanf("%s", type);

printf("\n");

int bill_no;
printf("Bill no: ");
scanf("%d", &bill_no);
printf("------------------------------------------------------------------------\n");


buyer();
// char buyer_name[50];
// printf("Buyer Name: ");
// scanf("%s", buyer_name);
// char buyer_address[100];
// printf("Buyer Address: ");
// scanf("%s", buyer_address);
// int buyer_phone;
// printf("Buyer Phone Number: ");
// scanf("%d", &buyer_phone);
// char receiver_name[50];
// printf("Receiver Name: ");
// scanf("%s", receiver_name);
// char mode_of_payment[20];
// printf("Mode of payment (Cash/Card/UPI): ");
// scanf("%s", mode_of_payment);
// printf("------------------------------------------------------------------------\n");



Item_Detail(type);
// if (strcmp(type, "P") == 0)
// {
//     int n, i;
//     struct Items item[100];
//     printf("Number of items: ");
//     scanf("%d", &n);
//     for(i=0; i<n; i++)
//     {   
//         printf("%d. Product name: ", i+1);
//         scanf("%s", item[i].product_name);
//         printf("    Quantity(in ml): ");
//         scanf("%d", &item[i].quantity);
//         printf("    Rate: ");
//         scanf("%f", &item[i].rate);
//         printf("    No of items: ");
//         scanf("%d", &item[i].no_of_items);
//         item[i].amount = item[i].no_of_items * item[i].rate;
//         printf("----------------------------------------------------------------------------------\n");

//         Psgst = (item[i].amount * 9) / 100;
//         printf("    Sgst: %.2f\n", Psgst);
//         Pcgst = (item[i].amount * 9) / 100;
//         printf("    Cgst: %.2f\n", Pcgst);
//         Pgst += Psgst + Pcgst;

//         PAmount= item[i].amount + Psgst + Pcgst;
//         printf("    Amount: %.2f\n", PAmount);
//         Ptotal_amount += PAmount;
//     }
// }
// else if (strcmp(type, "F") == 0)
// {
//     int n, i;
//     struct Items item[100];
//     printf("Number of items: ");
//     scanf("%d", &n);
//     for(i=0; i<n; i++)
//     {
//         printf("%d. Product name: ", i+1);
//         scanf("%s", item[i].product_name);
//         printf("    Quantity(in ml): ");
//         scanf("%d", &item[i].quantity);
//         printf("    Rate: ");
//         scanf("%f", &item[i].rate);
//         printf("    No of items: ");
//         scanf("%d", &item[i].no_of_items);

//         item[i].amount = item[i].no_of_items * item[i].rate;
//         printf("----------------------------------------------------------------------------------\n");

//         Fsgst = (item[i].amount * 2.5) / 100;
//         printf("    Sgst: %.2f\n", Fsgst);
//         Fcgst = (item[i].amount * 2.5) / 100;
//         printf("    Cgst: %.2f\n", Fcgst);
//         Fgst += Fsgst + Fcgst;

//         FAmount= item[i].amount + Fsgst + Fcgst;
//         printf("    Amount: %.2f\n", FAmount);
//         printf("----------------------------------------------------------------------------------\n");
//         Ftotal_amount += FAmount;

//     }
// }


// printf("------------------------------------------------------------------------\n");
// printf("| Total GST paid: %.2f |\n", (strcmp(type, "P") == 0) ? Pgst : Fgst);
// printf("| Total Amount to be paid: %.2f |\n", (strcmp(type, "P") == 0) ? Ptotal_amount : Ftotal_amount);
    printf("\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("\n");
    printf("                    Company Name: AgroMart\n");
    printf("\n");
    printf("        GSTIN: XXXXXXXXXX           Mobile No: XXXXXXXXXX\n");
    printf("        Date: %s           Time: %s\n", __DATE__, __TIME__);
    printf("----------------------------------------------------------------------------------\n");
    printf("                        TAX INVOICE / BILL OF SUPPLY\n");
    printf("\n");
    
    if (strcmp(type, "P") == 0 || strcmp(type, "p") == 0)
    {
        printf("\t\t\tPesticides licence No: XXXXXXX\n");
    }
    else
    {
        printf("\t\t\tFertilizers licence No: YYYYYYYY\n");
    }
    printf("Bill no: %d\n", bill_no);
    printf("----------------------------------------------------------------------------------\n");
    
    Bill(type);
    
    printf("----------------------------------------------------------------------------------\n");
    printf("Signature of Receiver:__________`_____\t Signature of Seller:_______________");
    printf("\n");
    printf("Thank you for shopping with us!\n");
    return 0;
}