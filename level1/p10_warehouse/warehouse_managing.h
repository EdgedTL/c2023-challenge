#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STOCK_COUNT 100
typedef struct Stock{
    int id;
    char name[15];
    int quantity;
    float price;
    float total;
}stock_t;

void check_stock(stock_t *stock){
    char* name = "\0";
    printf("Input stock name:\n");
    scanf("%s", &name);
    for(int i=0;i<MAX_STOCK_COUNT;i++){
        if(!strcmp(stock[i].name, name)){
            printf("ID: %d\n", stock[i].id);
            printf("Name: %s\n", stock[i].name);
            printf("Quantity: %d\n", stock[i].quantity);
            printf("Price: %f\n", stock[i].price);
            printf("Total: %f\n", stock[i].total);
            return;
        }
    }
    printf("Item not found\n");
}

stock_t* add_new_type(stock_t *stock){
    int id; int quantity; char *name = NULL; float price; float total;

    int stack = 0;
    if(stock[MAX_STOCK_COUNT-1].id != 0){
        printf("Stack is full\n");
        return NULL;
    }


    printf("Input data in the following format: \n ID Name Quantity Price Total \n");
    scanf_s("%d %14s %d %f %f",&id, name, &quantity, &price, &total);


    for(int i = 0;i<MAX_STOCK_COUNT;i++){
        if(stock[i].id == 0){stack = i;break;}
        if(id == stock[i].id){
            printf("ID already exists\n");
            return NULL;
        }
        if(!strcmp(name, stock[i].name)){
            if(price != stock[i].price){
                printf("Name repeated, automatically changed name\n");

                if(name[strlen(name)-1]-'0' <=9){
                    int x = name[strlen(name)-1]-'0';
                    name[strlen(name)-1] = (char)(x+1+'0');
                }else
                strcat(name, "_1");
            }
            else{
                printf("Item already exists\n");
                return NULL;
            }
        }
    }
    stock[stack].id = id;
    stock[stack].quantity = quantity;
    strcpy(stock[stack].name, name);
    stock[stack].price = price;
    stock[stack].total = total;
    printf("Item Added\nName: %s\tQuantity: %d\tPrice: %f\tTotal: %f\nID: %d\n\n",
           stock[stack].name, stock[stack].quantity, stock[stack].price, stock[stack].total, stock[stack].id);
    printf("Stock added. ID: %d",  stock[stack].id);
    return  stock;
}

void change_value(stock_t *stock){
    printf("Input stock ID:\n");
    int id;
    scanf("%d", &id);
    for(int i = 0;i<MAX_STOCK_COUNT;i++) {
        if (stock[i].id == id) {
            printf("Stock found. Please input new values\n");
            int quantity;float price, total;
            scanf("quantity: %d\n", &quantity);
            scanf("price: %f\n", &price);
            scanf("total: %f\n", &total);

            stock[i].quantity = quantity;
            stock[i].price = price;
            stock[i].total = total;
            printf("Item changed\nName: %s\tQuantity: %d\tPrice: %f\tTotal: %f\nID: %d\n\n",
                   stock[i].name, stock[i].quantity, stock[i].price, stock[i].total, stock[i].id);
            return;
        }
    }
    printf("Item not found\n");
}
void Inbound(stock_t* stock){
    int id, quantity;
    printf("Input stock ID:\n");
    scanf("%d", &id);

    printf("Input outbound quantity:\n");
    scanf("%d", &quantity);
    for(int i = 0;i<MAX_STOCK_COUNT;i++){
        if(stock[i].id == id){
            stock[i].quantity = stock[i].quantity + quantity;
            printf("Item inbound\nName: %s\tQuantity: %d\tPrice: %f\tTotal: %f\nID: %d\n\n",
                   stock[i].name, stock[i].quantity, stock[i].price, stock[i].total, stock[i].id);
            return;
        }
    }
    printf("Item not found");
}
void Outbound(stock_t* stock){
    int id; int quantity;
    printf("Input stock ID:\n");
    scanf("%d", &id);
    printf("Input outbound quantity:\n");
    scanf("%d", &quantity);
    for(int i = 0;i<MAX_STOCK_COUNT;i++){
        if(stock[i].id == id){
            if(stock[i].quantity < quantity){
                printf("Not enough in stock\n");
            }
            stock[i].quantity = stock[i].quantity - quantity;
            printf("Item outbound\nName: %s\tQuantity: %d\tPrice: %f\tTotal: %f\nID: %d\n\n",
                   stock[i].name, stock[i].quantity, stock[i].price, stock[i].total, stock[i].id);
            return;
        }
    }
    printf("Item not found\n");
}


void delete_record(stock_t *stock){
    int id;
    int itemCount = sizeof(stock) / sizeof(stock[0]);
    printf("Input stock ID:\n");
    scanf("%d", &id);
    for(int i = 0;i<=itemCount;i++){
        if(stock[i].id == id){
            for(int j = i;j<=itemCount;j++){
                stock[j] = stock[j+1];
                if(stock[j+1].id == 0||j+1==100){
                    return;
                }
            }
        }
    }
    printf("Stock ID not found\n");
}

int compareByName(const void *a, const void *b) {
    return strcmp(((struct Stock*)a)->name, ((struct Stock*)b)->name);
}

void sort(stock_t* stock){
    int sort_type;
    int itemCount = sizeof(stock) / sizeof(stock[0]);
    printf("Sorting type:\t1.ID\t2.Name \t3.Price\t4.Total\n");
    scanf("%d", &sort_type);
    switch (sort_type) {
        case 1:
            for(int i = 0;i<MAX_STOCK_COUNT;i++){
                for(int j = i+1;j<MAX_STOCK_COUNT;j++){
                    if(stock[i].id > stock[j].id){
                        stock_t temp;
                        temp = stock[i];
                        stock[i] = stock[j];
                        stock[j] = temp;
                    }
                }
            }
            break;
        case 2:

            qsort(stock, itemCount, sizeof(stock_t), compareByName);
            break;
        case 3:
            for(int i = 0;i<MAX_STOCK_COUNT;i++){
                for(int j = i+1;j<MAX_STOCK_COUNT;j++){
                    if(stock[i].price > stock[j].price){
                        stock_t temp;
                        temp = stock[i];
                        stock[i] = stock[j];
                        stock[j] = temp;
                    }
                }
            }
            break;
        case 4:
            for(int i = 0;i<MAX_STOCK_COUNT;i++){
                for(int j = i+1;j<MAX_STOCK_COUNT;j++){
                    if(stock[i].total > stock[j].total){
                        stock_t temp;
                        temp = stock[i];
                        stock[i] = stock[j];
                        stock[j] = temp;
                    }
                }
            }
            break;
        default:
            printf("Invalid input\n");
            return;
    }


    printf("Sorted\n");
}

void ShowStock(stock_t* stock) {
    for (int i = 0; i < MAX_STOCK_COUNT; i++) {
        printf("Name: %s\tQuantity: %d\tPrice: %f\tTotal: %f\tID: %d\n",
               stock[i].name, stock[i].quantity, stock[i].price, stock[i].total, stock[i].id);
    }
}



/*448816706
kubeedge
容器魔方*/