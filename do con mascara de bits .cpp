#include<bits/stdc++.h>
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
//gcd(a,b)= ax + by
//lCB x&-x
//set.erase(it) - ersases the element present at the required index//auto it = s.find(element)
//set.find(element) - iterator pointing to the given element if it is present else return pointer pointing to set.end()
//set.lower_bound(element) - iterator pointing to element greater than or equal to the given element
//set.upper_bound(element) - iterator pointing to element greater than the given element
// | ^
//__builtin_popcount(x)
//https://acm.timus.ru/status.aspx?space=1
using namespace std;
vi v;
int dp[(1<<21)];
void init(){
    for(int i=0;i<(1<<21);i++){
        dp[i]=-1;
    }
}
int n;
int f(int mask){
    if(mask==(1<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    dp[mask]=1e9;
    for(int i=0;i<n;i++){
        if((1<<i)&mask)continue;
        int MASK=mask+(1<<i);
        int pos=(i+1)%n;
        int BIT=(1<<pos);
        MASK=(MASK | BIT);
        pos=(i+2)%n;BIT=(1<<pos);
        MASK=(MASK  | BIT);
        int aux=0;
        for(int l=0;l<n;l++){
            if((1<<l)&MASK)continue;
            aux+=v[l];
        }
        //cout<<endl;
        //cout<<"aux  "<<aux<<endl;
        dp[mask]=min(dp[mask],f(MASK)+aux);
    }
    return dp[mask];
}

int main()
{
    init();
    int x;    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;    
        v.pb(x);
    }
    cout<<f(0);
    return 0;
}