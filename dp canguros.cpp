#include <bits/stdc++.h>
#define lcm(a,b) (a/__gcd(a,b))*b
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define F first
#define S second
#define mp make_pair
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;

using namespace std;
vi v;
int res=0;
int f(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        res++;
        return 1;
    }
    for(int i=0;i<v.size();i++){
        f(n-v[i]);
    }
}
int main()
{
    ///8 2 3 5
    int m,n,x;
    cin>>m>>n;///escalon al que quiero llegar y tipos de saltos
    /// el canguro empieza en 0
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    f(m);
    cout<<res<<endl;
    return 0;
}

