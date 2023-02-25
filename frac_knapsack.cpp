#include <iostream>
using namespace std;

float w[100], v[100], amount=0.0;
int n, i, j, m=90, temp;

class frac_knapsack {
    public:
        void get() {
            cin >> n;
            for(i=1;i<=n;i++) {
                cin >> v[i];
            }
            cin >> n;
            for(i=1; i<=n; i++) {
                cin >> w[i];
            }
        }
        void sort() {
            for(i=1;i<=n;i++) {
                for(j=1;j<=n;j++) {
                    if((v[j]/w[j]) < (v[j+1]/w[j+1])) {
                        temp = v[j];
                        v[j] = v[j+1];
                        v[j+1] = temp;
                        temp = w[j];
                        w[j] = w[j+1];
                        w[j+1] = temp;
                    }
                }
            }
        }
        void calc() {
            for(i=0; i<n; i++) {
                if(m>0 && w[i] <= m) {
                    m = m - w[i];
                    amount = amount + v[i];
                }
            }
        }
        void display() {
            cout << amount;
        }
};

int main() {
    frac_knapsack obj;
    obj.get();
    obj.sort();
    obj.calc();
    obj.display();
    return 0;
}