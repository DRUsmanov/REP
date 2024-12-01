#include <iostream>

int main()
{
#include <iostream>
#include <map>
#include<vector>

	using namespace std;

	int main() {

		int target = 12;
		vector<int> nums{ 2,3,8,9 };
		map<int, int> HashMap;
		for (int i = 0; i < nums.size(); i++) {
			int x = target - nums[i];
			if (HashMap.count(x)) {
				cout << HashMap[x] << " " << i;
			}
			HashMap[nums[i]] = i;
		}
		return 0;
	}
}