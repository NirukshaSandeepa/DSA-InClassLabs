#include <iostream>
#include <vector>

using namespace std;

void AddingElement(vector<int> &x, int n){
    if (x.size() == 0){
        x.push_back(n);
        return;
    }
    int indexNumber = 0;
    bool isChanged = false;

    for(int i=0;i<x.size();i++){
        if (n < x[i]){
            indexNumber=i;
            isChanged = true;
            break;
        }
    }
    if (! isChanged){
        x.push_back(n);
        return;
    }
    else{
        x.insert(x.begin()+indexNumber,n);
        return;
    }
    return;
}

float GettingMedian(vector<int> x){
    if (x.size()%2==1){
        return x[(x.size()-1)/2.0];
    }
    else{
        return ((x[x.size()/2]+x[(x.size()/2)-1])/2.0);
    }
}

int main(){

   int size;
   cout<<"Enter the size of array:";
   cin>>size;
   int arr[size];
   for(int i=0;i<size;i++)
      arr[i]=rand();
  
   cout<<"\nElements of the array:"<<endl;
   for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
   cout<<"\n\n";

    vector<int> x;

    for(int n : arr){

        AddingElement(x,n);
        for(int k : x){
            cout<<k<<" ";
        }
        cout<<"\n";
        cout << "Median is ";
        printf("%.2f",GettingMedian(x));
        cout<<"\n\n";
    }
    return 0;
}