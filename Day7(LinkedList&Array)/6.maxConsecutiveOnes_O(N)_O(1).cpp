class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxi=0;
        for(int i=0;i<size(nums);i++){
            if(nums[i]==0) cnt=0;
            else cnt++;
            maxi=max(cnt, maxi);
        }
        return maxi;
    }
};