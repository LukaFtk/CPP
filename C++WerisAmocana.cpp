#include <iostream>
#include <fstream>
using namespace std;

class Person {
protected:
	unsigned int ID;
	string name;
	string last_name;
	unsigned int birth_year;
	unsigned int gender;
	void set(unsigned int ID, string name, string last_name, unsigned int birth_year, unsigned int gender) {
		this->ID = ID; this->name = name; this->last_name = last_name; this->birth_year = birth_year; this->gender = gender;
	}
public:
	Person() {
		set(0, "saxeli", "gvari", 0, 0);
	}
	Person(unsigned int ID, string name, string last_name, unsigned int birth_year, unsigned int gender) {
		set(ID, name, last_name, birth_year, gender);
	}
	string getName() {
		return name;
	}
	string getLastName() {
		return last_name;
	}
	unsigned int getID() {
		return ID;
	}
	unsigned int getGender() {
		return gender;
	}
	unsigned int getBirthYear() {
		return birth_year;
	}
};

class Employer : public Person {
private:
	void set(string  position, unsigned int salary) {
		this->position = position;
		this->salary = salary;
	}
protected:
	string position;
	unsigned int salary;
public:
	Employer() : Person() {
		set("tanamdeboba", 0);
	}
	Employer(unsigned int ID, string name, string last_name, unsigned int birth_year, unsigned int gender, string  position, unsigned int salary):
	Person(ID, name, last_name, birth_year, gender)
	{
		set(position, salary);
	}
	
	string getPosition() {
		return position;
	}
	unsigned int getSalary() {
		return salary;
	}
};
void print(Employer& A) {
	cout << A.getID() << " " << A.getName() << " " << A.getLastName() << " " << A.getBirthYear() << " " << A.getGender() << " " << A.getPosition() << " " << A.getSalary() << endl;
}
void input(Employer* Arr) {
	int counter = 0;
	ifstream fin("D:\\faili1.txt");
	if (!fin.is_open()) {
		cerr << "Faili Ver Moidzebna!";
		exit(1);
	}
	unsigned int ID, birth_year, gender, salary;
	string name, last_name, position;
	while (fin >> ID >> name >> last_name >> birth_year >> gender >> position >> salary) {
		Employer tmp(ID, name, last_name, birth_year, gender, position, salary);
		Arr[counter] = tmp;
		counter++;
	}
}
void sortArr(Employer* Arr, unsigned int n) {
	for (int i = 0; i < n - 1; i++) {
		int t = i;
		for (int j = i + 1; j < n; j++) {
			if (Arr[j].getName()[0] < Arr[t].getName()[0]) {
				t = j;
			}
		}
		swap(Arr[i], Arr[t]);
	}
}
void deleteUser(Employer* Arr, unsigned int n, unsigned int ID) {
	int k = 0;  
	for (int i = 0; i < n; i++) { 
		if (Arr[i].getID() != ID) {
			Arr[k++] = Arr[i]; 
		}
	}
	while (k < n) { 
		Arr[k++] = Employer();
	}
}
void addUser(Employer* &Arr, Employer& user, unsigned int n) {
	Employer* tmpArr = new Employer[n + 1];
	for (int i = 0; i < n; i++) {
		tmpArr[i] = Arr[i];
	}
	tmpArr[n] = user;
	Arr = tmpArr;
}
void genderFilter(Employer* Arr, unsigned int n, unsigned int gender) {
	for (int i = 0; i < n; i++) {
		if (Arr[i].getGender() == gender) {
			print(Arr[i]);
			cout << endl;
		}
	}
}
void salaryFilter(Employer* Arr, unsigned int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		if (Arr[i].getSalary() > min && Arr[i].getSalary() < max) {
			print(Arr[i]);
			cout << endl;
		}
	}
}
int main() {
	Employer* arr = new Employer[4];
	for (int i = 0; i < 4; i++) {
		arr[i] = Employer();
	}
	input(arr);
	print(arr[2]);
	
	return 0;
}