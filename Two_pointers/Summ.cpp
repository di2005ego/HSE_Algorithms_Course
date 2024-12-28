#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num = 0, k = -1;
	int s = -1, f = -1, sum = 0, currSum = 0;
	vector<int> arr;
	cin >> num >> k;
	int len = num + 1;
	arr.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	if (num == 1) {
		if (arr[0] >= k) {
			cout << "Length = " << 1 << endl;
			cout << "Sum = " << arr[0] << endl;
			cout << "Start = " << 0 << endl;
			cout << "Finish = " << 0 << endl;
			exit(0);
		}
		else {
			cout << "No summ" << endl;
			exit(0);
		}
	}
	int p1 = 0;
	for (int p2 = 0; p2 < num; p2++) {
		currSum += arr[p2];
		while (currSum >= k) {
			int currLen = p2 - p1 + 1;
			if (currLen < len || (currSum > sum && currLen == len)) {
				len = currLen;
				sum = currSum;
				s = p1;
				f = p2;
			}
			currSum -= arr[p1];
			p1++;
		}
	}
	if (len == num + 1) {
		cout << "No summ" << endl;
	}
	else {
		cout << "Length = " << len << endl;
		cout << "Sum = " << sum << endl;
		cout << "Start = " << s << endl;
		cout << "Finish = " << f << endl;
	}
	return 0;
}