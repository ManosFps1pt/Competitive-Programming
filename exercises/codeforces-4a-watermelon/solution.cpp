#include <iostream>
using namespace std;

int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    // Write your solution here.
    int i;
    bool j;
    cin >> i;
    bool canSplit = (i > 2 && i % 2 == 0);
    cout << (canSplit ? "YES" : "NO");
    return 0;
}
