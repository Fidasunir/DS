#include<stdio.h>
void main(){
    int a[30][30],b[30][30],m[30][30],i,j,k,r,c;
    printf("Enter the no.of rows: ");
    scanf("%d",&r);
    printf("Enter the no.of columns: ");
    scanf("%d",&c);
    printf("Enter the first matrix : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the second matrix : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Matrix Multiplication: \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            m[i][j]=0;
            for(k=0;k<c;k++)
            {
                m[i][j]=m[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

