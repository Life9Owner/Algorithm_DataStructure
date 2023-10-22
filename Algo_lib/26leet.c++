#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    void T()
    {
        int n=3;
        int matrix[n][n]={{1,2,3},{4,5,6},{7,8,9}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // swap(matrix[i][j], matrix[j][i]);
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> more;
       auto it=nums.begin();
        for(int i=0;i<nums.size();i++)
        {
            if(more.find(nums[i])==more.end())//没有该键值
            {
                more.insert({nums[i],nums[i]});//插入
               
                 
            }
            else 
            {
               
                nums.erase(it);//已经存在，
               
            }
            
            cout<<"it:" <<&it<<endl;
            it++;
            cout<<"Map ";
            for(auto it=more.begin();it!=more.end();it++)
            {
                cout<<"("<<it->first<<","<<it->second<<")";
            }
            for (auto x:nums)cout<<x<<" ";
            cout<<"endl"<<endl;
        }
        return nums.size();
    }
};
int main()
{
    Solution x;
    // vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    // x.removeDuplicates(nums);
    // for(int x:nums)
    // cout<<x<<" ";
    x.T();
    return 0;
}