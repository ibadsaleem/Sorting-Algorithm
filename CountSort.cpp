#include <iostream>
using namespace std;
void CountSort(int *arr,int size){
	
	int *output=new int [size];
	int *countarray=new int [100];
	for (int i=0;i<100;i++)
	{
		countarray[i]=0;
	}
	for (int i=0;i<size;i++)
	{
		countarray[arr[i]]++;
	}
	for (int i=1;i<100;i++)
	{
		countarray[i]=countarray[i-1]+countarray[i];
	}
	for (int i=0;i<size;i++)
	{
		output[countarray[arr[i]]-1]=arr[i];
		--countarray[i];
	}
	for (int i=0;i<5;i++)
	{
		arr[i]=output[i];
	}
	
}
int main(){
	int *arr=new int [5]{5,0,1,7,6};
	CountSort(arr,5);
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
