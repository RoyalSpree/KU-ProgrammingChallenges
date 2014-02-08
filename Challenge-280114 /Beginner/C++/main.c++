/**
@file main.c++
@author Kaleb Goering */

#include <iostream>

using namespace std;

int main () {
	int n, k;
	int* array;
	
	//Takes user input
	cout << "How big is your array?" << endl;
	cin >> n;
	array = new int[n];
	cout << "Now please input your array." << endl;
	for(int i = 0; i < n; i++) {
		cin >> array[i];
	}
	cout << "How big is your block for rotation?" << endl;
	cin >> k;

	//Reverses the array
	int newArray[n];
	for(int i = 0; i < n; i += k) {
		if((i + k) >= n) {
			k = n - i;
		}
		for(int j = 0; j < k; j++) {
			newArray[i + j] = array[i + k - j - 1];
		}
	}
	//Puts it back into the proper array
	for(int i = 0; i < n; i++) {
		array[i] = newArray[i];
	}
	

	cout << "Your new array: " << endl;
	for(int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;	
}

