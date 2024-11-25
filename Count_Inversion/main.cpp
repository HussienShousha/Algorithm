#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void merge(long long *arr, int low, int mid, int high) {
    vector<long long > temp;
    int left = low;
    int right = mid + 1;



    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            cnt += (mid - left +1);
            temp.push_back(arr[right]);
            right++;
        }
    }



    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }


    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(long long  *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}
int CountingInversion(long long *arr, int low, int high)
{
    mergeSort(arr,low,high);
    return cnt;
}

int main() {
    int n;
    cin>>n;
    long  long  arr[n];
    for (int i = 0; i < n; ++i)
    {
     cin>>arr[i];
    }
    cout << CountingInversion(arr, 0, n - 1) << endl;


    return 0 ;
}