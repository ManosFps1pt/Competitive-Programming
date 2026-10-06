#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Write your solution here.
    int n, k, val;
    int answer = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        answer += (val > k ? 1 : 0);
    }
    cout << answer;

    return 0;
}
