#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/buyer.h"
#include"../include/Item_Detail.h"

char buyer_name[50];
char buyer_address[200];
long long buyer_phone;
char receiver_name[50];
char mode_of_payment[20];

void buyer(void){

printf("Buyer Name: ");
scanf("%s", buyer_name);

printf("Buyer Address: ");
scanf("%s", buyer_address);

printf("Buyer Phone Number: ");
scanf("%d", &buyer_phone);

printf("Receiver Name: ");
scanf("%s", receiver_name);

printf("Mode of payment (Cash/Card/UPI): ");
scanf("%s", mode_of_payment);

printf("----------------------------------------------------------------------------------\n");
}