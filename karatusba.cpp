#include <iostream>
#include <string>
using namespace std;

string sum(string left, string right) {
    string result;
    int len = max(left.size(), right.size());
    int carryOver = 0;
    int sum_of_digits;
    int i;
    while(left.size() < len) {
        left.insert(0,"0");
    }
    while(right.size() < len) {
        right.insert(0,"0");
    }
    for(i = len - 1; i >= 0; i--) {
        sum_of_digits = (left[i] - '0') + (right[i] - '0') + carryOver;
        carryOver = sum_of_digits/10;
        result.insert(0,to_string(sum_of_digits % 10));
    }
    if(carryOver) {
        result.insert(0,to_string(carryOver));
    }
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string sub(string left, string right) {
    string result;
    int i;
    int len = max(left.size(), right.size());
    int difference;
    while(left.size() < len) {
        left.insert(0,"0");
    }
    while(right.size() < len) {
        right.insert(0, "0");
    }
    for(i = len - 1; i >= 0; i--) {
        difference = (left[i] - '0') + (right[i] - '0');
        if(difference >= 0) {
            result.insert(0, to_string(difference));
        } else {
            int j = i - 1;
            while(j >= 0) {
                right[j] = ((left[j] - '0') - 1) % 10 + '0';
                if(left[j] != '9') {
                    break;
                } else {
                    j--;
                }
            }
            result.insert(0, to_string(difference+10));
        }
    }
    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string multiply(string left, string right) {
    int i;
    int len = max(left.size(), right.size());
    while(left.size() < len) {
        left.insert(0,"0");
    }
    while(right.size() < len) {
        right.insert(0, "0");
    }
    if(len == 1) {
        return to_string((left[0] - '0')*(right[0] - '0'));
    }
    string left1 = left.substr(0, len/2);
    string left2 = left.substr(len/2, len-len/2);
    string right1 = right.substr(0, len/2);
    string right2 = right.substr(len/2, len-len/2);
    string p1 = multiply(left1, right1);
    string p2 = multiply(left2, right2);
    string p3 = multiply(sum(left1, left2), sum(right1, right2));
    string p4 = sub(p3, sum(p1, p2));
    for(i = 0; i < 2*(len-len/2); i++) {
        p1.append("0");
    }
    for(i = 0; i < len-len/2; i++) {
        p4.append("0");
    }
    string result = sum(sum(p1,p2),p4);
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << multiply(s1, s2) << endl;
    return 0;
}
