#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std::chrono;

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  
void quickSortRecursive(int A[], int l, int h)
{
    if (l < h) {
        int p = partition(A, l, h);
        quickSortRecursive(A, l, p - 1);
        quickSortRecursive(A, p + 1, h);
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
    int arr[n];
     
    // Using copy() function
    // to copy elements
    copy(vec.begin(),vec.end(),arr);
    //-----------------

    auto start = high_resolution_clock::now();
    quickSortRecursive(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for recursive: "<< duration.count() << endl;
	//-----

    return 0;
}