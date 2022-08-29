//
//  main.cpp
//  ByteDance
//
//  Created by 张凯 on 2022/3/27.
//  Copyright © 2022 张凯. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> MA, MB;
    vector<int> weights1, weights2;
    vector<pair<int, int>> ans;
    int n1, n2, target, tmp, t1, t2;
    // input tree 1
    cin >> n1;
    for (int i = 0; i < n1; i++)
        cin >> tmp, weights1.push_back(tmp);
    for (int i = 0; i < n1 - 1; i++)
    {
        cin >>t1 >> t2;
        MA[t1]++;
        MA[t2]++;
    }
    // input tree 2
    cin >> n2;
    for (int i = 0; i < n2; i++)
        cin >> tmp, weights2.push_back(tmp);
    for (int i = 0; i < n2 - 1; i++)
    {
        cin >> t1 >> t2;
        MB[t1]++;
        MB[t2]++;
    }
    cin >> target;
    // search for the target in the x + y
    MA[1] += 1,MB[1] += 1; // root node especial
    for (int x = 1; x <= n1; x++)
        for (int y = 1; y <= n2; y++){
            if(MA[x] != 3 || MB[y] != 3) continue;
            else if (weights1[x - 1] + weights2[y - 1] == target){
                ans.push_back(make_pair(x, y));
            }  
        }
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;
    if (ans.size() == 0)
        cout << -1 << endl;
}
/*
7
1 1 1 1 1 1 1
1 2
1 3
2 4
2 5
3 6
3 7
3
1 1 1
1 2
1 3
2
*/