#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main()
{
  int arr[30],key1,key2,status;
  pid_t p1,p2;
  srand (time(NULL));
  printf("Array:");
  for(int i=0;i<30;i++){
    arr[i]=rand()%50+1;
    printf("%d",arr[i]);
    if(i==14) printf("|");
  }
  printf("\n\n Enter key 1 to search in first half");
  scanf("%d ", &key1);
  printf("Enter key 2 to search in second half");
  scanf("%d",&key2);
  //child 1
  p1=fork();
  if(p1<0){
     perror("fork failed");
     return 1;
  }
  if(p1==0){
     int found_index=255;
     for(int i=0;i<15;i++){
        if(arr[i]==key1){
          found_index=i;
          break;
         }
     }
      exit(found_index);
  }
  //parent waits for child 1
  waitpid(p1,&status,0);
  int res1=WEXITSTATUS(status);
  if(res1==255){
     printf("child 1:key %d not found in the first half . \n",key1);
   }
   else{
     printf("child 1:key %d not found at index %d. \n", res1);
   }
   //fork child 2(indices 15-20)
   
  //child 2
  p2=fork();
  if(p2 <0 ){
     perror("fork failed");
     return 1;
  }
  if(p2==0){
    int found_index=255;
    for(int i =15;i<30;i++)
    {
      if(arr[i]==key2){
         found_index=i;
         break;
      }
    }
    exit(found_index);
  }
  //parent wait for child 2
  waitpid(p2,&status,0);
  int res2=WEXITSTATUS(status);
  if(res2==255){
    printf("child 2: key %d not fount in the second half.\n",key2);
  }
  else{
    printf("child 2:key %d found at index %d.\n",key2,res2);
  }
  return 0;
}
