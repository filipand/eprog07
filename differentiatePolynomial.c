#include "polynomial.c"


int fac(int n) {
    if(n == 1 || n == 0) {
        return 1;
    }
    return n * fac(n-1);
}

Polynomial* differentiatePolynomial(Polynomial* p, int k) {
    int difPolyn_degree = (getPolyDegree(p)-k) < 0 ? 0 : (getPolyDegree(p)-k);

    Polynomial* diff = newPoly(difPolyn_degree);
    int i;
    for(i = getPolyDegree(p); i>= 0; i--) {
        if((i - k) >= 0) {
            int difPolyn_degree = i - k;
            double p_coef = getPolyCoefficient(p, i);
            double diff_p_coef = p_coef * ((double) (fac(i) / fac(i-k)));
            setPolyCoefficient(diff, difPolyn_degree, diff_p_coef);
        }
    }

    return diff;
}

void test_differentiatePolynomial() {
    Polynomial* p = newPoly(4);
    setPolyCoefficient(p, 4, 6);
    setPolyCoefficient(p, 2, 5);
    setPolyCoefficient(p, 1, 4);
    setPolyCoefficient(p, 0, 5);

    Polynomial* diff = differentiatePolynomial(p, 3);
    assert(getPolyDegree(diff) == 1);
    assert(getPolyCoefficient(diff, 1) == 144);
    assert(getPolyCoefficient(diff, 0) == 0);

    delPoly(diff);
    delPoly(p);
}

int main() {

    test_differentiatePolynomial();

    Polynomial* p = inputPolynomial();

    int k = 0;
    printf("k-te Ableitung = ");
    scanf("%d", &k);
    Polynomial* diff = differentiatePolynomial(p, k);

    printPolynom(diff);

    delPoly(diff);
    delPoly(p);
}
