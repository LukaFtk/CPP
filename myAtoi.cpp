#include <iostream>
#include <string>
using namespace std;

int myAtoi(string s) {
    int num = 0;
    bool sign = true;
    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            sign = false;
            counter++;
        }
        else if (s[i] == '+') {
            sign = true;
            counter++;
        }
        else if (s[i] == '.') {
            return num / 10;
        }
        else if (isdigit(s[i])) {
            num += s[i] - '0';
            if (num > 0 && i < s.size() - 1 && num < INT_MAX ) num *= 10;
            else if (sign == false && num > pow(2, 28)) {
                return -2147483648;
            }
            else if (num > pow(2, 28)) {
                return 2147483647;
            }
        }
        
        else if (!(isdigit(s[i])) && num == 0 && s[i] != ' ') return 0;
        else if (!(isdigit(s[i])) && num > 0) {
            return num / 10;
        }
    }
    if (counter > 1) return 0;
    if (sign == false) {
        num *= -1;
    }
    return num;
}

int main()
{
    cout << myAtoi("2147483640");

    return 0;
}
