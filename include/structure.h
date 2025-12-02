#ifndef STRUCT_H
#define STRUCT_H

typedef struct Items{ 
	char product_name[50];
	int quantity;
	float rate;
	int no_of_items;
	float amount;
}Items;

extern float Fsgst ,Fcgst ,Fgst ,FAmount ,Ftotal_amount;
extern float Psgst ,Pcgst ,Pgst ,PAmount ,Ptotal_amount;


extern struct Items item[100];
extern int n;
extern int i;
extern int bill_no;
#endif