#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Cartela {
    int numeros[5][5];
    bool marcados[5][5] = {}; // Inicializa todos como n�o marcados
};

// Fun��o para gerar cartela
void geracartela(Cartela* cartela) {
    int inicio[] = {1, 16, 31, 46, 61};
    int fim[] = {15, 30, 45, 60, 75};
    for (int coluna = 0; coluna < 5; coluna++) {
        int usados[15] = {0};
        for (int linha = 0; linha < 5; linha++) {
            if (linha == 2 && coluna == 2) { 
                cartela->numeros[linha][coluna] = 0;  //faz com que o meio da cartela tenha o numero 0
                continue; 
            }
            int numero;
            do {
                numero = rand() % (fim[coluna] - inicio[coluna] + 1) + inicio[coluna]; // vai de um fim da array fim menos um inicio da array inicio
                //exemplo:(fim[coluna]=30 - inicio[coluna]=16 = 14) + 1 = 15 porque a array come�a com o numero 0 ent�o seria de 0 a 14
                // + inicio[coluna] � usado para que por exemplo na coluna i o numero 2 seja sorteado, ele faz com que seja somado o numero minimo para a coluna
                // que nesse caso � o numero 16
            } while (usados[numero - inicio[coluna]] == 1); // repete at� o numero escolhido n�o ser repetido
            usados[numero - inicio[coluna]] = 1;
            cartela->numeros[linha][coluna] = numero;
        }
    }
}

// Fun��o para mostrar cartela
void mostraCartela(Cartela* cartela) {
    cout << "B  I  N  G  O\n"; 
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (cartela->numeros[linha][coluna] == 0)
                cout << " X "; // Marca o 0 no centro da cartela com a letra X
            else if (cartela->marcados[linha][coluna])
                cout << "*" << cartela->numeros[linha][coluna] << " "; // Se o numero foi chamado, exibe com um "*" no lado esquerdo
            else
                cout << cartela->numeros[linha][coluna] << " "; // Se n�o foi chamado, exibe o n�mero
        }
        cout << endl;
    }
}

// Fun��o para marcar cartela
bool marcarcartela(Cartela* cartela, int numero) {
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (cartela->numeros[linha][coluna] == numero) {
                cartela->marcados[linha][coluna] = true; //marca true na array marcados na linhae coluna que o numero esta na cartela
                return true;
            }
        }
    }
    return false; // Se n�o est� na cartela, retorna falso
}

// Fun��o para verificar bingo
void verificabingo(Cartela* cartela) {
    // Verificar linhas completas
    for (int linha = 0; linha < 5; linha++) {
        bool linhacompleta = true;
        for (int coluna = 0; coluna < 5; coluna++) {
            if (!cartela->marcados[linha][coluna] && cartela->numeros[linha][coluna] != 0){
             //determina que se o numero na linha e coluna que esta sendo verificadda n�o est� marcado como true na array marcados a linha n�o esta completa
            //cartela->numeros[linha][coluna] != 0 lembra de contar tambem o zero da cartela
                linhacompleta = false;
                break;
            }
        }
        if (linhacompleta) {
            cout << "LINHA COMPLETA!\n"; //se todos os numeros da linha estiverem marcados retorna informando que a linha esta completa
            return;
        }
    }

    // Verificar colunas completas
    for (int coluna = 0; coluna < 5; coluna++) {
        bool colunacompleta = true;
        for (int linha = 0; linha < 5; linha++) {
            if (!cartela->marcados[linha][coluna] && cartela->numeros[linha][coluna] != 0) {
                //determina que se o numero na linha e coluna que esta sendo verificadda n�o est� marcado como true na array marcados a linha n�o esta completa
            //cartela->numeros[linha][coluna] != 0 lembra de contar tambem o zero da cartela
                colunacompleta = false;
                break;
            }
        }
        if (colunacompleta) {
            cout << "COLUNA COMPLETA!\n";
            return;
        }
    }

    // Verificar se a cartela est� cheia
    bool cartelacheia = true;
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (!cartela->marcados[linha][coluna] && cartela->numeros[linha][coluna] != 0) {
                cartelacheia = false;
                break;
            }
        }
    }
    if (cartelacheia) {
        cout << "BINGO!\n";
    }
}

int main() {
    srand(time(0));  // Inicializa o gerador de n�meros aleat�rios
    int quantidadeDeCartelas;
    cout << "Digite a quantidade de cartelas a serem geradas: ";
    cin >> quantidadeDeCartelas;
    Cartela cartelas[quantidadeDeCartelas];  // Vetor fixo de cartelas

    // Vetor para armazenar os n�meros chamados
    int numerosChamados[76];  
    int quantidadeChamados = 0;  // Para controlar a quantidade de n�meros chamados

    int opcao;
    do {
        cout << "\nMenu:\n";
        cout << "1. Gerar cartela(s)\n";
        cout << "2. Exibir cartela(s)\n";
        cout << "3. Marcar numero\n";
        cout << "4. Exibir n�meros chamados\n";  // Op��o para exibir n�meros chamados
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            // Gerar as cartelas
            for (int i = 0; i < quantidadeDeCartelas; i++) {
                geracartela(&cartelas[i]); // Cria uma nova cartela
            }
            cout << quantidadeDeCartelas << " cartelas geradas com sucesso!\n";
        } 
        else if (opcao == 2) {
            if (quantidadeDeCartelas == 0) {
                cout << "Nenhuma cartela gerada.\n";
            } else {
                for (int i = 0; i < quantidadeDeCartelas; i++) {
                    cout << "\nCartela " << i + 1 << ":\n";
                    mostraCartela(&cartelas[i]); // Exibe as cartelas geradas
                }
            }
        } 
        else if (opcao == 3) {
            cout << "Digite o numero chamado: ";
            int numero;
            cin >> numero;

            // Armazenar o n�mero chamado no vetor
            if (quantidadeChamados < 76) {
                numerosChamados[quantidadeChamados] = numero;
                quantidadeChamados++;
            }

            bool numeroMarcado = false;
            // Marcar o n�mero em todas as cartelas
            for (int i = 0; i < quantidadeDeCartelas; i++) {
                if (marcarcartela(&cartelas[i], numero)) {
                    numeroMarcado = true;
                    cout << "Numero " << numero << " marcado na cartela " << i + 1 << ".\n";
                }
            }

            if (numeroMarcado) {
                for (int i = 0; i < quantidadeDeCartelas; i++) {
                    verificabingo(&cartelas[i]);
                }
            } else {
                cout << "Numero n�o encontrado em nenhuma cartela.\n";
            }
        }
        else if (opcao == 4) {
            cout << "N�meros chamados: ";
            for (int i = 0; i < quantidadeChamados; i++) {
                cout << numerosChamados[i] << " ";  // Exibe todos os n�meros chamados
            }
            cout << endl;
        }
    } while (opcao != 5);

    cout << "Bingo encerrado\n";
    return 0;
}

