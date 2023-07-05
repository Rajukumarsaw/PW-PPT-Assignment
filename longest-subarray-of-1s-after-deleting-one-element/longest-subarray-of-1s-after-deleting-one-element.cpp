class Solution {
public:
     unordered_map<int, int> mp;
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,maxsum=0;
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            while(mp[0]>1){
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            maxsum=max(maxsum,sum);
            j++;
        }
        if(mp[0]==0){
            return maxsum-1;
        }
        return maxsum;

    }
};