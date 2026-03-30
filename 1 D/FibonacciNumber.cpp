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
//time complexity - 
//space complexity - 

//State definition
//dp[i] = ith fibonacci number
//return dp[5]
