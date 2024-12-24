#include <stack>
#include <string>
#include <iostream>

using namespace std;
// ))()())()()()((()()()()()()))
int main() {
	int count = 0;
	int max[1] { 0 };
	stack<char> stack;
	string input_parentheses;
	cin >> input_parentheses;
	for (int i = 0; i < input_parentheses.size();i++) {
		if (input_parentheses[i] == ')' && stack.empty()) continue;
		if (stack.empty()) {
			stack.push(input_parentheses[i]);
			count++;
			continue;
		}
		if (input_parentheses[i] != stack.top() && !stack.empty()) {
			count++;
			stack.pop();
			stack.push(input_parentheses[i]);
		}
		else if (count > max[0]) {
			max[0] = count;
			stack.pop();
			count = 0;
		}
		else {
			stack.pop();
			count = 0;
		}
		if (i == input_parentheses.size() - 1 && count>max[0]) {
			max[0] = count;
			stack.pop();
			count = 0;
		}
		
	}
	int a = (max[0] / 2)*2;

	cout<<a;
	return 0;
}