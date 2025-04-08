// Push all the even elemest at the starting point of the array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    int left=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            swap(arr[left],arr[i]);
            left++;
        }
    }
    cout<< "The sorted by parity elements are:" ;
    for(int i=0;i<n;i++){
        cout << " "<< arr[i] << " ";
    }
    cout << endl;
}