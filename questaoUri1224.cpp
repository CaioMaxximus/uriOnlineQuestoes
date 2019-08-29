#include <stdlib.h>
#include <stack>
#include <list>
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include <sstream>


using namespace std;

//num carta representa quantas cartas ja foram escolhidas

int totalCartas;
int numTentativas;
list<int> listaDePossibilidades;

void cards(vector<int> cartas, int direita, int esquerda, int numCartasEscolhidas, int probabilidadesTotais, int cartaEscolhidaIndex, int albertoPts, int jogador)
{
    for (int i = esquerda; i <= direita; i++)
    {
        cout << cartas[i] << " , "  ;
    }cout << endl;
    
     if (numTentativas != probabilidadesTotais - 1)
    {
        int ptsAcumulados = albertoPts;
        if (jogador == 1)
        {   
            ptsAcumulados += cartas[cartaEscolhidaIndex];
            cout << "Jogador 1, vez;" << endl;
            cout << "ptssAcumulados: " << ptsAcumulados << endl;
            cout << "numCartasEscolhidas " << numCartasEscolhidas << endl;
            cout << "probabilidadesTotais " << probabilidadesTotais << endl;
            cout << "cartaEscolhidaIndex " << cartaEscolhidaIndex << endl;
            cout << "direita " << direita << endl;
            cout << "esquerda " << esquerda << endl;
            cout << "----- ----- -----" << endl;
            
            if (esquerda == 0 && direita == probabilidadesTotais - 1)
            {
                cout << "comecou o jogo!" << endl;
                cards(cartas, direita - 1, esquerda, numCartasEscolhidas + 1, probabilidadesTotais, direita, albertoPts, 0);
                cards(cartas, direita, esquerda + 1, numCartasEscolhidas + 1, probabilidadesTotais, esquerda, albertoPts, 0);
            }
            else if (numCartasEscolhidas == totalCartas)
            {
                //quando tiver lido todas as cartas
                //Pega a maior carta e volta
                cout << "ponto de parada" << endl;
                numTentativas += 1;
                listaDePossibilidades.push_back(ptsAcumulados);
            }
            else
            {

                cards(cartas, direita - 1, esquerda, numCartasEscolhidas + 1, probabilidadesTotais, direita, ptsAcumulados, 0);
                cards(cartas, direita, esquerda + 1, numCartasEscolhidas + 1, probabilidadesTotais, esquerda, ptsAcumulados, 0);
            }
        }
        else
        {
            cout << "Jogador 2, vez;" << endl;
            if (cartas[direita] > cartas[esquerda])
            {
                cards(cartas, direita - 1, esquerda, numCartasEscolhidas + 1, probabilidadesTotais, cartaEscolhidaIndex, ptsAcumulados, 1);
            }
            else
            {
                cards(cartas, direita, esquerda + 1, numCartasEscolhidas + 1, probabilidadesTotais, cartaEscolhidaIndex, ptsAcumulados, 1);
            }
        }
    }
    cout << "----- ----- -----" << endl;
}

int main()
{
    //formula da quantidade de possibilidades  = numCartas
    int totalCartas  = 0;
    numTentativas = 0;
    vector<int> cartas;
    stringstream streamNum;

    int num = 0;
    bool encontrou = false;
    int i = 0;

    char * entrada;
    entrada = (char*) malloc (sizeof(string)); 


    if(fgets(entrada,sizeof(entrada)/sizeof(entrada[0]),stdin) == NULL){
        goto saida;
    }
    fflush(stdin);
    string numString;
	while(isdigit(entrada[i])  || entrada[i] == ' '){
		if(entrada[i] == ' '){
			encontrou = true;
		}
		if(!encontrou){
            numString += entrada[i];
            
		}else{
            streamNum << numString;
            totalCartas += 1;
           streamNum >> num;
            cartas.push_back(num);
            num = 0;
            encontrou = false;
		}i++;
    }

    for (int i = 0; i < totalCartas; i++)
    {
       cout <<  cartas[i] << endl;
    }

    // cartas.push_back(47);
    // cartas.push_back(50);
    // cartas.push_back(-3);
    // cartas.push_back(7);

    // cards(cartas, 3, 0, 0, 4, 0, 0, 1);
    // for (int i = 0; i < totalCartas; i++)
    // {
    //     cout << listaDePossibilidades.back() << endl;
    //     listaDePossibilidades.pop_back();
    // }
    saida:
    return 0;
}