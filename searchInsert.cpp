#include<bits/stdc++.h>
using namespace std;
int bs(vector<int>arr,int n , int target){
    int low=0, high=n-1;
    int ans= n;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;

}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int target;
    cin>>target;
   int result= bs(arr,arr.size(),target);
   cout<<"The element can be inserted at"  << " "<<result<<"position";
    

}