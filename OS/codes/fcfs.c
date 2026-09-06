#include<stdio.h>
int main(){
int n;
printf("Enter n: ");
scanf("%d",&n);
int at[10]={0},bt[10]={0},ct[10]={0},tat[10]={0},wt[10]={0};
int Ttat,Twt;
for(int i=0;i<n;i++){
printf("Enter p%d aT",i+1);
scanf("%d",&at[i]);
printf("Enter p%d bT",i+1);
scanf("%d",&bt[i]);
}int sum=0;
for(int i=0;i<n;i++){
sum+=bt[i];
ct[i]=sum;
}
for(int i=0;i<n;i++){
tat[i]=ct[i]-at[i];}
for(int i=0;i<n;i++){
wt[i]=tat[i]-bt[i];
}
for(int i=0;i<n;i++){
printf("p%d %d %d %d %d %d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
}
