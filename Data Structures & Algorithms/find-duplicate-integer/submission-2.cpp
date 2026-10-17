class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        // first while is for find a meeting point we dont know that it is circular loop or not we just meet at some point.
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];

       }
       while(slow != fast);
       // after meeting we reset slow pointer at move both pointer 1 step so they meet at exact point where circular loop start or our duplicate found
       slow = 0 ;
       while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
       }

       return slow;
        
    }
};
