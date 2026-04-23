// DP question
// approach - 1 - using recursion only
// time complexity - n ^ d
// space complexity - O(1)

// class Solution {
// public:
//     int solve(vector<int> &jd, int d, int n, int idx) {
//         if(d == 1) {
//             int maxD = jd[idx];

//             for(int i = idx; i < n; i++) {
//                 maxD = max(maxD, jd[i]);
//             }

//             return maxD;
//         }

//         int minD = INT_MAX;
//         int maxD = jd[idx];
//         for(int i = idx; i <= n - d; i++) {
//             maxD = max(maxD, jd[i]);

//             int result = maxD + solve(jd, d - 1, n, i + 1);

//             minD = min(minD, result);
//         }

//         return minD;
//     } 
//     int minDifficulty(vector<int>& jd, int d) {
//        int n =  jd.size();

//        if(n < d) {
//             return -1;
//        }

//        return solve(jd, d, n, 0);
//     }
// };



// approach - 2 - using recursion + memoization
// time complexity - O((n ^ 2) * d)
// space complexity - O(n * d)

class Solution {
public:
    int solve(vector<int> &jd, vector<vector<int>> &memo, int d, int n, int idx) {
        if(d == 1) {
            int maxD = jd[idx];

            for(int i = idx; i < n; i++) {
                maxD = max(maxD, jd[i]);
            }

            return maxD;
        }

        if(memo[n - d][idx] != -1) {
            return memo[n - d][idx];
        } 

        int minD = INT_MAX;
        int maxD = jd[idx];
        for(int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jd[i]);

            int result = maxD + solve(jd, memo, d - 1, n, i + 1);

            minD = min(minD, result);
        }

        return memo[n - d][idx] = minD;
    } 
    int minDifficulty(vector<int>& jd, int d) {
       int n =  jd.size();

       if(n < d) {
            return -1;
       }

       vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

       return solve(jd, memo, d, n, 0);
    }
};
