class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=-1;
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else
              s=mid+1;
        }
        if(ans==-1){
            return s;
        }
        return ans;

    }
};