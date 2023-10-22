#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix(3,vector<int>(10,1));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    // int i=0;
    // for(vector<vector<int>>::iterator it=matrix.begin();it!=matrix.end();it++)
    // {
    //     cout<<*it[i]<<"  ";
    // }

    
    cout<<matrix.size()<<"--1"<<endl;//it is the row
    cout<<matrix[0].size()<<"--2"<<endl;//it is the column number
    cout<<matrix[1].size()<<"--3"<<endl;
    cout<<matrix.size()<<"--4"<<endl;

}