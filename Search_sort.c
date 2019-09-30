#include "search_sort.h"
#include "stdio.h"
#define arr_size 10
static void Print_array(uint_32 *array);

void main (void)
{	
	uint_32 option,key,result ; 
	uint_32 Arr[arr_size]={6,3,42,12,2,7,33,10,24,13};
	printf(" 1-Bubble_Sort \n 2-Selection_Sort \n 3-Linear_search \n 4-Binary_search \n 5-Merge Sort");
	scanf("%d",&option);
	switch (option)
	{
		case 1 :
		Bubble_Sort(Arr);
		Print_array(Arr);
		break ;
		case 2 : 
		Selection_Sort(Arr);
		Print_array(Arr);
		break ;
		case 3 :
		printf("enter key to search\n");
		scanf("%d",&key);
		result =Linear_search(Arr,key);
		if (result)
		{
		printf("found\n");
		printf("your key placed in index : %d",result);	}
		break ; 
		case 4 :
		printf("enter key to search\n");
		scanf("%d",&key);
		result =Binary_search(Arr,key);
		if (result)
		{
		printf("found\n");
		printf("your key placed in index : %d",result);	}
		break ; 
		case 5 :
		Merge_Sort(Arr);
		Print_array(Arr);
		break ;
		
		
		
	}
	
}
void Print_array(uint_32 *array)
{
	uint_32 counter=0; 	
	printf("Sorted ArraY :  ");
	for(counter=0;counter<arr_size-1;counter++)
	{
		printf("%d ",array[counter]);
	}

}

void Bubble_Sort(uint_32 *arr_ptr)
{
	uint_32 index_A ,index_B ,temp; /*3c*/
	for (index_A=0;index_A<arr_size-1;index_A++)/*c+2cn*/
	{
		for(index_B=0;index_B<arr_size-1-index_A;index_B++)/*nc+2cn^2*/
		{
			if (arr_ptr[index_B]>arr_ptr[index_B+1])/*cn^2*/
			{
				temp =arr_ptr[index_B];/*cn^2*/
				arr_ptr[index_B]=arr_ptr[index_B+1];/*cn^2*/
				arr_ptr[index_B+1]=temp ;/*cn^2*/
			}
			
		}
	}
		
}
/*t(n)=6cn^2+3nc+4c
*O(n)=n^2*/
 

void  Selection_Sort(uint_32 *arr_ptr)
{
	uint_32 index_A ,index_B ,temp ,min; /*4c*/
	for(index_A=0;index_A<arr_size-1;index_A++)/*c + 2cn*/
	{	min = index_A;/*nc*/
		for(index_B=index_A+1 ; index_B<arr_size;index_B++)/*cn + 2cn^2*/
		{
			if(arr_ptr[min]>arr_ptr[index_B])/*cn^2*/
			{min = index_B;}/*cn^2*/
			
		}
		temp=arr_ptr[index_A];/*cn*/
		arr_ptr[index_A]=arr_ptr[min];/*cn*/
		arr_ptr[min]=temp ;/*cn*/
	}
}
/*4cn^2+6cn+5c
*O(n)=n^2*/


uint_32  Linear_search(uint_32 *arr_ptr,uint_32 Key)
{
		uint_32 index  ;/*c*/
	for (index = 0 ; index<arr_size-1;index++)/*c+2cn*/
	{
		if(arr_ptr[index]==Key)/*cn*/
		{
			return index ; /*c*/
		}
	}
	printf("Not found\n");/*c*/
	return 0 ;	/*c*/
}
/*3cn+4cn
*O(n)=n */
uint_32  Binary_search(uint_32 *arr_ptr, uint_32 Key)
{
	uint_32 start , end , middle; /*3c*/
	Bubble_Sort(arr_ptr);/*t(n)=6cn^2+3nc+4c*/
	start = 0 ; /*c*/
	end  = arr_size-1 ; /*c*/
	middle = (start+end)/2 ; /*c*/
	while(start<=end) /*cn*/
	{
		middle = (start+end)/2 ; /*cn*/
		if(arr_ptr[middle]==Key)/*cn*/
		{return middle ; }/*cn*/
		
		else if (arr_ptr[middle]<Key)/*cn*/
		{
			start = middle+1 ; /*cn*/
		}
		else 
		{
			end = middle-1;/*cn*/
		}
	}
	printf("Not found\n");/*cn*/
	return 0 ;	/*c*/
}	
/*8cn+6clog(n) +(6cn^2+3nc+4c)
O(n)=n^2*/

void Merge_Sort(uint_32 *arr_ptr)
{ uint_32 index ,mid; /*2c*/
	mid = arr_size/2; /*c*/
	uint_32 left[mid]; /*c*/
	uint_32 right[arr_size-mid];/*c*/
	for (index=0;index<mid-1;index++)/*cn*/
	{ 	 	 	
		left[index]=arr_ptr[index];/*cn*/
	}
	for(index=mid; index<arr_size-1 ; index++)/*cn*/
	{
		right[index-mid]=arr_ptr[index];/*cn*/
	}	
	/*4nc+5c*/
	Merge_Sort(left);		/*4nc+5c*/
	Merge_Sort(right);	/*4nc+5c*/
	Merge(left,right,arr_ptr);	/*log(n)*/
}
/*O(n)=nlog(n)*/
void Merge(uint_32 *L ,uint_32 *R,uint_32 *A)
{ 
	uint_32 Left = arr_size/2 ; /*c*/
	uint_32 Right = arr_size-Left ;/*c*/
	uint_32 i = 0 ;/*c*/
	uint_32 j=0 ;/*c*/
	uint_32 k = 0 ; /*c*/
	while (i<Left && j <Right)/*clog(n)*/
	{
		if(L[i]<=R[j]) /*clog(n)*/
		{
			A[k]=L[i];/*clog(n)*/
			i++;/*clog(n)*/
		}
		else 
		{
			A[k]=R[j];/*clog(n)*/
			j++;/*clog(n)*/
		}
		k++;/*clog(n)*/

	}
	while (i<Left)
	{
	A[k]=L[i];
	i++;
	}
	while (j<Right)
	{
	A[k]=R[j];
	k++;
	j++;
	}
	
}
/*log(n)*/