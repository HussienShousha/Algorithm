#include <bits/stdc++.h>
using namespace std;
struct DisjointSet{
    int *rank;
    int *parent;
    int *size;
    int n;
    void Initialize(int _n)
    {
        n = _n+1;
        rank = new int[n];
        parent = new int[n];
        size = new int [n];
        for (int i = 0; i <=n; ++i) {
            rank[i] = 0;
            parent[i] = i;
            size[i] = 1;
        }
    }
    void Destroy()
    {
        delete [] rank;
        delete [] parent;
        n = 0;
    }
    int Find(int i)
    {
        if(i == parent[i])
        {
            return i;
        }
        return parent[i] = Find(parent[i]);

    }
    bool UnionByRank(int i, int j)
    {
        int ultimate_parent_i = Find(i);
        int ultimate_parent_j = Find(j);
        if(ultimate_parent_i == ultimate_parent_j)
        {
            return true;
        }
        if(rank[ultimate_parent_i] < rank[ultimate_parent_j])
        {
            parent[ultimate_parent_i] = ultimate_parent_j;

        }
        else if(rank[ultimate_parent_i] > rank[ultimate_parent_j])
        {
            parent[ultimate_parent_j] = ultimate_parent_i;
        }
        else
        {
            parent[ultimate_parent_j] = ultimate_parent_i;
            rank[ultimate_parent_i]++;
        }
        return false;



    }
    bool UnionBySize(int i,int j)
    {
        int ultimate_parent_i = Find(i);
        int ultimate_parent_j = Find(j);
        if(ultimate_parent_i == ultimate_parent_j)
        {
            return true;
        }
        if(size[ultimate_parent_i] < size[ultimate_parent_j])
        {
            parent[ultimate_parent_i] = ultimate_parent_j;
            size[ultimate_parent_j]+=size[ultimate_parent_i];

        }
        else if(size[ultimate_parent_i] >= size[ultimate_parent_j])
        {
            parent[ultimate_parent_j] = ultimate_parent_i;
            size[ultimate_parent_i]+=size[ultimate_parent_j];

        }

        return false;

    }

};
int main() {
    DisjointSet ds;
    ds.Initialize(7);
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);

    if(ds.Find(3) == ds.Find(7))
    {
        cout<<"Same 1\n";
    }
    else
    {
        cout<<"Not same 1\n";
    }

    ds.UnionByRank(3, 7);
    if(ds.Find(3) == ds.Find(7))
    {
        cout<<"Same 2\n";
    }
    else
    {
        cout<<"Not same 2\n";
    }
    for (int i = 0; i <= 7; ++i) {
        cout<<ds.size[i]<<" ";
    }
    ds.Destroy();


    return 0;
}
