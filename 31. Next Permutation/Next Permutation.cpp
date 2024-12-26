#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//19 5 8 74 7 5
//74 19 8 7 5 5

class arr {
public:
	vector<int> nums;
	void nextPermutation() {
		vector<int>::iterator it;
		map<int, int> chek;
		map<int, int> position;
		int step = -1;
		vector<int>resultat = nums;
		for (it = prev(nums.end(),1); it!=nums.begin(); it--) {
			chek[0] = 0;
			step = step + 1;
			int mnojitel = 1;
			for (int i = 1; i != nums.size()-step; i++) {
				mnojitel *= 10;
				int ele1 = *it;
				int ele2 = *prev(it, i);
				int sravnenie = mnojitel * ele1 - mnojitel * ele2 + ele2 - ele1;
				if (chek[0] == 0 && sravnenie > 0) {
					chek[0] = sravnenie;
					position[i] = step;
				}
				else if (sravnenie>0 && sravnenie < chek[0]) {
					chek[0] = sravnenie;
					position[i] = step;
				}
				if (chek[0] != 0 && i == nums.size() - step-1) {
					map<int, int>::iterator iter;
					iter = position.begin();
					resultat[nums.size() - 1 - iter->second] = nums[nums.size() - 1 - iter->second - iter->first];
					resultat[nums.size() - 1 - iter->second - iter->first] = nums[nums.size() - 1 - iter->second];
					sort(prev(resultat.end(), iter->first + iter->second), resultat.end());
					goto stop;
				}
			}
			if (it == next(nums.begin(), 1)) {
				sort(resultat.begin(), resultat.end());
			}
			
		}
		stop:
		for (int i = 0; i < resultat.size(); i++) {
			cout << resultat[i] << " ";
		}
	}
};

int main() {
	arr solution;
	solution.nums = { 3,2,1 };
	solution.nextPermutation();
		
}