#include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace std::chrono;

//function to swap elements by reference
void Swap_elements(int *x1, int *x2) {
    swap(x1, x2);
}

//class sorter to sort user's array
class sorter {
public:
    //polymorphism on function sort
    virtual void Sort(vector<int> array, int size) {
    }
};

// class selection sorter that  inherite form class sorter to sort the array using selection sort algo
class SelectionSorter : public sorter {
public:
    void Sort(vector<int> array, int size) {
        for (int i = 0; i < size - 1; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < size; ++j) {
                if (array[j] < array[min_idx]) {
                    min_idx = j;
                }
            }
            Swap_elements(&array[i], &array[min_idx]);
        }
    }
};

// class selection sorter that  inherite form clss sorter to sort the array using Quick sort algo(divide and conquer)
class QuickSorter : public sorter {
public:
    void quicksort(vector<int> arr, int low, int high) {
        if (low < high) {
            //take apivot to partition the array
            int pivot = arr[high];
            int i = (low - 1);
            for (int j = i + 1; j < high; ++j) {
                if (arr[j] < pivot) {
                    i++;
                    Swap_elements(&arr[j], &arr[i]);
                }
            }
            Swap_elements(&arr[high], &arr[i + 1]);
            int pi = i + 1;
            //call function quicksort to sort the part before the pivot
            quicksort(arr, low, pi - 1);
            //call function selection sort to sort the part after the pivot
            quicksort(arr, pi + 1, high);
        }
    }

    void Sort(vector<int> array, int size) {
        quicksort(array, 0, size - 1);
    }

};

class testbed {
private:
public:
    // generate a random list of integer numbers
    vector<int> GenerateRandomList(int Min, int Max, int size) {
        vector<int> v(size);
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            v.push_back(Min + (rand() % Max));
        }
        return v;
    }

    // generate a reversed random list of integer numbers
    vector<int> GenerateReverseOrderedList(int min, int max, int size) {
        vector<int> v(size);
        srand(time(nullptr));
        for (int i = 0; i < size; ++i) {
            v.push_back(min + (rand() % max));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        return v;
    }

    //function to return the time of a sort algo in microsecond
    long long RunOnce(sorter *s1, vector<int> data, int size) {
        auto start = high_resolution_clock::now();
        s1->Sort(data, size);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        return duration.count();
    }

    //calculate the average of a sorting algorithm's time
    long long RunAndAverage(sorter *s1, string type, int min, int max, int size, long long sets_num) {
        long long sum_time = 0;
        for (int i = 0; i < sets_num; ++i) {
            vector<int> arr(size);
            if (type == "sorted") {
                // if type is sorted
                arr = GenerateRandomList(min, max, size);
                s1->Sort(arr, size);
            } else if (type == "reversed") {
                // if type is reversed
                arr = GenerateReverseOrderedList(min, max, size);
            } else {
                // if type is random
                arr = GenerateRandomList(min, max, size);
            }
            sum_time += RunOnce(s1, arr, size);
        }
        long long res = (sum_time) / sets_num;
        return res;
    }

    // run an experient of a sorting algorithm
    void
    RunExperient(sorter *s1, string type, int min, int max, int min_val, int max_val, long long sets_num, int step) {
        cout << "set size" << setw(15) << "average time\n";
        for (int i = min_val; i <= max_val; i += step) {
            cout << i << setw(9) << RunAndAverage(s1, type, min, max, i, sets_num) << "\n";
        }
    }
};

int main() {
    testbed test1;
    sorter *sq = new QuickSorter;
    sorter *se = new SelectionSorter;
    cout << "Quick sort\n";
    // an experient to sort an random list on differnet sizes(from 500 to 10000) using Quick sort algo
    test1.RunExperient(sq, "random", 1, 100, 500, 10000, 1, 500);
    // an experient to sort an reversed list on differnet sizes(from 500 to 10000) using Quick sort algo
    test1.RunExperient(sq, "reversed", 1, 100, 500, 10000, 1, 500);
    cout << "\n";
    cout << "Selection sort\n";
    // an experient to sort a random list on differnet sizes(from 500 to 10000) using Selection sort algo
    test1.RunExperient(se, "random", 1, 100, 500, 10000, 1, 500);
    // an experient to sort a reversed list on differnet sizes(from 500 to 10000) using Selection sort algo
    test1.RunExperient(se, "reversed", 1, 100, 500, 10000, 1, 500);
    return 0;
}
