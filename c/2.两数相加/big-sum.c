/*************************************************************************
    > File Name: big-sum.c
    > Author: chaofei
    > Mail: chaofeibest@163.com 
    > Created Time: 2020-01-16 22:27:20
 ************************************************************************/

#include <stdio.h>

typedef struct bigint
{
    char *num;                //指向长整数数组（序号0中保存着最高位）
    char sign;               //符号（1表示正数，-1表示负数）
    int digit;                 //保存该数的位数（实际位数）
}BIGINT, *pBIGINT;

void BigIntAdd(pBIGINT num1,pBIGINT num2,pBIGINT result)
{
    int i,carry;
    carry=0;                              //清除进位 
    result->sign =num1->sign;           //保存符号 
    //将被加数复制到结果数组中 
    for(i=0;i<num1->digit;i++)             
        result->num[i]=num1->num[i];
    //num2中的数小，可能位数也少些 
    for(i=0;i<num2->digit;i++)               
    {
        //将对应位的数和进位数相加 
        result->num[i]=result->num[i]+num2->num[i]+carry;    
        carry=result->num[i]/10;       //计算进位数据 
        result->num[i]=result->num[i]%10;     //保留一位 
    }
    if(carry)                       //若最后还有进位 
        result->num[i]=result->num[i]+carry;
    BigIntTrim(result);                //整理结果 
} 

int main(void) {
    return 0;
}
