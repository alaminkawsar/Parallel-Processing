#include<bits/stdc++.h>
#include<mpi.h>
using namespace std; 
int n=10;
int arr[]={1,2,3,4,5,6,7,8,9,10};
int tempArr[100];
int s;

int main(int argc,char **argv){
    int nprocess,pid,element_per_process,recieved_element;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&nprocess);
    MPI_Comm_rank(MPI_COMM_WORLD,&pid);

    MPI_Status status;

    if(pid==0){
        int index,i,remaining_element;
        element_per_process = n/nprocess;
        for(i=1;i<nprocess-1;i++){
            index=i*element_per_process;
            MPI_Send(&element_per_process,1,MPI_INT,i,0,MPI_COMM_WORLD);
            MPI_Send(&arr[index],element_per_process,MPI_INT,i,0,MPI_COMM_WORLD);
        }
        index = i*element_per_process;
        remaining_element = n-index;
        MPI_Send(&remaining_element,1,MPI_INT,i,0,MPI_COMM_WORLD);
        MPI_Send(&arr[index],remaining_element,MPI_INT,i,0,MPI_COMM_WORLD);

        int sum = 0;
        for(int i=0;i<element_per_process;i++) sum+=arr[i];
        printf("Sum of Process ID %d =%d\n",pid,sum);
        int temp;
        for(int i=1;i<nprocess;i++){
            MPI_Recv(&temp,1,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            sum+=temp;
        }
        cout<<"Total Sum of Array: "<<sum<<endl;
        

    }else{
        MPI_Recv(&element_per_process,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(&tempArr,element_per_process,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int tempSum=0;
        for(int i=0;i<element_per_process;i++){
            tempSum+=tempArr[i];
        }
        printf("Sum of Process ID %d =%d\n",pid,tempSum);
        MPI_Send(&tempSum,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }

    
    MPI_Finalize();
    
    return 0;
}