#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1,4,6,9, 15, 15, 15};
    int left = 0;
    int right = 6;
    int target = 15;

    while (left <= right) {
        int mid = (left+right) / 2;
        cout << left << right << mid << " ";
        if (a[mid]==target) {
            cout << mid << endl;
            break;
        }
        if (a[mid] < target) {
            left = mid+1;
        }
        else {
            right = mid - 1;
        }
    }
}