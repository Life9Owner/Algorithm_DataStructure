// #include<bits/stdc++.h> //For 2D vector and sort() function 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int main()
{
     // Initializing 2D vector "vect" with 
    // values 
    // vector< vector<int> > vect{{6, 6}, 
    //                            {9, 2}, 
    //                            {9, 1}}; 
                                vector< vector<int> > vect{{6, 6, 1, 4}, 
                               {7, 1, 6, 5}, 
                               {3, 3, 9, 2}}; 

                                   // Printing before sorting
                                       // Use of "sort()" for sorting second row 
    // Indexing starts from '0'
    sort(vect.begin(), vect.end(),less<vector<int>>());
    //For comparing 2'nd column order
// bool sortcol(const vector<int>& v1,const vector<int>& v2) { 
//      return v1[1] < v2[1]; 
// } 


    // sort(vect.begin(),vect.end());
    // For each element 'x' in 'vect'
    for(auto x:vect){
        //For each element 'y' in 'x'
        for(auto y:x) cout << y << " ";
        cout << endl;
    }
    //OUTPUT:
    // 6 6 1 4
    // 7 1 6 5 
    // 8 3 9 2

    return 0;
}
   
