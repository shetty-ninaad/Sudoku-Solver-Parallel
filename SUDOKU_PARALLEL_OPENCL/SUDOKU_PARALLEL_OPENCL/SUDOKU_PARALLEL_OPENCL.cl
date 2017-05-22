
__kernel void SUDOKU(__global int *A,__global int *B,__global int *R,int n) 
{
	int id = get_global_id(0); //get the row no of SUDOKU I/P
	int temp[4] = {1,2,3,4}, l1,i,j,k,r1[4],flag;

	for( i=id*4 , j=0 ; j<4 ; i++,j++)
	r1[j]=A[i]; //copy row[id] into r1

	l1=id*24; //row index to start writing in B

    for(i=0;i<24;i++) //possibilities for row 1
    {
	for(j=0;j<4;j++)
    	{
    		flag=1;
    		for(k=0;k<4;k++)
    		{
    			if(r1[k]!=0 && r1[k]!=R[i*4+k])
    			flag=0; 
			}
			if(flag==0) break;
			B[l1*n + j]=R[i*4+j];	
		}
		if(flag==1)
		l1++;
	}
			for(i=l1;i<id*24+24;i++)
			for(j=0;j<4;j++)
			B[i*n + j]=0;
		
 }