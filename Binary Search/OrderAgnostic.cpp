#include <iostream>
#include <vector>
using namespace std;


int orderAgnosticBinarySearch(vector<int> &arr, int r)
{
    int n = arr.size();
    int low = 0;
    int high = arr.size() - 1;
    bool isAscending = arr[low] <= arr[high];  // agar sare elements same hon lol 

    while(low <= high)
    {
        int mid = low + (high - low)/2 ;
        if( r == arr[mid])
        {
            return mid;
        }

        if(isAscending)
        {
            if( r > arr[mid])
            {
                low = mid + 1;
            }

            else 
                high = mid - 1;
        }

        else 

        if(r > arr[mid])
        {
            high = mid - 1;
        }

        else 
            low = mid + 1;
    }


    return -1;
}


int main()
{
    vector<int> ascArr = {2,5,8,12,16,23,38,56,72,91};
    vector<int> desArr = {91,72,56,38,23,16,12,5,2};
    int target = 23;


    cout << "Ascending Index: " << orderAgnosticBinarySearch(ascArr, target) << endl;
    cout << "Descending Index: " << orderAgnosticBinarySearch(desArr, target) << endl;
}

