#include<stdio.h>

void swap(int *arr,int *arr2){
	int temp;
	temp=*arr;
	*arr=*arr2;
	*arr2=temp;
}
int part(int arr[],int lb,int ub){
	int pivot=arr[lb];
	int i=lb+1;
	int j=ub;
	do{
		while(arr[i]<=pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
		
	}while(i<j);
	swap(&arr[lb],&arr[j]);
	return j;
}
int quicksort(int arr[],int lb,int ub){
	int parti;
	if(lb<ub){
		parti=part(arr,lb,ub);
		quicksort(arr,lb,parti-1);
		quicksort(arr,parti+1,ub);
	}
}

int main(){
    int n,val;
    int arr[100];
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the values \n");
    for (int i=0;i<n;i++){
        scanf("%d",&val);
        arr[i]=val;
    }
    // Sorting
    // Quick Sort
    quicksort(arr,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
        
    



}
