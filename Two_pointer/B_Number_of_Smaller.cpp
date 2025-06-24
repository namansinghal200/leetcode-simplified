// Problem Link: codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1(n1), v2(n2);
    for (auto &i : v1)
        cin >> i;
    for (auto &i : v2)
        cin >> i;

    int i = 0;
    for (int j = 0; j < n2; j++)
    {
        while (i < n1 && v1[i] < v2[j])
            i++;
        cout << i << " ";
    }
}