#include <stdio.h>

#define NMAX 101
#define SIZE 16

int N;
int arr[17] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
//{ 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5 };
int bitree[NMAX];

void add(int pos, int val)
{
	while (pos<=SIZE)
	{
		bitree[pos] += val;		
		pos += (pos & -pos);
	}	
}

int subSum(int pos)
{
	int ret=0;

	while (pos !=0)
	{
		ret+=bitree[pos];

		pos = (pos & (pos -1));
	}
	return ret;
}

int main()
{
	int i, j;

	for (i = 1; i <= 16; i++)
		add(i, arr[i]);

	for (i = 1; i <= 16; i++)
	{
		printf("Sum(1~%d) = %d\n", i, subSum(i));
		
	}

	printf("\n");
}