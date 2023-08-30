#include <stdio.h>
#include <stdlib.h>

void dgemm( int length, double *X, double *Y, double *C ) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            double cij = 0;
            for(int k = 0; k < length; k++){
                cij += X[i+k*length] * Y[k+j*length];
            }
            C[i+j*length] = cij;
        }
    }
}

int main( void ) {
  const int N = 1024; // The benchmark runs on a fixed size of work
  printf( "Running DGEMM operation of size %d x 1\n", N );

  double *X = (double *) malloc( (N * N) * sizeof(double) );      // First vector
  double *Y = (double *) malloc( (N * N) * sizeof(double) );      // Second vector
  double *Result = (double *) malloc( (N * N) * sizeof(double) );

   dgemm( N, X, Y, Result );

   free( X );
   free( Y );
   free(Result);

   return 0;
}