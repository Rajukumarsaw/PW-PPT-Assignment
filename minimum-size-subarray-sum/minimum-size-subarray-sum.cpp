class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=1e9;

        int i=0,j=0;

        int sum=0;

        while(j<nums.size())
        {
            // increase the value of nums.
            sum +=nums[j];

            // if sum is less than target
            if(sum<target) j++;
            else
            {
                // once we get into sum greater or equal to target
                while(sum>=target)
                {

                    // compute the value of length.
                    len = min(len,j-i+1);

                    // decrease the count and slide the window.
                    sum-=nums[i++];
                }
                j++;
            }
        }

        return (len==1e9)? 0:len;
    }
};