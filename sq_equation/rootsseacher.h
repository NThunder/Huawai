#ifndef ROOTSSEASHER_H
#define ROOTSSEASHER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

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

struct Unit_t {
	struct Coef_t coef;
	struct Roots_t root;
};

double SecureInputInt();

struct Coef_t InputCoefs();

bool EqualZero(double);

int LineareQuation(struct Coef_t, struct Roots_t*);

int SquareQuation(struct Coef_t, struct Roots_t*);

int FindingTheRoots(struct Coef_t, struct Roots_t*);

int SearchResalts(int, struct Coef_t, struct Roots_t);

int CustomVersion();

void UnitTests();

#endif