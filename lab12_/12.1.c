#include <iostream>
#include <climits>

int *Dijkstra( int *L , int n) {
    int *dist = new int[n] ;      
    bool *visited = new bool[n] ;
    int INF = INT_MAX ;


    for ( int i = 0; i < n; i++ ) {
        dist[i] = INF ;
        visited[i] = false ;
    }


    dist[0] = 0 ;

    for (int count = 0; count < n - 1 ; count++) {

        int min = INF, u = -1 ;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v] ;
                u = v ;
            }
        }

        if (u == -1) break ; 
        visited[u] = true ;

 
        for ( int v = 0; v < n; v++ ) {
            int weight = L[u * n + v] ;
         
            if (!visited[v] && weight != -1 && dist[u] != INF 
                && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    delete[] visited ; 
    return dist ;
}

int main() {
    int n = 5, i = 0, j = 0, *d, *g ;
    g = new int[n * n] ;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1 ;

    g[0 * n + 1] = 100 ; g[0 * n + 2] = 80 ;
    g[0 * n + 3] = 30 ;  g[0 * n + 4] = 10 ;
    g[1 * n + 2] = 20 ;  g[3 * n + 1] = 20 ;
    g[3 * n + 2] = 20 ;  g[4 * n + 3] = 10 ;

    d = Dijkstra( g , n ) ;


    printf( "Shortest distances from node 0:\n " ) ;
    for ( i = 1 ; i < n ; i++ ) 
        printf( "To node %d: %d\n", i, d[i] ) ;

    delete[] g ;
    delete[] d ;
    return 0 ;
} 
