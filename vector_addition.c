//write C/C++ code for vector addition (prior to adding cuda)

#include <cuda_runtime.h>

#include <stdio.h>
#include <stdlib.h>

void vector_add(float *a, float *b, float *c, int n) {
	for (int i = 0; i < n; i++) {
		c[i] =a[i] + b[i];
	}
}


//the main function - necessary for all C programs
int main() {
    int n = 1000;  // Size of vectors
    float *a, *b, *c;

    // Allocate memory
    a = (float*)malloc(n * sizeof(float));
    b = (float*)malloc(n * sizeof(float));
    c = (float*)malloc(n * sizeof(float));

    // Initialize vectors (choose an arbitrary value for each of the two vectors being added)
    for (int i = 0; i < n; i++) {
        a[i] = i;
        b[i] = i * 2;
    }    
    
    // Perform vector addition
    vector_add(a, b, c, n);
    
    // Print first few results
    for (int i = 0; i < 10; i++) {
        printf("%f + %f = %f\n", a[i], b[i], c[i]);
    }
    
    // Free memory
    free(a);
    free(b);
    free(c);

    return 0;
}