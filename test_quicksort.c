#include <iostream>

using namespace std;

void swap(double arr[], int a, int b)
{
    double tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(double arr[], int arrLen, int leftId, int rightId)
{
    int pivotId = leftId;
    double pivot = arr[pivotId];

    for (int i = leftId + 1; i<=rightId; i++)
    {
        if (arr[i] < pivot)
        {
            //cout<<"advance pivot id"<<endl;
            pivotId ++;
            swap(arr, pivotId, i);
            
            //cout <<pivotId<<" "<< arr[pivotId] <<endl;
        }
    }
    swap(arr, pivotId, leftId);
    //cout <<pivotId<<" "<< arr[pivotId] <<endl;
    return pivotId;
    
}

int* quickSort(double arr[], int arrLen, int leftId, int rightId)
{
    cout << leftId <<" " << rightId <<endl;
    int pivotId = partition(arr, arrLen, leftId, rightId);
    
    if (leftId < pivotId)
    {
        quickSort(arr, arrLen, leftId, pivotId);
    }
    if (pivotId + 1 < rightId)
    {
        quickSort(arr, arrLen, pivotId + 1, rightId);
    }
}


int main()
{
    cout<<"Hello World"<<endl;

    //double a[] = {1, 2, 3, 5, -1, 0, -3, 5.5};
    //int ln = 8;
    
    double a[] = {10, -4, 2, 5, 8, 33, -5, 0, 2.3, 4.5, -5.9, 9, 22, 11, 3, 3, 3};
    int ln = 17;
    int p = partition(a, ln, 0, ln-1);
    cout << p <<endl;
    
    quickSort(a, ln, 0, ln-1);
    cout<<"---------"<<endl;
    for (int j = 0; j<ln; j++)
        cout << a[j] <<endl;
        
        
    
    return 0;
}

