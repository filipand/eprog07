#include <stdlib.h>
#include <assert.h>

typedef struct _polynomial_ {
    int grad;
    double* koef_vector;
} Polynomial;

Polynomial* newPoly(int n) {
    int i = 0;
    Polynomial* X = NULL;
    assert(n > 0);
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

