#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
        /*binary search on the real numbers*/


bool f(double x, int arr[], int n, int k)
{
    ll total=0;
    for(int i=0; i<n; i++){
        total += floor(arr[i]/x);
       // cout<<"total="<<total<<endl;
    }
    return total>=k;
}



int main(){
    

    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    double l=0, r=1e8;
    //here we run a loop its number of iterations depends upon the accuarcy 
    //that we need in answer its of logaritmic iterations  
    //cout
    for(int i=0; i<100; i++){
        double mid = (l+r)/2;
        if(f(mid,arr,n,k)){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<setprecision(20)<<l<<endl;
    return 0;
}