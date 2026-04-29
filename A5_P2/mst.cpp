#include "mst.h"
#include "binaryHeap.h"       // Custom binary heap
#include "binomialHeap.h"   // Custom binomial heap
#include "customErrorClass.h"


// ===== QuickUnion =====
QuickUnion::QuickUnion(int n) 
{
    parent.resize(n);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
}

int QuickUnion::find(int x) 
{
    if(x > parent.size()-1)
        throw MyException("number not in union range");
    int tmp = x;
    while(parent[tmp] != tmp){
        tmp = parent[tmp];
    }
    return tmp;
}

void QuickUnion::Union(int x, int y)    // always make y a child of x
{
    parent[find(y)] = find(x);
}

// ===== UnionFind =====
UnionFind::UnionFind(int n) 
{
    parent.resize(n);
    rank.resize(n);

    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int UnionFind::find(int x) 
{
    if(x > parent.size()-1)
        throw MyException("number not in union range");
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void UnionFind::Union(int x, int y) 
{
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX == rootY) return;

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// ===== MST =====
MST::MST(int vertices)
{
    n = vertices;
}

void MST::addEdge(int u, int v, int weight) 
{
    edges.push_back({u, v, weight});
}

int MST::kruskalV1() 
{
    int totalWeight = 0;
    HEAP binaryHeap(edges.size());
    QuickUnion graph(edges.size());

    for(Edge e : edges){
        binaryHeap.insertH(e);
    }

    Edge tmp = binaryHeap.peek();
    while(tmp.weight != -1){
        if(graph.find(tmp.src) != graph.find(tmp.dest)){
            totalWeight += tmp.weight;
            graph.Union(tmp.src, tmp.dest);
        }

        binaryHeap.deleteMin();
        tmp = binaryHeap.peek();
    }

    return totalWeight;
}

int MST::kruskalV2() 
{
    int totalWeight = 0;
    BinomialHeap binoHeap;
    UnionFind graph(edges.size());

    for(Edge e : edges){
        binoHeap.insert(e);
    }

    Edge tmp = binoHeap.findMin();
    while(tmp.weight != -1){
        if(graph.find(tmp.src) != graph.find(tmp.dest)){
            totalWeight += tmp.weight;
            graph.Union(tmp.src, tmp.dest);
        }

        binoHeap.deleteMin();
        tmp = binoHeap.findMin();
    }

    return totalWeight;
}
