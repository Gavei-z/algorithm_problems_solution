// a quite easy problem 
// HJ108
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << std::lcm(a, b) << endl;
    }
}
