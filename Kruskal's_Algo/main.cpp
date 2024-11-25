#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define Hussien_Ahmed_20226035 ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef enum
{
    MAX_HEAP,
    MIN_HEAP
}t_HEAP;
template<class T>
struct Heap
{
    T *Array;
    int size_of_array;
    int actual_size_of_array;
    int Index_Points_To_Last_Elem;
    t_HEAP MIN_OR_MAX;
    void Initialize(t_HEAP type, int First_Size)
    {

        MIN_OR_MAX = type;
        size_of_array = First_Size;
        Array = new T [size_of_array];
        for (int i = 0; i < size_of_array; ++i) {
            Array[i] = T();
        }
        Index_Points_To_Last_Elem = -1;
        actual_size_of_array = 0;

    }
    bool IsBeforeInt(int& a, int& b)
    {
        return a<b;
    }
    void Add(T New_Element)
    {
        if(Index_Points_To_Last_Elem + 1 == size_of_array)
        {
            int Temp_Size = size_of_array;
            T *Temp_Array = new T[size_of_array];
            for (int i = 0; i < size_of_array; ++i) {
                Temp_Array[i] = Array[i];
            }
            delete []Array;
            Array = NULL;
            size_of_array*=2;
            Array = new T[size_of_array];
            for (int i = 0; i < Temp_Size; ++i) {
                Array[i] = Temp_Array[i];
            }
            delete []Temp_Array;
            Temp_Array = NULL;
        }
        Array[++Index_Points_To_Last_Elem] = New_Element;
        actual_size_of_array++;
        Move_Up(Index_Points_To_Last_Elem);
    }
    void Move_Up( int idx)
    {
        int instance_of_parent = ((idx-1)/2);
        int Moving_idx = idx;

        if(MAX_HEAP==MIN_OR_MAX)
        {
            while ((0 != Moving_idx) && (Array[Moving_idx] >Array[instance_of_parent]))
            {
                swap(Array[Moving_idx], Array[instance_of_parent]);
                Moving_idx = instance_of_parent;
                instance_of_parent = ((instance_of_parent-1)/2);
            }
        }
        else if(MIN_HEAP == MIN_OR_MAX)
        {
            while ((0 != Moving_idx) && (Array[Moving_idx] < Array[instance_of_parent]))
            {
                swap(Array[Moving_idx], Array[instance_of_parent]);
                Moving_idx = instance_of_parent;
                instance_of_parent = ((instance_of_parent-1)/2);
            }
        }
    }
    T Get_First()
    {
        if(0 == actual_size_of_array)
        {
            return T();
        }
        else
        {
            return Array[0];
        }
    }
    T Retrieve_First()
    {
        T Top = Array[0];

        if(0 == actual_size_of_array)
        {
            return T();
        }
        else if(1 == actual_size_of_array)
        {
            actual_size_of_array--;
            Index_Points_To_Last_Elem--;
        }
        else if (2 == actual_size_of_array)
        {
            swap(Array[0],Array[1]);
            Index_Points_To_Last_Elem--;
            actual_size_of_array--;
        }
        else
        {
            swap(Array[0],Array[Index_Points_To_Last_Elem]);
            Index_Points_To_Last_Elem--;
            actual_size_of_array--;
        }
        Move_Down(0);
        return Top;


    }
    void Move_Down(int idx)
    {
        if((0 == actual_size_of_array) || (1 == actual_size_of_array))
        {
            return;
        }
        if(MAX_HEAP == MIN_OR_MAX)
        {
            if(2 == actual_size_of_array)
            {
                int instance_of_parent = idx;
                int Moving_idx_Left = (idx * 2) + 1;
                if(Array[instance_of_parent]<Array[Moving_idx_Left])
                {
                    swap(Array[instance_of_parent],Array[Moving_idx_Left]);
                }
            }
            else
            {
                unsigned int instance_of_parent = 0;
                unsigned int Moving_idx_Right = (instance_of_parent * 2) + 2;
                unsigned int Moving_idx_Left = (instance_of_parent * 2) + 1;
                while (instance_of_parent != actual_size_of_array)
                {
                    Moving_idx_Right = (instance_of_parent * 2) + 2;
                    Moving_idx_Left = (instance_of_parent * 2) + 1;

                    if((Moving_idx_Right < actual_size_of_array) &&(Moving_idx_Left < actual_size_of_array)&&(Array[Moving_idx_Right] >= Array[Moving_idx_Left]))
                    {
                        if(Array[instance_of_parent] < Array[Moving_idx_Right])
                        {
                            swap(Array[instance_of_parent] , Array[Moving_idx_Right]);
                            instance_of_parent = Moving_idx_Right;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if((Moving_idx_Right < actual_size_of_array) &&(Moving_idx_Left < actual_size_of_array)&&(Array[Moving_idx_Right] < Array[Moving_idx_Left]))
                    {
                        if(Array[instance_of_parent] < Array[Moving_idx_Left])
                        {
                            swap(Array[instance_of_parent] , Array[Moving_idx_Left]);
                            instance_of_parent = Moving_idx_Left;
                        }
                        else
                        {
                            break;
                        }

                    }


                    else if((Moving_idx_Left < actual_size_of_array) &&(Moving_idx_Right >= actual_size_of_array)&&(Array[instance_of_parent] < Array[Moving_idx_Left]))
                    {
                        swap(Array[instance_of_parent] , Array[Moving_idx_Left]);
                        instance_of_parent = Moving_idx_Left;

                    }
                    else
                    {
                        break;

                    }
                }

            }
        }
        else if(MIN_HEAP == MIN_OR_MAX)
        {


            if(2 == actual_size_of_array)
            {
                int instance_of_parent = idx;
                int Moving_idx_Left = (idx * 2) + 1;
                if(Array[instance_of_parent]>Array[Moving_idx_Left])
                {
                    swap(Array[instance_of_parent],Array[Moving_idx_Left]);
                }
            }
            else
            {
                unsigned int instance_of_parent = idx;
                unsigned int Moving_idx_Right = (instance_of_parent * 2) + 2;
                unsigned int Moving_idx_Left = (instance_of_parent * 2) + 1;
                while (instance_of_parent != actual_size_of_array)
                {
                    Moving_idx_Right = (instance_of_parent * 2) + 2;
                    Moving_idx_Left = (instance_of_parent * 2) + 1;

                    if((Moving_idx_Right < actual_size_of_array) &&(Moving_idx_Left < actual_size_of_array)&&(Array[Moving_idx_Right] <= Array[Moving_idx_Left]))
                    {
                        if(Array[instance_of_parent] > Array[Moving_idx_Right])
                        {
                            swap(Array[instance_of_parent] , Array[Moving_idx_Right]);
                            instance_of_parent = Moving_idx_Right;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if((Moving_idx_Right < actual_size_of_array) &&(Moving_idx_Left < actual_size_of_array)&&(Array[Moving_idx_Right] > Array[Moving_idx_Left]))
                    {
                        if(Array[instance_of_parent] > Array[Moving_idx_Left])
                        {
                            swap(Array[instance_of_parent] , Array[Moving_idx_Left]);
                            instance_of_parent = Moving_idx_Left;
                        }
                        else
                        {
                            break;
                        }

                    }


                    else if((Moving_idx_Left < actual_size_of_array) &&(Moving_idx_Right >= actual_size_of_array)&&(Array[instance_of_parent] > Array[Moving_idx_Left]))
                    {
                        swap(Array[instance_of_parent] , Array[Moving_idx_Left]);
                        instance_of_parent = Moving_idx_Left;

                    }
                    else
                    {
                        break;

                    }
                }

            }
        }

    }
    void Destroy()
    {
        delete []Array;
        Array = NULL;
        Index_Points_To_Last_Elem = -1;
        actual_size_of_array = size_of_array = 0;
    }
    T Right_child(int idx)
    {
        int Right = (idx*2)+2;
        if((0 != actual_size_of_array) && (idx < actual_size_of_array) && (1 != actual_size_of_array)&&(Right<actual_size_of_array))
        {
            return Array[Right];
        }
        else
        {
            return T();
        }
    }
    T Left_child(int idx)
    {
        int Left = (idx*2)+1;
        if((0 != actual_size_of_array) && (idx < actual_size_of_array) && (1 != actual_size_of_array) && (2 != actual_size_of_array)&&(Left<actual_size_of_array))
        {
            return Array[Left];
        }
        else
        {
            return T();
        }
    }
    T Parent(int idx)
    {
        if((0 != actual_size_of_array) && (idx < actual_size_of_array) && (1 != actual_size_of_array)&&(0 != idx))
        {
            return Array[((idx-1)/2)];
        }
        else
        {
            return T();
        }
    }
    int size_of_Heap()
    {
        return actual_size_of_array;
    }
    T& operator[](int i)
    {
        return Array[i];
    }


};
struct DisjointSet{
    int *rank;
    int *parent;
    int *size;
    int n;
    void Initialize(int _n)
    {
        n = _n;
        rank = new int[n];
        parent = new int[n];
        size = new int [n];
        for (int i = 0; i <n; ++i) {
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
int Min_Spanning_Tree(int v,vector<pair<int,int>> adj[])
{
    vector<pair<int,pair<int,int>>> edges;
    // time O(V+E)
    for (int i = 0; i < v; ++i) {
        for(auto it:adj[i])
        {
            int wt_edges = it.first;
            int node = i;
            int adjNode = it.second;
            edges.push_back({wt_edges,{node,adjNode}}); // it's bidirectional but, I use disjoint set it will be discarded
        }

    }
    Heap<pair<int,pair<int,int>>> heap;
    heap.Initialize(MIN_HEAP,edges.size());
    // imagine it x edges so o(X lg X)
    for (auto i : edges) {
        int wt_edges =i.first;
        int node = i.second.first;
        int adjNode = i.second.second;
        heap.Add({wt_edges,{node,adjNode}});
    }
    DisjointSet disjointSet;
    disjointSet.Initialize(v);
    int sum_of_weights = 0;
    // imagine it x edges so o( X * (4 * alpha ) * 2)
    while (heap.size_of_Heap() > 0){
        pair<int,pair<int,int>> i = heap.Retrieve_First();
        int wt_edges =i.first;
        int node = i.second.first;
        int adjNode = i.second.second;
        if(disjointSet.Find(node) != disjointSet.Find(adjNode))
        {
            sum_of_weights+=wt_edges;
            disjointSet.UnionBySize(node,adjNode);
        }
    }
    return sum_of_weights;

}

int main() {
    Hussien_Ahmed_20226035
    int n;
    int m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n]; // space is o(v+2E) is o(v+E)
    int u;
    int v;
    int cost;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v>>cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u}); // if directed graph this line is nothing so space complexity is o(E)
    }
    cout<<Min_Spanning_Tree(n,adj)<<endl;




    return 0;
}
