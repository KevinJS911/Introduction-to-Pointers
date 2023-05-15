#include <iostream>

using namespace std;

int& maxN(int& a, int& b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main(int argc, const char * argv[]) {
	int anInt = 0;
	float aFloat = 0.0;
	double aDouble = 0.0;
	
	//Finding sizes of  constants

	cout << "Memory bricks" << endl
	<<"int: " << sizeof(anInt) << endl //4
	 << "float: " << sizeof(aFloat) << endl //4
	 << "double: " << sizeof(aDouble) << endl; //8

	//Find address of the variables
	cout.setf(ios::hex);
	cout.unsetf(ios::dec);

	cout << "Address of, " << endl
	 << "int: " << &anInt <<endl
	 << "float: " << &aFloat << endl
	 << "double: " << &aDouble << endl;

	int* pInt = &anInt; // points to address of anInt variable
	float* pFloat = &aFloat; // points to address of aFloat variable
	double* pDouble = &aDouble; // points to address of aDouble variable
	cout << pInt << endl << pFloat << endl << pDouble << endl; // all of them 8 bytes long

	cout.setf(ios::dec);
	cout.unsetf(ios::hex);
	int anInt2 = 42;
	cout << "anInt2: "<<anInt2 << endl;
	//Calling by reference
	int& refanInt2 = anInt2;
	cout << "refanInt2: " << refanInt2 << endl;

		//Changing value
	anInt2 *= 3;
	cout << "anInt2: " << anInt2 << endl;
	cout << "refanInt2: " << refanInt2 << endl;

		//Changing value
	refanInt2 *= 3;
	cout << "anInt2: " << anInt2 << endl;
	cout << "refanInt2: " << refanInt2 << endl;

	// Why use references? -> Faster to pass through references in functions, subroutines
	//					   -> Passing arguments as references change the original variable
					//But passing by value creates copies (original variable stays constant)
	int a = 42;
	int b = 43;
	cout << "a: " << a << ", b:" << b << endl;
	//Best way to call functions (create references)
	maxN(a, b) = 99;
	cout << "a: " << a << ", b:" << b << endl;

	return 0;
}