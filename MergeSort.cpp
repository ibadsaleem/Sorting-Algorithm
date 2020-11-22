#include <iostream>
using namespace std;

void merge(int *arr,int l,int mid,int r)
{
//	cout<<l<<mid<<r<<endl;
	int limit1=mid-l+1;
	int limit2=r-mid;
	int L[limit1],R[limit2];
	
	for (int i = 0; i < limit1; i++)
        {
		L[i] = arr[l + i];
		}
    for (int j = 0; j < limit2; j++)
        R[j] = arr[mid + 1 + j];
    
	int i=0,j=0,k=l;
	while  (i<limit1 && j<limit2)
	{
		if (L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	 }
	 
	 while(i<limit1)
	 {
	 	arr[k]=L[i];
	 	i++;
	 	k++;
	  } 
	 	 while(j<limit2)
	 {
	 	arr[k]=R[j];
	 	k++;
	 	j++;
	  }    
}

void mergeSort(int *arr,int l,int r)
{
	if (r>l)
	{
		int mid=(l+r-1)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
	
}

int main()
{
	int *arr=new int[5]{5,0,1,4,6};
	mergeSort(arr,0,4);
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}
