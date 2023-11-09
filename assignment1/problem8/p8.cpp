#include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <vector>
// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, k, j;
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}
void binaryinsertionsort(int a[],int n){
        int i, loc, j, k, selected;

        for (i = 1; i < n; ++i) {
            j = i - 1;
            selected = a[i];

            // find location where selected should be inseretd
            int l=0,r=j;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (selected == a[mid]) {
                    l = mid + 1;
                    break;
                }
                else if (selected > a[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            loc = l;
            // Move all elements after location to create space
            while (j >= loc) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = selected;
        }

}
using namespace std;
using namespace std::chrono;
int main() {
    int sizes[21];
    int sz=500;
    for (int i = 0; i <21 ; ++i) {
        sizes[i]=sz;
        sz+=500;
    }
    cout<<"insertion sort\n";
    for (int i = 0; i < 21; ++i) {
        int n=sizes[i];
        int arr[n];
        for (int i = 0; i < n; ++i) {
           arr[i]=  (rand() % 10000);
        }
        auto start = high_resolution_clock::now();
        insertionSort(arr,n);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        cout << duration.count() << "\n";
    }

    cout<<"binary insertion sort\n";
    for (int i = 0; i < 21; ++i) {
        int n=sizes[i];
        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i]=  (rand() % 10000);
        }
        auto start = high_resolution_clock::now();
        binaryinsertionsort(arr,n);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        cout << duration.count() << "\n";
    }
    return 0;
}
