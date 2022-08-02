#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

if(rank==0)
{

char sdata[]="hello from talha";

printf("\n HI I am sending the massage %s to all the processes and my rank is %d ...\n ",sdata,rank);


for(int i=1;i<nprocs;i++){

MPI_Send(sdata,30,MPI_CHAR,i,20,MPI_COMM_WORLD);

}

printf("\n I am recieving the massage %s and my rank is %d ...\n ",sdata,rank);

}



if(rank!=0){
char rdata[30];

MPI_Recv(rdata,30,MPI_CHAR,0,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);

}


MPI_Finalize();
return 0;
}
