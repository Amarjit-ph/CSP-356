#include <iostream>
using namespace std;
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n-1; i++)
  for (j = 0; j < n-i-1; j++)
  if (arr[j] > arr[j+1])
  swap(&arr[j], &arr[j+1]);
}
int main(){
  int v[100],i,n,m;
  int t;
  int sum = 0;
  int sum1 = 0;
cin>>t;
while(t--){
  cout<<endl;
  cin>>n>>m;
  for(i=0;i<n;i++){
  cin>>v[i];
}
bubbleSort(v,n);
  for(int k=0,l=m;k<n-m-1,l<n;k++,l++){ 
  sum = sum+v[k];
  sum1 = sum1+v[l];
}
cout<<sum1-sum;
cout<<endl;
}
return 0;
}
