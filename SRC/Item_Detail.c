#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/Item_Detail.h"
#include"../include/Structure.h"
#include"../include/Bill.h"
#include"../include/Buyer_Detail.h"
#include"../include/Bill_No.h"
#include"../include/Storage.h"

void Item_Detail(const char *type){
    extern int n, i;
    extern struct Items item[100];
    printf("Number of items: ");
    scanf("%d", &n);
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    if (strcmp(type, "P") == 0 || strcmp(type, "p") == 0){
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
        printf("------------------------------------------------------------------------------------------------------------------------\n");
    }
    }
    else if (strcmp(type, "F") == 0 || strcmp(type, "f") == 0){
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
        printf("------------------------------------------------------------------------------------------------------------------------\n");
    }
    }
}