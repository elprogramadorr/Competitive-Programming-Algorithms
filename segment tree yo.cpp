#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
///suma en rangos
///parent of tree[k] is tree[k/2]
///children of tree[k] are tree[2*k] and tree[2*k+1]
///tree[n+x]=v[x] indexeando el primero en 0
vi tree;
int n;
void add(int k,int x){
    k+=n;
    tree[k]+=x;
    k/=2;
    for(k;k>0;k/=2){
        tree[k]=tree[2*k]+tree[2*k+1];
        ///tree[k]+=x;
        ///igual funka con lo de arriba
    }
}
int query(int a,int b){
    a+=n;b+=n;
    int sum=0;
    while(a<=b){
        if(a%2==1){
            sum+=tree[a];
            a++;
        }
        if(b%2==0){
            sum+=tree[b];
            b--;
        }
        a/=2;
        b/=2;
    }
    return sum;
}
int main()
{
    cin>>n;
    int x;
    tree.assign(4*n,0);
    for(int i=0;i<n;i++){
        cin>>x;
        add(i,x);
    }
    /*for(int i=1;i<=15;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;*/
    int q,c,y;
    cin>>q;
    ///c-> 0=update, 1=query
    ///las posiciones del update  y query indexeadas desde 0
    while(q--){
        cin>>c>>x>>y;
        if(c==0){
            add(x,y);
        }else{
            cout<<query(x,y)<<endl;
        }
    }
    //8 5 8 6 3 2 7 2 6

    return 0;
}
