#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int i, j;
int mainExit;
void closed();
void forDelay(int j);
void menu();
void newAcc();
void edit();
void transCat();
void see();
void erase();
void viewList();

struct date {
    int month, day, year;
};

struct {
    char name[60];
    int accNo, Age;
    char address[60];
    char citizenship[15];
    double phone;
    char accType[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdrawl;
}