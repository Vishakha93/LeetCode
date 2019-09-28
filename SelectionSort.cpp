#include <iostream>
#include <vector> 
using namespace std;

void selectionSort(vector<int>& arr) {
  //Find minimum in each iteration
	for(int i = 0; i < arr.size(); i++) {
		int jMin = i;
		for(int j = i + 1;  j < arr.size();  j++) {
			if(arr[j] < arr[jMin]) {
				jMin = j;
			}
		}
		if(jMin != i) {
			swap(arr[i], arr[jMin]);
		}
	}
}

int main() {
	vector<int> arr{3, 19, 5, 1, 23, 67};
	selectionSort(arr);

	for(int i = 0;  i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
