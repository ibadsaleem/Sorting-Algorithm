#include <iostream>
using namespace std;

void ShellSort(int *arr,int size)
{
	for (int gap=size/2;gap>0;gap=gap/2)
	{
		for (int i=gap;i<size;i++)
		{
			int temp=arr[i];
			int j;
			for (j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
			{
					arr[j]=arr[j-gap];		
			}
			arr[j]=temp;
		}
	}
}

int main()
{
	int *arr=new int [8]{5,1,0,6,7,-2,3,-5};
	ShellSort(arr,8);
	for (int i=0;i<8;i++)
	cout<<arr[i]<<" ";
}
