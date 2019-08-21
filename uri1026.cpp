#include <stdio.h>
#include <iostream>
#include <math.h>
#include<stdlib.h>

//https://www.urionlinejudge.com.br/judge/en/runs/add/1026

using namespace std;

void intToBinary(int num,int* numBinario)
{
	int dividendo = num;
	int divisor = 2;
	int resultado = -1;

	for (int i = 31; i >= 0; --i)
	{
		if (resultado != 0)
		{
			resultado = dividendo / divisor;
			numBinario[i] = dividendo % divisor;
			dividendo = resultado;
		}
		else
		{
			numBinario[i] = resultado;
		}
	}
}

int  binaryToInt(int *array){
	
	int saida = 0;

	int count = 31;

	for (int i = 0; i < 32; i++)
	{
		saida += pow(2,count) * array[i];
		count --;
	}
	
	return saida;
}

int somaSemCarry(int *array1,int *array2){
	int arraySoma[32];
	int saida = 0;
	int soma = 0;
	int bitArray1 = 0;
	int bitArray2 = 0;
	for (int i = 0; i < 32; i++)
	{
		bitArray1 = array1[i];
		bitArray2 = array2[i];
		if(bitArray1 == 0 && bitArray2 == 1 || bitArray1 == 1 && bitArray2 == 0){
			soma = 1;
		}
		else{
			soma = 0;
		}
		arraySoma[i] = soma;
			
	}

	saida = binaryToInt(arraySoma);
	

}


int main()
{
	char *entrada = (char*) malloc(sizeof(char));
	int num1 = 0;
	int num2 = 0;
	inicio:

	gets(entrada);

	if(*entrada == EOF){
		goto saida;
	}
		/* code */
	
	num1 = (int) entrada[0];
	num2 = (int) entrada[2];
	int array1[32];
	intToBinary(num1,array1);
	int array2[32];
	intToBinary(num2,array2);
	cout << somaSemCarry(array1,array2)<< endl;;
	goto inicio;

	saida:
	return 0;
}

