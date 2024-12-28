#include <iostream>
#include <vector>
using namespace std;

int maxElem(int x, int y, int z) {
	int answ = 0;
	if (x >= y) {
		if (x >= z) {
			answ = x;
		}
		else {
			answ = z;
		}
	}
	else {
		if (y >= z) {
			answ = y;
		}
		else {
			answ = z;
		}
	}
	return answ;
}

int minElem(int x, int y, int z) {
	int answ = 0;
	if (x < y) {
		if (x < z) {
			answ = x;
		}
		else {
			answ = z;
		}
	}
	else {
		if (y < z) {
			answ = y;
		}
		else {
			answ = z;
		}
	}
	return answ;
}

int main() {
	const int intMax = 2147483647;
	int num1, num2, num3, currRes;
	int minRes = intMax;
	vector<int> arr1, arr2, arr3;
	cin >> num1;
	arr1.resize(num1);
	for (int i = 0; i < num1; i++) {
		cin >> arr1[i];
	}
	cin >> num2;
	arr2.resize(num2);
	for (int i = 0; i < num2; i++) {
		cin >> arr2[i];
	}
	cin >> num3;
	arr3.resize(num3);
	for (int i = 0; i < num3; i++) {
		cin >> arr3[i];
	}
	vector<int> res(3);
	int i = 0, j = 0, k = 0;
	while (i < num1 && j < num2 && k < num3) {
		int maxEl = maxElem(arr1[i], arr2[j], arr3[k]);
		int minEl = minElem(arr1[i], arr2[j], arr3[k]);
		currRes = maxEl - minEl;
		if (currRes < minRes) {
			minRes = currRes;
			res[0] = arr1[i];
			res[1] = arr2[j];
			res[2] = arr3[k];
		}
		if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
			i++;
		}
		else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
			j++;
		}
		else {
			k++;
		}
	}
	cout << "Numbers = ";
	for (int elem : res) {
		cout << elem << " ";
	}
	cout << endl << "Result = " << minRes << endl;
	return 0;
}