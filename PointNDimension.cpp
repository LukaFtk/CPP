#include <iostream>
#include <cmath>
using namespace std;

class PointND {
private:
    void setN(unsigned int N) {
        if (N == 0) {
            N = 1;
        }
        this->N = fabs(N);
    }
protected:
    double* data;
    unsigned int N;
public:
    PointND() {
        setN(1);
        data = new double[N];
    }
    PointND(unsigned int N) {
        setN(N);
        data = new double[N];
    }
    unsigned int getN() {
        return N;
    }
    void setI(unsigned int I, double myData) {
        data[I] = myData;
    }
    double getI(unsigned int I) {
        if (I > N - 1) {
            I = N - 1;
        }
        return data[I];
    }
    double D(PointND tmp) {
        double sum = 0;
        for (int i = 0; i < getN(); i++) {
            double diff = getI(i) - tmp.getI(i);
            sum += diff * diff;
        }
        return sqrt(sum);
    }
};

class Point3D : public PointND {
public:
    Point3D() : PointND(3) {}
    Point3D(double x, double y, double z) : PointND(3) {
        setI(0, x);
        setI(1, y);
        setI(2, z);
    }
    double getX() {
        return data[0];
    }
    double getY() {
        return data[1];
    }
    double getZ() {
        return data[2];
    }
};

class Point2D : public PointND {
public:
    Point2D() : PointND(2) {}
    Point2D(double x, double y) : PointND(2) {
        setI(0, x);
        setI(1, y);
    }
    double getX() {
        return data[0];
    }
    double getY() {
        return data[1];
    }
};
class Point1D : public PointND {
public:
    Point1D() : PointND(1) {}
    Point1D(double x) : PointND(1) {
        setI(0, x);
    }
    double getX() {
        return data[0];
    } 
};

int main() {
    Point2D P1 = Point2D(-3, 5);
    Point2D P2 = Point2D(3, 5);
    cout << P1.D(P2);
    
      
	return 0;
}