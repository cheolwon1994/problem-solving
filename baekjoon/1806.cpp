#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num, target;
	cin >> num >> target;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	int left = 0, right = 0, answer = num + 1;
	int sum = arr[0];

	while (left <= right) {
		if (sum >= target) {
			answer = min(answer, right - left + 1);
			if (left == right) {
				if (right == num - 1) break;
				right++;
				left++;
				sum = arr[right];
			}
			else {
				sum -= arr[left++];
			}
		}
		else {
			if (right == num - 1) break;
			sum += arr[++right];
		}
	}
	answer == num + 1 ? cout << 0 : cout << answer;
	return 0;
}