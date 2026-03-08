#include <stdio.h>

int KnapsackBT( int *w, int *v , int n , int wx , int i , int *x ) {
    if ( i == n ) {
        return 0 ;
    }

    int not_take = KnapsackBT( w , v , n , wx , i + 1 , x ) ;

    int take = -1 ;
    int temp_x[n] ;
    for (int j = 0 ; j < n ; j++ ) temp_x[j] = x[j] ;

    if (wx >= w[i]) {
        take = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, temp_x) ;
    }

    if (take > not_take) {
        x[i] = 1;
        for (int j = i + 1; j < n; j++) x[j] = temp_x[j] ;
        return take;
    } else {
        x[i] = 0 ;
        return not_take ;
    }
}

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 } ;
    int v[5] = { 1, 6, 18, 22, 28 } ;
    int *x , vx ;
    
    x = new int[n] ;
    
    vx = KnapsackBT( w , v , n , wx , 0 , x) ;
    
    printf( "Value = %d\n" , vx) ;
    for ( int i = 0 ; i < n ; i++ ) printf( "%d ", x[i]) ;
    
    delete[] x ;
    return 0 ;
}
