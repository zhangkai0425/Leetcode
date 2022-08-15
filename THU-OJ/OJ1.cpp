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
    int n1, n2, target, tmp, parent, child;
    // input tree 1
    cin >> n1;
    for (int i = 0; i < n1; i++)
        cin >> tmp, weights1.push_back(tmp);
    for (int i = 0; i < n1 - 1; i++)
    {
        cin >> parent >> child;
        MA[parent]++;
    }
    // input tree 2
    cin >> n2;
    for (int i = 0; i < n2; i++)
        cin >> tmp, weights2.push_back(tmp);
    for (int i = 0; i < n2 - 1; i++)
    {
        cin >> parent >> child;
        MB[parent]++;
    }
    cin >> target;
    // search for the target in the x + y
    for (int x = 1; x <= n1; x++)
        for (int y = 1; y <= n2; y++)
            if (MA[x] != 2 || MB[x] != 2)
                continue;
            else if (weights1[x - 1] + weights2[y - 1] == target)
                ans.push_back(make_pair(x, y));
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;
    if (ans.size() == 0)
        cout << -1 << endl;
}