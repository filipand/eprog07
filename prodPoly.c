#include "polynomial.c"

Polynomial* prodPoly(Polynomial* p, Polynomial* q) {
    int p_degree = getPolyDegree(p);
    int q_degree = getPolyDegree(q);
    Polynomial* r = newPoly(p_degree + q_degree);

    int p_i, q_i;
    for(p_i = p_degree; p_i>=0; p_i--) {
        for(q_i = q_degree; q_i>=0; q_i--) {
            int r_coef_index = p_i + q_i;
            double r_coef_old = getPolyCoefficient(r, r_coef_index);
            double r_coef_add = getPolyCoefficient(p, p_i) * getPolyCoefficient(q, q_i);
            double r_coef_new = r_coef_old + r_coef_add;
            setPolyCoefficient(r, r_coef_index, r_coef_new);
        }
    }

    return r;
}

void test_prodPoly() {
    Polynomial* p = newPoly(2);
    setPolyCoefficient(p, 2, 4);
    setPolyCoefficient(p, 1, -4);
    setPolyCoefficient(p, 0, -7);

    Polynomial* q = newPoly(1);
    setPolyCoefficient(q, 1, 1);
    setPolyCoefficient(q, 0, 3);

    Polynomial* r = prodPoly(p, q);

    assert(getPolyDegree(r) == getPolyDegree(p) + getPolyDegree(q));
    assert(getPolyCoefficient(r, 3) == 4);
    assert(getPolyCoefficient(r, 2) == 8);
    assert(getPolyCoefficient(r, 1) == -19);
    assert(getPolyCoefficient(r, 0) == -21);
}

int main() {

    test_prodPoly();

    Polynomial* p = inputPolynomial();
    Polynomial* q = inputPolynomial();
    Polynomial* r = prodPoly(p, q);

    printPolynom(r);

    delPoly(p);
    delPoly(q);
    delPoly(r);

    return 0;
}
