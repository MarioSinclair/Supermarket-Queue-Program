/*
Name: Mario Sinclair
Supermarket Queue Program
*/
#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int exday[SIZE];
int exmonth[SIZE];
int exyear[SIZE];
int rear = - 1;
int front = - 1;
int count = 0;

struct date{
    int day;
    int month;
    int year;
};

main()
{
    int choice, milkid, id, c;
    struct date info;
    while (1)
    {
        system("cls");
        printf("1.Stockmilk \n");
        printf("2.Sellmilk \n");
        printf("3.Printstock\n");
        printf("4.Check\n");
        printf("5.Search\n");
        printf("6.Exit\n");
        printf("Please select the desired option\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the milk ID number\n");
                scanf("%d",&milkid);
                printf("Enter the milk day\n");
                scanf("%d", &info.day);
                if (info.day > 30){
                    printf("Invalid day\n");
                    printf("Returning to menu...\nPlease re enter VALID information");
                    sleep(2);
                    main();
                }
                printf("Enter the milk month\n");
                scanf("%d", &info.month);
                if (info.month > 12){
                    printf("Invalid day\n");
                    printf("Returning to menu...\nPlease re enter VALID information");
                    sleep(2);
                    main();
                }
                printf("Enter the milk year\n");
                scanf("%d", &info.year);
                    if (info.day >= 15){
                        info.month = info.month + 1;
                        info.day = info.day - 15;
                    }else{
                        info.day = info.day + 15;
                    }
                        if (info.month >= 12){
                            info.year = info.year + 1;
                            info.month = info.month - 12;
                        }
                    stockmilk(milkid,info);
                    break;
            case 2:
                sellmilk();
                break;
            case 3:
                printstock();
                break;
            case 4:
                checkexp(info);
                break;
            case 5:
                printf("Please enter the id you are looking for\n");
                scanf("%d", &id);
                c = search(id);
                if (c != 1){
                    printf("Milk Expiry Date: %d/%d/%d (DD/MM/YYYY)\n", exday[c], exmonth[c], exyear[c]);
                    printf("\n");
                    getch();
                }
                break;
            case 6:
                exit(0);
                break;
            default:
            printf("Incorrect choice \n");
        }
    }
}

void stockmilk(int milkid, struct date info)
{
    if ((front == rear + 1) || (front = 0 && rear == SIZE - 1)){
        printf("There is no more space available\n");
        getch();
    }else{
        if (front == - 1)
        front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = milkid;
        exday[rear] = info.day;
        exmonth[rear] = info.month;
        exyear[rear] = info.year;
        count++;
        printf("\nMilk ID: %d\nMilk Expiration date: %d/%d/%d (DD/MM/YYYY)\nEntered\n", milkid, info.day, info.month, info.year);
        getch();
    }
}

void sellmilk()
{
    if (count == 0){
        printf("There is no milk to be sold \n");
        getch();
        return ;
    }
    else{
        count--;
        printf("Milk ID: %d has been sold\n", queue[front]);
        front = (front + 1) % SIZE;
        getch();
    }
}


void checkexp(){
    if (front == - 1 || front > rear)
    {
        printf("There is no milk available\n");
        getch();
        return ;
    }
    else
    {
        printf("Milk ID: %d is next available\n", queue[front]);
        printf("Milk Expiry Date: %d/%d/%d (DD/MM/YYYY)\n", exday[front], exmonth[front], exyear[front]);
        getch();
    }
}

int search(int id){
        if (count == 0){
        printf("There is no milk to be found \n");
        getch();
    }else{
        for (int c = front; c <= rear; c++){
            if (queue[c] == id){
            printf("Milk ID: %d \n", queue[c]);
            return c;
            }else{
            printf("Invalid ID number");
            sleep(1);
            return 1;
            }
        }
        getch();
    }
}

void printstock()
{
    if (count == 0){
        printf("There is no milk available \n");
        getch();
    }else
    {
        for (int c = front; c <= rear; c++){
            printf("Milk ID: %d \n", queue[c]);
            printf("Milk Expiry Date: %d/%d/%d (DD/MM/YYYY)\n", exday[c], exmonth[c], exyear[c]);
            printf("\n");
        }
        getch();
    }
}
