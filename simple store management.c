/************************************************************
This project is made by Sadi,Sahidul, Abed and Mubasshir.
It is our first-year project,showcasing a
simple store management system.
Documentation is prepared by Mubasshir.
Project published date: 24 January 2025.
*/
#include<stdio.h>
#include<string.h>
struct item_info //This struct is for a product.
{
    int id;  //Product id
    char name[100];
    int quantity;  //Quantity of the product in stock
    double price;  //Price of the product in kg
};

int n;  //n is number of items product.txt has
struct item_info arr[100]; //Array to hold product details(max 100)

void readdata() //This function reads product data from product.txt
{
    FILE *fp;
    fp = fopen("product.txt", "r");  //Open the file in read mode
    fscanf(fp,"%d", &n);
    for(int i=0; i<n; i++)
    {
        fscanf(fp,"%d %s %d %lf", &arr[i].id, &arr[i].name, &arr[i].quantity, &arr[i].price);
    }
    fclose(fp);
}

void writedata()  //This function writes product data to product.txt in write mode.
{
    FILE *fp;
    fp = fopen("product.txt", "w"); //Open the file in write mode
    fprintf(fp,"%d\n", n);
    for(int i=0; i<n; i++)
    {
        fprintf(fp,"%d %s %d %.2lf\n", arr[i].id, arr[i].name, arr[i].quantity, arr[i].price);
    }
    fclose(fp);
}
void show()  //This function displays all product details in the terminal
{
    printf("Total Item %d\n", n);
    printf("Code\tName\t\tQuantity\tPrice(per Kg)\n", n);
    for(int i=0; i<n; i++)
    {
        printf("%d\t%s\t\t%d\t\t%.2lf\n", arr[i].id, arr[i].name, arr[i].quantity, arr[i].price);
    }
}
/*Orderdetails function collect address and contact number from the user and writes them
in order.txt file*/
void orderdetails(int total) //total is total price of the items. first it was initialized by 0.
{
    char address[20];
    int phone;
    double total_price;
    printf("Adress - ");
    scanf("%s", &address);
    printf("Contact - ");
    scanf("%d", &phone);
    total_price = total;
    FILE *or;
    or = fopen("order.txt", "a");  //Open order.txt file in append mode
    fprintf(or,"\n%s\n%d\n%.2lf\n", address, phone, total_price);
    printf("Your order is successful.\nThanks for your order.\n");
    printf("Note: You can rate our Product after getting through option 4.\n");
}
/*This function is for cancelling order. For cancelling an order the user is asked of his/her phone
number. Then the function search the number in order.txt file. We also created temp.txt file so that
we can add those contact that is not equal to the cancelled contact. we used temp.txt file as a
temporary storage  */
void readwrite()
{
    int phone, found=0; /*found is considered as flag here, when the desired number is found, the value changed to 1
                                otherwise it remains 0*/
    printf("Enter phone number: ");
    scanf("%d", &phone);
    FILE *or = fopen("order.txt", "r");
    FILE *temp = fopen("temp.txt", "w"); /*Created temp.txt so that all the details of the user
                                           is saved in temp.txt excluding the canceled order */

    char address[100];
    int temp_phone;
    double total_price;
    //Loop through the orders and copy all orders
    while (fscanf(or, "%s %d %lf", address, &temp_phone, &total_price) != EOF)
    {
        if (temp_phone == phone)
        {
            found = 1;
            continue;
        }
        fprintf(temp, "\n%s\n%d\n%.2lf\n", address, temp_phone, total_price);
    }

    fclose(or);
    fclose(temp);

    remove("order.txt"); //As the data is saved in temp.txt that's why order.txt is removed
    rename("temp.txt", "order.txt"); //temp.txt is renamed as order.txt

    if (found)
        printf("Order canceled successfully.\n");
    else
        printf("Phone number not found.\n");
}
/*This function is used for giving max review of any product. It considers
only the max point*/
void view(int revcode,int rate){ //revcode means the product code that user put in
    int pcode, newrate; //pcode means product code
    char max[20]=",max.";
    FILE *r = fopen("review.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    while(fscanf(r,"%d %d %s", &pcode, &newrate, max)!=EOF){
        if(pcode==revcode){
            if(newrate<rate) newrate = rate;
        }
        fprintf(temp, "%d %d%s\n", pcode, newrate, max);
    }
    fclose(r);
    fclose(temp);

    remove("review.txt");
    rename("temp.txt", "review.txt");
}

/*This function reads product review from review.txt file and shows
that to user*/
void show_readreview(){
    int itemcode, rating;
    char full[20];
    FILE *fl = fopen("review.txt", "r");
    while(fscanf(fl,"%d %d %s", &itemcode, &rating, full)!=EOF){
        printf("%d\t\t%d%s\n", itemcode, rating, full);
    }
}

int main()
{
    printf("\t\t\t\t\t --Welcome to Ramadan_Outlet--\n");
    printf("\t\t\t\t\t     1. View all items\n");
    printf("\t\t\t\t\t     2. Order\n");
    printf("\t\t\t\t\t     3. Cancel order\n");
    printf("\t\t\t\t\t     4. Product Review\n");
    printf("\n\t\t\t\t\t   Select your choice: ");
    int choice;
    scanf("%d", &choice);
    printf("\n");
    if(choice==1)
    {
        readdata();
        show();
    }
    if(choice==2)
    {
        readdata();
        show();
        printf("\nAdd product\n");
        int  total=0;
        while(1)
        {
            int product_code, net;
            printf("Product code - ");
            scanf("%d", &product_code);
            printf("Quantity - ");
            scanf("%d", &net);
            for(int i=0; i<n; i++)
            {
                if(product_code==arr[i].id)
                {
                    arr[i].quantity -= net; //it calculates the price
                    total += net * arr[i].price;
                }
            }
            printf("Anything else?(yes or no)");
            char s[20];
            scanf("%s", &s);
            if(strcmp(s, "no")==0)
            {
                printf("Total Price = %d\n\n", total);
                break;
            }
            if(strcmp(s, "no")==1) printf("\n");
        }
        orderdetails(total);
        writedata();
    }
    if(choice==3)
    {
        readwrite();
    }
    if(choice==4)
    {
        readdata();
        show();
        int revcode, rate, k;
        printf("How many product do you want to rate: ");
        scanf("%d", &k);
        for(int i=0; i<k; i++){
            printf("Poduct code: ");
            scanf("%d", &revcode);
            printf("Rate(out of 10): ");
            scanf("%d", &rate);
            view(revcode, rate);
        }
        printf("Product code\tRating\n");
        show_readreview();
    }
}
