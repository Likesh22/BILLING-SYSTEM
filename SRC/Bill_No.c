#include <stdio.h>
#include <ctype.h>
#include "../include/Bill_No.h"

static const char *filename_for_type(char type) {
    if (toupper((unsigned char)type) == 'P') return "billno_P.txt";
    return "billno_F.txt";
}

int BillNumber(char type) {
    const char *fname = filename_for_type(type);
    int bill_no = 1;
    FILE *fp = fopen(fname, "r");
    if (fp != NULL) {
        if (fscanf(fp, "%d", &bill_no) != 1) bill_no = 1;
        fclose(fp);
    }
    fp = fopen(fname, "w");
    if (fp != NULL) {
        fprintf(fp, "%d\n", bill_no + 1);
        fclose(fp);
    }
    return bill_no;
}
