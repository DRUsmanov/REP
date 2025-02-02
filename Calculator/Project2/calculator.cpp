#include "calculator.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//������� ReadNumber ��������� �������� � �������� � ���� ��������� ������������� ����� � ������������� ������ ������ ������������ � TRUE
//� ������ ���� ������� �� �����, �� ������� ������ "Error: Numeric operand expected" � ������������� ������ ������ ������������ � FALSE
bool ReadNumber(Number& result) {
	if (std::cin >> result) {
		return true;
	}
	else {
		std::cerr << err_not_number << std::endl;
		return false;
	}
}

//������� ReadOperator ��������� �������� � �������� � ���� ��������� ������������� �������������� �������� � ������������� ������ ������ ������������ � TRUE
//� ������ ���� ������� ����������� �������� ������� ������ "Error: Unknown token" � ������������� ������ ������ ������������ � FALSE
bool ReadOperator(std::string& op) {
	std::cin >> op;
	if (std::find(correct_operation.begin(), correct_operation.end(), op) == correct_operation.end()) {
		std::cerr << err_not_operation << op << std::endl;
		return false;
	}
	else return true;
}
//������� ������� ����� ������������. �������� �� ��� ��� ���� �� ������� ������� "q" ��� �� �������� ������.
//�� ������� ������ ������ ������ �������� �����.
bool RunCalculatorCycle() {
	Number result, num, memory;
	std::string op;
	bool calculator_status_is_ok, memory_status_is_ok = false;

	calculator_status_is_ok = ReadNumber(result);

	while (calculator_status_is_ok) {
		calculator_status_is_ok = ReadOperator(op);
		if (op == "+") {
			calculator_status_is_ok = ReadNumber(num);
			if (calculator_status_is_ok) result += num;
		}
		else if (op == "-") {
			calculator_status_is_ok = ReadNumber(num);
			if (calculator_status_is_ok) result -= num;
		}
		else if (op == "*") {
			calculator_status_is_ok = ReadNumber(num);
			if (calculator_status_is_ok) result *= num;
		}
		else if (op == "/") {
			calculator_status_is_ok = ReadNumber(num);
			if (calculator_status_is_ok) result /= num;
		}
		else if (op == "**") {
			calculator_status_is_ok = ReadNumber(num);
			if (calculator_status_is_ok) result = pow(result, num);
		}
		else if (op == ":") {
			calculator_status_is_ok = ReadNumber(num);
			if (calculator_status_is_ok) result = num;
		}
		else if (op == "c") {
			result = 0;
		}
		else if (op == "s") {
			memory = result;
			memory_status_is_ok = true;
		}
		else if (op == "l") {
			if (memory_status_is_ok) result = memory;
			else {
				std::cerr << err_memory_empty << std::endl;
				break;
			}
		}
		else if (op == "=") {
			std::cout << result << std::endl;
		}
		else if (op == "q") {
			break;
		}
	}

	return true;
}

