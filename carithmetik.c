#include <stdio.h>
#include <math.h>
#include "cdouble.c"

cdouble* cadd(cdouble* x, cdouble* y);
cdouble* csub(cdouble* x, cdouble* y);
cdouble* cmul(cdouble* x, cdouble* y);
cdouble* cdiv(cdouble* x, cdouble* y);

double cnorm(cdouble* c);

int main() {

	double a,b;

	printf("[1] Enter complex number values: ");
	scanf("%lf%lf",&a,&b);
	cdouble* x = newCDouble(a,b);


	printf("[2] Enter complex number values: ");
	scanf("%lf%lf",&a,&b);
	cdouble* y = newCDouble(a,b);

	printEQ(x,y,'+',cadd(x,y));
	printEQ(x,y,'-',csub(x,y));
	printEQ(x,y,'*',cmul(x,y));
	printEQ(x,y,'/',cdiv(x,y));


	printf("Norm: ");
	printCD(x);
	printf(" = %f\n",cnorm(x));

	(void)delCDouble(x);
	(void)delCDouble(y);

	return 0;
}

cdouble* cadd(cdouble* x, cdouble* y) {
	return newCDouble(getCDoubleReal(x) + getCDoubleReal(y), getCDoubleImag(x) + getCDoubleImag(y));
}

cdouble* csub(cdouble* x, cdouble* y) {
	return newCDouble(getCDoubleReal(x) - getCDoubleReal(y), getCDoubleImag(x) - getCDoubleImag(y));
}

// (ac - bd) + (ad + bc)i
cdouble* cmul(cdouble* x, cdouble* y) {
	double real = getCDoubleReal(x) * getCDoubleReal(y) - getCDoubleImag(x) * getCDoubleImag(y);
	double imag = getCDoubleReal(x) * getCDoubleImag(y) + getCDoubleImag(x) * getCDoubleReal(y);

	return newCDouble(real, imag);
}

// (a+ib) / (c+id) = ((ac+bd)/((c^2)+(d^2)))+i((bc-ad)/((c^2)+(d^2)))
cdouble* cdiv(cdouble* x, cdouble* y) {
	if ( getCDoubleReal(y) == 0 && getCDoubleImag(y) == 0 )
        printf("Division by 0 + 0i is not allowed.");

	double real = ((getCDoubleReal(x) * getCDoubleReal(y) + getCDoubleImag(x) * getCDoubleImag(y)) / ((getCDoubleReal(y) * getCDoubleReal(y)) + (getCDoubleImag(y) * getCDoubleImag(y))));
	double imag = ((getCDoubleImag(x) * getCDoubleReal(y) - getCDoubleReal(x) * getCDoubleImag(y)) / ((getCDoubleReal(y) * getCDoubleReal(y)) + (getCDoubleImag(y) * getCDoubleImag(y))));

   return newCDouble(real, imag);
}

//(a + bi)(a - bi) = a^2 + b^2
double cnorm(cdouble* c) {
	return sqrt(getCDoubleReal(c) * getCDoubleReal(c) + getCDoubleImag(c) * getCDoubleImag(c));
}
