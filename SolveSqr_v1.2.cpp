#include <stdio.h>
#include <math.h>

const int INF_ROOTS = -1;

int SolveSqr (double a, double b, double c, double* x1, double* x2);
int test_SolveSqr ();
void solving_mode ();
int test_mode ();

int main () {

	printf("#SQUARE EQUATION SOLVER 9000 + TESTER v1.2\n");
	printf("# (c) Gleb Ovsyannikoff 2017\n\n");

	if (test_mode () == 0)
		solving_mode ();

	return 0;
}

int SolveSqr (double a, double b, double c, double* x1, double* x2) {

	int end = -2;

	double d = 0;

	*x1 = 0;
	*x2 = 0;


	if (a == 0) {
		if (b == 0) {
			end = (c == 0) ? INF_ROOTS : 0;
		}
		else {
			*x1 = -c / b;
			end = 1;
		}
	}
	else {
		d = b*b - 4*a*c;
		if (d >= 0){
			if (d == 0){
				*x1 = -b / (2*a);
				end = 1;
			}
			else {
				*x1 = (-b + sqrt(d)) / (2*a);
				*x2 = (-b - sqrt(d)) / (2*a);
				end = 2;
			}
		}
		else {
			end = 0;
		}

	}
	return end;
}

int test_SolveSqr () {
	                     /*a  b  c  x1 x2  n*/
	double test[6][5] = {{0, 0, 0, 0, 0},
	                     {0, 0, 2, 0, 0},
	                     {0, 5, 6, -1.2, 0},
	                     {1, 2, 2, 0, 0},
	                     {1, -8, 15.75, 4.5, 3.5},
	                     {1, 4, 4, -2, 0}};

	int end = 0, i = 0, n = 0, testN[6] = {INF_ROOTS, 0, 1, 0, 2, 1};
	double x1 = 0, x2 = 0;

	for (i = 0; i <= 5; i++) {
		n = SolveSqr(test[i][0], test[i][1], test[i][2], &x1, &x2);
		if ((n != testN[i]) || (x1 != test[i][3]) || (x2 != test[i][4])) {
			printf ("ERROR\na = %lg\nb = %lg\nc = %lg\n"
					"expected result\nx1 = %lg\nx2 = %lg\nn = %d\n"
					"got result\nx1 = %lg\nx2 = %lg\nn = %d\n\n",
			        test[i][0], test[i][1], test[i][2],
			        test[i][3], test[i][4], testN[i],
		        	x1, x2, n);
			end = 1;
		}
	}

	return end;
}

void solving_mode () {

	double a=0, b=0, c=0, x1=0, x2=0;
	int n=0;

	printf("Enter coefficients from equation\n"
			"a*x^2 + b*x + c = 0\n");

	printf("write a: ");
	scanf("%lg", &a);
	printf("write b: ");
	scanf("%lg", &a);
	printf("write c: ");
	scanf("%lg", &a);

	n = SolveSqr(a, b, c, &x1, &x2);

	switch (n) {

		case 0:
			printf ("The equation has no roots");
			break;

		case 1:
			printf ("The equation has one root\nx = %lg\n", x1);
			break;

		case 2:
			printf ("The equation has two roots\nx1 = %lg\nx2 = %lg\n", x1, x2);
			break;

		case INF_ROOTS:
			printf ("Any number is a root of the equation\n");
			break;

		default:
			printf ("ERROR n switch\n");
	}
}

int test_mode () {

	int test = 0;

	test = test_SolveSqr ();

	if (test == 0) {
		printf ("system check OK\n\n");
	}
	else {
		printf ("system check failed\n"
				"program is finished\n");
	}
	return test;
}