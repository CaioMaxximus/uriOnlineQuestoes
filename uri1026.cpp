#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>

//https://www.urionlinejudge.com.br/judge/en/runs/add/1026

using namespace std;

void intToBinary(unsigned int num,int* numBinario)
{
	unsigned int dividendo = num;
	const  int divisor = 2;
	unsigned int resultado = 1;

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

unsigned int  binaryToInt(int *array){
	
	unsigned int saida = 0;

	int count = 31;

	for (int i = 0; i < 32; i++)
	{
		saida += pow(2,count) * array[i];
		count --;
	}
	
	return saida;
}

unsigned int somaSemCarry(int *array1,int *array2){
	int arraySoma[32];
	unsigned int saida = 0;
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
	inicio:
	string strNum1 = "";
	string strNum2 = "";
	register char entrada[30];
	
	unsigned int num1 = 0;
	unsigned int num2 = 0;
	bool encontrouPrimeiro = false;
	int i = 0;
	stringstream streamNum1;
	stringstream streamNum2;

	register int array1[32];
	register int array2[32];

	if(fgets(entrada,sizeof(entrada)/sizeof(entrada[0]),stdin) == NULL){
		goto saida;
	}
	fflush(stdin);
	while(isdigit(entrada[i])  || entrada[i] == ' '){
		if(entrada[i] == ' '){
			encontrouPrimeiro = true;
		}
		if(!encontrouPrimeiro){
			strNum1 += entrada[i];
		}else{
			strNum2 += entrada[i];
		}i++;
	}

	streamNum1 << strNum1;
	streamNum2 << strNum2;

	streamNum1 >> num1;
	streamNum2 >> num2;

	intToBinary(num1,array1);
	intToBinary(num2,array2);

	
	cout << somaSemCarry(array1,array2)<< endl;;
	

	goto inicio;

	saida:
	return 0;
}

