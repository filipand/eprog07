#ifndef _CDOUBLE_
#define _CDOUBLE_

typedef struct _CDOUBLE_ {
	double a;
	double b;
} cdouble;

cdouble* newCDouble(double a, double b);
cdouble* delCDouble(cdouble* c);
void setCDoubleReal(cdouble* c, double a);
double getCDoubleReal(cdouble *c);
void setCDoubleImag(cdouble* c, double b);
double getCDoubleImag(cdouble* c);

void printCD(cdouble* c);
void printEQ(cdouble* c, cdouble* z, char a, cdouble* r);

#endif