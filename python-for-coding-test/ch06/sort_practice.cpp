#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> origin) {
	
	vector<int> v = origin;
	
	for(int i = 0; i < v.size() - 1; ++i) {
		int min_idx = i;
		
		for(int j = i + 1; j < v.size(); ++j)
			if(v[j] < v[min_idx])
				min_idx = j;
			
		int temp = v[i];
		v[i] = v[min_idx];
		v[min_idx] = temp;
	}
	
	for(int num : v)
		cout << num << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<int> vec = {3, 39, 48, 10, 49, 12};
	
	selection_sort(vec);
	
	for(int num : vec)
		cout << num << ' ';
	cout << endl;
	
	return 0;
}
