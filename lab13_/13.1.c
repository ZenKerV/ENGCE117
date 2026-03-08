int *KnapsackGreedy( int *w , int *v , int n , int wx ) {
    int *x = new int[n] ;
    float ratio[n] ;
    int idx[n] ;

    for ( int i = 0 ; i < n ; i++ ) {
        x[i] = 0 ;
        ratio[i] = (float)v[i] / w[i] ;
        idx[i] = i ;
    }


    for ( int i = 0; i < n - 1; i++) {
        for ( int j = 0; j < n - i - 1; j++ ) {
            if (ratio[idx[j]] < ratio[idx[j+1]] ) {
                int temp = idx[j] ;
                idx[j] = idx[j+1] ;
                idx[j+1] = temp ;
            }
        }
    }

    int currentW = 0 ;
    for (int i = 0 ; i < n; i++) {
        if ( currentW + w[idx[i]] <= wx ) {
            x[idx[i]] = 1 ;
            currentW += w[idx[i]] ;
        }
    }
    return x ;
}
2. Knapsack Problem - Dynamic ProgrammingThe Dynamic Programming (DP) approach explores all combinations to find the absolute maximum value , even if the "best" individual items aren't picked first.Selection Logic: By picking Item 3 (wt: 5) and Item 4 (wt: 6), the total weight is exactly $11$ and the total value is $40$ ($18+22$). This outperforms the greedy total value of $35$ ($28+6+1$).Result: 0 0 1 1 0.C++int *KnapsackDP(int *w, int *v, int n, int wx) {
    int dp[n + 1][wx + 1] ;
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (w[i - 1] <= j)
                dp[i][j] = (v[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j]) ? 
                            v[i - 1] + dp[i - 1][j - w[i - 1]] : dp[i - 1][j] ;
            else dp[i][j] = dp[i - 1][j] ;
        }
    }

    int *x = new int[n] ;
    int res = dp[n][wx] ;
    int j = wx ;
    for (int i = n; i > 0; i--) {
        if (res != dp[i - 1][j]) {
            x[i - 1] = 1 ;
            res -= v[i - 1] ;
            j -= w[i - 1] ;
        } else x[i - 1] = 0 ;
    }
    return x ;
}
