
/*28 February 2015
  Created by S Pramod <---> domarps
  Problem Link : http://cprogrammingquest.blogspot.in/2015/01/sms-dictionary-sorting.html
(Indian National Olympiad in Informatics, INOI, 2007)
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX_CHAR 8 
#define MAX_IP 100000

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
  int i;
  int j;
  int k;
  int min_id;
  int num;
  int fnum;
  char map;
  char temp[8];
  int number=0;
  int t_num;
  int place; 
  int maximum;
  int* arr; 
  int min;
  int max_freq;
  int freq_ctr = 0;
  int flag = 0;
  int p_val,p_max,c_val,c_max;
  // FILE* fp = fopen("tf","r"); 
  int count;
  int result; 
  int max;
  int* ctr_arr;
 
  fscanf(stdin,"%d\n",&num);
  arr =  malloc(num * sizeof(int));
  //temp = (char*)malloc(MAX_CHAR * sizeof(char));
  
  for(i=0;i<num;i++) 
  {
    fscanf(stdin,"%s",temp); 
    number = 0;
    for(j=0;j<strlen(temp);j++)
    {
      map = temp[j];
      switch(map)
      {
        case 'a':
        case 'b':
        case 'c': t_num = 2; break;

        case 'd':
        case 'e':
        case 'f': t_num = 3; break;          

        case 'g':
        case 'h':
        case 'i': t_num = 4; break;
                  
        case 'j':
        case 'k':
        case 'l': t_num = 5; break;
                  
        case 'm':
        case 'n':
        case 'o': t_num = 6; break;
                  
        case 'p':
        case 'q':
        case 'r':
        case 's': t_num = 7; break;
                  
        case 't':
        case 'u':
        case 'v': t_num = 8; break;
                  
        case 'w':
        case 'x':
        case 'y':
        case 'z': t_num = 9; break; 
      }
      number = number * (10) + t_num;
    }
    arr[i] = number;
  }

  mergeSort(arr,0,num-1);
  ctr_arr = malloc((arr[num-1]+1) * sizeof(int));
  // for(i=0;i<num;i++) printf("%d \n",arr[i]);
  k = num+1;
  c_val = arr[0]; 
  c_max = 1;
  p_max = 0;
  for(i=1;i<num;i++)  
  {
     if(c_val != arr[i])
     {
        if(p_max < c_max)
        {
           p_val = c_val;
           p_max = c_max;
        }
        c_max = 1;
        c_val = arr[i];
     }
     else
     {
         c_max++;
     }
  }
  if(c_max > p_max) printf("%d\n",c_val);
  else printf("%d\n",p_val);
}  

 
