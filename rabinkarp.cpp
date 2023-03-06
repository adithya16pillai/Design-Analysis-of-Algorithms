#include<string.h>
#include<iostream>
#include<vector>
using namespace std;

#define d 256
 
void get_input(vector<char>& a) {
    char c;
    while (1){
        c = getchar();
        if (c == '\n')
        break;
        a.push_back(c);
    }
    return;
}
void rabinKarp(char *pat, char *test, int q) {
    int m = strlen(pat);
    int n = strlen(test);
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;
    for (i = 0; i < m-1; i++)
        h = (h*d)%q;
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + test[i]) % q;
    }
    for (i = 0; i <= n - m; i++){
        if ( p == t ) {
            for (j = 0; j < m; j++) {
                if (test[i + j] != pat[j])
                    break;
            }
            if (j == m) {
                cout << "Pattern found at position: " << i;
            }
        }
        if ( i < n - m ){
            t = (d * (t - test[i] * h) + test[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
 
int main() {
    vector<char> test;
    vector<char> pat;
    cout<<"Enter test string: ";
    get_input(test);
    cout<<"Enter pattern string: ";
    get_input(pat);
    char *text,*pattern;
    text=&test[0];
    text[test.size()]='\0';
    pattern=&pat[0];
    pattern[pat.size()]='\0';
    int q;
    cout << "Enter mod value (q): ";
    cin >> q;
    rabinKarp(pattern, text, q);
    getchar();
    return 0;
}