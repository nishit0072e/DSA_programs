#include<stdio.h>
int main(){
     int arr[100],n,i,j,temp;
    printf("NUmber of elements: ");
    scanf("%d",&n);
    printf("enter %d elements: \n",n);
    for(i=0;i<n;i++){
        printf("\ndata[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }        
    }
    printf("sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}