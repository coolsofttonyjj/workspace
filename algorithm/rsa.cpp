/**
 * @file rsa.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-06-08
 */

#include <stdio.h>
#include <math.h>

#define P 3
#define Q 11
#define N (P*Q)
#define Z ((P-1)*(Q-1))
#define E 3
#define D 7

int main( int argc, char* argv[] )
{
	int TrsMsg[4] = {12,15,22,5};
	long en[4], de[4];
	int SecCode[4], DeMsg[4];
	printf( "下面是一个RSA加解密算法的简单演示:\n" );
	printf( "\t Copyright(C) Tony.\n\n" );
	printf( "报文\t加密\t\t加密后密文\n" );

	for( int i = 0; i < 4; ++i )
	{
		en[i] = (int)pow(TrsMsg[i], E);
		SecCode[i] = en[i] % N;
		printf("%d\t%d\t\t%d\n", TrsMsg[i], en[i], SecCode[i]);
	}

	printf("原始报文\t密文\t加密\t\t解密报文\n");

	for( int i = 0; i < 4; ++i )
	{
		de[i] = pow( SecCode[i], D );
		DeMsg[i] = de[i] % N;
		printf("%d\t%d\t%d\t\t%d\n", TrsMsg[i], SecCode[i],de[i], DeMsg[i] );
	}
	return 0;
}
