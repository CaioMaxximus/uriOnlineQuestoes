#include <stdio.h>
#include <iostream>
#include <math.h>

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

	int num1;
	int num2;

	cin >> num1;
	cin >> num2;
	int array1[32];
	intToBinary(num1,array1);
	int array2[32];
	intToBinary(num2,array2);
	
	cout << "segundo numero" << endl;
	for (int i = 0; i < 32; ++i)
	{
		cout << array1[i];
	}
	
	cout << endl;
	
	cout << "primeiro numero" << endl;

	for (int i = 0; i < 32; ++i){	
		cout << array2[i];
	}
	cout << somaSemCarry(array1,array2);
}

