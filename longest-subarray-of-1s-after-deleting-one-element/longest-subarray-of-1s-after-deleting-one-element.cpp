class Solution {
public:
     
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,maxsum=0;
        int zeros=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                zeros++;
            };
            sum+=nums[j];
            while(zeros>1){
                if(nums[i]==0)
                zeros--;

                sum-=nums[i];
                i++;
            }
            maxsum=max(maxsum,sum);
        }
        if(zeros==0){
            return maxsum-1;
        }
        return maxsum;

    }
};