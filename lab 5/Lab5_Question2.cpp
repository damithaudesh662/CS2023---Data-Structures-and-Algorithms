#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std::chrono;

using namespace std;
int PivotLocation(int arr[],int min,int max){
    int pivot=arr[max];
    int i=min-1;
    int temp1;
    
    for(int j=min;j<max;j++){
        int temp2;
        
        if(arr[j]<pivot){
            i=i+1;
            //swap(arr[i], arr[j])
            temp2=arr[i];
            arr[i]=arr[j];
            arr[j]=temp2;
        }
    }
    //swap(arr[i + 1], arr[high])
    temp1=arr[i+1];
    arr[i+1]=arr[max];
    arr[max]=temp1;
    return i+1;

}

void RecursiveQuicksort(int arr[],int min,int max){
    if(min<max){
        int pivot_location=PivotLocation(arr,min,max);
        RecursiveQuicksort(arr,min,pivot_location-1);
        RecursiveQuicksort(arr,pivot_location+1,max);
    }
}
int main(){
    
   
    int arr []={7,3,5,2} ;
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    int arr2 [arrSize]={};
    
    int number;
    
    
    
    for(int x=0;x<arrSize;x++){
        
        
        
        arr2[x]=arr[x];
        RecursiveQuicksort(arr2,0,x+1);
        for(int i:arr2){
            cout<<i<<" ";
        }
        if(x==0){
            cout<<"median is: "<<endl;
            float a=arr2[0];
            cout<<a;
            cout<<endl;

        }
        
        else if(x%2==0){
            cout<<"median is :"<<endl;;
            float b=arr2[(x+1)/2];
            cout<<b;
            cout<<endl;
        }
        
        else{
            cout<<"median is :"<<endl;;
            float c=((arr2[x/2]+arr2[(x/2)+1])/2);
            cout<<c;
            cout<<endl;
        }


    }
    
    
    
    
   
    
    return 0;
    
    
    
}