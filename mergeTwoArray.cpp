// Merge two Array without any extra space 
// Optimal Solution 1 

#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
vector<int>arr(n);
cout<<"Enter the no of elements in array 1"<<endl;
cin>>n;
cout << "Enter the elements for array 1"<<endl;
for(int i=0;i<n;i++) cin>>arr[i];
sort(arr.begin(),arr.end());


int m;
vector<int>arr2(m);
cout<<"Enter the no of elements in array 2"<<endl;
cin>>m;
cout << "Enter the elements for array 2"<<endl;
for(int i=0;i<m;i++) cin>>arr2[i];
sort(arr2.begin(),arr2.end());

int left=n-1;
int right=0;
while(left>=0 && right<m){
    if(arr[left]>arr2[right]){
        swap(arr[left],arr[right]);
        left--;
        right++;
    }
    else{
        break;
    }
    sort(arr.begin(),arr.end());
    sort(arr2.begin(),arr2.end());

}





}