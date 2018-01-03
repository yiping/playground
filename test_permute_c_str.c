
#include <iostream>
#include <string.h>

using namespace std;

int count = 0;

void swap(char arr[], int a, int b)
{
    char tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void permute(char arr[], int leftId, int rightId)
{
    if (leftId < rightId)
    {
        for (int k=leftId; k <= rightId; k ++ )
        {
            swap(arr, leftId, k);
            permute(arr, leftId + 1, rightId);
            swap(arr, leftId, k);
        }
    }
    else
    {
        count ++;
        cout<< "["<<count <<"]" <<arr <<endl;
    }
}

int main()
{
    cout<<"Hello World"<<endl;
    cout << "------"<<endl;

    // each test C string has no duplicates
    
    //char x[] = {'h', 'e'};
    //cout << strlen(x)<<endl;
    
    char a[] = "abc";
    int al = strlen(a);
    
    char b[] = "ctag";
    int bl = strlen(b);
    
    char c[] = "mathworks";
    int cl = 9;
    
    //for (int i= 0; i < al; i++)
    //    cout << a[i] <<" ";
    //cout << endl;
    
    count = 0;
    cout << a <<endl;
    cout<<"---------"<<endl;
    permute(a, 0, al - 1);
    
    count = 0;
    cout << "--------"<<endl;
    permute(b, 0, bl - 1);
    
    count = 0;
    cout << "--------"<<endl;
    permute(c, 0, cl - 1);
    return 0;    
}