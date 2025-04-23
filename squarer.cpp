#include<bits/stdc++.h>
using namespace std;
int findd(int n){
    long long  low=1;
    long long high=n;
    long long ans;
    while(low<=high){
        long long mid= (low+high)/2;
        if(mid*mid<=n){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
int main(){
    int n;
    cout<<"Enter the no to check its square root"<<endl;
    cin>>n;
    int result= findd(n);
    cout<<"The square root with max int value is :  "<<result;
    return 0;

}