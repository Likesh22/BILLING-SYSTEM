#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/Item_Detail.h"
#include"../include/structure.h"
#include"../include/bill.h"

void Item_Detail(const char *type){
    extern int n, i;
    extern struct Items item[100];
    printf("\tNumber of items: ");
    scanf("%d", &n);
    printf("------------------------------------------------------------------------\n");
if (strcmp(type, "P") == 0 || strcmp(type, "p") == 0)
{
    for(i=0; i<n; i++)
    {   
        printf("%d. Product name: ", i+1);
        scanf("%s", item[i].product_name);
        printf("    Quantity(in ml): ");
        scanf("%d", &item[i].quantity);
        printf("    Rate: ");
        scanf("%f", &item[i].rate);
        printf("    No of items: ");
        scanf("%d", &item[i].no_of_items);
        item[i].amount = item[i].no_of_items * item[i].rate;
        printf("------------------------------------------------------------------------\n");

        // Psgst = (item[i].amount * 9) / 100;
        // printf("    Sgst: %.2f\n", Psgst);
        // Pcgst = (item[i].amount * 9) / 100;
        // printf("    Cgst: %.2f\n", Pcgst);
        // Pgst += Psgst + Pcgst;

        // PAmount= item[i].amount + Psgst + Pcgst;
        // printf("    Amount: %.2f\n", PAmount);
        // printf("------------------------------------------------------------------------\n");
        // Ptotal_amount += PAmount;
    }
}
else if (strcmp(type, "F") == 0 || strcmp(type, "f") == 0)
{
    for(i=0; i<n; i++)
    {
        printf("%d. Product name: ", i+1);
        scanf("%s", &item[i].product_name);
        printf("    Quantity(in ml): ");
        scanf("%d", &item[i].quantity);
        printf("    Rate: ");
        scanf("%f", &item[i].rate);
        printf("    No of items: ");
        scanf("%d", &item[i].no_of_items);

        item[i].amount = item[i].no_of_items * item[i].rate;
        printf("------------------------------------------------------------------------\n");

        // Fsgst = (item[i].amount * 2.5) / 100;
        // printf("    Sgst: %.2f\n", Fsgst);
        // Fcgst = (item[i].amount * 2.5) / 100;
        // printf("    Cgst: %.2f\n", Fcgst);
        // Fgst += Fsgst + Fcgst;

        // FAmount= item[i].amount + Fsgst + Fcgst;
        // printf("    Amount: %.2f\n", FAmount);
        // printf("------------------------------------------------------------------------\n");
        // Ftotal_amount += FAmount;

    }
}
}