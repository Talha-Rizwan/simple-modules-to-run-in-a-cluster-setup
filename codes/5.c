#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//applying the functionality of scatter

int n=16/nprocs;


if(rank==0)
{

char sdata[]="hello from talha";
printf("\n HI I am sending the massage %s to all the processes and my rank is %d ...\n ",sdata,rank);


char rdata[n+1];
int k=0;

for(int i=0;i<nprocs;i++){

printf("enter the number sending value for this process number %d ",i);
scanf("%d",&n);
char d[n];

	for(int j=0;j<n;j++){

	d[j]=sdata[k];
	if(i==0){
	rdata[j]=sdata[k];

	}
	k++;

	}
if(i!=0){
MPI_Send(d,n,MPI_CHAR,i,20,MPI_COMM_WORLD);
}


else if(i==0){
rdata[n]='\0';

}

}





printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);

}



if(rank!=0){
char rdata[30];

MPI_Recv(rdata,n,MPI_CHAR,0,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);

}


MPI_Finalize();
return 0;
}
