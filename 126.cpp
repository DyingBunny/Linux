#include<iostream>

int main()
{
    int sum=0,i=0;
    char input[5];

    std::cin>>input;
    for(i=0;input[i]!='\0';i++)
    {
	if(input[i]<'0'||input[i]>'9')
	{
	    std::cout<<"Invalid input"<<std::endl;
	    sum=-1;
	    break;
	}
	sum=sum*10+input[i]-'0';
    }
    std::cout<<sum<<std::endl;
    return 0;
}
