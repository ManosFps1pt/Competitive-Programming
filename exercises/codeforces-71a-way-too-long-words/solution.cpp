#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string word;
    cin >> n;
    string words[n];
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        words[i] = (word.length() <= 10 ? word : (word[0] + to_string(word.length() - 2) + word[word.length() - 1]));
    }
    for (int i = 0; i < n; i++)
    {
        cout << words[i] << endl;
    }
    return 0;
}