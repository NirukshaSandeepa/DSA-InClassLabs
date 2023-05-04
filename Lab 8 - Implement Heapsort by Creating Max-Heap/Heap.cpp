#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{ 
int largest = root;
int left = 2 * root + 1;
int right = 2 * root + 2;

if (left < n && arr[left] > arr[largest])
    largest = left; // If left child is larger than root we can assign largest to left

if (right < n && arr[right] > arr[largest])
    largest = right; // If right child is larger than largest we can assign largest to right

if (largest != root) {
    swap(arr[root], arr[largest]); // If largest is not root swap the elements
    heapify(arr, n, largest); // Recursively call the heapify function
}
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
// Rearrange array (building heap)
for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

// Extract an element from heap one by one
for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]); // Move current root to end
    heapify(arr, i, 0); // call max heapify on the reduced heap
} 
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n\n";
}
  
// main program
int main() {
   cout<<"Input space separated integers"<<endl; // get the space separated integers as input
   string input;
   getline(cin, input); // read the entire line of input
   stringstream ss(input); // create a stringstream object
   vector<int> nums; // create a vector to store the integers
   int num;
   while (ss >> num) { // extract integers one by one
        nums.push_back(num); // add the integer to the vector
   }
   int* heap_arr = nums.data();
   int n = nums.size();
   cout<<"\nInput array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}