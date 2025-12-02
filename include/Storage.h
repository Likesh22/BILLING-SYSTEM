#ifndef STORAGE_H
#define STORAGE_H

void ensure_bills_dir(void);
int Save_Bill(char type, int Bill_No);
void list_bills(char type);
int view_bill(const char *filename);
int edit_bill(const char *filename);

#endif