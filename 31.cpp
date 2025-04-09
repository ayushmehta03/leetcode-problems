#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if (arr[i]<arr[i+1]){
            index=i;
            break;
        }
        if(index==-1){
            reverse(arr.begin(),arr.end());
            break;

        }
        for(int i=n-1;i>=index;i--){
            if(arr[i]>arr[index]){
                swap(arr[i],arr[index]);
            }
            reverse(arr.begin()+index,arr.end());
        }
        cout<<"The next permutation is :";
        for(int i=0;i<n;i++){
            cout<<" "<< arr[i];
        }
    }
}