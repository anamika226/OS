#include <stdio.h>

int main() {

    int at[5]  = {0,0,0,0,0};
    int bt1[5] = {5,7,6,8,5};
    int io[5]  = {2,2,3,1,2};
    int bt2[5] = {3,2,4,2,5};

    int pct[5], ct[5];
    int i;

    // ----- PCT -----
    pct[0] = bt1[0] + io[0];

    for(i = 1; i < 5; i++) {
        pct[i] = pct[i-1] + bt1[i] + io[i];
    }

    // ----- CT -----
    ct[0] = pct[0] + bt2[0];

    for(i = 1; i < 5; i++) {

        if(ct[i-1] > pct[i])
            ct[i] = ct[i-1] + bt2[i];
        else
            ct[i] = pct[i] + bt2[i];
    }

    printf("PN\tAT\tBT1\tIO\tBT2\tPCT1\tCT\n");

    for(i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt1[i], io[i], bt2[i], pct[i], ct[i]);
    }

    return 0;
}
