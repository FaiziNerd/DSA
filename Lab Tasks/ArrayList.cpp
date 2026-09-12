#include <iostream>
using namespace std;

int* InsertionAtEnd(int* arr, int n, int val)
{
    int* arr1 = new int[n + 1];

    for(int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
    }

    arr1[n] = val;

    delete[] arr;
    return arr1;
}


int* InsertionAtStart(int* arr, int n, int val)
{
    int* arr1 = new int[n + 1];

    for(int i = 0; i < n; i++)
    {
        arr1[i + 1] = arr[i]; 
    }

    arr1[0] = val;

    delete[] arr;
    return arr1;
}

int LinearSearch(int* arr, int n, int target)
{
    int i = 0;
    while(i < n)
    {
        if(arr[i] == target)
        {
            return i; 
        }
        i++;
    }
    return -1; 
}

int* InsertionAfterSpecificValue(int* arr, int n, int val, int target)
{
    int index = LinearSearch(arr, n, target);
    if(index == -1)
    {
        cout << "Target value not found!" << endl;
        return arr;
    }

    int* arr1 = new int[n + 1];

    for(int i = 0; i <= index; i++)
    {
        arr1[i] = arr[i];
    }

    arr1[index + 1] = val;

    for(int i = index + 1; i < n; i++)
    {
        arr1[i + 1] = arr[i];
    }

    delete[] arr;
    return arr1;
}


int* InsertionBeforeSpecificValue(int* arr, int n, int val, int target)
{
    int index = LinearSearch(arr, n, target);
    if(index == -1)
    {
        cout << "Target value not found!" << endl;
        return arr;
    }

    int* arr1 = new int[n + 1];

    for(int i = 0; i < index; i++)
    {
        arr1[i] = arr[i];
    }

    arr1[index] = val;

    for(int i = index; i < n; i++)
    {
        arr1[i + 1] = arr[i];
    }

    delete[] arr;
    return arr1;
}


void PrintArrayList(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int* DeleteFromEnd(int* arr, int n)
{
    int* arr1 = new int[n - 1];

    for(int i = 0; i < n - 1; i++)
    {
        arr1[i] = arr[i];
    }

    delete[] arr;
    return arr1;
}

int* DeleteFromStart(int* arr, int n)
{
    int* arr1 = new int[n - 1];

    for(int i = 0; i < n - 1; i++)
    {
        arr1[i] = arr[i + 1];
    }

    delete[] arr;
    return arr1;
}


int* DeleteSpecificValue(int* arr, int n, int target)
{
    int index = LinearSearch(arr, n, target);
    if(index == -1)
    {
        cout << "Value not found!" << endl;
        return arr;
    }

    int* arr1 = new int[n - 1];

    for(int i = 0; i < index; i++)
    {
        arr1[i] = arr[i]; 
    }

    for(int i = index + 1; i < n; i++)
    {
        arr1[i - 1] = arr[i];
    }

    delete[] arr;
    return arr1;
}

int main()
{
    int size;
    int value;
    int target;

    cout << "Enter the size of the ArrayList: ";
    cin >> size;

    int* ArrayList = new int[size];

    cout << "Enter the values: ";
    for(int i = 0; i < size; i++)
    {
        cin >> ArrayList[i];
    }

    cout << "Enter the value you want to insert: ";
    cin >> value;

    
    ArrayList = InsertionAtEnd(ArrayList, size, value);
    size++;

    
    ArrayList = InsertionAtStart(ArrayList, size, value);
    size++;

    cout << "Enter target value to insert AFTER: ";
    cin >> target;
    
    ArrayList = InsertionAfterSpecificValue(ArrayList, size, value, target);
    size++;

    cout << "Enter target value to insert BEFORE: ";
    cin >> target;

    ArrayList = InsertionBeforeSpecificValue(ArrayList, size, value, target);
    size++;

    
    ArrayList = DeleteFromEnd(ArrayList, size);
    size--;

       
    ArrayList = DeleteFromStart(ArrayList, size);
    size--;

    cout << "Enter specific value to DELETE: ";
    cin >> target;
    
    ArrayList = DeleteSpecificValue(ArrayList, size, target);
    size--;

    
    cout << "Final Array List: ";
    PrintArrayList(ArrayList, size);

    delete[] ArrayList;

    return 0;
}