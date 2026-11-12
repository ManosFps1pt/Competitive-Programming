#include <iostream>
#include <vector>

int main() {
    int t, a, b, c, low, med, high;
    std::cin>>t;
    bool res[t];
    for (int i=0;i<t;i++) {
        std::cin>>a>>b>>c;
        // if (a<=b && a<=c) {low =a;}
        // if (b<=a && b<=c) {low=b;}
        // if (c<=a && c<=b) {low=c;}
        // if (a>=b && a>=c) {high =a;}
        // if (b>=a && b>=c) {high=b;}
        // if (c>=a && c>=b) {high=c;}
        if (a<=b && a<=c && b<=c) {low=a;med=b;high=c;}
        if (a<=b && a<=c && b>=c) {low=a;med=c;high=b;}
        if (b<=a && a<=c && b<=c) {low=b;med=a;high=c;}
        if (b<=c && a>=c && b<=a) {low=b;med=c;high=a;}
        if (b<=c && a>=c && b<=a) {low=b;med=c;high=a;}
        if (c<=a && a>=b && c<=b) {low=c;med=b;high=a;}
        if (c<=a && a<=b && c<=b) {low=c;med=a;high=b;}

        if ((high - low)==2 && (high-med)==1) {
            res[i] = true;
        } else {
            res[i] = false;
        }
    }
    for (int i=0;i<t;i++) {
        std::string out = (res[i] ? "YES" : "NO");
        std::cout << out << "\n";
    }
}