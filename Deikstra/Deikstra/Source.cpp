#include<iostream>
#include<vector>

int main() {
	using namespace std;
	setlocale(LC_ALL, "ru");

	int matrix[10][10];
	int k;

	cout << " ������� ����� ��������� �������: ";
	cin >> k;

	for (int v = 0; v < k; v++) {

		for (int i = 0; i < k; i++) {
			cout << "������� ����� ��� ������� " <<v<<":";
			cin >> matrix[v][i];
		}
		
	}

	matrix[0][0] = 0;

	cout << "�������: " << endl;
	for (int v = 0; v < k; v++) {
		for (int i = 0; i < k; i++) {
			cout << matrix[v][i]<<" ";
			}
		cout<<endl;
	}
	



	return 0;
}