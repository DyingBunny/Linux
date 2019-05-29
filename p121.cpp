#include<iostream>

int main()
{
    int sum = 0, i = 0;
    char input[5];

    while (1) {
	sum = 0;
	std::cin >> input;
	for (i = 0; input[i] != '\0'; i++) {
	    sum = sum * 10 + input[i] - '0';
	}
	std::cout << sum << std::endl;
    }
    return 0;
}
