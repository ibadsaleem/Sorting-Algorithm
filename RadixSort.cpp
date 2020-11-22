#include <iostream>
using namespace std;
int getmax(int *arr,int size)
{
	int max=arr[0];
	for (int i=1;i<size;i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
void CountSort(int *arr,int size,int exp){
	
	int *output=new int [size];
	int *countarray=new int [100];
	for (int i=0;i<100;i++)
	{
		countarray[i]=0;
	}
	for (int i=0;i<size;i++)
	{
		countarray[(arr[i]/exp)%10]++;
	}
	for (int i=1;i<100;i++)
	{
		countarray[i]=countarray[i-1]+countarray[i];
	}
	for (int i=0;i<size;i++)
	{
		output[countarray[(arr[i]/exp)%10]-1]=arr[i];
        countarray[(arr[i] / exp) % 10]--; 
	}
	for (int i=0;i<size;i++)
	{
		arr[i]=output[i];
	}
	
}
void radixSort(int *arr,int size)
{
	int m =getmax(arr,size);
	
	for (int exp=1;m/exp>0;exp*=10)
	CountSort(arr,size,exp);
}

int main()
{
	int *arr=new int[5]{5,0,1,4,6};
	radixSort(arr,5);
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}
