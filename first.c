#include<stdio.h>

#include<stdlib.h>
#include<time.h>
void bubblesort(int arr[],int n){
    for (int  i = 0; i < n-1; i++)
    {
        for(int j=0; j<n-i-1;j++){
            if (arr[j]<arr[j+1])
            {
               int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
            
        }
       
    }
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

     
      if (array[i] < array[min_idx])
        min_idx = i;
    }

   
    swap(&array[min_idx], &array[step]);
  }
}

double measureTime(void (*sortFunction)(int[], int), int arr[], int n) {
    clock_t start_time = clock();
    sortFunction(arr, n);
    clock_t end_time = clock();
    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

int main(){
    int array_sizes[] = {70, 80, 90, 120, 150, 170, 190, 220, 250, 300};
    int num_sizes = sizeof(array_sizes) / sizeof(array_sizes[0]);
    
    double bubble_sort_times[num_sizes];
    double selection_sort_times[num_sizes];

    for (int i = 0; i < num_sizes; i++) {
        int size = array_sizes[i];
        int arr[size];
        int arr_copy[size];

        for (int j = 0; j < size; j++) {
            int value = rand() % 1000 + 1;
            arr[j] = value;
            arr_copy[j] = value;
        }
        
        bubble_sort_times[i] = measureTime(bubblesort, arr, size);
        selection_sort_times[i] = measureTime(selectionSort, arr_copy, size);
    }

    printf("Array Size\tBubble Sort Time (s)\tSelection Sort Time (s)\n");
    for (int i = 0; i < num_sizes; i++) {
        printf("%d\t\t%f\t\t%f\n", array_sizes[i], bubble_sort_times[i], selection_sort_times[i]);
    }
   
    
    
    return 0;
}