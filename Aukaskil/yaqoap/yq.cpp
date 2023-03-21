#include <iostream> 
#include <stack> 
#include <map>

using namespace std; 
typedef long long ll;

#define MAXN 1000000
ll p[MAXN];
ll find(ll x){
    return p[x] < 0 ? x : (p[x] = find(p[x]));
}
void join(ll x, ll y){
    ll rx = find(x), ry = find(y);                                             
    if (rx == ry) return;                                                       
    if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;                            
    else p[rx] += p[ry], p[ry] = rx;                                            
}
void init(){
    for (ll i = 0; i < 200010; i++){p[i] = 0;}
}
ll size(ll x){
    return -p[find(x)];
}
void print(ll n){
    for(ll i = 0; i < n; i++){

    }
}

int main(){
    ll n,q;
    ll input;
    cin >> n;
    init();
    map<ll,bool> inserted;
    map<ll,ll> dict;
    ll array[n];
    for(ll i = 0; i < n; i++){
        cin >> input;
        if(inserted[input]){
            ll old_index = dict[input];
            p[i]--;
            join(i,old_index);
            array[i]=input;
        }
        else{
            array[i]=input;
            inserted[input]=true;
            dict[input]=i;
            p[i]--;
        }
    }

    cin >> q;
    ll i,j;
    for(ll k = 0; k < q; k++){
        cin >> i;
        cin >> j;
        cout << size(i-1);
        join(i-1,j-1);
        cout << ' ' << size(j-1) << '\n';
    }
    return 0;
}
