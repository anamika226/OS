#include<stdio.h>
int main()
{
    int n=5;
    int AT[5]={0,1,2,3,4};
    int BT[5]={5,7,6,2,4};
    int CT[5],TAT[5],WT[5];
    float avg_TAT=0,avg_WT=0;
    CT[0]=AT[0]+BT[0];
    
    for(int i=1;i<n;i++){
      if(CT[1-1]>AT[i])
      CT[i]=CT[i-1]+BT[i];
      else
      CT[i]=AT[i-1]+BT[i];
      
    }
    for(int i=0;i<n;i++)
    {
       TAT[i]=CT[i]-AT[i];
       WT[i]=TAT[i]-BT[i];
       avg_TAT+=TAT[i];
       avg_WT+=TAT[i];
    }
    avg_TAT=avg_TAT/n;
    avg_WT=avg_WT/n;
    printf("\n PN\t AT\t BT\t CT\t TAT\t WT \n");
    for(int i=0;i<n;i++)
    {
       printf("p%d\t%d\t%d\t%d\t%d\t%d\n",i+1,AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
    printf("\n Average TAT=%.2f \n",avg_TAT);
    printf("Average WT=%.2f \n",avg_WT);
    return 0;
}
