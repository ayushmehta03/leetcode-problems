// for this we need to find the largest elemnt which is less than equal to the given target
#include<bits/stdc++.h>
using namespace std;
int bsF(vector<int>arr, int low, int high,int x ){
    int ans=0;
    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]>=x){
            ans=arr[mid];
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
 int result= bsF(arr, 0, arr.size()-1,target);
 cout<< "The smallest elemnt which is less than equal to the target is " << " "<<result;
}