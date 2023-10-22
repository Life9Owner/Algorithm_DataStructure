#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class StockPrice {
public:
    static bool cmp(int a,int b)//timestamp
    {
        return a<=b;
    }

    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if(hash_map.find(timestamp)!=hash_map.end())
        {
            for(int i=0;i<pri.size();i++)
            {
                if(pri[i]==hash_map[timestamp])
                {
                    is_modified=1;
                    is_changed=1;
                    pri[i]=price;
                    break;
                }
            }
        }
        else{
            time.push_back(timestamp);
            pri.push_back(price);
            is_changed=1;
            is_modified=1;
        }
        hash_map[timestamp]=price;
        
        
    }
    
    int current() {
        sorted=time;
       
        sort(sorted.begin(),sorted.end(),cmp);
           
       
        return hash_map[sorted[sorted.size()-1]];
    }
    
    
    int maximum() {
        sorted=pri;
        if(is_changed==1)
        {
            sort(sorted.begin(),sorted.end(),cmp);
            is_changed=0;
        }
        return sorted[sorted.size()-1];
    }
    
    int minimum() {
        sorted=pri;
        if(is_changed==1)
        {
            sort(sorted.begin(),sorted.end(),cmp);
            is_changed=0;
        }
        return sorted[0];
    }
    unordered_map<int,int> hash_map;
    vector<int> pri;
    vector<int> time;
    vector<int> sorted;
    int is_changed=0;
    int is_modified=0;

};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

int main() {
    // vector<string> actions = {"StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"};
    // vector<vector<int>> values = {{}, {1, 10}, {2, 5}, {}, {}, {1, 3}, {}, {4, 2}, {}};
vector<string> actions =
 {"StockPrice","update","minimum","update",
 "update","minimum","minimum","update","maximum",
 "update","minimum","current","minimum","update",
 "current","minimum","current","current","update",
 "maximum","maximum","update","minimum","minimum",
 "maximum","maximum","update","maximum","current",
 "maximum","minimum","minimum","update","current"};
vector<vector<int>> values = {{}, {45, 9233}, {}, 
{55, 9651}, {37, 3902}, {}, {}, {25, 4833}, {},
 {53, 4521}, {}, {}, {}, {22, 1161}, {}, {}, {},
  {}, {55, 6897}, {}, {}, {20, 5354}, {}, {}, {}, 
  {}, {30, 5623}, {}, {}, {}, {}, {}, {25, 2725}, {}};

    StockPrice* obj = nullptr;
    vector<int> result;

    for (int i = 0; i < actions.size(); i++) {
        if (actions[i] == "StockPrice") {
            obj = new StockPrice();
            result.push_back(NULL);
        } else if (actions[i] == "update") {
            obj->update(values[i][0], values[i][1]);
            result.push_back(NULL);
        } else if (actions[i] == "current") {
            result.push_back(obj->current());
        } else if (actions[i] == "maximum") {
            result.push_back(obj->maximum());
        } else if (actions[i] == "minimum") {
            result.push_back(obj->minimum());
        }
    }

    // Clean up
    delete obj;

    // Output the results
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
