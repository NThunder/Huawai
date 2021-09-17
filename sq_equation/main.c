#include "rootsseacher.h"

/**
 * \note Checks the result of the function FindingTheRoots() with the reference values in the units array;
 */

void UnitTests() {

	struct Roots_t root = {0, 0};
	struct Unit_t units[10] = { {{0, 0, 2}, {0, 0}},
								{{0, 25, 5}, {-0.200000, 0}},
								{{1, 5, 4}, {-1.00000, -4.00000}},
								{{2, 8, 8}, {-2, 0}},
								{{7, 4, 9}, {0, 0}},
								{{0, 0, 0}, {INFINITE, INFINITE}} };
	for (int i = 0; i < 6; ++i) {
		FindingTheRoots(units[i].coef, &root);

		if (units[i].root.x1 == root.x1 && units[i].root.x2 == root.x2) {
			printf("%d) Succsess\n", i);
		} else {
			printf("%d) Fail\n", i);
		}
	}
}

int main() {

	UnitTests();

	CustomVersion();
	
	return 0;
}