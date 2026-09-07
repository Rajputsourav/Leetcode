class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int MAX = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1){
                count +=1;
            }
            else{
                MAX = max(count,MAX);
                count = 0;
            }
        }
        return max(count, MAX);
        
    }
};