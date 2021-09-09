#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"
#include "assert.h"

#define INFINITE INT_MAX

struct Coef_t {
	double a;
	double b;
	double c;
};

struct Roots_t {
	double x1;
	double x2;
};

/**
 *  Inputs the coefficients.
 * 
 * \return Coefficients of square equation.
 */

struct Coef_t InputCoef() {

	struct Coef_t coef = {0, 0, 0};

	printf("Coef a:\n");
	scanf("%lf", &coef.a);

	printf("Coef b:\n");
	scanf("%lf", &coef.b); 

	printf("Coef c:\n");
	scanf("%lf", &coef.c);

	return coef;
}

/**
 *  Solves the squere equation.
 * 
 * \param[in] coef  coef - Struct, consists the coefficients: a, b and c.
 * \param[out] root  root - Pointer on struct, consists the 1st and 2nd roots.
 * 
 * \return Number of roots.
 * 
 * \note In case of infinite number of roots, returns INFINITE.
 */

int FindingTheRoots(struct Coef_t coef, struct Roots_t *root) {

	assert(isfinite(coef.a));
	assert(isfinite(coef.b));
	assert(isfinite(coef.c));
	assert(root != NULL);

	if (!coef.a) {
		if (!coef.b) {
			if (!coef.c) {
				return INFINITE;
			} else {
				return 0;
			}
		} else {
			root->x1 = -coef.c / coef.b;
			return 1;
		}
	} else {
		double d = coef.b * coef.b - 4 * coef.a * coef.c;
		if (d > 0) {
			root->x1 = (-coef.b + sqrt(d)) / (2 * coef.a);
			root->x2 = (-coef.b - sqrt(d)) / (2 * coef.a);
			return 2;
		} else if (d == 0) {
			root->x1 = -coef.b / (2 * coef.a);
			return 1;
		} else {
			return 0;
		}
	}
}

/**
 *  Сonsiders the return values of the FindingTheRoots function.
 */

int main() {

	//printf("Enter the coefficients of square equation:\n");
	//struct Coef_t coef = InputCoef();
	struct Coef_t coef = {0, 0, 0};
	for (int i = 0; i < 70; ++i) {
		struct Roots_t root = {0, 0};
		coef.a = rand() % 21;
		coef.b = rand() % 147;
		coef.c = rand() % 15;
		int count_of_roots = FindingTheRoots(coef, &root);
		switch (count_of_roots) {

			case 0: printf("Discriminant is less then zero or a == 0, b == 0 and c != 0. Not roots:( ");
					break;

			case 1: printf("Discriminant equals zero or it's a linear equation ");
					printf("The root x = %lf\n", root.x1);
					break;

			case 2: printf("Roots: x1 = %lf; x2 = %lf ", root.x1, root.x2);
					break;

			case INFINITE: printf("All coefficients equal zero:(\n");
						  printf("There are infinity roots");
				break;

			default: printf("Error in func main(): count_of_roots = %d ", count_of_roots);
					return 1;
		}
		printf(" | (%lf, %lf, %lf)\n", coef.a, coef.b, coef.c);
	}
	return 0;
}