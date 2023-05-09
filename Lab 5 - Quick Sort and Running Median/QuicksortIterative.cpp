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

void quickSortIterative(int arr[], int l, int h)
{
    int stack[h - l + 1];
  
    int top = -1;
  
    stack[++top] = l;
    stack[++top] = h;
  
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
  

        int p = partition(arr, l, h);
  
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
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
    int arr[n];
     
    // Using copy() function
    // to copy elements
    copy(vec.begin(),vec.end(),arr);
    //-----------------

    auto start2 = high_resolution_clock::now();
    quickSortIterative(arr, 0, n - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken for iterative: "<< duration2.count() << endl;
    
    return 0;
}