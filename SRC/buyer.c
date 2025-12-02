#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/buyer.h"
#include"../include/Item_Detail.h"

void buyer(void){

char buyer_name[50];
printf("Buyer Name: ");
scanf("%s", &buyer_name);
char buyer_address[100];
printf("Buyer Address: ");
scanf("%s",&buyer_address);
int buyer_phone;
printf("Buyer Phone Number: ");
scanf("%d", &buyer_phone);
char receiver_name[50];
printf("Receiver Name: ");
scanf("%s", &receiver_name);
char mode_of_payment[20];
printf("Mode of payment (Cash/Card/UPI): ");
scanf("%s", &mode_of_payment);
printf("------------------------------------------------------------------------\n");
}