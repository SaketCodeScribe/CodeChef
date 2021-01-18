#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<ll, tree*>
#define v vector<int>
#define vb vector<bool>
v tree={}, lazy={};
ll n, k, ch, a, b;

void update_query(ll ind, ll low, ll high, ll l, ll r){
    lazy[ind]%=2;
    if(lazy[ind]){
        tree[ind]=high-low+1-tree[ind];
        if(low!=high){
            lazy[2*ind+1]+= lazy[ind];
            lazy[2*ind+2]+= lazy[ind];
        }
        lazy[ind]=0;
    }
    if(r<low || l>high || low>high)
        return;
    if(l==low && r==high){
        tree[ind]=high-low+1-tree[ind];
        if(low!=high){
            lazy[2*ind+1]++;
            lazy[2*ind+2]++;
        }
        return;
    }
    ll mid=low+(high-low)/2;
    if(low!=high){
        if(l<=mid && r>mid){
            update_query(2*ind+1, low, mid, l, mid);
            update_query(2*ind+2, mid+1, high, mid+1, r);
        }
        else{
            update_query(2*ind+1, low, mid, l, r);
            update_query(2*ind+2, mid+1, high, l, r);
        }
        tree[ind]=tree[2*ind+1]+tree[2*ind+2];
    }
    return;
}

ll range_query(ll ind, ll low, ll high, ll l, ll r){
    lazy[ind]%=2;
    if(lazy[ind]){
        tree[ind]=high-low+1-tree[ind];
        if(low!=high){
            lazy[2*ind+1]+= lazy[ind];
            lazy[2*ind+2]+= lazy[ind];
        }
        lazy[ind]=0;
    }
    if(r<low || l>high || low>high)
        return 0;
    if(l==low && r==high)
        return tree[ind];
    ll mid=low+(high-low)/2;
    if(low!=high){
        if(l<=mid && r>mid)
            return range_query(2*ind+1, low, mid, l, mid)+
                   range_query(2*ind+2, mid+1, high, mid+1, r);
        else
            return range_query(2*ind+1, low, mid, l, r)+
            range_query(2*ind+2, mid+1, high, l, r);
    }
    return 0;
}

int main() {
    cin>>n>>k;
    ll size=1;
    while(size<n)
        size*=2;
    tree.assign(2*size, 0);
    lazy.assign(2*size, 0);
    while(k--){
        cin>>ch>>a>>b;
        if(!ch)
            update_query(0, 0, n-1, a, b);
        else
            cout<<range_query(0, 0, n-1, a, b)<<endl;
    }
	return 0;
}
