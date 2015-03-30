#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_OF_CHARS 256
#define MAX_SIZE 20
#define bool int 

int M,N;

char Append(int i,int j,char** array)
{
  if(i >= 0 && i < M && j >= 0 && j < N)
  {
     return array[i][j]; 
  }  
}  
char Backtrack(int i_start,int j_start,char** a)
{
  char* str =  malloc(sizeof(char)*256);
  char temp = 'X';
  int count = 0;
  int i = i_start;
  int j = i_start;
  str[count] = a[i_start][j_start];
  while(temp = Append(i+1,j,a) == '0')
      {
            printf("%s ",str);
            count++;
            str[count] = temp; 
      }
  count = 0;
  str[count] = a[i_start][j_start];
  while(temp = Append(i-1,j,a) == '0')
      {
            printf("%s ",str);
            count++;
            str[count] = temp; 
      }
  count = 0;
  str[count] = a[i_start][j_start];
  while(temp = Append(i,j+1,a) == '0')
      {
            printf("%s ",str);
            count++;
            str[count] = temp; 
      }
  count = 0;
  str[count] = a[i_start][j_start];
  while(temp = Append(i,j-1,a) == '0')
      {
            printf("%s ",str);
            count++;
            str[count] = temp; 
      }
}
int main() 
{
   int i,j;
   int index;
   char op; 
   char **array = NULL;
   char temp;
   bool bin_hash[NO_OF_CHARS]; 
   for(i = 0; i < NO_OF_CHARS ; i++) bin_hash[i] = 0; 
   scanf("%d %d",&M,&N);
   array = malloc(sizeof(char*)*M);
   for (index=0; index<M; index++)
   {
      *(array+index) = malloc(sizeof(char)*N); 
      if (!*(array+index))
      {
         printf ("\nMemory Allocation Failure !\n");
         exit (EXIT_FAILURE);
      }
   }
   for(i = 0; i < M; i++)
   {
       for(j= 0; j < N; j++)
       {
                  while((op = getchar()) == '\n' || (op  == ' '));
                  //printf("%d %c %d",j,op,j);
                  array[i][j] = op;
       }
       //printf("\n"); 
   }   
   for(i = 0;i < M*N;i++)
   {
      temp = array[i%M][i/N]; 
//      printf("%d ",bin_hash[temp]);
      if(bin_hash[temp] == 0)
      {
         bin_hash[temp] = 1;
      }
      else
      {
         array[i%M][i/N]  = '0';
      }
   }
   for(i = 0; i < M; i++)
   {
  //     for(j=0; j < N ; j++) printf("%c",array[i][j]);
  //     printf("\n");
   }
   
   for(i = 0;i < M; i++)
   {
     for(j= 0;j < N;j++) 
                          Backtrack(i,j,array);
   }  
   return 0;
}
