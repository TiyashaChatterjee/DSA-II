class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        //meeting point
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int sl2 = 0;
        while(sl2!=slow){
            sl2=nums[sl2];
            slow=nums[slow];
        }
        return slow;
    }
};
