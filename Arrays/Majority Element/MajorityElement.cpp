class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj= nums[0];
        int count =0;
        
        for(int i =0; i<n; i++)
        {
            if(maj == nums[i])
                count++;
            else
            {
                count--;
                if(count == -1)
                {
                    maj = nums[i];
                    count =1;
                }
            }
            
        }
        return maj;
    }
};