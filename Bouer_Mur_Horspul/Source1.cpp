#include <iostream>
using namespace std;
int a = 1;
void f() {
	int b = 1;
	static int c = a;
	cout << "a= " << a << " b= " << b << " c= " << c << endl;
}
int main() {
	
	while (a < 4) {
		f();
	}


	return 0;
}