class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]==nums[i+1])
            {
                i+=2;
                if(nums[i+1]==nums[i+2])
                {
                    i+=1;
                }
            }
            else{
                return -1;
            }
            cnt++;
        }
        return cnt;
    }
};
AddressSanitizer: heap-use-after-free on address 0x7f6e8bc54d7c at pc 0x000000367673 bp 0x7ffe42396250 sp 0x7ffe42396248
最后执行的输入：
Hidden for this testcase during contest.
标准输出：
Hidden for this testcase during contest.
220,109,109,400,347,347,400,109,109,347,400,400,109,400,109,109,316,109,400,109,109,109,347,109,109,400,400,109,109,109,109,109,109,109,109,109,400,109,109,109,400,400,400,109,400,400,400,109,316,400,109,109,400,141,109,400,400,109,109,400,109,109,109