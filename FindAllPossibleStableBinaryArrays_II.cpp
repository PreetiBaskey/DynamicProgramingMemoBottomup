//approach - 1 - dynamic programming
//time complexity - O(zero * one)
//space complexity - O(zero * one)
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        // memo[i][j][k]: number of stable arrays with i zeros and j ones ending in k (0 or 1)
        vector<vector<vector<int>>> memo(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

        // Base Case: Arrays containing only 0s (must be <= limit)
        for(int i = 0; i <= min(zero, limit); i++) {
            memo[i][0][0] = 1;
        }

        // Base Case: Arrays containing only 1s (must be <= limit)
        for(int j = 0; j <= min(one, limit); j++) {
            memo[0][j][1] = 1;
        }

        for(int i = 1; i <= zero; i++) {
            for(int j = 1; j <= one; j++) {
                
                // Transition for ending with 1:
                // We can append a '1' to any stable array ending in 0 or 1
                memo[i][j][1] = (memo[i][j - 1][0] + memo[i][j - 1][1]) % MOD;
                // If we have more than 'limit' ones, we must subtract sequences that 
                // would now have (limit + 1) consecutive ones.
                // This happens if the sequence at (j - 1 - limit) ended with a 0 
                // and was followed by exactly 'limit + 1' ones.
                if(j > limit) {
                    memo[i][j][1] = (memo[i][j][1] - memo[i][j - 1 - limit][0] + MOD) % MOD;
                }

                // Transition for ending with 0:
                // We can append a '0' to any stable array ending in 0 or 1
                memo[i][j][0] = (memo[i - 1][j][0] + memo[i - 1][j][1]) % MOD;
                // Subtract sequences that now have (limit + 1) consecutive zeros.
                // This happens if the sequence at (i - 1 - limit) ended with a 1 
                // and was followed by exactly 'limit + 1' zeros.
                if(i > limit) {
                    memo[i][j][0] = (memo[i][j][0] - memo[i - 1 - limit][j][1] + MOD) % MOD;
                }
            }
        }

        return (memo[zero][one][0] + memo[zero][one][1]) % MOD;
    }
};
