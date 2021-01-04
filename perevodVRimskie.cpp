#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int F(string s) {
    int sum = 0, cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        int t;
        switch(c) {
            case 'I':
            t = 1;
            break;
            case 'V':
            t = 5;
            break;
            case 'X':
            t = 10;
            break;
            case 'L':
            t = 50;
            break;
            case 'C':
            t = 100;
            break;
            case 'D':
            t = 500;
            break;
            case 'M':
            t = 1000;
            break;
        }
        if (cur < t) {
            if (cur == 0) {
                cur = cur + t;
            } else {
                cur = -cur + t;
                sum = sum + cur;
                cur = 0;
            }
        } else {
            sum = sum + cur;
            cur = t;
        }
    }
    return sum + cur;
}


int main() {

}
