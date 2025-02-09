#include <iostream>
#include <string>

void PrintMas(int row, int num_column, char **mas) {
	for (int i = 0;i < row;++i) {
		for (int k = 0;k < num_column;++k) {
			std::cout << mas[i][k];
		}
		std::cout << std::endl;
	}
}

int main() {

	std::string s;
	getline(std::cin, s);
	int s_size = s.size();

	int row;
	std::cin >> row;
		
	int num_column = (row - 1) * (s_size / (2 * row - 2)) + (s_size % (2 * row - 2)) / row + (s_size % (2 * row - 2)) % row;

	//Определение числа заходов
	int step;
	int step_size = 2 * row - 2;
	if (s_size % step_size != 0) {
		step = s_size / step_size + 1;
	}
	else {
		step = s_size / step_size;
	}
		
	//Создание массива результатов и заполнение массива
	char** mas=new char* [row];
	for (int i=0; i < num_column; ++i) {
		mas[i] = new char[num_column] {};
	}
		
	for (int r = 0;r < row;++r) {
		for (int c = 0;c < num_column;++c) {
			mas[r][c] = ' ';
		}
	}
	
	//Начало заходов в строку
	int counter = 0; //Счетчик элементов
	int column = 0; //Счетчик столбцов
	int first_step_position = 0; 

	for (int l = 0;l < step;++l) {
		//Первый столбец
		for (int r = 0;r < row;++r) {
			if (counter < s_size) {
				mas[r][column] = s[first_step_position + r];
				++counter;
			}
			else {
				goto exit;
			}

		}

		++column;
		first_step_position += row;

		//Остальные столбцы в заходе
		for (int c = 0;c < row - 2;++c) {
			if (counter < s_size) {
				mas[row - c - 2][column] = s[first_step_position + c];
				++counter;
				++column;
			}
			else {
				PrintMas(row, num_column, mas);
				return 0;
			}
		}

		first_step_position += (row - 2);
	}
	exit:

	

}

