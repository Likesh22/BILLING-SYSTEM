#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/Buyer_Detail.h"
#include"../include/Item_Detail.h"
#include"../include/Bill.h"
#include"../include/Structure.h"

static void print_item_row(FILE *out, int no, const char *name, int qty_ml, float rate, int pcs, float amount, float sgst, float cgst, float total)
    {
    fprintf(out,"%-4d | %-16s | %-7d | %-10.2f | %-11d | %-12.2f | %-10.2f | %-10.2f | %-14.2f |\n",no, name, qty_ml, rate, pcs, amount, sgst, cgst, total);
    }

void Bill(FILE *out, const char *type, int Bill_No) {
    float gst_total = 0.0f;
    float grand_total = 0.0f;
   
   
    fprintf(out,"\n");
    fprintf(out,"------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(out,"------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(out,"\n");
    fprintf(out,"\t\t\t\t\t\tCompany Name: AgroMart\n");
    fprintf(out,"\n");
    fprintf(out,"        \t\t\t\tGSTIN: XXXXXXXXXX           Mobile No: XXXXXXXXXX\n");
    fprintf(out,"        \t\t\t\tDate: %s           Time: %s\n", __DATE__, __TIME__);
    fprintf(out,"------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(out,"\t\t\t\t\t\tTAX INVOICE / BILL OF SUPPLY\n");
    fprintf(out,"\n");
    
    if (strcmp(type, "P") == 0 || strcmp(type, "p") == 0)
    {
        fprintf(out,"\t\t\t\t\t\tPesticides licence No: XXXXXXX\n");
    }
    else
    {
        fprintf(out,"\t\t\t\t\t\tFertilizers licence No: YYYYYYYY\n");
    }
    fprintf(out,"Bill no: %d\n", Bill_No);

    fprintf(out,"------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(out,"Buyer Name: %s \t\tBuyer Phone Number: %lld\n", buyer_name,buyer_phone);
    fprintf(out,"Buyer Address: %s\t\tMode of payment: %s\n", buyer_address, mode_of_payment);
    fprintf(out,"------------------------------------------------------------------------------------------------------------------------\n");
    
    fprintf(out,"\nNo.  | %-16s | %-7s | %-10s | %-11s | %-12s | %-10s | %-10s | %-14s |\n",
           "Product Name", "Qty(ml)", "Rate", "No OF Items", "Amount", "SGST", "CGST", "Total");
    fprintf(out,"-----+------------------+---------+------------+-------------+--------------+------------+------------+------------------\n");

    for (int i = 0; i < n; i++) {
        float sgst, cgst, line_total;
        if (type[0] == 'P' || type[0] == 'p') {
            sgst = item[i].amount * 0.09f;
            cgst = item[i].amount * 0.09f;
        } else {
            sgst = item[i].amount * 0.025f;
            cgst = item[i].amount * 0.025f;
        }
        float total = item[i].amount + sgst + cgst;

        gst_total += sgst + cgst;
        grand_total += total;

        print_item_row(out, i + 1, item[i].product_name, item[i].quantity,
                       item[i].rate, item[i].no_of_items, item[i].amount,
                       sgst, cgst,total);
    }

    fprintf(out,"-----+------------------+---------+------------+-------------+--------------+------------+------------+------------------\n");
    fprintf(out,"| %-98s %12.2f |\n","Total GST paid: ", gst_total);
    fprintf(out,"| %-98s %12.2f |\n","Amount to be paid without GST: ", grand_total - gst_total);
    fprintf(out,"| %-98s %12.2f |\n","Total Amount to be paid including GST: ", grand_total);
    fprintf(out,"--------------------------------------------------------------------------------------------------------------------------\n");
}