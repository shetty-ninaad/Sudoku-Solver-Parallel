#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int R[24][4],pos=0;

int combination[5200][4],posn=0;
void nPr(int a[4],int check[4],int l=0, int r=3)
{
int temp,flag,t_arr[4];

if(l==r)  
{
   for (int j=0; j<=r; j++)
	    if(a[j]>check[j])
			return;
			
   for (int j=0; j<=r; j++)
		t_arr[j]=a[j];
		
	flag=0;
	for(int i=0;i<posn;i++) // check for already found case in combination array
	{
		flag=1;
		for(int j=0;j<4;j++)
		{
			if(t_arr[j]!=combination[i][j])
			{
				flag=0;
				break;
			}
		}
		if(flag==1) break;
	}
	
	if(flag==0)
	{
	   for (int j=0; j<=r; j++)
		combination[posn][j]=t_arr[j];
	   posn++;
    }
    
}

else
    for(int i=l;i<=r;i++)
    {
      temp=a[l];a[l]=a[i];a[i]=temp;//swap a[l] & a[i]
      nPr(a,check,l+1,r);
      temp=a[l];a[l]=a[i];a[i]=temp;//swap a[l] & a[i]
    }
}

void nCr(int chosen[], int arr[],int index, int r, int start, int end, int check[4])
{
    if (index == r)
    {
    	int data[4];
    	 for (int i = 0; i < r; i++)
            data[i]=arr[chosen[i]];
        nPr(data,check,0,3);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        nCr(chosen, arr, index + 1, r, i, end,check);
    }
    return;
} 

void permute(int a[4],int l=0, int r=3)
{
int temp;
if(l==r) 
{
    for(int i=0;i<=r;i++) 
       R[pos][i]=a[i];
    pos++;
}
else
    for(int i=l;i<=r;i++)
    {
      temp=a[l];a[l]=a[i];a[i]=temp;//swap a[l] & a[i]
      permute(a,l+1,r);
      temp=a[l];a[l]=a[i];a[i]=temp;//swap a[l] & a[i]
    }
}

int chk(int S[4][4])
{ 
int maxm,minm,sum,pro,f,i,j,k;

		
		//CHECK SUDOKU
		
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
							return 99;
						}
				} 
			}
	    }
	}
	return 909;
}
 
 int main() 
{
	int A[16]= {0,2,0,4,3,0,0,1,0,0,1,0,0,0,4,3};
	int B[384],n=4;
	   	
	int temp[4] = {1,2,3,4}, l1,i,j,k,r1[4],flag;
	permute(temp,0,3);
   
    int R1[96];
    for(i=0;i<24;i++)
    for(j=0;j<4;j++)
    R1[i*4+j]=R[i][j];
    
   for(int id=0;id<4;id++){


	for( i=id*4 , j=0 ; j<4 ; i++,j++)
	r1[j]=A[i];

	l1=id*24; //row index to start writing in B

    for(i=0;i<24;i++) //possibilities for row 1
    {
	for(j=0;j<4;j++)
    	{
    		flag=1;
    		for(k=0;k<4;k++)
    		{
    			if(r1[k]!=0 && r1[k]!=R1[i*4+k])
    			flag=0; 
			}
			if(flag==0) break;
			B[l1*n + j]=R1[i*4+j];	
		}
		if(flag==1)
		l1++;
	}
			for(i=l1;i<id*24+24;i++)
			for(j=0;j<4;j++)
			B[i*n + j]=0;
}
		
		printf("\n The Resultant Matrix : \n");
	for (int i = 0; i < 384; i++)
	{
		if (B[i] == 0) continue;
		else 
		{
			if((i%96)==0) cout << "\n\t ROW "<<i/96<<"\n";
			cout << B[i] << " ";
			if ((i + 1) % n == 0)
				cout << endl;
		}
	}
	////////////
	int arr[24],chosen[5], check[4], r=4,l=0,m=-1,num;

	for (int i = 0; i < 384; i+=4)
	{
		if(i%96==0)
		{
			l=0;m++;
		}
		if (B[i] != 0) l++;
		check[m]=l;
	}
    num = sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<24;i++) arr[i]=i+1;
    
    nCr(chosen, arr, 0, r, 0, num-1,check);
    cout<<"\n Posn : "<<posn;
    
  ///////////////////////////////////////////////////////// Kernel 2
  int CMB[10000];
	for (i = 0; i < posn; i++)
			for (j = 0; j < 4; j++)
				CMB[i * 4 + j] = combination[i][j];

int RES[5200]; 	
int R01[24][4], R02[24][4], R03[24][4], R04[24][4], S[4][4] ;
int combo[5200][4] ;
for(int id=0;id<posn;id++)
{
	RES[id]=0;

	
	int maxm,minm,sum,pro,f,i,j,k;

	for(i=0;i<24;i++)
	for(j=0;j<4;j++)
	{ 
		 R01[i][j]=B[(i+0) *4 + j];
		 R02[i][j]=B[(i+24)*4 + j];
		 R03[i][j]=B[(i+48)*4 + j];
		 R04[i][j]=B[(i+72)*4 + j];
	}
	

	for(i=0;i<posn;i++)
	for(j=0;j<4;j++)
	combo[i][j]=CMB[i*4+j];

int S[4][4];

i=id;

for(j=0;j<4;j++)       //LOAD SUDOKU INTO ARRAY
		S[0][j]=R01[combo[i][0]-1] [j];
		for(j=0;j<4;j++)
		S[1][j]=R02[combo[i][1]-1] [j];
		for(j=0;j<4;j++)
		S[2][j]=R03[combo[i][2]-1] [j];
		for(j=0;j<4;j++)
		S[3][j]=R04[combo[i][3]-1] [j];

	RES[id]=chk(S);
}
		
////OUTPUT 		
  for (i = 0; i < posn; i++)
		{
			if (RES[i] == 99)
			{
					cout << "\n SOLUTION ->" <<i<<" "<< combination[i][0] << combination[i][1] << combination[i][2] << combination[i][3] <<"\n";
					for(j=0;j<4;j++)
						cout<<R01[combination[i][0]-1][j]<<" "; cout<<endl;
					for(j=0;j<4;j++)
						cout<<R02[combination[i][1]-1][j]<<" ";cout<<endl;
					for(j=0;j<4;j++)
						cout<<R03[combination[i][2]-1][j]<<" ";cout<<endl;
					for(j=0;j<4;j++)
						cout<<R04[combination[i][3]-1][j]<<" ";cout<<endl;
			}
	
		}
			return 0;
 }




