#include<stdio.h>
int main()
{
	int a[50],i,item,n,flag=0;
	printf("enter size of the array:");
	scanf("%d",&n);
	printf("enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter element to be searched:");
	scanf("%d",&item);
	for(i=0;i<n;i++)
        {
         	if(a[i]==item)
		{
			printf("%d present at position %d",item,i);
			flag=1;
		}
		if(flag==-1)
		{
			printf("item is not found");
		}
	}
}
