//matrix normal multiplication

#include<bits/stdc++.h>
#include <stdio.h>
#include <mpi.h>

using namespace std;

     
int main(int argc, char **argv){
   printf("Input The size of of 1st matrix:\n");
   int n,m, p,q; cin>>n>>m;
   int matrix1[n+5][m+5];
   int matrix2[p+5][q+5];

   printf("Input the first matrix:\n");
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
         cin>>matrix1[i][j];
   }

   printf("Input the size of 2nd matrix");
   cin>>p>>q;

   printf("Input the first matrix:\n");
   for(int i=0;i<p;i++){
      for(int j=0;j<q;j++)
         cin>>matrix2[i][j];
   }

   if(m!=p){
      printf("Matrix mulplication can't be possible.
      \nFirst matrix column and second matrix are must be same.\n
      But found as %d and %d\n",m,p);
   }

   return 0;
}