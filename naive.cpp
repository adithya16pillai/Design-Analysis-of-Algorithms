#include <iostream>
#include <string.h>
using namespace std;

void naive(string testString, string pattern, int arr[], int *ind) {
    int testLength = testString.size();
    int patLength = pattern.size();
    for(int i = 0; i <= (testLength - patLength); i++)   {
        int j;
        for(j = 0; j < patLength; j++) {
            if(testString[i+j] != pattern[j]) {
                break;
            }
        }
        if(j == patLength) {
            (*ind)++;
            arr[(*ind)] = i;
        }
    }
}

int main() {
    string testString, pattern;
    cout << "Enter the test string: ";
    cin >> testString;
    cout << "Enter the pattern: ";
    cin >> pattern;
    int locArr[testString.size()];
    int ind = -1;
    naive(testString, pattern, locArr, &ind);
    for(int i = 0; i <= ind; i++) {
        cout << "The pattern is found in the position: " << locArr[i] << endl;
    }
    return 0;
}