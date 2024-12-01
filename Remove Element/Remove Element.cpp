#include <iostream>
#include <vector>
using namespace std;

class Object{
public:
    vector<int> nums;
    int val;
    void RemoveElement() {
        vector<int>::iterator it;
        for (it=nums.begin(); it<nums.end();it++) {
            if (*it == val) {
                --it;
                nums.erase(it+1);
            }
        }
        for (it = nums.begin(); it < nums.end(); it++){
            cout << *it << " ";
        }
    }
    
};

int main()
{
    vector<int> nums={ 5,4,3,2,1,2,6,8,9,2,4,6 };
    
    Object Solution;
    Solution.nums = nums;
    Solution.val = 2;
    Solution.RemoveElement();
    
    return 0;
}

