#include <stdio.h>
#include "polynomial.c"

double evalPolynomial(Polynomial* p, int x);

void test_evalPolynomial() {

    Polynomial* p = newPoly(4);
    setPolyCoefficient(p, 4, 6);
    setPolyCoefficient(p, 2, 5);
    setPolyCoefficient(p, 1, 4);
    setPolyCoefficient(p, 0, 5);

    assert(evalPolynomial(p, 2) == 129);

}

int main() {

    test_evalPolynomial();

	Polynomial* p = inputPolynomial();

	int x = 0;
	printf("Auswertungspunkt x = ");
	scanf("%d",&x);

	double result = evalPolynomial(p,x);
	printf("p(x) = %f\n",result);

	delPoly(p);

	return 0;
}

double evalPolynomial(Polynomial* p, int x) {
	double result = 0;
    double x_i = 1;

	int i;
	for(i=0; i<= getPolyDegree(p); i++) {
		result += getPolyCoefficient(p, i) * x_i;
		x_i = x_i * x;
	}

	return result;
}
