// Máquina de Café 

// O novo prédio da Sociedade Brasileira de Computação (SBC) possui 3 andares. Em determinadas épocas do ano, os funcionários da SBC bebem muito café. Por conta disso, a presidência da SBC decidiu presentear os funcionários com uma nova máquina de expresso. Esta máquina deve ser instalada em um dos 3 andares, mas a instalação deve ser feita de forma que as pessoas não percam muito tempo subindo e descendo escadas.

// Cada funcionário da SBC bebe 1 café expresso por dia. Ele precisa ir do andar onde trabalha até o andar onde está a máquina e voltar para seu posto de trabalho. Todo funcionário leva 1 minuto para subir ou descer um andar. Como a SBC se importa muito com a eficiência, ela quer posicionar a máquina de forma a minimizar o tempo total gasto subindo e descendo escadas.

// Sua tarefa é ajudar a diretoria a posicionar a máquina de forma a minimizar o tempo total gasto pelos funcionários subindo e descendo escadas.

// Entrada
// A entrada consiste em 3 números, A1 , A2 , A3 (0 ≤ A1 , A2 , A3 ≤ 1000), um por linha, onde Ai representa o número de pessoas que trabalham no i-ésimo andar.

// Saída
// Seu programa deve imprimir uma única linha, contendo o número total de minutos a serem gastos com o melhor posicionamento possível da máquina.


// Todo funcionário leva 1 minuto para subir ou descer um andar
// -> tempo gasto = (andarAtual - andarTotal) * 2


// Posicionar a máquina de forma a minimizar o tempo total gasto pelos funcionários subindo e descendo escadas


#include <iostream>

using namespace std;

int main(){
    int op = 0;
    int menorTempo = 10000000;
    int funcionarios[3];
    cout << "Insira o numero de pessoas que trabalham por andar. " << endl;
    for (int i = 0; i < 3; ++i){
        cin >> funcionarios[i];
    }
     
    // Testar todos os casos para todos os andares e verificar o menor
    for(int i = 0; i < 3; ++i){
        int tempo = 0;
        for (int j = 0; j < 3;++j){
            tempo += funcionarios[j] * abs(i - j) * 2; //QuantFunc * difAndar * 2min
        }

        if (tempo < menorTempo) menorTempo = tempo;
    }

    cout << menorTempo << endl;



    return 0;
}