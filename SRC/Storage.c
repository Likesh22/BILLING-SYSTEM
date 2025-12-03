#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

#include "../include/Storage.h"
#include "../include/Buyer_Detail.h"
#include "../include/Structure.h"
#include "../include/Bill.h"


void ensure_bills_dir(void) {
#ifdef _WIN32
    _mkdir("bills");
#else
    mkdir("bills", 0755);
#endif
}

static void make_bill_filename(char type, int Bill_No, char *out, size_t outlen) {
    char T = (type >= 'a' && type <= 'z') ? (char)(type - 32) : type;
    snprintf(out, outlen, "bills/%c-%05d.txt", T, Bill_No);
}

static void append_index(char type, const char *filename) {
    char indexname[256];
    char T = (type >= 'a' && type <= 'z') ? (char)(type - 32) : type;
    snprintf(indexname, sizeof(indexname), "bills/index_%c.txt", T);
    FILE *f = fopen(indexname, "a");
    if (!f) return;
    fprintf(f, "%s\n", filename);
    fclose(f);
}
int Save_Bill(char type, int Bill_No) {
    ensure_bills_dir();

    char fname[260];
    make_bill_filename(type, Bill_No, fname, sizeof(fname));

    FILE *fp = fopen(fname, "w");
    if (!fp) return -1;

    Bill(fp, &type, Bill_No);    

    fclose(fp);

    append_index(type, fname);
    return 0;
}

void list_bills(char type) {
    printf("\n");
    ensure_bills_dir();
    char indexname[256];
    char T = (type >= 'a' && type <= 'z') ? (char)(type - 32) : type;
    snprintf(indexname, sizeof(indexname), "bills/index_%c.txt", T);
    FILE *f = fopen(indexname, "r");
    if (!f) {
        printf("No saved bills for type %c\n", T);
        return;
    }
    char line[512];
    int idx = 0;
    while (fgets(line, sizeof(line), f)) {
        size_t ln = strlen(line);
        if (ln && line[ln-1] == '\n') line[ln-1] = '\0';
        printf("%d) %s\n", ++idx, line);
    }
    fclose(f);
}

int view_bill(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Cannot open file: %s\n", filename);
        return -1;
    }
    char buf[1024];
    while (fgets(buf, sizeof(buf), f)) fputs(buf, stdout);
    fclose(f);
    return 0;
}

int edit_bill(const char *filename) {
#ifdef _WIN32
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "notepad \"%s\"", filename);
    return system(cmd);
#else
    if (system(NULL) == 0) return -1;
    if (system("which nano > /dev/null 2>&1") == 0) {
        char cmd[1024];
        snprintf(cmd, sizeof(cmd), "nano \"%s\"", filename);
        return system(cmd);
    } else {
        char cmd[1024];
        snprintf(cmd, sizeof(cmd), "vi \"%s\"", filename);
        return system(cmd);
    }
#endif
}