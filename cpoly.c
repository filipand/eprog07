#include <stdlib.h>
#include <assert.h>
#include "cdouble.c"

typedef struct _cpoly_ {
    int degree;
    cdouble** c;
} CPoly;

CPoly* newCPoly(int n) {
    
    CPoly* p = malloc(sizeof(CPoly));
    assert(p != NULL);
    
    assert(n > 0);
    p->degree = n;
    p->c = malloc((n+1)*sizeof(cdouble*));
    assert(p->c != NULL);
    
    int i;
    for (i=0; i<n+1; ++i) {
        p->c[i] = malloc(sizeof(cdouble));
    }
    return p;
}

CPoly* delCPoly(CPoly* p){
    assert(p != NULL);

    int i;
    for (i=0; i<p->degree + 1; ++i) {
        assert(p->c[i] != NULL);
        free(p->c[i]);
    }
    free(p);
    return NULL;
}

int getCPolyDegree(CPoly* p) {
    assert(p != NULL);
    return p->degree;
}

cdouble* getCPolyCoefficient(CPoly* p, int i) {
    assert(p != NULL);
    assert((i>=0) && (i <= p->degree));
    return p->c[i];
}

void setCPolyCoefficient(CPoly* p, int i, cdouble* c) {
    assert(p != NULL);
    assert((i>=0) && (i <= p->degree));
    p->c[i]->a = c->a;
    p->c[i]->b = c->b;
}

void printCPoly(CPoly *p) {
    int i;
    for(i = 0; i < p->degree;i++) {
        printCD(p->c[i]);
    }
}