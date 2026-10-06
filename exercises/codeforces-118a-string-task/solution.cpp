#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Write your solution here.
    string s, res;
    // char temp;
    cin >> s;
    // ready script for geeksforgeeks
    // https://www.geeksforgeeks.org/cpp/tolower-function-in-cpp/
    for (auto &x : s)
    {
        x = tolower(x);
    }

    for (auto &x : s)
    {
        if (!(x == 'a' || x == 'o' || x == 'y' || x == 'e' || x == 'u' || x == 'i'))
        {
            res += ".";
            res += x;
        }
    }
    cout << res;
    return 0;
}
