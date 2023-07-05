#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

struct seg
{
    int l;
    int r;
    int len;
};


pair<bool, pair<int, int>> can_seg(ll mid, vll sum, vll xr, int n){
    ll ans = sum[1]-xr[1], ans_l = 0, ans_r = 0;
    ll sm = 0, min_sum = 0, min_pos = -1;

    for(int r=0; r<n; r++){
        sm += sum[r+1] - xr[r+1];
        ll curr = sm - min_sum;
        if(curr > ans){
            ans = curr;
            ans_l = min_pos + 1;
            ans_r = r;
        } 
        if(sm < min_sum){
            min_sum = sm;
            min_pos = r;
        }
    }

    return {ans>=mid,{ans_l,ans_r}};
}

void solve(){
    ll n,q;
    cin>>n>>q;
                //cout<<"n="<<n<<" "<<"q="<<q<<endl;
    vll arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vll sum(n+1);
    vll xr(n+1);
    sum[0] = 0;
    xr[0] = 0;
    for(int i=1; i<n+1; i++){
        sum[i] = sum[i-1]+arr[i-1];
        xr[i] = (xr[i-1]^arr[i-1]);
    }

    
    while(q--){
        ll L,R;
        cin>>L>>R;

        ll lo=0;
        ll hi=1e14+20;

        while (hi>lo+1)
        {   
            ll mid = lo + (hi-lo)/2;
                       // cout<<"mid="<<mid<<endl;
            if(can_seg(mid,sum,xr,n).first){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        auto ans = can_seg(lo,sum,xr,n);
        cout<<ans.second.first+1<<" "<<ans.second.second+1<<endl;
       
    }
}

int main(){
    int t;
    //cout<<"give t\n";
    cin>>t;
    //cout<<"t="<<t<<endl;
    while(t--){
        solve();
    }
    return 0;
}