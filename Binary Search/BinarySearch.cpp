#include <iostream>
#include <vector>
using namespace std;

class Solution
{
 public:

 int binarySearch(vector<int> &nums, int a)
 {
    int n = nums.size();
    int low = 0, high = nums.size() - 1;

    while( low <= high)
    {
        int mid = low + (high - low)/2 ;
        if(nums[mid] == a)
        {
            return mid;
        }
        else if( a > nums[mid])
        {
            low = mid + 1;
        }
        else 
         high = mid - 1;
    }

    return -1;
 }

};

int main ()
{
    vector<int> a = {3,4,5,6,7,8};
    int target = 6;
    Solution obj; 

    int ind = obj.binarySearch(a,target);
    if(ind == -1)
    {
        cout << "The target is not present" << endl;
    }
    else 
        cout << "The target is at index: " << ind << endl;

    return 0;
}