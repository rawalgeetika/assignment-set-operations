#include <stdio.h>
#define SIZE 5

void accept(int *ptr);
void display(int *ptr, int n);
int find_union(int arr1[], int arr2[], int * union_arr);
int find_intersection(int arr1[], int arr2[], int * intersection_arr);
int find_difference(int arr1[], int arr2[], int * difference_arr);
int find_symm_difference_union(int arr1[], int arr2[], int * symm_difference_arr, int difference_1_size, int difference_2_size);


int main(){
    int arr1[SIZE], arr2[SIZE], union_arr[2*SIZE], intersection_arr[SIZE], difference_arr_1[SIZE], difference_arr_2[SIZE], symm_difference_arr[SIZE], n, i, j;

    printf("Enter Set 1 :\n");
    accept(arr1);
    display(arr1, SIZE);

    printf("Enter Set 2 :\n");
    accept(arr2);
    display(arr2, SIZE);

    n = find_union(arr1, arr2, union_arr);
    printf("Union Array :");
    display(union_arr, n);

    n = find_intersection(arr1, arr2, intersection_arr);
    printf("Intersection Array :");
    display(intersection_arr, n);

    i = find_difference(arr1, arr2, difference_arr_1);
    printf("Difference no.1:A - B :");
    display(difference_arr_1, i);

    j = find_difference(arr2, arr1, difference_arr_2);
    printf(" D ifference no.2:B - A :");
    display(difference_arr_2, j);

    n = find_symm_difference_union(difference_arr_1, difference_arr_2, symm_difference_arr, i, j);
    printf("Symmetric Difference Array :");
    display(symm_difference_arr, n);

    return 0;
}

void accept(int *ptr){
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter %d th element :",i+1);
        scanf("%d",&ptr[i]);
    }
}

void display(int *ptr, int n){
    printf("{");
    for (int i = 0; i < n; i++)
    {
        if (i==n-1)
        {
            printf(" %d ",ptr[i]);
        }
        else{
            printf(" %d,",ptr[i]);
        }
    }
    printf("}\n\n");
}

int find_union(int arr1[], int arr2[], int * union_arr){
    int k = 0;

   
    for (int i = 0; i < SIZE; i++)
    {
        union_arr[k] = arr1[i];
        k++;
    }

   
    for (int i = 0; i < SIZE; i++)
    {
        int j=0;
        for (j = 0; j < SIZE; j++)
        {
            if (arr2[i]==arr1[j])
            {
                break;
            }
        }
        if (j==SIZE)
        {
            union_arr[k] = arr2[i];
            k++;
        }
    }
    return k;
}

int find_intersection(int arr1[], int arr2[], int * intersection_arr){
    int k=0;

  
    for (int i = 0; i < SIZE; i++)
    {
        int j=0;
        for (j = 0; j < SIZE; j++)
        {
            if (arr1[i]==arr2[j])
            {
                intersection_arr[k] = arr1[i];
                k++;
                break;
            }
        }
    }
    return k;

}

int find_difference(int arr1[], int arr2[], int * difference_arr){
    int k=0;

    for (int i = 0; i < SIZE; i++)
    {
        int j=0;
        for (j = 0; j < SIZE; j++)
        {
            if (arr1[i]==arr2[j])
            {
                break;
            }
        }
        if (j==SIZE)
        {
            difference_arr[k] = arr1[i];
            k++;
        }
    }
    return k;
}
int find_symm_difference_union(int arr1[], int arr2[], int * symm_difference_arr, int difference_1_size, int difference_2_size){
    int k = 0;

   
    for (int i = 0; i < difference_1_size; i++)
    {
        symm_difference_arr[k] = arr1[i];
        k++;
    }

    
    for (int i = 0; i < difference_1_size; i++)
    {
        int j=0;
        for (j = 0; j < difference_2_size; j++)
        {
            if (arr2[i]==arr1[j])
            {
                break;
            }
        }
        if (j==difference_2_size)
        {
            symm_difference_arr[k] = arr2[i];
            k++;
        }
    }
    return k;
}
