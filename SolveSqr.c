#include <stdio.h>
#include <math.h>

#define INF_ROOTS -1

int SolveSqr (double a, double b, double c, double *x1, double *x2);
int test_SolveSqr ();
int CustomTest_SolveSqr ();
void solving_mode ();
void test_mode ();
void custom_test_mode ();


int main() {

    int mode;

    printf("#SQUARE EQUATION SOLVER 9000 + TESTER v2.1\n"); //title
    printf("# (c) Gleb Ovsyannikoff 2017\n\n");

    printf("What do you want to do?\n1 (solve)\n2 (standard test)\n3 (custom test)\n");  //choosing mode
    scanf("%d", &mode);
    switch (mode) {
        case 1:
            solving_mode ();
            break;

        case 2:      //standard examples testing mode
            test_mode ();
            break;

        case 3:      //custom examples testing mode
            custom_test_mode ();
            break;

        default:
            printf ("ERROR mode switch");
    }
    return 0;
}

int SolveSqr (double a, double b, double c, double *x1, double *x2) {

    int end = 3;                        //NO ERRORS BUT CUSTOM TEST FAIL

    if (a == 0) {                       //002 005 006 ERROR
        if (b == 0) {                   //002 005 ERROR
            end = (c == 0) ? INF_ROOTS : 0; //002 005 ERROR
        }
        else {                          //006 ERROR
            *x1 = -c / b;               //006 ERROR
            end = 1;                    //006 END ERROR
        }
    }
    else {                              //001 003 004 ERROR
        double d = b*b -4*a*c;          //001 003 004 x1x2  ERROR
        if (d >= 0){                    //003 004 ERROR
            if (d == 0){                 //003 ERROR
                *x1 = *x2 = -b / (2*a);  //003 x1x2 ERROR
                end = 1;                 //003 END ERROR
            }
            else {                       //004 ERROR
                *x1 = (-b + sqrt(d)) / (2*a);//004 x1x2 ERROR
                *x2 = (-b - sqrt(d)) / (2*a);//004 x1x2 ERROR
                end = 2;                 //004 END ERROR
            }
        }
        else {                           //001 ERROR
            end = 0;                     //001 ERROR
        }

    }
    return end;
}

int test_SolveSqr () {
    int end = 0;
    double x1 = 0, x2 = 0;

    if (SolveSqr(1, 2, 2, &x1, &x2) !=0) {
        end = 1;
        printf ("ERROR 001\n");
    }
    if (SolveSqr(0, 0, 2, &x1, &x2) != 0) {
        end = 1;
        printf ("ERROR 002\n");
    }
    if (!((SolveSqr(1, 2, 1, &x1, &x2) == 1) && (x1 == -1) && (x2 == -1))) {
        end = 1;
        if (SolveSqr(1, 2, 1, &x1, &x2) != 1)
            printf ("END + ");
        printf ("ERROR 003");
        if (x1 != -1)
            printf ("x1");
        if (x2 != -1)
            printf ("x2");
        printf ("\n");
    }
    if (!((SolveSqr(1, 7, 12, &x1, &x2) == 2) && (x1 == -3) && (x2 == -4))) {
        end = 1;
        if (SolveSqr(1, 7, 12, &x1, &x2) != 2)
            printf ("END + ");
        printf ("ERROR 004");
        if (x1 != -1)
            printf("x1");
        if (x2 != -1)
            printf("x2");

        printf("\n");
    }
    if (SolveSqr(0, 0, 0, &x1, &x2) != -1) {
        end = 1;
        printf ("ERROR 005\n");
    }
    if (!( (SolveSqr(0, 5, 6, &x1, &x2) == 1) && (x1 == -1.2))) {
        end = 1;
        if (SolveSqr(0, 5, 6, &x1, &x2) != 1)
            printf ("END + ");
        printf("ERROR 006\n");
    }

    return end;
}

int CustomTest_SolveSqr () {
    int end = 0, n;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, testX1 = 0, testX2 = 0;

    printf("write number of roots (if equation has infinite roots write -1):\n");
    scanf("%d", &n);

    switch (n) {
        case 0:
            printf ("write: a b c\n");
            scanf ("%lg %lg %lg", &a, &b, &c);
            if (n != SolveSqr(a, b, c, &x1, &x2)) {
                end = 1;
            }
            break;

        case 1:
            printf ("write: a b c x\n");
            scanf ("%lg %lg %lg %lg", &a, &b, &c, &testX1);
            testX2 = testX1;
            if (!((n == SolveSqr(a, b, c, &x1, &x2))&&(testX1 == x1)&&(testX2 == x2))){
                end = 1;
            }
            break;

        case 2:
            printf ("write: a b c x1 x2\n");
            scanf("%lg %lg %lg %lg %lg", &a, &b, &c, &testX1, &testX2);
            if ( !( (n == SolveSqr(a, b, c, &x1, &x2)) &&
                    ( ((testX1 == x1)&&(testX2 == x2)) || ((testX1 == x2)&&(testX2 == x1)) ) ) ){
                end = 1;
            }
            break;

        case INF_ROOTS:
            printf ("write: a b c\n");
            scanf ("%lg %lg %lg", &a, &b, &c);
            if (n != SolveSqr(a, b, c, &x1, &x2)){
                end = 1;
            }
            break;

        default:
            printf ("ERROR n > 2 or n < -1");
    }
    return end;
}

void solving_mode () {

    double a=0, b=0, c=0, x1=0, x2=0;
    int n=0;

    printf("write: a b c\n");  //entering parameters
    scanf("%lg %lg %lg", &a, &b, &c);

    n = SolveSqr(a, b, c, &x1, &x2);

    switch (n) {   //giving answer

        case 0:
            printf ("The equation has no roots");
            break;

        case 1:
            printf ("The equation has one root\n%lg", x1);
            break;

        case 2:
            printf ("The equation has two roots\n%lg\n%lg", x1, x2);
            break;

        case -1:
            printf ("Any number is a root of the equation");
            break;

        default:
            printf ("ERROR n switch");
    }
}

void test_mode () {

    int test=0;

    test = test_SolveSqr ();
    if (test==0){            //result of test
        printf ("test passed");
    }
    else {
        printf ("test failed");
    }
}

void custom_test_mode () {

    int test=0;

    test = CustomTest_SolveSqr ();
    if (test==0){            //result of test
        printf ("test passed");
    }
    else {
        printf ("test failed");
    }
