//
// Created by Gavei on 2022/5/3.
//

/**
* A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (≤10
10
 ) is the initial numer and K (≤100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/

#include "iostream"
#include "algorithm"
using namespace std;

string n;
int k;
void add()
{
    string t = n;
    reverse(t.begin(), t.end());
    int sum = 0, carry = 0;
    for (int i = 0; i < t.size(); ++i){
        sum = (n[i] - '0') + (t[i] - '0') + carry;
        carry = 0;
        if (sum >= 10){
            sum -= 10;
            carry = 1;
        }
        n[i] = sum + '0';
    }
    if (carry)
        n += '1';
    reverse(n.begin(), n.end());
}
bool check(){
    string t = n;
    reverse(t.begin(), t.end());
    if (t == n)
        return true;
    return false;
}
int main(){
    cin >> n >> k;
    int cnt = 0;
    if (!check()){
        while(cnt < k)
        {
            add();
            cnt ++;
            if (cnt >= k || check())
                break;
        }
    }
    cout << n <<endl << cnt;
    return 0;
}