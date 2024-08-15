#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

int main() {
	using namespace std;
	setlocale(LC_ALL, "ru");
		
	int vesa[10][10];
	vector<int> dist;
	vector<int> prosmotreno;
	int elements;
	int vstart;
	int ime;
		
	cout << "Введите количество вершин графа (не более 10): ";
	cin >> elements;

	cout << "Введите связи с вершинами, если связи нет введите 0"<<endl;
	for (int v1 = 0; v1 < elements; v1++) {

		vesa[v1][v1] = 0;

		for (int v2=v1+1; v2 < elements; v2++) {
			
				cout << v1 << " - " << v2 << ":";
				cin >> vesa[v1][v2];
				vesa[v2][v1] = vesa[v1][v2];
									
		}
		
	}
		
	cout <<endl<< "Матрица: " << endl;
	for (int v1 = 0; v1 < elements; v1++) {
		for (int v2 = 0; v2 < elements; v2++) {
			cout << vesa[v1][v2]<<" ";
			}
		cout<<endl;
	}
	
	cout << endl<<"Укажите начальную вершину: ";
	cin >> vstart;
	
	
	for (int i = 0; i < elements; i++) {
		dist.push_back(vesa[vstart][i]);
	}

	prosmotreno.push_back(vstart);

	auto minelement = dist[0];

	/*if (minelement == 0) {
		minelement = *max_element(begin(dist),end(dist)) + 1;
	}*/

	for (int i = 0; i < elements; i++) {
		int chek = count(prosmotreno.begin(), prosmotreno.end(), i);
		if (dist[i] != 0 && chek==0) {
			if (dist[i] < minelement) {
				 minelement = dist[i];
				 ime = i;
			}
		}
	}
	
	for (int i = 0; i < elements; i++) {
		cout << dist[i] << " ";
	}
	
	cout << endl;
	cout << prosmotreno[0]<<endl;
	cout << ime << endl;

	for (int i = 0; i < elements; i++) {
		if (vesa[ime][i] < dist[i]) {
			dist[i] = vesa[ime][i];
		}
	}
	

	return 0;
}