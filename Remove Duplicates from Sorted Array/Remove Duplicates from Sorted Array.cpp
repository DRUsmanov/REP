#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    
    vector<int> original;
    vector<int>::iterator it;

    int removeDuplicates(vector<int>& nums) {
        
        for (it = nums.begin(); it != nums.end(); it++) {
            int ele = *it;
            if (find(original.begin(), original.end(), ele) != original.end()) {
                it--;
                nums.erase(it + 1);
            }
            else {
                original.push_back(*it);
            }
        }
        return nums.size();

    };
    void print() {
        for (it = original.begin(); it != original.end(); it++) {
            cout << *it;
        }
    }
};

//void removeDuplicates(vector<int> nums) {
//    vector<int> nums2;
//    int j = 1;
//    nums2.push_back(nums[0]);
//    for (int i = 1; i < nums.size(); i++) {
//        if (nums[i] != nums[i - 1]) {
//        nums2.push_back(nums[i]);
//        }
//        j++;
//    }
//    for (int i = 0; i < nums2.size(); i++) {
//        cout << nums2[i] << " ";
//    }
//}

int main()
{
    vector<int> nums = { 1, 2, 2, 3, 3, 3, 4, 5, 5, 6 };

    Solution line;
      
    
    line.removeDuplicates(nums);
    line.print();
    
    
    return 0;
}

