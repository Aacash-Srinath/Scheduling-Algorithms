#include<stdio.h>  
#include<conio.h>  
void main()  
{   
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf("\nTotal Number of Processes :: ");  
    scanf("%d", &NOP);  
    y = NOP;  
for(i=0; i<NOP; i++)  
{  
printf("\n");  
printf("Arrival Time of P%d: \t", i+1);   
scanf("%d", &at[i]);  
printf("Burst Time of P%d : \t", i+1); 
scanf("%d", &bt[i]);  
temp[i] = bt[i];   
}  
printf("\nEnter Time Quantum :: ");  
scanf("%d", &quant);  
printf("\nProcess \t BT \t TAT \t WT ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0)    
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--;
        printf("\nP%d \t\t %d\t %d\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
        wt = wt+sum-at[i]-bt[i];  
        tat = tat+sum-at[i];  
        count =0;     
    }  
    if(i==NOP-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  
avg_wt = wt * 1.0/NOP;  
avg_tat = tat * 1.0/NOP;  
printf("\n\nAverage Turnaround Time :: %f", avg_wt);  
printf("\nAverage Waiting Time :: %f", avg_tat);  
getch();  
}  
