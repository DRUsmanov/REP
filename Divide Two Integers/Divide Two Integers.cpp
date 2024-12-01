#include <iostream>
using namespace std;

template<typename T, typename K>
class DIV {
public:
    T dividend;
    K divisor;

    int divide() {
        int i = 0;
        int ans = 0;
        int j = 0;
        if (dividend == divisor) {
            ans = 1;
            cout << ans;
            return 1;            
        };
        if (divisor == 1) {
            ans = dividend;
            cout << ans;
            return dividend;
        };
        if (divisor == -1) {
            ans = -dividend;
            cout << ans;
            return -dividend;
        };
        while (i != dividend) {
            if (dividend > 0) {
                i++;
            };
            if (dividend < 0) {
                i--;
            };
            if (divisor > 0) {
                j++;
            };
            if (divisor < 0) {
                j--;
            };
            if (j == divisor) {
                if (dividend < 0 && divisor>0 || dividend > 0 && divisor < 0) {
                    ans--;
                    j = 0;
                }
                else {
                    ans++;
                    j = 0;
                };
            };
        };
        cout << ans;
        return ans;
    };
};

int main()
{
    //dividend can not be -2147483648 and divisor -1 at the same time
    DIV<int, int> example;
    example.dividend = -32;
    example.divisor = -5;
    example.divide();


    return 0;

}

