// GROUP:   S6
// ID:      20226035
// Assign:  08
// Assign:  ClosetsPair
// UVA:     10245 (The Closest Pair Problem)
// Name:    Hussien Ahmed Abdel-Wahab Mohamed



#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define Hussien_Ahmed_20226035 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template<class Type>
void Merge(Type* a, int n, bool (*IsBefore)(Type& a, Type& b))
{
    int mid = n/2;
    int i = 0;
    int j = mid;
    int k = 0;
    Type* temp = new Type[n];
    while ((i < mid) and (j < n))
    {
        if(IsBefore(a[i],a[j]))
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];

        }
    }
    while ((i < mid))
    {
        temp[k++] = a[i++];
    }
    while ((j < n))
    {
        temp[k++] = a[j++];
    }
    for (int l = 0; l < n; ++l) {
        a[l] = temp[l];
    }
    delete [] temp;
}

template<class Type>
void MergeSort(Type* a, int n, bool (*IsBefore)(Type& a, Type& b))
{
    if(n <= 1)
    {
        return;
    }
    int mid = n/2;
    MergeSort(a, mid, IsBefore);
    MergeSort(a+mid, n-mid, IsBefore);
    Merge(a, n, IsBefore);
}
struct Point
{
    double x;
    double y;
};
// true -> not swap
// false -> swap
bool IsBeforeX(Point& a, Point& b)
{
    return a.x < b.x;
}
bool IsBeforeY(Point& a, Point& b)
{
    return a.y < b.y;
}
double dist(Point& a, Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double ClosestPair(Point* p, int n)
{
    if(n <= 1)
    {
        return 1e20;
    }
    if(n <= 2)
    {
        return dist(p[0],p[1]);
    }
    int mid = n/2;
    Point M = p[mid];
    double d1 = ClosestPair(p,mid);
    double d2 = ClosestPair(p+mid, n-mid);
    double  d = min(d1, d2);
    Point* slice = new Point[n];
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if(fabs(p[i].x - M.x) < d)
        {
            slice[idx++] = p[i];
        }
    }
    MergeSort(slice, idx, IsBeforeY);

    for (int i = 0; i < idx; ++i) {
        for (int j = i+1; j < idx and (slice[j].y - slice[i].y < d) ; ++j) {
            d = min(d, dist(slice[j] , slice[i]));
        }
    }

    return d;


}
int main()
{
    int n;
    int x;
    int y;
    double distance;
    while (cin>>n)
    {
        if(0 == n)
        {
            break;
        }
        Point* points = new Point[n];
        for (int i = 0; i < n; ++i) {
          cin>>x>>y;
          points[i].x = x;
          points[i].y = y;
        }
        MergeSort(points, n, IsBeforeX);
        distance = ClosestPair(points, n);
        if(distance >= 10000)
        {
            cout<<"INFINITY"<<endl;
            continue;
        }
        cout<<distance<<endl;

    }

    return 0;
}