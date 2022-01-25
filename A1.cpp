#include <iostream>

using namespace std;

int main()
{
    int arr[10][10];
    int i,j;
    int result1;
    int result2;

    for(j=0;j<=2;j++){   
        for(i=0;i<=2;i++){
        cin>>arr[j][i];
        }
    }
    
    result1 = arr[0][0]+arr[0][2]+arr[1][1]+arr[2][0]+arr[2][2];
    result2 = arr[0][1]+arr[1][0]+arr[1][2]+arr[2][1];
    cout<<result1;
    cout<<"\n";
    cout<<result2;
 }
