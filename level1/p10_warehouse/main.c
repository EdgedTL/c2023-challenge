#include "warehouse_managing.h"


void main(){
    bool exit = false;


    stock_t *stock = (stock_t*)malloc(MAX_STOCK_COUNT * sizeof(stock_t));




    while(!exit){
        int action;
        printf("Input your action:\n1: Check for stock\n2: Inbound\n3: Outbound\n4: Change values\n5: Display entire stock\n6: Add stock\n7: Delete stock\n8: Sort data\n9: Exit\n");
        scanf("%d", &action);
        printf("\n");
        printf("--------------------------------\n");
        switch (action) {
            case 1:
                check_stock(stock);
                break;
            case 2:
                Inbound(stock);
                break;
            case 3:
                Outbound(stock);
                break;
            case 4:
                change_value(stock);
                break;
            case 5:
                ShowStock(stock);
                break;
            case 6:
                add_new_type(stock);
                break;
            case 7:
                delete_record(stock);
                break;
            case 8:
                sort(stock);
                break;
            case 9:
                exit = true;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
        printf("--------------------------------\n");

    }

}
