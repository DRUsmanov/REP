#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    //map<int, char> table={ {1000,'M'},{500,'D'},{100,'C'},{50,'L'},{10,'X'},{5,'V'},{1,'I'} };
    map<char, int> table{ {'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    vector<int> ri_num;
    vector<int>i_num;
    int num=0;
    string r_num{ "IIIV" };

    for (int i = 0; i < r_num.size(); i++) {
        ri_num.push_back(table[r_num[i]]);
    }

    for (int i = 0; i < ri_num.size(); i++) {
        if (i == ri_num.size() - 1) {
            i_num.push_back(ri_num[i]);
            break;
        }
        if (ri_num[i] < ri_num[i + 1]) {
            i_num.push_back(ri_num[i+1] - ri_num[i]);
            i++;
        }
        else  {
            i_num.push_back(ri_num[i]);
        }
        
    }

    for (int i = 0; i < i_num.size(); i++) {
        num+=i_num[i];
    }

    cout << num;

    return 0;
}
