#include <iostream>
#include <vector>
using namespace std;
// p 进程数，r资源种类
int p;
int r;
int maxs[10][10];       // 最大需求矩阵
int allocation[10][10]; // 分配矩阵
int need[10][10];       // 需求矩阵
int available[10];      // 可用资源向量
int request[10];        // 请求向量当前进程对各类资源的申请量,算法的入口参数
void infInput();
int compare(int m[], int n[]);
int total = 0;

int pi = 0;
void safe_sequence(bool marked[], int allocated[][10], int max[][10], int need[][10],
                   int available[], vector<int> safe);
bool is_available(int process_id, int (*allocated)[10], int (*max)[10], int (*need)[10], int available[]);
// bool is_available(int process_id, int** allocated,int** max, int** need, int available[]);
// 安全性检验函数，检测是否存在安全序列
int safety_test()
{

    int i, j, k, l, flag = 0;
    int finish[p];
    int work[r];
    for (i = 0; i < p; i++)
    {
        finish[i] = 0;
        // vis为1即表示available满足第i进程的资源需要
    }
    for (i = 0; i < r; i++)
    {
        work[i] = available[i];
    }
    cout << "分配序列(计算过程)：\n";
    cout << "            allocation            need              avilable" << endl;
    int index = 0;
    for (k = 0; k < p; k++)
    {
        for (i = 0; i < p; i++)
        {
            if (finish[i] == 1)
            {
                continue;
            }
            else
            {
                if (compare(work, need[i])) // available>=need
                {
                    finish[i] = 1;
                    cout << '\n'
                         << "进程" << i + 1 << '\t';
                    flag = 1;
                    for (j = 0; j < r; j++)
                    {
                        printf("  %2d ", allocation[i][j]);
                    }
                    cout << "     ";
                    for (j = 0; j < r; j++)
                    {
                        printf("  %2d ", need[i][j]);
                    }
                    cout << "     ";
                    for (j = 0; j < r; j++)
                    {
                        printf("  %2d ", work[j] + allocation[i][j]);
                    }
                    for (l = 0; l < r; l++)
                    {
                        work[l] = work[l] + allocation[i][l];
                        // 进程完成，释放资源
                    }
                    //  ans[pi][index++]=i+1;

                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
    }
    pi++;
    cout << '\n';
    for (l = 0; l < p; l++)
    {
        if (finish[l] == 0)
        {
            return 0; // 不存在安全序列
        }
    }
    return 1; // 存在安全序列
}

// 申请进程后的安全性检验函数

void request_test(int n)
{ // 银行家算法
    int j;
    // n=n-1;
    if (compare(available, request) && compare(need[n - 1], request)) // available>=request 并且 need >=request
    {
        for (j = 0; j < r; j++)
        {
            allocation[n - 1][j] = allocation[n - 1][j] + request[j];
            need[n - 1][j] = need[n - 1][j] - request[j];
            available[j] = available[j] - request[j];
        }
        if (safety_test())
        {
            cout << "允许" << n << "进程申请资源！\n";
        }
        else
        {
            cout << "不允许" << n << "进程申请资源！\n";
            for (j = 0; j < r; j++)
            {
                allocation[n - 1][j] = allocation[n - 1][j] - request[j];
                need[n - 1][j] = need[n - 1][j] + request[j];
                available[j] = available[j] + request[j];
            }
        }
    }
    else
    {
        cout << "申请资源量越界！\n";
    }
}

int main()
{
    int i, n; // n-第n个资源申请
    cout << "请输入进程数：";
    cin >> p;
    cout << "请输入资源种类数：";
    cin >> r;
    infInput();       // 输入函数
    vector<int> safe; //
    bool marked[p];
    memset(marked, false, sizeof(marked));
    for (int i = 0; i < r; i++)
    {

        int sum = 0;
        for (int j = 0; j < p; j++)
            sum += allocation[j][i];

        available[i] = available[i] - sum;
    }
    cout << "安全序列是:" << endl;
    safe_sequence(marked, allocation, maxs, need, available, safe);
    // if (safety_test() == 1)
    // {

    // }
    // else
    // {
    //     cout << "不存在安全序列\n";
    // }
    cout << "请输入发出请求向量request的进程编号：";
    cin >> n;
    cout << "请输入请求向量request\n";
    for (i = 0; i < r; i++)
    {
        cin >> request[i];
    }
    request_test(n);
    return 0;
}

// 输入函数
void infInput()
{
    int i, j;
    cout << "请输入最大需求矩阵max\n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> maxs[i][j];
        }
    }
    cout << "请输入分配矩阵allocation\n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> allocation[i][j];
        }
    }
    cout << "需求矩阵need\n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = maxs[i][j] - allocation[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
        // calculate the value of the need matrix
    }

    cout << "请输入可用资源向量available\n";
    for (i = 0; i < r; i++)
    {
        cin >> available[i];
    }
}
// 比较进程为m中的元素全大于n中的元素返回1，否则返回0
int compare(int m[], int n[])
{
    for (int i = 0; i < r; i++)
    {
        if (m[i] < n[i])
        {
            return 0;
        }
    }
    return 1;
}
bool is_available(int process_id, int (*allocated)[10], int (*max)[10], int (*need)[10], int available[])
{

    bool flag = true;

    // check if all the available resources
    // are less greater than need of process
    for (int i = 0; i < r; i++)
    {

        if (need[process_id][i] > available[i])
            flag = false;
    }

    return flag;
}

// Print all the safe-sequences
void safe_sequence(bool marked[], int allocated[][10], int max[][10], int need[][10],
                   int available[], vector<int> safe)
{

    for (int i = 0; i < p; i++)
    {

        //检查是否未标记
        //已经并且可以分配
        if (!marked[i] && is_available(i, allocated, max, need, available))
        {
            // mark the process
            marked[i] = true;
            // 增加available
            // 通过从进程i取消分配资源
            for (int j = 0; j < r; j++)
                available[j] += allocated[i][j];

            safe.push_back(i);
            // 通过进程i找到安全序列
            safe_sequence(marked, allocated, max, need, available, safe);
            //还原
            safe.pop_back();
            marked[i] = false;
            for (int j = 0; j < r; j++)
                available[j] -= allocated[i][j];
        }
    }
    if (safe.size() == p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "P" << safe[i] + 1;
            if (i != (p - 1))
                cout << "--> ";
        }
        cout << endl;
    }
}