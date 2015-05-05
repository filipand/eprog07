#include <stdio.h>
#include "cpoly.c"

CPoly* addCpolynomials(CPoly* a, CPoly* b);
cdouble* cadd(cdouble* x, cdouble* y);

int main() {

	printf("Enter the size of Complex Polynomials: ");
	int n;
	scanf("%d",&n);


	int i;
	printf("Enter %d Complex numbers for the first CPoly: \n",n);
	CPoly* c1 = newCPoly(n);
	for(i=0;i<n;i++) {
		printf("[%d]: (a + bi): ",i+1);
		double a,b;
		scanf("%lf%lf",&a,&b);
		cdouble* x = newCDouble(a,b);
		setCPolyCoefficient(c1,i,x);
	}

	printf("Enter %d Complex numbers for the second CPoly: \n",n);
	CPoly* c2 = newCPoly(n);
	for(i=0;i<n;i++) {
		printf("[%d]: (a + bi): ",i+1);
		double a,b;
		scanf("%lf%lf",&a,&b);
		cdouble* x = newCDouble(a,b);
		setCPolyCoefficient(c2,i,x);
	}

	CPoly* result = addCpolynomials(c1,c2);

	printCPoly(result);

	(void)delCPoly(c1);
	(void)delCPoly(c2);
	return 0;
}

CPoly* addCpolynomials(CPoly* a, CPoly* b) {
	int degree = getCPolyDegree(a);
	CPoly* result = newCPoly(degree);

	int i;
	for(i=0;i < degree;i++) {
		setCPolyCoefficient(result, i, cadd(getCPolyCoefficient(a,i),getCPolyCoefficient(b,i)));
	}
	return result;
}

cdouble* cadd(cdouble* x, cdouble* y) {
	return newCDouble(getCDoubleReal(x) + getCDoubleReal(y), getCDoubleImag(x) + getCDoubleImag(y));
}
