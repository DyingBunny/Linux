#include<iostream>

int add_range(int low, int high)
{
    int i, sum;
    for (i = low; i <= high; i++) {
	sum = sum + i;
    }
    return sum;
}

int main()
{
    int result[100];
    result[0] = add_range(1, 10);
    result[1] = add_range(1, 100);
    std::cout << result[0]<<" "<< result[1] << std::endl;
    return 0;
}
