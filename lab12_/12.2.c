#include <stdio.h>

int *KnapsackGreedy( int *w , int *v , int n , int wx ) {
    int *x = new int[n] ;
    float *ratio = new float[n] ;
    int *indices = new int[n] ;

 
    for (int i = 0 ; i < n; i++) {
        x[i] = 0 ;
        ratio[i] = (float)v[i] / w[i] ;
        indices[i] = i ;
    }

  
    for ( int i = 0 ; i < n - 1; i++ ) {
        for ( int j = 0 ; j < n - i - 1 ; j++ ) {
            if (ratio[indices[j]] < ratio[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1] ;
                indices[j + 1] = temp ;
            }
        }
    }


    int currentWeight = 0 ;
    for (int i = 0; i < n ; i++) {
        int idx = indices[i] ;
        if (currentWeight + w[idx] <= wx) {
            x[idx] = 1 ;
            currentWeight += w[idx] ;
        }
    }

    delete[] ratio ;
    delete[] indices ;
    return x ;
}
