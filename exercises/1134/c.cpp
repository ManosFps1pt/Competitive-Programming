
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t, len;
    std::cin >> t;
    std::vector<std::vector<int>> arr(t);
    std::vector<std::vector<int>> arr2(t);
    for (int i = 0; i < t; i++) {
        std::cin >> len;
        arr[i].resize(len);
        arr2[i].resize(len);
        for (int j = 0; j < len; j++) {
            std::cin >> arr[i][j];
        }
        std::sort(arr[i].begin(), arr[i].end());
        for (int j = 0; j < len; j++) {
            arr2[t][j] = (j%2==0)?arr[i][j]:arr[i][len-j];
        }
    }
    for (int i = 0; i < t; i++) {
    for (int j = 0; j < arr2[i].size(); j++) {
         std::cout << arr2[i][j] << " ";
    }
    std::cout << "\n";
    }

    return 0;
}
