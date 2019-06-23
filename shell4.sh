#!/bin/bash
#a test about sort

echo "please input a number list"
read -a arrs
for((i=0;i<${#arrs[@]};i++))
{
    for((j=0;j<${#arrs[@]}-1;j++))
    {
	if [[ ${arrs[j]} -gt ${arrs[j+1]} ]]; then
	tmp=${arrs[j]}
	arrs[j]=${arrs[j+1]}
	arrs[j+1]=$tmp
	fi
    }
}
echo "after sort"
echo ${arrs[@]}

