#include <stdio.h>

Int main()
{
	Int count = 0, max = 0, min = 0;
	printf("Enter the number of numbers to be inputed: ");
	scanf("%d", &count);
	int arr[count];
	for (int i = 0; i < count; i++)
	{
		Printf("Enter the %dth number: ", i + 1);
		scanf("%d", &arr[i]);
		if(arr[i] > max)
		{
			max = arr[i];
		}
		If(arr[i] < min)
		{
			min = arr[i];
		}
	}
	printf("The largest number is %d and the smallest number is %d", max, min)
}
