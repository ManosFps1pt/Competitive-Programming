#include <iostream>

int main() {
    int t, msw, len;
    std::string str;
    bool isRed = true;
    char l;
    std::cin>>t;
    int res[t];
    for (int i=0;i<t;i++) {
        isRed = true;
        msw = 0;
        std::cin>>len;
        std::cin>>str;
        for (int j=0;j<len;j++) {
            l = str[j];
            if (l != (isRed?'R':'B')) {msw++;isRed^=true;}
            isRed ^= true;
        }
        res[i] = msw;
    }
    for (int i=0;i<t;i++) {
        std::cout << res[i] << "\n";
    }

    return 0;
}