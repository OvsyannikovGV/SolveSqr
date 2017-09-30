#include <iostream>
#include <math.h>
#include <assert.h>

const int INF_ROOTS = -3;

int solve_sqr(const double a, const double b, const double c, double *x1, double *x2, double *discr);
int test_solve_sqr();
void solving_mode();
int test_mode();

int main() {

	std::cout << "#SQUARE EQUATION SOLVER 9000 + TESTER v1.2\n"
		<< "# (c) Gleb Ovsyannikoff 2017\n\n";

	if (test_mode() == 0)
		solving_mode();

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
//! @return Number of roots (retValue)
//!
//! @note In case of infinite number of roots,
//! returns INF_ROOTS.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

int solve_sqr(const double a, const double b, const double c, double *x1, double *x2, double *discr) {

	assert(x1);
	assert(x2);

	*x1 = 0;
	*x2 = 0;
	*discr = 0;

	if (a == 0) {
		if (b == 0) {
			return (c == 0) ? INF_ROOTS : 0;
		}
		else {
			*x1 = -c / b;
			return 1;
		}
	}
	else {
		*discr = b*b - 4 * a*c;
		if (*discr >= 0) {
			if (*discr == 0) {
				*x1 = -b / (2 * a);
				return 1;
			}
			else {
				*x1 = (-b + sqrt(*discr)) / (2 * a);
				*x2 = (-b - sqrt(*discr)) / (2 * a);
				return 2;
			}
		}
		else {
			*x1 = (-b) / (2 * a);
			return (b == 0) ? -1 : -2;
		}
	}
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Tests function solve_sqr
//!
//! @return 0 if tested function work properly,
//! 1 if tested function does not work correctly
//!
//! @note when tested function gives incorrect
//! answer, outputs information about error
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

int test_solve_sqr() {
	/*a  b  c  x1 x2  n discr*/
	double test[7][6] = { { 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 2, 0, 0, 0 },
	{ 0, 5, 6, -1.2, 0, 0 },
	{ 5, 0, 3.2, 0, 0, -64 },
	{ 1, 2, 2, -1, 0, -4 },
	{ 1, -8, 15.75, 4.5, 3.5, 1 },
	{ 1, 4, 4, -2, 0, 0 } };

	int end = 0, i = 0, n = 0, test_n[7] = { INF_ROOTS, 0, 1, -1, -2, 2, 1 };
	double x1 = 0, x2 = 0, discr = 0;

	for (i = 0; i <= 5; i++)
	{
		n = solve_sqr(test[i][0], test[i][1], test[i][2], &x1, &x2, &discr);
		if ((n != test_n[i]) || (x1 != test[i][3]) || (x2 != test[i][4]))
		{
			std::cout << "ERROR " << i << ":\n"
				<< "a = " << test[i][0] << "\n"
				<< "b = " << test[i][1] << "\n"
				<< "c = " << test[i][2] << "\n"
				<< "expected result\n"
				<< "x1 = " << test[i][3] << "\n"
				<< "x2 = " << test[i][4] << "\n"
				<< "n = " << test_n[i] << "\n"
				<< "discr = " << test[i][5] << "\n"
				<< "got result\n"
				<< "x1 = " << x1 << "\n"
				<< "x2 = " << x2 << "\n"
				<< "n = " << n << "\n"
				<< "discr = " << discr << "\n";
			end = 1;
		}
	}
	return end;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Create some kind of interface for user
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

void solving_mode() {

	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, discr, imgnr_part = 0;
	int n = 0;

	std::cout << "Enter coefficients from equation\n"
		<< "a*x^2 + b*x + c = 0\n";

	std::cout << "write a: ";
	std::cin >> a;
	std::cout << "write b: ";
	std::cin >> b;
	std::cout << "write c: ";
	std::cin >> c;

	n = solve_sqr(a, b, c, &x1, &x2, &discr);

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

	case -2:
		imgnr_part = sqrt(abs(discr)) / (2 * a);
		std::cout << "The equation has two roots\nx1 = " << x1 << " + i*" << imgnr_part
			<< "\nx2 = " << x1 << " - i*" << imgnr_part << "\n";
		break;

	case -1:
		imgnr_part = sqrt(abs(discr)) / (2 * a);
		std::cout << "The equation has two roots\nx1 = i*" << imgnr_part << "\nx2 = -i*" << imgnr_part << "\n";
		break;

	default:
		std::cout << "ERROR n switch\n";
	}
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! tells user about result of test_solve_sqr
//!
//! @return 0 if solve_sqr work properly,
//! 1 if solve_sqr does not work correctly
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐

int test_mode() {

	int test = 0;

	test = test_solve_sqr();

	if (test == 0) {
		std::cout << "system check OK\n\n";
	}
	else {
		std::cout << "system check failed\n"
			<< "program is finished\n";
	}
	return test;
}
