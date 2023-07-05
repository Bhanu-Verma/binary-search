#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

bool good(int mid,int n,int x,int y){
    ll t=min(x,y);
    if(mid<t){
        return false;
    }

    return ((mid-t)/x+(mid-t)/y)>=n-1;
}

int main(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll r=2e9+100;
    ll l=0;
    if(n==1){
        cout<<min(x,y)<<endl;
    }else{
        
       // ll mid=l+(r-l)/2;
        
        while(r>l+1){
            //cout<<"mid="<<mid<<endl;
           // cout<<"I am here\n";
           ll mid=l+(r-l)/2;

            if(good(mid,n,x,y)){
                r=mid;
            }else{
                l=mid;
            }
            
        }
        cout<<r<<endl;
    }
        

    return 0;
}