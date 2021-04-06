#include <iostream>

using namespace std;

int change_val(int &p){
	p = 3;

	return 0;
}

int main(){
	int number;
	int arr[3] = {1, 2, 3};

	cout << arr[0] << arr[1] << arr[2] << endl;

	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	cout << arr[0] << arr[1] << arr[2] << endl;

	cin >> number;
}