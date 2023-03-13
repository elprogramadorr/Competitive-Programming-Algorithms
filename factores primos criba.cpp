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
#define INF 1000000000
//salida rapida "\n"
//DECIMALES fixed<<sp(n)<<x<<endl;
using namespace std;

int main()
{

    vi v;
    for(int i=0;i<=100000;i++){
        v.pb(i);
    }
    for(int i=2;i*i<=100000;i++){
        for(int l=i*i;l<=100000;l+=i){
            if(v[l]==l){
                v[l]=i;
            }
        }
    }
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        while(1){
            cout<<v[x]<<" ";
            if(v[x]==x){
                break;
            }
            x/=v[x];
        }
        cout<<endl;
    }
    return 0;
}
