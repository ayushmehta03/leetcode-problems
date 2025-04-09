#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    int even=0, odd=1;
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            ans[even]=arr[i];
            even+=2;
        }
        else{
            ans[odd]=arr[i];
            odd+=2;
        }
    }
    cout<<"The rearranged array is : ";
    for(int i=0;i<n;i++){
        cout << " "<<ans[i];
    }

}