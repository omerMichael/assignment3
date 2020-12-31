#define size_arr 50
#include <stdio.h>

void printArray(int *arr, int n) 
{ 
    int i; 
    for (i = 0; i < n-1; i++)
    {
        printf("%d,", *(arr+i));
    }// end for

printf("%d", *(arr+i));
} 

//***************************************************
void shift_element(int *arr, int i)
{
for (int j=i-1; j>0; j--)
	*( arr+1+j)=*(arr+j);
 //end for
}
//**************************************************
void insertion_sort(int *arr, int len)
{ 
    int val,i , j; 
    for (i = 1; i < len; i++)
    {
       val= *(arr+i);
        j = i - 1; 
       // int counter=0;
        //here we need to chenge with shift element
        while ( (*(arr+j) > val) && j>=0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
         
         
            // until here
         //end while
       *(arr +j+1) = val; 
    } //end for
 }//end functionn

//**********************************************
  int main() 
  {
    int arr[size_arr];
    int a;

    //input
    // printf ("enter 50 number into array: \n");

    for(int i=0 ; i<size_arr; i++)
    {
    	scanf("%d", &a);
    	*(arr+i)=a;
  	}

    //output
    // printf("Before Arr \n");
    // printArray(arr, size_arr); 
    
    insertion_sort(arr, size_arr);

    // printf("After insetionSort \n");
    printArray(arr, size_arr);

     //shift_element(arr, size_arr);
     //printf("After shift_element \n");
     //printArray(arr, size_arr);

return 0;
  }
