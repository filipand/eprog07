#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cdouble.h"

cdouble* newCDouble(double a, double b) {
	cdouble* c = malloc(sizeof(cdouble));
	assert(c != NULL);
	c->a = a;
	c->b = b;
	return c;
}

cdouble* delCDouble(cdouble* c) {
	free(c);
	c = NULL;
	assert(c == NULL);
	return c;
}

void setCDoubleReal(cdouble* c, double a) {
	assert(c != NULL);
	c->a=a;
}

double getCDoubleReal(cdouble *c) {
	assert(c != NULL);
	return c->a;
}

void setCDoubleImag(cdouble* c, double b) {
	assert(c != NULL);
	c->b=b;
}

double getCDoubleImag(cdouble* c) {
	assert(c != NULL);
	return c->b;
}

void printCD(cdouble* c) {
	printf("%f + %fi\n", c->a, c->b);
}

void printEQ(cdouble* c, cdouble* z, char a, cdouble* r) {
	printf("(%f + %fi)", c->a, c->b);
	printf(" %c ",a);
	printf("(%f + %fi)", z->a, z->b);
	printf(" = ");
	printf("(%f + %fi)\n", r->a, r->b);
}
