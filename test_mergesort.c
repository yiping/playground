

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


void merge(double arr[], int arrLen, int leftId, int midId, int rightId)
{
    int lp = leftId;
    int rp = midId + 1;
    
    double arrTmp[arrLen];
    
    int tmpId = leftId;
    while (lp <= midId && rp <= rightId)
    {
        if (arr[lp] < arr[rp])
        {
            arrTmp[tmpId] = arr[lp];
            lp ++;
            tmpId ++;
        }
        else
        {
            arrTmp[tmpId] = arr[rp];
            rp ++;
            tmpId ++;
        }
    }
    
    // take care of the rest
    if (rp > rightId)
    {
        for (int k=lp; k <= midId; k++)
        {
            arrTmp[tmpId] = arr[k];
            tmpId ++;
        }
    }
    
    if (lp > midId)
    {
        for (int k=rp; k <= rightId; k++)
        {
            arrTmp[tmpId] = arr[k];
            tmpId ++;
        }
    }
    
    //copy back
    for (int j = leftId; j<tmpId; j++)
            arr[j] = arrTmp[j];
    
}

void mergeSort(double arr[], int arrLen, int leftId, int rightId)
{
    int midId = (leftId + rightId)/2;
    
    if (rightId - leftId > 1)
    {
        //split
        
        mergeSort(arr, arrLen, leftId, midId);
        mergeSort(arr, arrLen, midId + 1, rightId);
    }    
    else
    {
        if (arr[leftId] > arr[rightId])
        {
            swap(arr, leftId, rightId);
        }
        return;
    }
    
    //merge
    merge(arr, arrLen, leftId, midId, rightId);
}

int main()
{
    cout<<"Hello World"<<endl;

    //double a[] = {1, 2, 3, 5, -1, 0, -3, 5.5};
    //int ln = 8;
    
    double a[] = {10, -4, 2, 5, 8, 33, -5, 0, 2.3, 4.5, -5.9, 9, 22, 11, 3, 3, 3};
    int ln = 17;
    
    //double a[] = {0, 3, 4, 1, 2, 5, 4};
    //int ln = 7;
    
    //double a[] = {0, 5, 2, 4};
    //int ln = 4;
    
    //merge(a, 6, 0, 2, 5);
    //merge(a, 4, 0, 1, 3);
    
    //int p = partition(a, ln, 0, ln-1);
    //cout << p <<endl;
    
    //quickSort(a, ln, 0, ln-1);
    mergeSort(a, ln, 0, ln-1);
    
    cout<<"---------"<<endl;
    for (int j = 0; j<ln; j++)
        cout << a[j] <<endl;
        
        
    
    return 0;
}


