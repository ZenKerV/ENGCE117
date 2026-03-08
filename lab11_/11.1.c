#include <stdio.h>


int BinSearch( int data[], int n, int find ) ;

int main() {
    int data[6] = { 1, 2, 3, 4, 5, 7 } ;
    int n = 6 ; 
    int find = 5;
    
    int pos = BinSearch( data, n, find ) ;
    
    if (pos != -1) {
        printf( "Found %d at %d\n", find, pos ) ;
    } else {
        printf( "%d not found\n", find ) ;
    }
    
    return 0 ;
}


int BinSearch( int data[] , int n , int find ) {
    int low = 0 ;
    int high = n - 1 ;
    
    while (low <= high) {
        int mid = low + (high - low) / 2 ; 
        
 
        if (data[mid] == find) {
            return mid ;
        }
        
       
        if (data[mid] < find) {
            low = mid + 1 ;
        } 
    
        else {
            high = mid - 1 ;
        }
    }
    
    return -1 ;
}
