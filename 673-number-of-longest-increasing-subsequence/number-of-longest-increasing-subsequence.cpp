class Solution {
public:
// int findNumberOfLIS(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& memo) {
//     if (currIndex == -1)
//         return 1;

//     if (memo[currIndex][prevIndex + 1] != -1)
//         return memo[currIndex][prevIndex + 1];

//     int count = 0;
//     if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
//         count += findNumberOfLIS(nums, currIndex - 1, currIndex, memo);
//         count += findNumberOfLIS(nums, currIndex - 1, prevIndex, memo);
//     }
//     else {
//         count += findNumberOfLIS(nums, currIndex - 1, prevIndex, memo);
//     }

//     memo[currIndex][prevIndex + 1] = count;

//     return count;
// }

int findNumberOfLIS(vector<int>& nums) {
    // int n = nums.size();
    // vector<vector<int>> memo(n, vector<int>(n + 1, -1));

    // return findNumberOfLIS(nums, n - 1, -1, memo);
    int n = nums.size();
    vector<int> lengths(n, 1);  // lengths[i] represents the length of the LIS ending at index i
    vector<int> counts(n, 1);   // counts[i] represents the count of the LIS ending at index i
    int maxLen = 1;
    int result = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                }
                else if (lengths[j] + 1 == lengths[i]) {
                    counts[i]+= counts[j];
                }
            }
        }
        maxLen = max(maxLen, lengths[i]);
    }

    for (int i = 0; i < n; i++) {
        if (lengths[i] == maxLen) {
            result += counts[i];
        }
    }

    return result;
}
  
};