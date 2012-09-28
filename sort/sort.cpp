
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;

    return 0;

}

int selectSort(int *a, int n)
{
    int min;
    for(int i = 0; i < n; ++i)
    {
		min = i;
		for(int j = i+1; j < n; ++j)
		{
		    if(a[j] < a[min])
		    {
			min = j;
		    }
		}
		if(i != min)
		{
		    swap(a[i], a[min]);
		}
	}
    return 0;
}

int insertSort(int *a, int n)
{
	for(int i = 1; i < n; ++i)
	{
		int tmp = a[i];
		int j;
		for(j = i; j > 0 && tmp < a[j-1]; --j)
		{
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
    return 0;
}

int shellSort(int *a, int n)
{
	for(int gap = n/2; gap > 0; gap /= 2)
	{
		for(int i = gap; i < n; ++i)
		{
			for(int j = i-gap; j > 0 && a[j] > a[j+gap]; j -= gap)
			{
				swap(a[j], a[j+gap]);
			}
		}
	}
    return 0;
}

int bubbleSort(int *a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		bool isSwap = false;
		for(int j = 1; j < n-i; ++j)
		{
			if(a[j] < a[j-1])
			{
				swap(a[j], a[j-1]);
				isSwap = true;
			}
		}
		if(!isSwap)
			break;
	}
    return 0;
}

int quickSort(int *a, int l, int r)
{
	if(l < r)
	{
		int i = l;
		int j = r;
		int x = a[l];

		while(i < j)
		{
			while(i < j && a[j] > x)
				--j;

			if(i < j)
				a[i++] = a[j];

			while(i < j && a[i] < x)
				++i;

			if(i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		quickSort(a, l, i-1);
		quickSort(a, i+1, r);
	}

    return 0;
}


int main()
{
//    int a[] = {1, 99, 22, 34, 65, 3, 87, 1, 23, 21};
	long start = 0;
	long end = 0;
	const int num = 60000;
	int a[num];
	for(int k = 0; k < num; ++k)
	{
		a[k] = rand()%num;
	}
	/*
    for(int i = 0; i < num; ++i)
    {
		printf("%d-",a[i]);
    }
    printf("\n");
	*/
    //selectSort(a, 10);
	//insertSort(a, 10);
	//quickSort(a, 0, 9);
	//bubbleSort(a, 10);
	start = clock();
	quickSort(a, 0, num-1);
	//bubbleSort(a, 10);
	//shellSort(a, num);
	end = clock();
    for(int i = 0; i < num; ++i)
    {
		printf("%d-",a[i]);
    }
    printf("\n");
	printf("the time ---%ld ---\n",(end-start)/1000);
    return 0;
}
