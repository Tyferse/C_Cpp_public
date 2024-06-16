#include <stdio.h>


void print(int number) {
    printf("Your number is %d\n", number);
}


float del(float a, float b) {
    float res;
    if (b != 0) 
        res = a / b;
    else 
        res = 0.0;
    
    return res;
}


void get_value(int *my_pointer) {
    *my_pointer = 1000;
}


struct students {int id; 
                 float percentage;
                 char name};


int main() {

    int num = 23, y = 45, res, age;
    res = y % num;
    res += 1;

	float x;
	x = 4.732;
    char sym = 'T';
    double dbl = 25.252638451;


    printf("Hello wolrd! %d, %.2f, %d\n", num, x, sym + 1);
    printf("Result is %f\n", res * dbl);

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age > 18) 
        printf("Your age is bigger than 18. Age is %d\n", age);
    else if (age < 18) 
        printf("Your age is less than 18. Age is %d\n", age);
    else 
        printf("Your age is equal 18!\n");

    int res2 = x > y ? 23 : 45;
    printf("%d\n", res2);


    switch (res2) {
        case 23:
            printf("Variable %d\n", res2);
            break;
        case 45:
            printf("Variable %d\n", res2);
            break;
        default:
            printf("Your case is not detected.\n");
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    for (int i = 100; i > 0; i /= 2) {
        printf("%d\n", i);
    }

    int i = 256;
    do {
        printf("%d\n", i);
    } while (i < 100);


    print(i);
    float result = del(1.0, 0.0);
    printf("%f\n", result);
    result = del(5.0, 60.0);
    printf("%f\n", result);

    // char array [5] = {'T', 'e', 'y', 'W', 'J'};
    // char arr [] = "Hello";
    int nums [3] = {5, 36, 256};
    nums[0] = 6;
    printf("element is %d\n", nums[0]);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", nums[i]);
    }

    char strings [2][5] = {{'T', 'e', 'y', 'W', 'J'}, 
                           {'H', 'e', 'l', 'l', 'o'}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", strings[i][j]);
        }
        printf("\n");
    }


    int getValue;
    get_value(&getValue);
    printf("Value of variable is %d\n", getValue);


    struct students maks;
    maks.id = 1;
    maks.percentage = 23.7;
    maks.name = 'M';

    struct students oleg;
    oleg.id = 2;
    oleg.percentage = 50.2;
    oleg.name = 'O';

    printf("Maks id is %d\n", maks.id);


    return 0;
}
