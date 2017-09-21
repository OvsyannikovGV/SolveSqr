#include <iostream>
#include <math.h>

const int INF_ROOTS = -1;

int SolveSqr (double a, double b, double c, double* x1, double* x2);
int test_SolveSqr ();
void solving_mode ();
int test_mode ();

int main () {

	std::cout << "#SQUARE EQUATION SOLVER 9000 + TESTER v1.2\n"
	          << "# (c) Gleb Ovsyannikoff 2017\n\n";

	if (test_mode () == 0)
		solving_mode ();

	return 0;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation a*x^2 + b*x + c = 0
//!
//! @param [in] a a‐coefficient
//! @param [in] b b‐coefficient
//! @param [in] c c‐coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns INF_ROOTS.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

int SolveSqr (double a, double b, double c, double* x1, double* x2) {

	int end = 3;

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

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Tests function SolveSqr
//!
//! @return 0 if tested function work properly,
//! 1 if tested function does not work correctly
//!
//! @note when tested function gives uncorrect
//! answer, outputs information about error 
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

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
			std::cout << "ERROR " << i << ":\n"
			          << "a = " << test[i][0] << "\n"
			          << "b = " << test[i][1] << "\n"
			          << "c = " << test[i][2] << "\n"
			          << "expected result\n"
			          << "x1 = " << test[i][3] << "\n"
			          << "x2 = " << test[i][4] << "\n"
			          << "n = " << testN[i] << "\n"
			          << "got result\n"
			          << "x1 = " << x1 << "\n"
			          << "x2 = " << x2 << "\n"
			          << "n = " << n << "\n\n";
			end = 1;
		}
	}

	return end;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Create some kind of interface for user
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

void solving_mode () {

	double a=0, b=0, c=0, x1=0, x2=0;
	int n=0;

	std::cout << "Enter coefficients from equation\n"
	          << "a*x^2 + b*x + c = 0\n";

	std::cout << "write a: ";
	std::cin >> a;
	std::cout << "write b: ";
	std::cin >> a;
	std::cout << "write c: ";
	std::cin >> a;

	n = SolveSqr(a, b, c, &x1, &x2);

	switch (n) {

		case 0:
			std::cout << "The equation has no roots\n";
			break;

		case 1:
			std::cout << "The equation has one root\nx = " << x1 << "\n";
			break;

		case 2:
			std::cout << "The equation has two roots\nx1 = " << x1 << "\nx2 = " << x2 << "\n";
			break;

		case INF_ROOTS:
			std::cout << "Any number is a root of the equation\n";
			break;

		default:
			std::cout << "ERROR n switch\n";
	}
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! tells user about result of test_SolveSqr
//!
//! @return 0 if SolveSqr work properly,
//! 1 if SolveSqr does not work correctly
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

int test_mode () {

	int test = 0;

	test = test_SolveSqr ();

	if (test == 0) {
		std::cout << "system check OK\n\n";
	}
	else {
		std::cout << "system check failed\n"
		          << "program is finished\n";
	}
	return test;
}
