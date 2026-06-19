#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
     int i = left;
     int j = mid + 1;
     int k = left;
     long long inv_count = 0;

     while (i <= mid && j <= right)
     {
          if (arr[i] <= arr[j])
               temp[k++] = arr[i++];
          else
               temp[k++] = arr[j++];
          inv_count += (mid - i + 1);
     }

     while (i <= mid)
          temp[k++] = arr[i++];

     while (j <= right)
          temp[k++] = arr[j++];

     for (i = left; i <= right; i++)
          arr[i] = temp[i];

     return inv_count;
}

long long mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
     long long inv_count = 0;
     if (left < right)
     {
          int mid = left + (right - left) / 2;

          inv_count += mergeSortAndCount(arr, temp, left, mid);
          inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
          inv_count += mergeAndCount(arr, temp, left, mid, right);
     }
     return inv_count;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     int n;
     cin >> n;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
          cin >> arr[i];

     vector<int> temp(n);
     cout << mergeSortAndCount(arr, temp, 0, n - 1) << "\n";

     return 0;
}