#include <bits/stdc++.h>

using namespace std;
struct Item{
    int value;
    int weight;
};

// true -> no swap
//false -> swap

bool cmp(Item &a, Item &b)
{
    double  w1 = (double) a.value / (double) a.weight;
    double  w2 = (double) b.value / (double) b.weight;
    return (w1 > w2);
}
double fractionalKnapsack(Item *arr, int w, int n)
{// O(n log n + n) n is number of items
    sort(arr, arr+n, cmp);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; ++i) {
        if(curWeight + arr[i].weight <= w)
        {
            curWeight +=  arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = w - curWeight;
            finalValue += (arr[i].value / (double) arr[i].weight) *((double) remain);
            break;
        }
    }
    return finalValue;
}
int main() {
    int n;
    int w;
    int val;
    int wt;
    double ans;
    cin>>n;
    cin>>w;
    Item arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>val>>wt;
        arr[i].value = val;
        arr[i].weight = wt;
    }
    ans = fractionalKnapsack(arr,w,n);
    cout<<ans<<endl;


    return 0;
}
