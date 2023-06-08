#include <iostream>
#include <cmath>
using namespace std;


// funqcia romelic sheamowmebs masivis zomebs taviant set-ebshi.
// tu momxmarebeli miutetbs zomas 0-s an 0ze naklebs,
// mashin es funqcia gamoidzaxeba avtomaturad
unsigned int sizeSetterForArrays(unsigned int size) {
	if (size == 0) {
		cerr << "Array Size Couldn't be Zero!, Please Enter Correct Size" << endl;
		int temporaryVarForSize = 0;
		while (temporaryVarForSize <= 0) {
			cin >> temporaryVarForSize;
			if (temporaryVarForSize <= 0)
				cerr << "Please Enter The Acceptable Array Size" << endl;
			else {
				cerr << "Array Size Accepted!" << endl;
			}
		}
		size = temporaryVarForSize;
	}
	return size;
}

// base class aqvs virtual funqcia
// moqmedebs sxvadasxva monacemta tipebze
// elementebis shetana gaketebulia operatorit, xolo gamotana funqciit

// 1 ganzomilebiani vectori
template <class dataType>
class OneDimensionalVector {
protected:
	unsigned int size;
	dataType* vector1D;

	void setVectorSize(unsigned int size) {
		this->size = sizeSetterForArrays(size);
		allocate1DVector();
	}
	void allocate1DVector() {
		vector1D = new dataType[size];
		for (unsigned int i = 0; i < size; i++) {
			vector1D[i] = dataType();
		}
	}
public:
	OneDimensionalVector() {
		setVectorSize(1);
	}
	OneDimensionalVector(unsigned int size) {
		setVectorSize(size);
	}

	unsigned int getVectorSize() {
		return size;
	}
	virtual void print() {
		for (unsigned int i = 0; i < size - 1; i++) {
			cout << vector1D[i] << " ";
		}
		cout << vector1D[size - 1];
	}
	template <class input>
	friend istream& operator>>(istream& is, OneDimensionalVector<input>& temporaryObject);
};

template <class dataType>
istream& operator>>(istream& is, OneDimensionalVector<dataType>& temporaryObject) {
	for (unsigned int i = 0; i < temporaryObject.getVectorSize(); i++) {
		is >> temporaryObject.vector1D[i];
	}
	return is;
}


// 2 ganzomilebiani vectori
template <class dataType>
class TwoDimensionalVector : public OneDimensionalVector<dataType> {
protected:
	unsigned int verticalSize;
	dataType** vector2D;

	void setVectorSize(unsigned int verticalSize) {
		this->verticalSize = sizeSetterForArrays(verticalSize);
		allocate2DVector();
	}
	void allocate2DVector() {
		vector2D = new dataType*[this->size];
		for (unsigned int i = 0; i < this->size; i++) {
			vector2D[i] = new dataType[verticalSize];
		}
	}

public:
	TwoDimensionalVector() : OneDimensionalVector<dataType>() {
		setVectorSize(1);
	}
	TwoDimensionalVector(unsigned int size, unsigned int verticalSize) : OneDimensionalVector<dataType>(size) {
		setVectorSize(verticalSize);
	}

	unsigned int getVerticalSize() {
		return verticalSize;
	}
	void print() {
		for (unsigned int i = 0; i < this->getVectorSize(); i++) {
			for (unsigned int j = 0; j < verticalSize - 1; j++) {
				cout << vector2D[i][j] << " ";
			}
			cout << vector2D[i][verticalSize - 1] << endl;
		}
	}
	template <class input>
	friend istream& operator>>(istream& is, TwoDimensionalVector<input>& temporaryObject);
};

template <class dataType>
istream& operator>>(istream& is, TwoDimensionalVector<dataType>& temporaryObject) {
	for (unsigned int i = 0; i < temporaryObject.getVectorSize(); i++) {
		for (unsigned int j = 0; j < temporaryObject.getVerticalSize(); j++) {
			is >> temporaryObject.vector2D[i][j];
		}
	}
	return is;
}



// 3 ganzomilebiani vectori
template <class dataType>
class ThreeDimensionalVector: public TwoDimensionalVector<dataType> {
protected:
	unsigned int numberOfMatrixes;
	dataType*** vector3D;

	void setVectorSize(unsigned int numberOfMatrixes) {
		this->numberOfMatrixes = sizeSetterForArrays(numberOfMatrixes);
		allocate3DVector();
	}
	void allocate3DVector() {
		vector3D = new dataType **[this -> size];
		for (unsigned int i = 0; i < this -> size; i++) {
			vector3D[i] = new dataType*[this -> verticalSize];
			for (unsigned int j = 0; j < this -> verticalSize; j++) {
				vector3D[i][j] = new dataType[numberOfMatrixes];
			}
		}
	}
public:
	ThreeDimensionalVector() :TwoDimensionalVector<dataType>() {
		setVectorSize(1);
	}
	ThreeDimensionalVector(unsigned int size, unsigned int verticalSize, unsigned int numberOfMatrixes) : TwoDimensionalVector<dataType>(size, verticalSize) {
		setVectorSize(numberOfMatrixes);
	}

	unsigned int getNumberOfMatrixes() {
		return numberOfMatrixes;
	}
	void print() {
		for (unsigned int i = 0; i < numberOfMatrixes; i++) {
			cout << "Matrix " << i + 1 << ":" << endl;
			for (unsigned int j = 0; j < this->getVectorSize(); j++) {
				cout << "[";
				for (unsigned int k =0; k < this->getVerticalSize(); k++) {
					cout << vector3D[j][k][i];
					if (k < this->getVerticalSize() - 1) {
						cout << ", ";
					}
				}
				cout << "]" << endl;
			}
			cout << endl;
		}
	}
	template <class input>
	friend istream& operator>>(istream& is, ThreeDimensionalVector<input>& temporaryObject);
};

template <class dataType>
istream& operator>>(istream& is, ThreeDimensionalVector<dataType>& temporaryObject) {
	for (unsigned int i = 0; i < temporaryObject.getNumberOfMatrixes(); i++) {
		cout << "Enter Matrix " << i + 1 << ":" << endl;
		for (unsigned int j = 0; j < temporaryObject.getVectorSize(); j++) {
			for (unsigned int k = 0; k < temporaryObject.getVerticalSize(); k++) {
				is >> temporaryObject.vector3D[j][k][i];
			}
		}
		cout << endl;
	}
	return is;
}

int main() {
	ThreeDimensionalVector<double> tmp = ThreeDimensionalVector<double>(3, 2, 2);
	cin >> tmp;
	tmp.print();
	return 0;
}