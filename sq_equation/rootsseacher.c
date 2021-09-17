#include "rootsseacher.h"

/**
 *  Sequre input of the integer digit.
 * 
 * \return Integer digit entered from the keyboard.
 * 
 * \note The user is given three attempts to enter a number.
 */

double SecureInputInt() {

	int digit = 0;
	char buffer[100];

	int counter = 3;
	while(counter) {

		if (scanf("%s", buffer) == EOF) {
			printf("Oops... End of file detected:(\n");
			exit(1);
		}

		digit = atoi(buffer);

		if (digit == 0) {
			if (*buffer != '0') {
				printf("Oops... It's not digit:( Please, try again.\n");
			} else {
				return digit;
			}
		} else {
			return digit;
		}
		--counter;
	}

	printf("You're not attentive:(");
	exit(1);
}

/**
 *   Sequre Input of the coefficients.
 * 
 * \return Coefficients of square equation.
 */

struct Coef_t InputCoefs() {
	struct Coef_t coef = {0, 0, 0};
	printf("Enter the integer coefficients of square equation(a, b, c):\n");
	printf("Coef a:\n");
	coef.a = SecureInputInt();
	printf("Coef b:\n");
	coef.b = SecureInputInt();
	printf("Coef c:\n");
	coef.c = SecureInputInt();
	return coef;
}

/**
 *  
 * \param[in] digit digit - a double number to be compared with zero. 
 * 
 * \return True if the digit is close to zero, false else
 * 
 * \note accuracy: 1e-9
 */

bool EqualZero(double digit) {
	if (fabs(digit) < 1e-9) {
		return 1;
	} else {
		return 0;
	}
}

/**
 *  
 * \param[in] coef  coef - Struct, consists the coefficients: a, b and c.
 * \param[out] root  root - Pointer on struct, consists the 1st and 2nd roots.
 * 
 * \return The label indicating the number of roots.
 * 
 * \note In case of infinite number of roots, returns INFINITE.
 */

int LineareQuation(struct Coef_t coef, struct Roots_t *root) {

	assert(isfinite(coef.b));
	assert(isfinite(coef.c));
	assert(root != NULL);

	if (EqualZero(coef.b)) {
		if (EqualZero(coef.c)) {
					root->x1 = root->x2 = INFINITE;
			return INFINITE;
		} else {
			root->x1 = root->x2 = 0;
			return 0;
		}
	} else {
		root->x1 = -coef.c / coef.b;
		root->x2 = 0;
		return 1;
	}
}

/**
 *  
 * \param[in] coef  coef - Struct, consists the coefficients: b and c.
 * \param[out] root  root - Pointer on struct, consists the root.
 * 
 * \return The label indicating the number of roots.
 * 
 * \note Search for roots through the discriminant.
 */

int SquareQuation(struct Coef_t coef, struct Roots_t *root) {

	assert(isfinite(coef.a));
	assert(isfinite(coef.b));
	assert(isfinite(coef.c));
	assert(root != NULL);

	double d = coef.b * coef.b - 4 * coef.a * coef.c;
	if (d > 0) {
		root->x1 = (-coef.b + sqrt(d)) / (2 * coef.a);
		root->x2 = (-coef.b - sqrt(d)) / (2 * coef.a);
		return 2;
	} else if (EqualZero(d)) {
		root->x1 = -coef.b / (2 * coef.a);
		root->x2 = 0;
		return 3;
	} else {
		root->x1 = root->x2 = 0;
		return 4;
	}
}

/**
 *  Solves the square equation.
 * 
 * \param[in] coef  coef - Struct, consists the coefficients: a, b and c.
 * \param[out] root  root - Pointer on struct, consists the 1st and 2nd roots.
 * 
 * \return The label indicating the number of roots.
 * 
 * \note In case of infinite number of roots, returns INFINITE.
 */

int FindingTheRoots(struct Coef_t coef, struct Roots_t *root) {

	assert(isfinite(coef.a));
	assert(isfinite(coef.b));
	assert(isfinite(coef.c));
	assert(root != NULL);

	if (EqualZero(coef.a)) {
		return LineareQuation(coef, root);
	} else {
		return SquareQuation(coef, root);
	}
}

/**
 * \param[in] count_of_roots  count_of_roots - The label indicating the number of roots.
 * \param[in] coef  coef - Struct, consists the coefficients: a, b and c.
 * \param[in] root  root - Pointer on struct, consists the 1st and 2nd roots.
 * 
 * \return Information about the presence of errors.
 * 
 * \note Еhe last input line displays all the coefficients.
 */

int SearchResalts(int count_of_roots, struct Coef_t coef, struct Roots_t root) {
	switch (count_of_roots) {

		case 0: printf("a == 0, b == 0 and c != 0. Not roots:( ");
				assert(EqualZero(coef.a));
				assert(EqualZero(coef.b));
				assert(!EqualZero(coef.c));
				break;

		case 1: printf("It's a linear equation. ");
				assert(EqualZero(coef.a));
				assert(!EqualZero(coef.b));
				printf("The root x = %lf\n", root.x1);
				break;

		case 2: printf("Roots: x1 = %lf; x2 = %lf ", root.x1, root.x2);
				assert(!EqualZero(coef.a));
				break;

		case 3: printf("Discriminant equals zero. ");
				assert(!EqualZero(coef.a));
				printf("The root x = %lf", root.x1);
				break;

		case 4: printf("Discriminant is less then zero. Not roots:( ");
				assert(!EqualZero(coef.a));
				break;

		case INFINITE: printf("All coefficients equal zero:(\n");
					   printf("There are infinity roots");
					   assert(EqualZero(coef.a));
					   assert(EqualZero(coef.b));
					   assert(EqualZero(coef.c));
					   break;

		default: printf("Error in func main(): count_of_roots = %d ", count_of_roots);
				 return 1;
	}
	printf(" | coef: (%lf, %lf, %lf)\n", coef.a, coef.b, coef.c);
	return 0;
}

/**
 * \return Information about the presence of errors.
 * 
 * \note Prompts the user to set an equation and safely solves it.
 */

int CustomVersion() {

	struct Coef_t coef = InputCoefs();

	struct Roots_t root = {0, 0};

	return SearchResalts(FindingTheRoots(coef, &root), coef, root);
}