#include <iostream>
using namespace std;
void swap1(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}
int partition(int arr[],int high,int low)
{
	int i=low-1;
	
	for (int j=low;j<high;j++)
	{
		if (arr[j]<arr[high])
		{
			i++;
			swap1(&arr[i],&arr[j]);
		}	
	}
	swap1(&arr[i+1],&arr[high]);
	return i+1;
}		


void quicksort(int arr[], int low,int high){

		if (low<high)
		{
			
		int pi=0;
		pi=partition(arr,high,low);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
}
}		

int main()
{
	int arr[5]={2,1,0,5,4};
	quicksort(arr,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
	
