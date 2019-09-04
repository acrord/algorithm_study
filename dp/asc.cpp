#include <stdio.h>
#include <stdlib.h>

int arr[1000+1];
int sol[1000+1]; 

int N;
int main(void)
{
	int i;
	int max;
	int ind;

	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	max = 0;
	sol[1] = arr[0];
	for(i=0; i<N; i++)
	{
		ind = max;
		for(;;)
		{	
			if(sol[ind] < arr[i])
			{
				if(ind == max)
				{
					max++;
					sol[max] = arr[i];
				}
				else
				{
					sol[ind+1] = arr[i];
				}
				break;
			}
			if(--ind<0)
				break;
		}
	}
	printf("%d\n",max);
	return 0;
}