#include<iostream>
#include<vector>

int main() {
	using namespace std;
	setlocale(LC_ALL, "ru");

	int matrix[10][10];
	int k;

	cout << " Введите число элементов матрицы: ";
	cin >> k;

	for (int v = 0; v < k; v++) {

		for (int i = 0; i < k; i++) {
			cout << "Введите связи для вершины " <<v<<":";
			cin >> matrix[v][i];
		}
		
	}

	matrix[0][0] = 0;

	cout << "Матрица: " << endl;
	for (int v = 0; v < k; v++) {
		for (int i = 0; i < k; i++) {
			cout << matrix[v][i]<<" ";
			}
		cout<<endl;
	}
	



	return 0;
}