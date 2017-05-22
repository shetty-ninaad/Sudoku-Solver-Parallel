#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int R[24][4], pos=0;
int combination[6000][4],posn=0; //posn -> sizeof combination array

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
printf(" ");
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

void load_check(int R1[24][4], int R2[24][4], int R3[24][4], int R4[24][4])
{
	int S[4][4],i,j,k;
	int max,min,sum,pro,f;
	for(i=0;i<posn;i++)
	{
		for(j=0;j<4;j++)       //LOAD SUDOKU INTO ARRAY
		S[0][j]=R1[combination[i][0]-1] [j];
		for(j=0;j<4;j++)
		S[1][j]=R2[combination[i][1]-1] [j];
		for(j=0;j<4;j++)
		S[2][j]=R3[combination[i][2]-1] [j];
		for(j=0;j<4;j++)
		S[3][j]=R4[combination[i][3]-1] [j];
		
		//CHECK SUDOKU
		
		//CHECK COLUMN
		for(k=0;k<4;k++)
		{
			f=1;sum=0;pro=1;max=0;min=5;
			for(j=0;j<4;j++)
			{
				sum+=S[j][k];
				pro*=S[j][k];
				if(max<S[j][k]) max=S[j][k];
				if(min>S[j][k]) min=S[j][k];
			}
			if(max!=4 || min!=1 ||sum!=10 || pro!=24 )
			{
				f=0;break;
			}
	    }
	    if(f==1) //CHECK BOX
	    {
	    	sum=0;pro=1;max=0;min=5;
			sum=S[0][0]+S[0][1]+S[1][0]+S[1][1];
	    	pro=S[0][0]*S[0][1]*S[1][0]*S[1][1];
	    	min=(S[0][0]<S[0][1])?(S[0][0]<S[1][0])?(S[0][0]<S[1][1])?S[0][0]:S[1][1]:(S[1][0]<S[1][1])?S[1][0]:S[1][1]:(S[0][1]<S[1][0])?(S[0][1]<S[1][1])?S[0][1]:S[1][1]:(S[1][0]<S[1][1])?S[1][0]:S[1][1];
	    	max=(S[0][0]>S[0][1])?(S[0][0]>S[1][0])?(S[0][0]>S[1][1])?S[0][0]:S[1][1]:(S[1][0]>S[1][1])?S[1][0]:S[1][1]:(S[0][1]>S[1][0])?(S[0][1]>S[1][1])?S[0][1]:S[1][1]:(S[1][0]>S[1][1])?S[1][0]:S[1][1];
	    
	    	if(max==4 && min==1 &&sum==10 && pro==24 )
			{
				sum=0;pro=1;max=0;min=5;
				sum=S[2][0]+S[2][1]+S[3][0]+S[3][1];
	    		pro=S[2][0]*S[2][1]*S[3][0]*S[3][1];
	    		min=(S[2][0]<S[2][1])?(S[2][0]<S[3][0])?(S[2][0]<S[3][1])?S[2][0]:S[3][1]:(S[3][0]<S[3][1])?S[3][0]:S[3][1]:(S[2][1]<S[3][0])?(S[2][1]<S[3][1])?S[2][1]:S[3][1]:(S[3][0]<S[3][1])?S[3][0]:S[3][1];
	    		max=(S[2][0]>S[2][1])?(S[2][0]>S[3][0])?(S[2][0]>S[3][1])?S[2][0]:S[3][1]:(S[3][0]>S[3][1])?S[3][0]:S[3][1]:(S[2][1]>S[3][0])?(S[2][1]>S[3][1])?S[2][1]:S[3][1]:(S[3][0]>S[3][1])?S[3][0]:S[3][1];
	            
	            if(max==4 && min==1 &&sum==10 && pro==24 )
				{
					sum=0;pro=1;max=0;min=5;
					sum=S[2][2]+S[2][3]+S[3][2]+S[3][3];
	    			pro=S[2][2]*S[2][3]*S[3][2]*S[3][3];
	    			min=(S[2][2]<S[2][3])?(S[2][2]<S[3][2])?(S[2][2]<S[3][3])?S[2][2]:S[3][3]:(S[3][2]<S[3][3])?S[3][2]:S[3][3]:(S[2][3]<S[3][2])?(S[2][3]<S[3][3])?S[2][3]:S[3][3]:(S[3][2]<S[3][3])?S[3][2]:S[3][3];
	    			max=(S[2][2]>S[2][3])?(S[2][2]>S[3][2])?(S[2][2]>S[3][3])?S[2][2]:S[3][3]:(S[3][2]>S[3][3])?S[3][2]:S[3][3]:(S[2][3]>S[3][2])?(S[2][3]>S[3][3])?S[2][3]:S[3][3]:(S[3][2]>S[3][3])?S[3][2]:S[3][3];
	                
	                if(max==4 && min==1 &&sum==10 && pro==24 )
					{
						sum=0;pro=1;max=0;min=5;
						sum=S[0][2]+S[0][3]+S[1][2]+S[1][3];
	    				pro=S[0][2]*S[0][3]*S[1][2]*S[1][3];
	    				min=(S[0][2]<S[0][3])?(S[0][2]<S[1][2])?(S[0][2]<S[1][3])?S[0][2]:S[1][3]:(S[1][2]<S[1][3])?S[1][2]:S[1][3]:(S[0][3]<S[1][2])?(S[0][3]<S[1][3])?S[0][3]:S[1][3]:(S[1][2]<S[1][3])?S[1][2]:S[1][3];
	    				max=(S[0][2]>S[0][3])?(S[0][2]>S[1][2])?(S[0][2]>S[1][3])?S[0][2]:S[1][3]:(S[1][2]>S[1][3])?S[1][2]:S[1][3]:(S[0][3]>S[1][2])?(S[0][3]>S[1][3])?S[0][3]:S[1][3]:(S[1][2]>S[1][3])?S[1][2]:S[1][3];
	                    
	                    if(max==4 && min==1 &&sum==10 && pro==24 )
						{
							
							cout<<"\n\n\t -- SOLUTION -- \n";
	    					for(j=0;j<4;j++)
							{
								cout<<"\n\t";
								for(k=0;k<4;k++)
									cout<<S[j][k]<<" ";	
	    					}
						}
				}
			}
	    }
	}

}
}
int main()
{
	int A[4][4];
	int R1[24][4], R2[24][4], R3[24][4], R4[24][4];
	int r1[4], r2[4], r3[4], r4[4];
	int S[24][4];
	int i,j,k,n,l1,l2,l3,l4,flag;
	int temp[4]={1,2,3,4};
    cout<<"\n Enter the values of input (4X4 SUDOKU) -> \n";
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    cin>>A[i][j];
    
    for(i=0;i<4;i++)
    {
		r1[i]=A[0][i];
    	r2[i]=A[1][i];
    	r3[i]=A[2][i];
    	r4[i]=A[3][i];
    }
    
    permute(temp);
    
///////// PERMUTATIONS OF ALL POSSIBLE ROWS ////////////////////
	
    l1=0;
    for(i=0;i<pos;i++) //possibilities for row 1
    {
	for(j=0;j<4;j++)
    	{
    		flag=1;
    		for(k=0;k<4;k++)
    		{
    			if(r1[k]!=0 && r1[k]!=R[i][k])
    			flag=0; 
			}
			if(flag==0) break;
			R1[l1][j]=R[i][j];	
		}
		if(flag==1)
		l1++;
	}
	cout<<"\n\n--ROW 1--\n";
	 for(i=0;i<l1;i++)  //display of row 1 possibilities
    {
      cout<<"\n\t";
	  for(j=0;j<4;j++)
    	cout<<" "<<R1[i][j];
	}
	
	    l2=0;
    for(i=0;i<pos;i++) //possibilities for row 2
    {
	for(j=0;j<4;j++)
    	{
    		flag=1;
    		for(k=0;k<4;k++)
    		{
    			if(r2[k]!=0 && r2[k]!=R[i][k])
    			flag=0; 
			}
			if(flag==0) break;
			R2[l2][j]=R[i][j];	
		}
		if(flag==1)
		l2++;
	}
	cout<<"\n\n--ROW 2--\n";
	 for(i=0;i<l2;i++)  //display of row 2 possibilities
    {
      cout<<"\n\t";
	  for(j=0;j<4;j++)
    	cout<<" "<<R2[i][j];
	}
	
	    l3=0;
    for(i=0;i<pos;i++) //possibilities for row 3
    {
	for(j=0;j<4;j++)
    	{
    		flag=1;
    		for(k=0;k<4;k++)
    		{
    			if(r3[k]!=0 && r3[k]!=R[i][k])
    			flag=0; 
			}
			if(flag==0) break;
			R3[l3][j]=R[i][j];	
		}
		if(flag==1)
		l3++;
	}
	cout<<"\n\n--ROW 3--\n";
	 for(i=0;i<l3;i++)  //display of row 3 possibilities
    {
      cout<<"\n\t";
	  for(j=0;j<4;j++)
    	cout<<" "<<R3[i][j];
	}
	
	    l4=0;
    for(i=0;i<pos;i++) //possibilities for row 4
    {
	for(j=0;j<4;j++)
    	{
    		flag=1;
    		for(k=0;k<4;k++)
    		{
    			if(r4[k]!=0 && r4[k]!=R[i][k])
    			flag=0; 
			}
			if(flag==0) break;
			R4[l4][j]=R[i][j];	
		}
		if(flag==1)
		l4++;
	}
	cout<<"\n\n--ROW 4--\n";
	 for(i=0;i<l4;i++)  //display of row 4 possibilities
    {
      cout<<"\n\t";
	  for(j=0;j<4;j++)
    	cout<<" "<<R4[i][j];
	}
//////////////// Computing PERMUTATIONS & COMBINATIONS OF ALL ROWS ////////////////////	
   
	int arr[24],chosen[5], check[4], r=4;
    check[0]=l1;check[1]=l2;check[2]=l3;check[3]=l4;
    n = sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<24;i++) arr[i]=i+1;
    
    nCr(chosen, arr, 0, r, 0, n-1,check);

///////////////// Checking if it follows SUDOKU RULES //////////////////////////////	
	load_check(R1,R2,R3,R4);
	return 0;
}



/* 
QUESTION 

0 2 0 4
3 0 0 1
0 0 1 0
0 0 4 0

1 0 0 0
0 2 0 0
0 0 3 0
0 0 0 4

*/
