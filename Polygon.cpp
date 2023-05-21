#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class MyPoint {
protected:
	double x;
	double y;
public:
	MyPoint() : x(0), y(0) {}
	MyPoint(double x, double y) {
		set(x, y);
	}

	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	void set(double x, double y) {
		setX(x); setY(y);
	}
	void setX(double x) {
		this->x = x;
	}
	void setY(double y) {
		this->y = y;
	}
	friend double Distance(MyPoint& A, MyPoint& B);
	friend double Determinant(MyPoint& A, MyPoint& B);
	friend istream& operator>>(istream& is, MyPoint& A);
	friend ostream& operator<<(ostream& os, MyPoint& A);
};
istream& operator>>(istream& is, MyPoint& A) {
	cin >> A.x >> A.y;
	return is;
}
ostream& operator<<(ostream& os, MyPoint& A) {
	cout << A.x << " " << A.y;
	return os;
}
double Distance(MyPoint& A, MyPoint& B) {
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
double Determinant(MyPoint& A, MyPoint& B) {
	return A.x * B.y - B.x * A.y;
}
class Polygon : public MyPoint {
private:
	void setN(unsigned int N) {
		if (N == 0) { cerr << "Wrong Size!"; exit(1); }
		this->N = N;
	}
	void create() {
		arr = new MyPoint[N];
		clear();
	}
	void clear() {
		for (int i = 0; i < N; i++) {
			arr[i] = MyPoint();
		}
	}
protected:
	MyPoint* arr;
	unsigned int N;
public:
	Polygon() {
		setN(1);
		create();
	}
	Polygon(unsigned int N) {
		setN(N);
		create();
	}
	unsigned int getN() {
		return N;
	}
	double P() {
		double sum = 0;
		for (int i = 0; i < N - 1; i++) {
			sum += Distance(arr[i], arr[i + 1]);
		}
		sum += Distance(arr[0], arr[N - 1]);
		return sum;
	}
	double S() {
		double sum = 0;
		for (int i = 0; i < N - 1; i++) {
			sum += 0.5 * Determinant(arr[i], arr[i + 1]);
		}
		sum += 0.5 * Determinant(arr[0], arr[N - 1]);
		return sum;
	}

	friend istream& operator>>(istream& is, Polygon& A);
	friend ostream& operator<<(ostream& os, Polygon& A);
	friend void input(Polygon& A);
	friend void generatePdf(Polygon& A);

};
istream& operator>>(istream& is, Polygon& A) {
	for (int i = 0; i < A.getN(); i++) {
		cin >> A.arr[i];
	}
	return is;
}
void input(Polygon& A) {
	ifstream fin("D:\\points.txt");
	double a, b;
	int counter = 0;
	while (fin >> a >> b) {
		A.arr[counter].set(a, b);
		counter++;
	}
}
ostream& operator<<(ostream& os, Polygon& A) {
	for (int i = 0; i < A.getN(); i++) {
		cout << A.arr[i] << endl;
	}
	return os;
}

void generatePdf(Polygon& A) {
	ofstream file("pointFigura.pdf");
	double minX = A.arr[0].getX();
	double maxX = minX;
	double minY = A.arr[0].getY();
	double maxY = minY;
	for (unsigned int i = 1; i < A.getN(); i++) {
		double x = A.arr[i].getX();
		double y = A.arr[i].getY();
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	int margin = 30;
	int pageWidth = 600;
	int pageHeight = 800;
	double scaleFactor = (pageWidth - 2.0 * margin) / (maxX - minX);

	file << "%PDF-1.7\n";
	file << "1 0 obj\n";
	file << "<< /Type /Catalog /Pages 2 0 R >>\n";
	file << "endobj\n";
	file << "2 0 obj\n";
	file << "<< /Type /Pages /Kids [3 0 R] /Count 1 >>\n";
	file << "endobj\n";
	file << "3 0 obj\n";
	file << "<< /Type /Page /Parent 2 0 R /MediaBox [0 0 " << pageWidth << " " << pageHeight << "] /Contents 4 0 R >>\n";
	file << "endobj\n";
	file << "4 0 obj\n";
	file << "<< /Length 61 >>\n";
	file << "stream\n";

	for (unsigned int i = 0; i < A.getN(); i++) {
		file << (margin + (A.arr[i].getX() - minX) * scaleFactor) << " " << (margin + (A.arr[i].getY() - minY) * scaleFactor) << (i == 0 ? " m\n" : " l\n");
	}

	file << "h\n";
	file << "S\n";
	file << "endstream\n";
	file << "trailer\n";
	file << "<< /Root 1 0 R /Size 5 >>\n";
	file.close();

	string openCommand = "start";
	if (!openCommand.empty()) {
		string command = openCommand + " " + "pointFigura.pdf";
		system(command.c_str());
	}
}

int main(int argc, char** argv) {
	// shieyvanet koordinatebi romelime xerxit
	// zoma miutitet input(A) shemtxvevashi
	Polygon A = Polygon(4);
	//input(A);
	cin >> A;
	generatePdf(A);
	
	return 0;
}