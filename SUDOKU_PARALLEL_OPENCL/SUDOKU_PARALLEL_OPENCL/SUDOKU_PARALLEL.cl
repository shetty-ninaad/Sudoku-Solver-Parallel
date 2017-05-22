
__kernel void LOADCHECK(__global int *B,__global int *CMB,__global int *RES,int posn) 
{
	int id = get_global_id(0); //get the index of current thread
	
	int R1[24][4], R2[24][4], R3[24][4], R4[24][4], combo[5200][4], S[4][4] ;
	int maxm,minm,sum,pro,f,i,j,k;

	for(i=0;i<24;i++)
	for(j=0;j<4;j++)
	{ 
		 R1[i][j]=B[(i+0) *4 + j];
		 R2[i][j]=B[(i+24)*4 + j];
		 R3[i][j]=B[(i+48)*4 + j];
		 R4[i][j]=B[(i+72)*4 + j];
	}

	for(i=0;i<posn;i++)
	for(j=0;j<4;j++)
	combo[i][j]=CMB[i*4+j];

	i=id;

for(j=0;j<4;j++)       //LOAD SUDOKU INTO ARRAY
		S[0][j]=R1[combo[i][0]-1] [j];
		for(j=0;j<4;j++)
		S[1][j]=R2[combo[i][1]-1] [j];
		for(j=0;j<4;j++)
		S[2][j]=R3[combo[i][2]-1] [j];
		for(j=0;j<4;j++)
		S[3][j]=R4[combo[i][3]-1] [j];

		///// CHECK SUDOKU MATRIX /////
		
		//CHECK COLUMN
		for(k=0;k<4;k++)
		{
			f=1;sum=0;pro=1;maxm=0;minm=5;
			for(j=0;j<4;j++)
			{
				sum+=S[j][k];
				pro*=S[j][k];
				if(maxm<S[j][k]) maxm=S[j][k];
				if(minm>S[j][k]) minm=S[j][k];
			}
			if(maxm!=4 || minm!=1 ||sum!=10 || pro!=24 )
			{
				f=0;break;
			}
	    }
	    if(f==1) //CHECK BOX
	    { 
			
	    	sum=0;pro=1;maxm=0;minm=5;
			sum=S[0][0]+S[0][1]+S[1][0]+S[1][1];
	    	pro=S[0][0]*S[0][1]*S[1][0]*S[1][1];
	    	minm=(S[0][0]<S[0][1])?(S[0][0]<S[1][0])?(S[0][0]<S[1][1])?S[0][0]:S[1][1]:(S[1][0]<S[1][1])?S[1][0]:S[1][1]:(S[0][1]<S[1][0])?(S[0][1]<S[1][1])?S[0][1]:S[1][1]:(S[1][0]<S[1][1])?S[1][0]:S[1][1];
	    	maxm=(S[0][0]>S[0][1])?(S[0][0]>S[1][0])?(S[0][0]>S[1][1])?S[0][0]:S[1][1]:(S[1][0]>S[1][1])?S[1][0]:S[1][1]:(S[0][1]>S[1][0])?(S[0][1]>S[1][1])?S[0][1]:S[1][1]:(S[1][0]>S[1][1])?S[1][0]:S[1][1];
	    
	    	if(maxm==4 && minm==1 &&sum==10 && pro==24 )
			{
				sum=0;pro=1;maxm=0;minm=5;
				sum=S[2][0]+S[2][1]+S[3][0]+S[3][1];
	    		pro=S[2][0]*S[2][1]*S[3][0]*S[3][1];
	    		minm=(S[2][0]<S[2][1])?(S[2][0]<S[3][0])?(S[2][0]<S[3][1])?S[2][0]:S[3][1]:(S[3][0]<S[3][1])?S[3][0]:S[3][1]:(S[2][1]<S[3][0])?(S[2][1]<S[3][1])?S[2][1]:S[3][1]:(S[3][0]<S[3][1])?S[3][0]:S[3][1];
	    		maxm=(S[2][0]>S[2][1])?(S[2][0]>S[3][0])?(S[2][0]>S[3][1])?S[2][0]:S[3][1]:(S[3][0]>S[3][1])?S[3][0]:S[3][1]:(S[2][1]>S[3][0])?(S[2][1]>S[3][1])?S[2][1]:S[3][1]:(S[3][0]>S[3][1])?S[3][0]:S[3][1];
	            
	            if(maxm==4 && minm==1 &&sum==10 && pro==24 )
				{
					sum=0;pro=1;maxm=0;minm=5;
					sum=S[2][2]+S[2][3]+S[3][2]+S[3][3];
	    			pro=S[2][2]*S[2][3]*S[3][2]*S[3][3];
	    			minm=(S[2][2]<S[2][3])?(S[2][2]<S[3][2])?(S[2][2]<S[3][3])?S[2][2]:S[3][3]:(S[3][2]<S[3][3])?S[3][2]:S[3][3]:(S[2][3]<S[3][2])?(S[2][3]<S[3][3])?S[2][3]:S[3][3]:(S[3][2]<S[3][3])?S[3][2]:S[3][3];
	    			maxm=(S[2][2]>S[2][3])?(S[2][2]>S[3][2])?(S[2][2]>S[3][3])?S[2][2]:S[3][3]:(S[3][2]>S[3][3])?S[3][2]:S[3][3]:(S[2][3]>S[3][2])?(S[2][3]>S[3][3])?S[2][3]:S[3][3]:(S[3][2]>S[3][3])?S[3][2]:S[3][3];
				    
	                if(maxm==4 && minm==1 &&sum==10 && pro==24 )
					{
						sum=0;pro=1;maxm=0;minm=5;
						sum=S[0][2]+S[0][3]+S[1][2]+S[1][3];
	    				pro=S[0][2]*S[0][3]*S[1][2]*S[1][3];
	    				minm=(S[0][2]<S[0][3])?(S[0][2]<S[1][2])?(S[0][2]<S[1][3])?S[0][2]:S[1][3]:(S[1][2]<S[1][3])?S[1][2]:S[1][3]:(S[0][3]<S[1][2])?(S[0][3]<S[1][3])?S[0][3]:S[1][3]:(S[1][2]<S[1][3])?S[1][2]:S[1][3];
	    				maxm=(S[0][2]>S[0][3])?(S[0][2]>S[1][2])?(S[0][2]>S[1][3])?S[0][2]:S[1][3]:(S[1][2]>S[1][3])?S[1][2]:S[1][3]:(S[0][3]>S[1][2])?(S[0][3]>S[1][3])?S[0][3]:S[1][3]:(S[1][2]>S[1][3])?S[1][2]:S[1][3];
	                    
	                    if(maxm==4 && minm==1 &&sum==10 && pro==24 )
						{
							RES[id]=99;
							printf("\n\n\t** Kernel ID : %d -> SUCCESS **",id);
						}
				} 
			}
	    }
	}

///// DISPLAY /////
printf("\n\t ID : %d | COMBINATION : %d %d %d %d\n",id,combo[id][0],combo[id][1],combo[id][2],combo[id][3]); 
printf("\n\t     --- SUDOKU Matrix ---\n\t\t");

for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	printf("%d ",S[i][j]);
	printf("\n\t\t");
}
	for(i=0;i<24;i++) //Fake printing R1 R2 R3 R4 - Some deep mythological or spiritual error
{
    if(R1[i][0]==0) break;
	for(j=0;j<4;j++)
	printf(" ",R1[i][j]);

}
	for(i=0;i<24;i++)
{
    if(R2[i][0]==0) break;
	for(j=0;j<4;j++)
	printf(" ",R2[i][j]);

}
	for(i=0;i<24;i++)
{
    if(R3[i][0]==0) break;
	for(j=0;j<4;j++)
	printf(" ",R3[i][j]);
}
	for(i=0;i<24;i++)
{
    if(R4[i][0]==0) break;
	for(j=0;j<4;j++)
	printf(" ",R4[i][j]);
}



			
 }
