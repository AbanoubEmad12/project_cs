#include <iostream>
#include <stdexcept>
using namespace std;
#define size 10

class IndexOutOfBoundsException : public exception {
public:
	IndexOutOfBoundsException(const char* msg) : exception(msg) {

	}
};

class LowerBoundException : public IndexOutOfBoundsException {
public:
	LowerBoundException() : IndexOutOfBoundsException("index lower bound exception") {

	}
};
class UpperBoundException : public IndexOutOfBoundsException {
public:
UpperBoundException():IndexOutOfBoundsException("index upper bound exception") {

	}
};
class UninitializedException : public exception {
public:
	UninitializedException() : exception("uninitialized element exception") {

	}
};
class mylist {
private:
	int arr[size];
	bool initialized[size];
public:
	mylist() {
		for (int i = 0; i < size; i++) {
			initialized[i] = false;
		}
	}
	void setelement(int index, int value) {
		if (index < 0) {
			throw LowerBoundException();
		}
		else if (index >= size) {
			throw UpperBoundException();
		}
		else {
			arr[index] = value;
			initialized[index] = true;
		}
	}
	
	int getelement(int index) {
		if (index < 0) {
			throw LowerBoundException();
		}
		else if (index >= size) {
			throw UpperBoundException();
		}
		else if (initialized[index] == false) {
			throw UninitializedException();
		}
		else {
			return arr[index];
			
		}
	}
	void print() {
		for(int i=0;i<size;i++){
			if (initialized[i] == true) {
				cout << arr[i] << " ";
		}
			else {
				cout << "U ";
			}
		}
		
	}

};
int main() {
	try {
		mylist list;
		list.setelement(5, 100);
		list.setelement(1, 200);
		list.setelement(9, 500);
		list.print();
		int x = 0;

		while (!(x == -1)) {
			cout << "enter index";
			cin >> x;
			cout << list.getelement(x);
			cout << "\n";

		}
	}
	catch (LowerBoundException& e) {
		cout << "it is lower";
	}
	catch (UpperBoundException& e) {
		cout << "it is Upper";
	}
	catch (UninitializedException& e) {
		cout << "it is uninitialized";
	}
	cout << "the last line before return";
}