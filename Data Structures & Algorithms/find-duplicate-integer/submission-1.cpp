class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        //move then check
        int slow2 = 0;
        while(slow2!=slow){
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow; 
    // we should use return the value of the meeting point
    }
};
