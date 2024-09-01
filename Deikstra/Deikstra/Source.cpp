#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
#include<cstdlib>

int main() {
	using namespace std;
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
		
	int vesa[10][10];
	vector<int> dist;
	vector<int> prosmotreno;
	int dist_step[10][10];
	int vstart;
	int ime;
	int vfinish;
	
		
	for (int v1 = 0; v1 < 10; v1++) {

		vesa[v1][v1] = 0;

		for (int v2=v1+1; v2 < 10; v2++) {
			vesa[v1][v2]= 1 + rand() % 50;
			vesa[v2][v1] = vesa[v1][v2];
									
		}
		
	}
			
	cout <<endl<< "Матрица: " << endl;
	for (int v1 = 0; v1 < 10; v1++) {
		for (int v2 = 0; v2 < 10; v2++) {
			cout << vesa[v1][v2]<<" ";
			}
		cout<<endl;
	}
	
	cout << endl<<"Укажите начальную вершину: ";
	cin >> vstart;
	
	for (int i = 0; i < 10; i++) {
		dist.push_back(vesa[vstart][i]);
	}
	for (int i = 0; i < 10; i++) {
		dist_step[0][i] = vesa[vstart][i];
	}
		
	prosmotreno.push_back(vstart);
	auto minelement = *max_element(begin(dist), end(dist)) + 1;
	
	int step = 0;
	ime = vstart;
	while (prosmotreno.size()!= 10) {
		step++;
		for (int i = 0; i < 10; i++) {
			int chek = count(prosmotreno.begin(), prosmotreno.end(), i);
			if (dist[i] != 0 && chek == 0 && vesa[ime][i]!=0) {
				if (dist[i] < minelement) {
					minelement = dist[i];
					ime = i;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			int chek = count(prosmotreno.begin(), prosmotreno.end(), i);
			if (vesa[ime][i] != 0 && chek == 0) {
				if (dist[ime] + vesa[ime][i] < dist[i]) {
					dist[i] = dist[ime] + vesa[ime][i];
				}
				if (dist[i] == 0) {
					dist[i] = dist[ime] + vesa[ime][i];
				}
			}
		}
		for (int i=0; i < 10; i++) {
			dist_step[step][i] = dist[i];
		}
		prosmotreno.push_back(ime);
		minelement = *max_element(begin(dist), end(dist)) + 1;
	}
	
	
	cout << "Минимальные растояния от веришны " << vstart << endl;
	for (int i = 0; i < 10; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
	cout << "Просмотрены вершины: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << prosmotreno[i] << " ";
	}
	cout << endl;
	cout << "Путь: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int s = 0; s < 10; s++) {
			cout << dist_step[i][s] << " ";
		}
		cout << endl;
	}

	cout << "Введите конечную вершину: ";
	cin >> vfinish;

	int size_dist;
	for (int i = 9; i > 0; i--) {
		if (dist_step[i - 1][vfinish] > dist_step[i][vfinish]) {
			size_dist = i+1;
		}
	}
	
	cout << "Кратчайший путь от вершины " << vstart << " до вершины " << vfinish << " :";
	for (int i = 0; i < size_dist; i++) {
		cout << prosmotreno[i] << "-";
	}
	cout << vfinish;
	return 0;
}