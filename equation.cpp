#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>

bool isgood(double x, double c){
    return x*x+sqrt(x)>=c;
}

int main(){
    double c;
    cin>>c;
    double l = 0;
    double r = 1e6;

    for(int i=1; i<=80; i++){
        double mid=l+(r-l)/2;
        if(isgood(mid,c)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<setprecision(20)<<r<<endl;
    return 0;
}