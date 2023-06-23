#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

class AbstractData {
protected:
	unsigned int firstField;
	string secondField;
	unsigned int thirdField;
	void set(unsigned int firstField, string secondField, unsigned int thirdField) {
		setFirst(firstField); setSecond(secondField); setThird(thirdField);
	}
	void setFirst(unsigned int firstField) {
		this->firstField = firstField;
	}
	void setSecond(string secondField) {
		this->secondField = secondField;
	}
	void setThird(unsigned int thirdField) {
		this->thirdField = thirdField;
	}
public:
	AbstractData() : firstField(0), secondField(""), thirdField(0) {}
	AbstractData(unsigned int firstField, string secondField, unsigned int thirdField) {
		set(firstField, secondField, thirdField);
	}
	
	unsigned int getFirst() {
		return firstField;
	}
	string getSecond() {
		return secondField;
	}
	unsigned int getThird() {
		return thirdField;
	}
	virtual string toString() = 0;
};

class Products : public AbstractData {
public:
	Products():AbstractData(){}
	Products(unsigned int firstField, string secondField, unsigned int thirdField):AbstractData(firstField, secondField, thirdField){}
	
	string toString() {
		stringstream output;
		output << "Product Code: " << firstField << "\tName: " << secondField << "\tPrice: " << thirdField << endl;
		return output.str();
	}
};

class Supplier : public AbstractData {
public:
	Supplier() :AbstractData() {}
	Supplier(unsigned int firstField, string secondField, unsigned int thirdField) :AbstractData(firstField, secondField, thirdField) {}
	
	string toString() {
		stringstream output;
		output << "Supplier Code: " << firstField << "\tName: " << secondField << "\tProduct Price: " << thirdField << endl;
		return output.str();
	}
};

template <class T>
class ListOfProducts{
protected:
	T* data;
	unsigned int N;
	void setN(unsigned int N) {
		if (N == 0) {
			cerr << "Wrong Array Size!";
			exit(1);
		}
		this->N = N;
	}
	void create() {
		data = new T[N];
		for (int i = 0; i < N; i++) {
			data[i] = T();
		}
	}
public:
	ListOfProducts() {
		setN(1);
		create();
	}
	ListOfProducts(unsigned int N) {
		setN(N);
		create();
	}

	unsigned int getN() {
		return N;
	}
	string toString() {
		stringstream tmp;
		for (int i = 0; i < N; i++) {
			tmp << data[i].toString() << endl;
		}
		return tmp.str();
	}
	void setI(unsigned int I, T Property) {
		data[I] = Property;
	}
	T getI(unsigned int I) {
		return data[I];
	}

	template <class T1, class T2>
	friend void outputDataWithSupplierCode(ListOfProducts<T1> FirstData, ListOfProducts<T2> SecondData);
	
	template <class T1, class T2>
	friend unsigned int WholeValueBySupplier(ListOfProducts<T1> ProductData, T2 SupplierData);
};

template <class T>
ListOfProducts<T> inputData(string filename) {
	ifstream fin(filename.c_str());
	if (filename.empty()){
		cerr << "File Not Found!";
		exit(1);
	}
	unsigned int firstField;
	string secondField;
	unsigned int thirdField;
	int counter = 0;

	while (fin >> firstField >> secondField >> thirdField) {
		counter++;
	}
	fin.close();

	ListOfProducts<T> Arr = ListOfProducts<T>(counter);
	fin.open(filename.c_str());
	unsigned int index = 0;
	while (fin >> firstField >> secondField >> thirdField) {
		Arr.setI(index, T(firstField, secondField, thirdField));
		index++;
	}
	fin.close();
	return Arr;
}

template <class T>
void outputDataIntoFile(ListOfProducts<T> temporaryName, string filename) {
	ofstream fout(filename.c_str());
	fout << temporaryName.toString();
	fout.close();
}

template <class T1, class T2>
void outputDataWithSupplierCode(ListOfProducts<T1> ProductData, ListOfProducts<T2> SupplierData) {
	ofstream fout("D:\\OutputFileName.txt");
	if (ProductData.getN() != SupplierData.getN()) {
		cerr << "Wrong Sizes!!!!!!";
		exit(1);
	}

	for (int i = 0; i < SupplierData.getN(); i++) {
		bool Checker = false;
		unsigned int SumOfTotalValue = WholeValueBySupplier(ProductData, SupplierData.getI(i)); 
		
		if (SumOfTotalValue > 0) {
			fout << SupplierData.getI(i).toString();
			Checker = true;
		}

		for (int j = 0; j < ProductData.getN(); j++) {
			if (SupplierData.getI(i).getFirst() == ProductData.getI(j).getFirst()) {
				fout << ProductData.getI(j).toString();
			}
		}

		if (Checker) {
			fout << "Jamuri Girebuleba: " << SumOfTotalValue << endl;
			fout << endl;
		}
	}
	fout.close();
}

template <class T1, class T2>
unsigned int WholeValueBySupplier(ListOfProducts<T1> ProductData, T2 SupplierData) {
	unsigned int SumOfValue = 0;
	for (int j = 0; j < ProductData.getN(); j++) {
		if (SupplierData.getFirst() == ProductData.getI(j).getFirst()) {
			SumOfValue += ProductData.getI(j).getThird();
		}
	}
	return SumOfValue;
}

int main() {
	ListOfProducts<Products> Arr1 = inputData<Products>("D:\\Products.txt");
	ListOfProducts<Supplier> Arr2 = inputData<Supplier>("D:\\Supplier.txt");
	outputDataWithSupplierCode(Arr1, Arr2);
	return 0;
}