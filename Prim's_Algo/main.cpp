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

int Prims(int v, vector<pair<int, int>> adj[])
{ // time -> E log E
    // space o(E) -> heap
    // <cost,<node,parent>>
    Heap<pair<int,pair<int,int>>> heap;
    heap.Initialize(MIN_HEAP,v);
    bool visited_array[v];
    pair<int,int> MST[v];
    int idx = 0;
    int sum_of_weight_edges = 0;
    heap.Add({0,{0,-1}});
    while (heap.size_of_Heap() > 0)
    {
        pair<int,pair<int,int>> top = heap.Retrieve_First();
        int node = top.second.first;
        int parent = top.second.second;
        int cost = top.first;
        if(!visited_array[node])
        {
            sum_of_weight_edges += cost;
            visited_array[node] = true;
            if(-1 != parent)
            {
                MST[idx++] = {node,parent};
            }
            for (int i = 0; i < adj[node].size(); ++i) {
                int neighbour = adj[node][i].second;
                if(!visited_array[neighbour])
                {
                    cost = adj[node][i].first;
                    heap.Add({cost,{neighbour,node}});
                }
            }
        }

    }
    return sum_of_weight_edges;


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
    cout << Prims(n, adj);



    return 0;
}
