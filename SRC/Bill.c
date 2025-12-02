#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/buyer.h"
#include"../include/Item_Detail.h"
#include"../include/Bill.h"
#include"../include/structure.h"

static void print_item_row(int no, const char *name, int qty_ml, float rate, int pcs, float amount, float sgst, float cgst, float total)
    {
    printf("%-4d | %-16s | %-7d | %-10.2f | %-11d | %-12.2f | %-10.2f | %-10.2f | %-14.2f |\n",no, name, qty_ml, rate, pcs, amount, sgst, cgst, total);
    }

void Bill(const char *type) {
    float gst_total = 0.0f;
    float grand_total = 0.0f;
   
   
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\t\tCompany Name: AgroMart\n");
    printf("\n");
    printf("        \t\tGSTIN: XXXXXXXXXX           Mobile No: XXXXXXXXXX\n");
    printf("        \t\tDate: %s           Time: %s\n", __DATE__, __TIME__);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tTAX INVOICE / BILL OF SUPPLY\n");
    printf("\n");
    
    if (strcmp(type, "P") == 0 || strcmp(type, "p") == 0)
    {
        printf("\t\t\t\tPesticides licence No: XXXXXXX\n");
    }
    else
    {
        printf("\t\t\t\tFertilizers licence No: YYYYYYYY\n");
    }
    printf("Bill no: %d\n", bill_no);

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Buyer Name: %s \t\tBuyer Phone Number: %lld\n", buyer_name,buyer_phone);
    printf("Buyer Address: %s\t\tMode of payment: %s\n", buyer_address, mode_of_payment);
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("\nNo.  | %-16s | %-7s | %-10s | %-11s | %-12s | %-10s | %-10s | %-14s |\n",
           "Product Name", "Qty(ml)", "Rate", "No OF Items", "Amount", "SGST", "CGST", "Total");
    printf("-----+------------------+---------+------------+-------------+--------------+------------+------------+------------------\n");

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

    printf("-----+------------------+---------+------------+-------------+--------------+------------+------------+------------------\n");
    printf("| %-98s %12.2f |\n","Total GST paid: ", gst_total);
    printf("| %-98s %12.2f |\n","Amount to be paid without GST: ", grand_total - gst_total);
    printf("| %-98s %12.2f |\n","Total Amount to be paid including GST: ", grand_total);
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}