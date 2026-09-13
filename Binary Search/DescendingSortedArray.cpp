#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:

    int BinarySearch(vector<int> &nums, int target)
    {
      int n = nums.size();
      int low = 0, high = nums.size() - 1;

      while( low <= high)
      {
        int mid = low + (high - low)/2 ;
        if(target == nums[mid])
        {
            return mid;
        }

        else if (target > nums[mid])
        {
          high = mid - 1;
        }
        else 
          low = mid + 1;
      }

      return -1;
    }
};


int main()
{
    vector<int> a = {20,17,15,14,13,12,10,9,8,4};
    int target = 4;
    Solution obj;

    int ind = obj.BinarySearch(a, target);
    if(ind == -1)
    {
        cout << "The target is not found" << endl;
    }

    else
        cout << "The target is at index: " << ind << endl;

    return 0;
}