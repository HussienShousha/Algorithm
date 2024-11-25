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
    void Move_Up(int idx)
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
template<class T>
struct Array {
    int n, sz;
    T* arr;
    int Index_Points_To_Last_Elem;
    void Initialize(int _n) {
        n = _n;
        sz = 0;
        arr = new T[n];
        Index_Points_To_Last_Elem = -1;
    }
    void Destroy() {
        delete[] arr;
        n = 0;
        sz = 0;
        Index_Points_To_Last_Elem = -1;
    }
    void AddLast(T v) {
        if (Index_Points_To_Last_Elem + 1 == n) {
            int Temp_Size = n;
            T* Temp_Array = new T[n];
            for (int i = 0; i < n; ++i) {
                Temp_Array[i] = arr[i];
            }
            delete[] arr;
            n *= 2;
            arr = new T[n];
            for (int i = 0; i < Temp_Size; ++i) {
                arr[i] = Temp_Array[i];
            }
            delete[] Temp_Array;
        }
        arr[++Index_Points_To_Last_Elem] = v;
        sz++;
    }
    T& operator[](int i) {
        return arr[i];
    }
};

struct Edge {
    int w;
    int v;
};

struct Node {
    Array<Edge> adj;
    void Initialize(int _n) { adj.Initialize(_n); }
    void Destroy() { adj.Destroy(); }
};

struct Graph {
    int n;
    Node* nodes;
    void Initialize(int _n) {
        n = _n;
        nodes = new Node[n];
        for (int i = 0; i < n; ++i) nodes[i].Initialize(n);
    }
    void Destroy() {
        for (int i = 0; i < n; ++i) nodes[i].Destroy();
        delete[] nodes;
    }
};
void Dijkstra(int src, int n, Graph graph,int* distance)
{
    //<weight,node>
    Heap<pair<int,int>> heap;
    heap.Initialize(MIN_HEAP,n);
    heap.Add({0,src});
    distance[src] = 0;
    while (0 < heap.size_of_Heap())
    {
        pair<int,int> top = heap.Retrieve_First();
        int weight = top.first;
        int node = top.second;

        for (int i = 0; i < graph.nodes[node].adj.sz; ++i)
        {
            int edgeWeight = graph.nodes[node].adj[i].w;
            int adjNode = graph.nodes[node].adj[i].v;

            if (weight + edgeWeight< distance[adjNode])
            {
                distance[adjNode] = weight + edgeWeight;
                heap.Add({distance[adjNode], adjNode});
            }
        }
    }

}

int main()
{
    Hussien_Ahmed_20226035
    int n;
    int m;
    int x;
    int y;
    int weight;
    int src;
    Graph graph;
    cin>>n>>m;
    graph.Initialize(n);
    int distance[n];
    for (int i = 0; i < n; ++i)
    {
        distance[i] = INT_MAX;
    }

    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>weight;
        graph.nodes[x].adj.AddLast({weight,y});
        graph.nodes[y].adj.AddLast({weight,x});

    }
    cin>>src;
    Dijkstra(src,n,graph,distance);//O(E log V)
    for (int i = 0; i < n; ++i)
    {
        cout<<"Shortest Path from "<<src<<" to node -> "<<i<<" is "<<distance[i]<<endl;
    }






    return 0;
}
