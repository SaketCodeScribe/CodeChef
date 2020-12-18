#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(a,b) for(ll i=a; i<b; i++)

int main() {
	// your code goes here
	ll t, n, k;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    n-=k;
	    ll ans=1;
	    k--;
	    if(n>0){
	        n+=k;
	        if(k>n/2)
	            k=n-k;
    	    fr(0,k){
    	        ans*=(n-i);
    	        ans/=(i+1);
    	    }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}