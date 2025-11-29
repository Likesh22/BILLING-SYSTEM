#ifndef STRUCT_H
#define STRUCT_H

struct Items{ 
	char product_name[50];
	int quantity;
	float rate;
	int no_of_items;
	float amount;
};

extern float Fsgst ,Fcgst ,Fgst ,FAmount ,Ftotal_amount;
extern float Psgst ,Pcgst ,Pgst ,PAmount ,Ptotal_amount;

#endif