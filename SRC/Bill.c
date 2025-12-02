#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/buyer.h"
#include"../include/Item_Detail.h"
#include"../include/Bill.h"
#include"../include/structure.h"

static void print_item_row(int no, const char *name, int qty_ml, float rate, int pcs,
                           float amount, float sgst, float cgst, float total)
{
    printf("%-4d | %-16s | %-7d | %-6.2f | %-3d | %-8.2f | %-8.2f | %-8.2f | %-9.2f\n",
           no, name, qty_ml, rate, pcs, amount, sgst, cgst, total);
}

void Bill(const char *type) {
    float gst_total = 0.0f;
    float grand_total = 0.0f;

    printf("\nNo.  | %-16s | %-7s | %-6s | %-3s | %-8s | %-8s | %-8s | %-9s\n",
           "Product Name", "Qty(ml)", "Rate", "Qty", "Amount", "SGST", "CGST", "Total");
    printf("-----+------------------+---------+--------+-----+----------+----------+----------+-----------\n");

    for (int i = 0; i < n; i++) {
        float sgst, cgst, line_total;
        if (type[0] == 'P' || type[0] == 'p') {
            sgst = item[i].amount * 0.09f;
            cgst = item[i].amount * 0.09f;
        } else {
            sgst = item[i].amount * 0.025f;
            cgst = item[i].amount * 0.025f;
        }
        line_total = item[i].amount + sgst + cgst;

        gst_total += sgst + cgst;
        grand_total += line_total;

        print_item_row(i + 1, item[i].product_name, item[i].quantity,
                       item[i].rate, item[i].no_of_items, item[i].amount,
                       sgst, cgst, line_total);
    }

    printf("-----+------------------+---------+--------+-----+----------+----------+----------+-----------\n");
    printf("| Total GST paid: %.2f |\n", gst_total);
    printf("| Amount to be paid without GST: %.2f |\n", grand_total - gst_total);
    printf("| Total Amount to be paid: %.2f |\n", grand_total);
}