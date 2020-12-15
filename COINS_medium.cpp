#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define v vector<ll>
#define map unordered_map<ll, ll>
#define fr(a,b) for(i=a; i<b; i++)

ll Calcbgold(map& dp, ll n){
    if(n<12)
        return dp[n]=n;
    if(dp.count(n))
        return dp[n];
    ll ans=max(n, Calcbgold(dp, n/2)+Calcbgold(dp, n/3)+Calcbgold(dp, n/4));
    return dp[n]=ans;
}

int main() {
	// your code goes here
	ll n, i;
    map dp={};
	while(cin>>n){
        Calcbgold(dp, n);
	    cout<<dp[n]<<endl;
	}
	return 0;
}