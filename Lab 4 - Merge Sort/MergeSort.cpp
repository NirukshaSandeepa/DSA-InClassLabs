#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std::chrono;

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];
}

void MergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    MergeSortRecursive(arr, left, mid);
    MergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void MergeSortIterative(vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}

int main() {
	cout<<"Total elements in array: ";
    //-----
	int n ;
    cin>>n;// Size of the vector
    vector<int> vec(n);
    random_device rd; // Obtain a random seed from the OS
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, 100000); // Set the range of random numbers to [1, 100]
    for (int i = 0; i < n; ++i) {
        vec[i] = distrib(gen); // Generate a random number and add it to the vector
    }
    //-----------------
    auto start = high_resolution_clock::now();
    MergeSortRecursive(vec, 0, vec.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for recursive: "<< duration.count() << endl;
	//-----
    auto start2 = high_resolution_clock::now();
    MergeSortIterative(vec);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken for iterative: "<< duration2.count() << endl;
    
    return 0;
}