class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(int j=0;j<n;j++){
            if(mp[nums[j]]>1){
                return nums[j];
            }
        }
        return 0;
    }
};
