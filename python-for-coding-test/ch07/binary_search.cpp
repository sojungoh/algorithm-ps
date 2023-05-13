#include <iostream>
#include <algorithm>

using namespace std;

int binary_search_recur(int * arr, int target, int start, int end) {
	if(start > end)
		return -1;
	
	int mid = (start + end) / 2;
	
	if(arr[mid] == target)
		return mid;
	else if(arr[mid] > target)
		return binary_search_recur(arr, target, start, mid - 1);
	else
		return binary_search_recur(arr, target, mid + 1, end); 
}

int binary_search_iter(int * arr, int target, int start, int end) {
	
	while(start <= end) {
		
		int mid = (start + end) / 2;
		
		if(arr[mid] == target)
			return mid;
		
		if(arr[mid] > target)
			end = mid - 1;
		else if(arr[mid] < target)
			start = mid + 1;
	}
	
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cout << "Input a number you want to find: ";
	cin >> n;
	
	int arr[10] = {3, 19, 48, 4, 58, 22, 20, 8, 35, 50};
	
	sort(arr, arr + 10);
	
	cout << binary_search_recur(arr, n, 0, 9) << '\n';
	cout << binary_search_iter(arr, n, 0, 9) << '\n';
	
	return 0;
}
