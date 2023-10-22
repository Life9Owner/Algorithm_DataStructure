class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> maps(100000,0);
        for(int i=0;i<nums.size();i++)
        {
            maps[nums[i]]++;
        }
        int cnt=0;
        for(int i=0;i<maps.size();i++)
        {
            if(maps[i]!=0)
            {
               if(maps[i]%3==0)
               {
                   cnt+=maps[i]/3;
               }
               else if(maps[i]%2==0)
               {
                   cnt+=maps[i]/2;
               }
                else if(maps[i]%5==0){
                    cnt+=(2*maps[i]/5);
                }
                else{
                    return -1;
                }
            }
            
        }
        return cnt;
    }
};