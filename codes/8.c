#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//applying the functionality of gather




if(rank!=0){
int n;
char sdata[]="hello from talha";

n=rank+1;
char d[n+1];

for(int i=0;i<n;i++){

d[i]=sdata[i];

}

d[n]='\0';

printf("\n HI I am sending the massage %s to processor 0  and my rank is %d ...\n ",d,rank);


MPI_Send(d,10,MPI_CHAR,0,20,MPI_COMM_WORLD);

}




if(rank==0){

//printf("\n HI I am sending the massage h to processor 0  and my rank is %d ...\n ",rank);

char rdata[10];
char recdata[50];
int k=0;


for(int i=1;i<nprocs;i++){
MPI_Recv(rdata,10,MPI_CHAR,i,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

for(int l=0;rdata[l]!='\0';l++){
recdata[k]=rdata[l];
k++;
}


//printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);
}
recdata[k]='\0';
//printf("\n I am recieving the massage h and my rank is %d ...\n ",rank);

printf("the data received to process number %d is  %s \n",rank,recdata);

for(int i=1;i<nprocs;i++){

MPI_Send(recdata,20,MPI_CHAR,i,20,MPI_COMM_WORLD);
}

}


if(rank!=0){

char redata[50];
MPI_Recv(redata,20,MPI_CHAR,0,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

printf("the data received to process number %d is  %s \n",rank,redata);

}



MPI_Finalize();
return 0;
}
