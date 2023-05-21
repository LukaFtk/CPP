#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void fromDouble(double num) {
	if (num == 0) cout << num << "/" << "x";
	int counter = 0;
	unsigned long long int n = fabs(num) * 100000000000000;
	while (n % 10 == 0) {
		n /= 10;
		counter++;
	}
	int x = 14 - counter ;
	cout << "(" << fixed << setprecision(0) << num * pow(10, x) << " / " << pow(10, x) << ")" << endl;
}

int main() {
	long double num = 17.00003;
	fromDouble(num);	
    return 0;
}