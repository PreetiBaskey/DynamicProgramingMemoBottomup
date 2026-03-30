//approach - 1 - using recursion
//time complexity - O(2^n) 
//space complexity - O(1)
// class Solution {
// public:
//     int fib(int n) {
//         if(n == 0) {
//             return 0;
//         }
//         if(n == 1) {
//             return 1;
//         }

//         return fib(n - 1) + fib(n - 2);
//     }
// };





//approach - 2 - using dp
//time complexity - O(n)
//space complexity - O(n)
class Solution {
public:
    int solveWithDP(vector<int> &dp, int n) {
        if(n <= 1) {
            return n;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = solveWithDP(dp, n - 1) + solveWithDP(dp, n - 2);
    }
    int fib(int n) {
        if(n <= 1){
            return n;
        }

        vector<int> dp(n + 1, -1);

        return solveWithDP(dp, n);
    }
};





//approach - 3 - using bottom up
//time complexity - O(n)
//space complexity - O(n)

//State definition
//dp[i] = ith fibonacci number
//return dp[5]


// class Solution {
// public:
//     int fib(int n) {
//         if(n <= 1) {
//             return n;
//         }

//         vector<int> dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 1;

//         for(int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }

//         return dp[n];
//     }
// };





//approach - 4 - with constant space complexity
//time complexity - O(n)
//space complexity - O(1)
class Solution {
public:
    int fib(int n) {
        if(n <= 1) {
            return n;
        }

        int prevPrev = 0;
        int prev = 1;
        int curr;

        for(int i = 0; i < n - 1; i++) {
            curr = prevPrev + prev;

            prevPrev = prev;
            prev = curr;
        }

        return curr;
    }
};
