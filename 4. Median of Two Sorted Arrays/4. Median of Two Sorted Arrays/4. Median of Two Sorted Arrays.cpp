#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> nums1{ 1,2 };
    vector<int> nums2{ 4,3 };
    double a;
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    nums1.size()  % 2 == 0 ? a=(double)(nums1[(nums1.size()/ 2) - 1] + nums1[nums1.size() / 2]) / 2   :a=(double)nums1[nums1.size() / 2];
    cout << a;
    return 0;
}



