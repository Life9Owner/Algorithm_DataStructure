#include <iostream>
#include <vector>
using namespace std;
int cnt=0;
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);//A 通过B 移动到 C
    }
    

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C){
        if (n == 1){
            C.push_back(A.back());
            A.pop_back();//只剩一个时，直接压入目标
            return;
        }
        // move(2,A,C,B)
        move(n-1, A, C, B);    // 将A上面n-1个通过C移到B
        // printf("arrived here!\n");
        // cnt++;
        C.push_back(A.back());  // 将A最后一个移到C
        A.pop_back();          // 这时，A空了;
        move(n-1, B, A, C);     // 将B上面n-1个通过空的A移到C
        
    }
};

int main() {
    vector<int> A = {3, 2, 1};  // 输入测试用例
    vector<int> B, C;                   // 创建空的 B 和 C 向量作为中转和目标
    Solution obj;
    obj.hanota(A, B, C);                    // 调用 hanota 函数进行汉诺塔操作
    cout << "C = ";
    for (int val : C) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
 }
