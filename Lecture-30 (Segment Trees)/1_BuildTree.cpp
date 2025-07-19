#include <bits/stdc++.h>
using namespace std;
//              MIN RANGE QUERIES      
// find min element in range l to r
void buildtree(int *a, int *tree, int s, int e, int index){
    if(s==e){
        tree[index]=a[s];
        return;
    }
    int m=(s+e)/2;
    buildtree(a,tree,s, m,2*index);
    buildtree(a,tree,m+1,e,index*2+1);
    tree[index]=min(tree[index*2],tree[index*2+1]);
    return;

}
int query(int * tree, int ss, int se, int qs, int qe, int index){
    // case 1: complete overlap
    if(qs<=ss and qe>=se) return tree[index];

    // if no overlap
    if((qe<ss) or qs>se ) return INT_MAX;

    // Complex overlap
    int op1=INT_MAX, op2= INT_MAX;
    op1= query(tree,ss, (ss+se)/2, qs,qe, index*2);
    op2= query(tree,(ss+se)/2,se, qs,qe, index*2+1);
    return min(op1,op2);
}
int main() {
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);
    int *tree=new int[4*n +1];
    
    buildtree(a,tree,0,n-1,1);// 1 based indexing in tree;

    for(int i=0;i<4*n+1;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl<<"Query processing\n";
    cout<< query(tree, 0, n-1, 2, 4, 1);
    return 0;
}