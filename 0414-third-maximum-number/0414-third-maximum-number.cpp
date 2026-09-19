class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long max = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;
        for(int i = 0;i<n;i++){
            if(nums[i] == max || nums[i] == secondMax || nums[i] == thirdMax)
                continue;
            if(nums[i] > max){
                thirdMax = secondMax;
                secondMax = max;
                max = nums[i];
            }
            else if(nums[i] > secondMax){
                thirdMax = secondMax;
                secondMax = nums[i];
            }
            else if(nums[i] > thirdMax){
                thirdMax = nums[i];
            }
        }
        if(thirdMax == LLONG_MIN) {
            return max;
        }

        return thirdMax;
    }
};