class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closest=INT_MAX;
       
        sort(nums.begin(),nums.end());
         int ans;
         
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
              int sum=nums[i]+nums[j]+nums[k];
              if(abs(sum-target)<closest){
                  ans=sum;
                  closest=abs(sum-target);

              }
             if (sum < target) {
                j++;
            } else {
                k--;
            }
            }
        }
        return ans;
    }
};