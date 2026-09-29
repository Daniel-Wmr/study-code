#include <iostream>
using namespace std;

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {5, 2, 8, 1};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Kleinstes Element im unsortierten Teil suchen
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Tauschen
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        printArray(arr, n);
    }

    return 0;
}