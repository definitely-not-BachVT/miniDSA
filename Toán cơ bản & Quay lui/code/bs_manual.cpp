#include <iostream>
#include <vector>

using namespace std;

int manualBinarySearch(const vector<int> &arr, int target)
{
     int left = 0;
     int right = arr.size() - 1;

     while (left <= right)
     {
          int mid = left + (right - left) / 2;

          if (arr[mid] == target)
               return mid;

          else if (arr[mid] < target)
               left = mid + 1;
          else
               right = mid - 1;
     }

     return -1;
}

int main()
{
     vector<int> arr = {10, 25, 32, 45, 50, 68, 77, 89, 95};
     int target = 68;

     int result = manualBinarySearch(arr, target);

     if (result != -1)
          cout << "Tim thay " << target << " tai chi so: " << result << endl;
     else
          cout << "Khong tim thay " << target << " trong mang." << endl;

     return 0;
}