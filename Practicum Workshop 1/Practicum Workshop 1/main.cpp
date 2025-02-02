#include <iostream>
#include <vector>
#include <string>

enum class command {
	EXIT, 
	TABLES_INFO,
	BOOK_N,
	FREE_N,
	BOOK,
	UNKNOW_COMMAND
};

command ExtrackCommand(const std::string& input_command) {
	if (input_command == "EXIT") {
		return command::EXIT;
	}
	else if (input_command == "TABLES_INFO") {
		return command::TABLES_INFO;
	}
	else if (input_command == "BOOK_N") {
		return command::BOOK_N;
	}
	else if (input_command == "FREE_N") {
		return command::FREE_N;
	}
	else if (input_command == "BOOK") {
		return command::BOOK;
	}
	else {
		return command::UNKNOW_COMMAND;
	}
}

void EXIT(bool& is_progress) {
	is_progress = false;
}

void TABLES_INFO(const std::vector<std::string>& table_status) {
	for (size_t table_number = 0; table_number < table_status.size();++table_number) {
		std::cout << "Table " << table_number <<" is " << table_status[table_number] << std::endl;
	}
}

void BOOK_N(int person, const std::vector<int>& table_size, std::vector<std::string>& table_status) {
	for (size_t table_number = 0; table_number < table_size.size(); ++table_number) {
		if (table_size[table_number] >= person && table_status[table_number] != "Reserved") {
			table_status[table_number] = "Reserved";
			std::cout << "Table " << table_number << " is reserved for you now!" << std::endl;
			break;
		}
	}
}

void FREE_N(size_t table_number, std::vector<std::string>& table_status) {
	table_status[table_number] = "Free";
	std::cout << "Table " << table_number << " is Free now!" << std::endl;
}

void BOOK(size_t table_number, std::vector<std::string>& table_status) {
	if (table_number > 9) {
		std::cout << "Sorry, there is no such table." << std::endl;
	}
	else if (table_status[table_number] != "Free") {
		std::cout << "Sorry, table is reserved." << std::endl;
	}
	else {
		table_status[table_number] = "Reserved";
		std::cout << "Table " << table_number << " is reserved for you now!" << std::endl;
	}
}

int main() {
	std::vector<int>table_size{ 2, 2, 2, 2, 4, 4, 4, 6, 6, 8 };
	std::vector<std::string>table_status{ "Free","Free","Free","Free","Free","Free","Free","Free","Free","Free" };
	bool is_progress = true;
	std::string input_command;
	size_t table_number = 0;
	int person = 0;

	while (is_progress) {
		std::cout << "Input command: ";
		std::cin >> input_command;
		switch (ExtrackCommand(input_command)) {
		case command::TABLES_INFO:
			TABLES_INFO(table_status);
			break;
		case command::BOOK_N:
			std::cin >> person;
			BOOK_N(person, table_size, table_status);
			break;
		case command::FREE_N:
			std::cin >> table_number;
			FREE_N(table_number, table_status);
			break;
		case command::BOOK:
			std::cin >> table_number;
			BOOK(table_number, table_status);
			break;
		case command::EXIT:
			EXIT(is_progress);
			break;
		case command::UNKNOW_COMMAND:
			std::cout << "UNKNOW COMMAND" << std::endl;
			break;
		}
	}
}