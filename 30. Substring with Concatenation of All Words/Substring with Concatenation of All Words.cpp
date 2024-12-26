#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class words {
public:
    string s;
    vector<string> word;
    void find() {
        map<int, int> position;
        for (int i = 0; i < word.size(); i++) {
            int a = 0;
            int start = 0;
            while (a!=-1) {
                a = s.find(word[i], start);
                if (a == -1) {
                    break;
                }
                start = a + word[0].size();
                position[a] = i;
                                
            }
            
        }
        vector<int>chek;
        vector<int>result;
        int counter = 0;
        map<int, int>::iterator it;
        int ele1;
        int ele2;
        for (it=position.begin();it!=prev(position.end(),2);it++) {
            for (int i = 0; i < word.size(); i++) {
                ele1 = next(it, i)->second;
                if (count(chek.begin(), chek.end(), ele1) == 0) {
                    chek.push_back(ele1);
                }
                else {
                    chek.clear();
                    break;
                }
                if (chek.size()==3 && i == 2) {
                    result.push_back(it->first);
                    chek.clear();
                }
            }         
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }
};



int main()
{
    words text;
    text.s = { "barfoofoobarthefoobarman" };
    text.word = { "bar","foo","the" };
    text.find();

    return 0;
}

