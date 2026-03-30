//approach - 1 - using recursion - time limit exceeded
//time complexity - O(2 ^ n)
//space complexity - O(n) - recursion stack
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n < 0) {
//             return 0;
//         }
//         if(n == 0) {
//             return 1;
//         }

//         int oneStep = climbStairs(n - 1);
//         int twoStep = climbStairs(n - 2);

//         return oneStep + twoStep;
//     }
// };




//approach - 2 - using memoization
//time complexity - O(n)
//space complexity - O(n)
// class Solution {
// public:
//     int solveWithDP(vector<int> &dp, int n) {
//         if(n < 0) {
//             return 0;
//         }
//         if(n == 0) {
//             return 1;
//         }

//         if(dp[n] != -1) {
//             return dp[n];
//         }

//         return dp[n] = solveWithDP(dp, n - 1) + solveWithDP(dp, n - 2);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n + 1, -1);

//         return solveWithDP(dp, n);
//     }
// };




//approach - 3 - using bottom up
//time complexity - O(n)
//space complexity - O(n)

//state definition
//dp[i] = no. of ways to climb i stairs

// class Solution {
// public:
//     int climbStairs(int n) {
//     if(n == 1 || n == 2 || n == 3) {
//             return n;
//         }

//        vector<int> dp(n + 1);

//        dp[0] = 0;
//        dp[1] = 1;
//        dp[2] = 2;

//        for(int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//        }
 
//        return dp[n];
//     }
// };





//approach - 4 - using constant space
//time complexity - O(n)
//space complexity - O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3) {
            return n;
        }

        int prevPrev = 1;
        int prev = 2;
        int curr;

        for(int i = 3; i <= n; i++) {
            curr = prevPrev + prev;

            prevPrev = prev;
            prev = curr;
        }

        return curr;
    }
};
