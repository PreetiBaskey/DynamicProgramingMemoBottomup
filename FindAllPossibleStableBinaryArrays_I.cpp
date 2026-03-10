//approach - 1 - top down approach
//time complexity - 
//space complexity - 
// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit, vector<vector<vector<int>>> &memo) {
//         if(onesLeft == 0 && zerosLeft == 0) {
//             return 1;
//         }

//         if(memo[onesLeft][zerosLeft][lastWasOne] != -1) {
//             return memo[onesLeft][zerosLeft][lastWasOne];
//         }

//         int result = 0;
//         if(lastWasOne == true) { //explore 0s
//             for(int length = 1; length <= min(limit, zerosLeft); length++) {
//                 result = (result + solve(onesLeft, zerosLeft - length, false, limit, memo)) %     MOD;
//             }
//         }
//         else { // explore 1s
//             for(int length = 1; length <= min(limit, onesLeft); length++) {
//                 result = (result + solve(onesLeft - length, zerosLeft, true, limit, memo)) % MOD;
//             }
//         }

//         return memo[onesLeft][zerosLeft][lastWasOne] = result;
//     }
//     int numberOfStableArrays(int zero, int one, int limit) {
//         vector<vector<vector<int>>> memo(one + 1, vector<vector<int>>(zero + 1, vector<int>(2, -1)));

//         int startWithOne = solve(one, zero, false, limit, memo);
//         int startWithZero = solve(one, zero, true, limit, memo);

//         return (startWithOne + startWithZero) % MOD;
//     }
// };





//approach - 2
//time complexity - O(zero * one * limit)
//space complexity - O(zero * one)
class Solution {
public:
    int MOD = 1e9 + 7;
    
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> memo(one + 1, vector<vector<int>>(zero + 1, vector<int>(2, -1)));

        memo[0][0][0] = 1;
        memo[0][0][1] = 1;

        for(int onesLeft = 0; onesLeft <= one; onesLeft++) {
            for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {
                if(onesLeft == 0 && zerosLeft == 0) {
                    continue;
                }

                int result = 0;
                for(int length = 1; length <= min(zerosLeft, limit); length++) {
                    result = (result + memo[onesLeft][zerosLeft - length][0]) % MOD;
                }
                memo[onesLeft][zerosLeft][1] = result;

                result = 0;
                for(int length = 1; length <= min(onesLeft, limit); length++) {
                    result = (result + memo[onesLeft - length][zerosLeft][1]) % MOD;
                }
                memo[onesLeft][zerosLeft][0] = result;
            }
        }

        int startWithOne = memo[one][zero][false];
        int startWithZero = memo[one][zero][true ];

        return (startWithOne + startWithZero) % MOD;
    }
};
