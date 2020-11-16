#include<stdio.h>

int main()    
{      
    int arr[] = {1, 2, 3, 4, 2, 7, 8, 8, 3};     
           
    int length = sizeof(arr)/sizeof(arr[0]);    
              
    for(int i = 0; i < length; i++) 
    {    
        for(int j = i + 1; j < length; j++) 
        {    
            if(arr[i] == arr[j])    
                printf("%d is a repeating element\n", arr[j]);
                    
        }    
    } 

    printf("\nOriginal array is: ");
    for(int i = 0; i < length; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\nNew array is: ");
    for(int i = 0; i < length; i++)
    {
        for(int j = i+1; j < length; )
        {
            if(arr[j] == arr[i])
            {
                for(int k = j; k < length; k++)
                {
                    arr[k] = arr[k+1];
                }
                length--;
            }
            else
            {
                j++;
            }
        }
    }

    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }


    return 0;    
}  