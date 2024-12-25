#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(0));
	vector<int>line;
	vector<int>revers_line;
	int line_size = rand() % 20;
	if (line_size == 0) {
		cout << "Сгенерирован пустой лайн"<<endl;
		system("pause");
		return 0;
	}
	for (int i = 0;i < line_size;i++) {
		line.push_back(rand() /*% 15*/);
		/*srand(time(0));*/
	}
	sort(line.begin(), line.end());
	int point = rand() % line_size;
	for (int i = 0;i < line_size - point;i++) {
		revers_line.push_back(line[point + i]);
	}
	for (int i = line_size-point;i < line_size;i++) {
		revers_line.push_back(line[i - (line_size - point)]);
	}
	cout << "Сгенерирован лайн: ";
	for (int i = 0;i < line.size();i++) {
		cout << line[i] << " ";
	}
	cout << endl;
	cout << "Сгенерирован перевернутый лайн относительно элемента "<<point<<": ";
	for (int i = 0;i < revers_line.size();i++) {
		cout << revers_line[i] << " ";
	}
	cout << endl;
	cout << "Введите элемент поиска: ";
	int target;
	cin >> target;
	int left = 0;
	int right = revers_line.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (revers_line[mid] == target) {
			cout<< "Позиция элемента: "<<mid;
			return 0;
		}
		if (revers_line[mid] >= revers_line[left]) {
			if (target >= revers_line[left] && target < revers_line[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else {
			if (target > revers_line[mid] && target <= revers_line[right]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}
	cout << "Элемент не найден.";
	return 0;

}

