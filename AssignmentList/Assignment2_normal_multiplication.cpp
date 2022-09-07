//matrix normal multiplication

#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

     
int main(int argc, char **argv){

   freopen("input.txt","r",stdin);

   printf("Input The size of of 1st matrix:\n");
   int n,m, p,q; cin>>n>>m;
   int matrix1[n+5][m+5];

   printf("Input the first matrix:\n");
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
         cin>>matrix1[i][j];
   }

   printf("Input the size of 2nd matrix");
   cin>>p>>q;
   int matrix2[p+5][q+5];

   printf("Input the 2nd matrix:\n\n");
   for(int i=0;i<p;i++){
      for(int j=0;j<q;j++)
         cin>>matrix2[i][j];
   }

   if(m!=p){
      printf("Matrix mulplication can't be possible.\n1st matrix column and 2nd matrix row values are must be same.\nBut found %d,%d\n",m,p);
      return 0;
   }

   //Now we will make a matrix with nxq dimention
   int ansMatrix[n+5][q+5];
   for(int k=0;k<n;k++){
      for(int i=0;i<q;i++){
         //m==p
         ansMatrix[k][i]=0;
         for(int j=0;j<m;j++){
            ansMatrix[k][i]+=matrix1[k][j]*matrix2[j][i];
         }
      }
   }
   //show answer of multiplication
   printf("Matrix Multiplication Result:\n");
   m = q;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         printf("%d ",ansMatrix[i][j]);
      }
      cout<<endl;
   }


   return 0;
}