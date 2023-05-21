#include <iostream>
#include <cmath>

class MassCenter {
private:
	unsigned int N;
	double* data;
	void setN(unsigned int N) {
		if (N == 0) {
			std::cerr << "Wrong Size!";
			exit(1);
		}
		this->N = N;
		create();
	}
	unsigned int getN() {
		return N;
	}
	void create() {
		data = new double[N];
		clear();
	}
	void clear() {
		for (int i = 0; i < N; i++) {
			data[i] = 0;
		}
	}
public:
	MassCenter() {
		setN(1);
	}
	MassCenter(unsigned int N) {
		setN(N);
	}
	friend double getI(MassCenter& A, unsigned int I);
	friend void setI(MassCenter& A, unsigned int I, double myData);
	friend void print(MassCenter& A);
};

void setI(MassCenter& A, unsigned int I, double myData) {
	A.data[I] = myData;
}
double getI(MassCenter& A, unsigned int I) {
	return A.data[I];
}
void print(MassCenter& A) {
	for (int i = 0; i < A.getN(); i++) {
		std::cout << "data[" << i << "] = " << getI(A, i) << std::endl;
	}
}
void input(MassCenter* Arr, unsigned int n) {
	double tmp;
	for (int i = 0; i < n; i++) {
		std::cout << "point " << i + 1 << std::endl;
		for (int j = 0; j < 4; j++) {
			std::cin >> tmp;
			if (j == 3 && tmp <= 0) {
				std::cerr << "araswori masa!";
				exit(1);
			}
			setI(Arr[i], j, tmp);
		}
		std::cout << std::endl;
	}
}
void cords(MassCenter* Arr, MassCenter& A, unsigned int n) {
	for (int i = 0; i < 4; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			if (i != 3)
				sum += getI(Arr[j], i) * getI(Arr[j], 3);
			else
				sum += getI(Arr[j], i);
		}
		setI(A, i, sum);
	}
	for (int i = 0; i < 3; i++) {
		double tmp = getI(A, i) / getI(A, 3);
		setI(A, i, tmp);
	}
}
int main()
{
	int n = 3, m = 4;
	MassCenter* M = new MassCenter[n];
	for (int i = 0; i < n; i++) {
		M[i] = MassCenter(m);
	}
	input(M, n);
	MassCenter answer(m);
	cords(M, answer, n);
	print(answer);
	
	return 0;
}

