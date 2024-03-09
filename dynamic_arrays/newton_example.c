#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "darray.h"

int **pascal_triangle(size_t n);
int **pascal_triangle_pa(size_t n);
DArray *pascal_triangle_darray(size_t n);
void polynomial(size_t n);
void polynomial_darray(size_t n);


int main(void) {
    int **res = pascal_triangle_pa(20);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%i ", res[i][j]);
        }
        printf("\n");
    }

    DArray *arr = pascal_triangle_darray(20);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%i ", get(&arr[i], j));
        }
        printf("\n");
    }

    for (size_t i = 0; i < 15; i++)
        polynomial(i);

    for (size_t i = 0; i < 15; i++)
        polynomial_darray(i);

    // Free memory
    for (int i = 0; i < 20; i++) {
        free(arr[i].darray);
        free(res[i]);
    }
    free(arr);
    free(res);

    return 0;
}

int **pascal_triangle(size_t n) {
    int **p = (int**)malloc(sizeof(int *) * n);
    if (!p) return NULL;

    for (size_t i = 0; i < n; ++i) {
        p[i] = (int*)malloc(sizeof(int) * (i + 1));
        if (!p[i]) return NULL;

        p[i][0] = 1;

        for (int j = 1; j < i; ++j) {
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
        }
        p[i][i] = 1;
    }

    return p;
}


/*
* Pointer arithmetic implementation
*/ 
int **pascal_triangle_pa(size_t n) {
    int **p = (int**)malloc(sizeof(int *) * n);
    if (!p) return NULL;

    for (size_t i = 0; i < n; ++i) {
        *(p + i) = (int*)malloc(sizeof(int) * (i + 1));
        if (!*(p + i)) return NULL;

        **(p + i) = 1;

        for (int j = 1; j < i; ++j) {
            *(*(p + i) + j) = *(*(p + i - 1) + j - 1) + *(*(p + i - 1) + j);
        }
        *(*(p + i) + i) = 1;
    }

    return p;
}

DArray *pascal_triangle_darray(size_t n) {
    DArray *arr = (DArray *)malloc(sizeof(DArray) * n);
    assert(arr && "Could not allocate space for array.");

    for (size_t i = 0; i < n; i++) {
        DArray darr = self_init(&darr);
        arr[i] = darr;
        push_back(&arr[i], 1);

        for (int j = 1; j < i; j++) 
            push_back(&arr[i], arr[i - 1].darray[j - 1] + arr[i - 1].darray[j]);

        push_back(&arr[i], 1);
    }

    return arr;
}


// O(1) access a[i] -> addr_array + size_of_elem*(i - first_index)

void polynomial(size_t n) {
    assert(n >= 0 && "Only polynomials of degree n >= 0 are allowed");
    
    int **triangle = pascal_triangle(n + 1);
    assert(triangle);

    printf("(x + y)^%lli = ", n);

    printf("x^%lli + ", n);
    for (size_t i = 1, j = n - 1; i < n; i++, j--) {
        printf("%i(x^%lli)(y^%lli) + ", triangle[n][i], j, i);
    }

    // printf("%i(x^0)(y^%lli)$$\n", triangle[n][n], n);
    printf("y^%lli\n", n);

    for (int i = 0; i < n; i++) 
        free(triangle[i]);
    free(triangle);

}

/*
* Polynomial using dynamic arrays
*/
void polynomial_darray(size_t n) {
    assert(n >= 0 && "Only polynomials of degree n >= 0 are allowed");

    DArray *triangle = pascal_triangle_darray(n + 1);

    printf("(x + y)^%lli = ", n);

    printf("x^%lli + ", n);
    for (size_t i = 1, j = n - 1; i < n; i++, j--) {
        printf("%i(x^%lli)(y^%lli) + ", triangle[n].darray[i], j, i);
    }

    // printf("%i(x^0)(y^%lli)$$\n", triangle[n][n], n);
    printf("y^%lli\n", n);

    for (int i = 0; i < n; i++) 
        free(triangle[i].darray);
    free(triangle);

}