#include <iostream>
using namespace std;

int print_lcs(string str1, string str2, int i, int j) {
    if (i == 0 || j == 0)
        return 0;
    if (str1[i - 1] == str2[j - 1]) {
        return 1 + print_lcs(str1, str2, i - 1, j - 1);
    } else {
        return max(print_lcs(str1, str2, i - 1, j), print_lcs(str1, str2, i, j - 1));
    }
}
int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout<<"Length of LCS is: "<< print_lcs(str1, str2, str1.size(), str2.size()) << endl;
}