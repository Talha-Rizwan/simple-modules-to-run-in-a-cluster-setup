#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//applying the functionality of redice amd applying the functionality of sum




if(rank!=0){

char sdata[10];
int rr=rank+48;
sdata[0]=(char)rr;
printf("\n HI I am sending the massage %s to processor 0  and my rank is %d ...\n ",sdata,rank);


MPI_Send(sdata,10,MPI_CHAR,0,20,MPI_COMM_WORLD);

}




if(rank==0){

printf("\n HI I am sending the massage %d to processor 0  and my rank is %d ...\n ",rank,rank);

int sum=0;



char rdata[10];

for(int i=1;i<nprocs;i++){
MPI_Recv(rdata,10,MPI_CHAR,i,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

char aa=rdata[0]-48;
sum+=aa;


printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);
}

printf("\n I am recieving the massage %d and my rank is %d ...\n ",rank,rank);
sum+=rank;
printf("\n the total sum of all the received values of ranks is : %d ",sum);

}

MPI_Finalize();
return 0;
}
