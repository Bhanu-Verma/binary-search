#include<bits/stdc++.h>
using namespace std;
#define ll long long 

/*task--after a given number all the numbers are satisfying the given requirment
* so our task is to find that minimum number
*/

/*In these type of problems we divide the complete set of numbers in two types using a function
* function gives 1 if number satisfies the given condition 
* otherwise it gives 0
* now our task is two find the minimum value that satisfies the given condition
* so we can use binary search on this set
*/

int f(ll x, ll a, ll b, ll n){
    if(((x/a)*(x/b))>=n){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    ll l=0;
    ll h;
    
    ll n;
    //cin>>n;
    ll a,b;
    cin>>a>>b>>n;
    ll k=0;
    while(1){
        //cout<<"loop1";
        if(f(pow(2,k),a,b,n)){
            break;
        }else{
            k+=1;
        }
    }
    h = pow(2,k);
    //cout<<"h="<<h<<endl;
    while(h>l+1){
       // cout<<"loop2";
        ll m=l+(h-l)/2;
        if(f(m,a,b,n)==1){
            h=m;
        }else{
            l=m;
        }
    }
    cout<<h<<endl;
    return 0;
}
