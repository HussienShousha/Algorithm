#include <bits/stdc++.h>


using namespace std;
struct Interval{
    int start;
    int End;
    Interval(int s,int e)
    {
        start = s;
        End = e;
    }
    Interval()
    {
        start = 0;
        End = 0;
    }
};
// if true -> no swap
//if false -> swap
bool cmp(const Interval &a, const Interval &b)
{
    return a.End < b.End;
}
int intervalScheduling(Interval *intervals, int n)
{ // sorting -> O(n log n) n is number of activities
  // iterating -> O(n)
  // total: O(n log n)
    sort(intervals+1 ,intervals+n+1, cmp);


    int cnt = 0;
    int lastEndTime = -1;
    for (int i = 1; i <= n; ++i) {
        if(intervals[i].start >= lastEndTime)
        {
            cnt++;
            lastEndTime = intervals[i].End;
        }
    }
    return cnt;
}
int main() {
    int n;
    int start;
    int End;
    cin>>n;
    Interval interval[n];
    for (int i = 1; i <= n ; ++i) {
        cin>>start>>End;
        interval[i] = Interval(start,End);
    }
    int maxNumberOfActivity  = intervalScheduling(interval,n);
    cout<<maxNumberOfActivity<<endl;


    return 0;
}
