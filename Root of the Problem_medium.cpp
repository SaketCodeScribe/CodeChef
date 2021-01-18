#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t, x, y, n;
    cin>>t;
    while(t--){
        cin>>n;
        ll s1, s2;
        s1=s2=0;
        while(n--){
            cin>>x>>y;
            s1+=x;
            s2+=y;
        }
        cout<<s1-s2<<endl;
    }
	return 0;
}
