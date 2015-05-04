#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct _polynomial_ {
    int grad;
    double* koef_vector;
} Polynomial;

Polynomial* newPoly(int n) { // n ist Grad des Polynoms
    int i = 0;
    Polynomial* X = NULL;
    assert(n >= 0);
    X = malloc(sizeof(Polynomial));
    assert(X != NULL);
    X->grad = n;
    X->koef_vector = malloc((n+1)*sizeof(double));
    assert(X->koef_vector != NULL);
    for (i=0; i<n+1; ++i) {
        X->koef_vector[i] = 0;
    }
    return X;
}

Polynomial* delPoly(Polynomial* X){
    assert(X != NULL);
    free(X->koef_vector);
    free(X);

    return NULL;
}

int getPolyDegree(Polynomial* X) {
    assert(X != NULL);
    return X->grad;
}

double getPolyCoefficient(Polynomial* X, int i) {
    assert(X != NULL);
    assert((i>=0) && (i <= X->grad));
    return X->koef_vector[i];
}

void setPolyCoefficient(Polynomial* X, int i, double polI) {
    assert(X != NULL);
    assert((i>=0) && (i <= X->grad));
    X->koef_vector[i] = polI;
}

Polynomial* inputPolynomial() {

    Polynomial* X = NULL;
    int i = 0;
    int n = 0;
    double input = 0;

    printf("Dimension des Polynoms n=");
    scanf("%d",&n);
    assert(n > 0);

    X = newPoly(n);

    for (i=0; i < n+1; ++i) {
        input = 0;
        printf("x^%d * ",i);
        scanf("%lf",&input);
        setPolyCoefficient(X,i,input);
    }

    return X;
}

void printPolynom(Polynomial* X) {
    int i;
    for (i=getPolyDegree(X); i >= 0; --i) {
        printf("%f * x^%d + ",getPolyCoefficient(X, i), i);
    }
}


