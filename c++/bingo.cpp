#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Cartela {
    int numeros[5][5];
    bool marcados[5][5] = {}; // Inicializa todos como não marcados
};

// Função para gerar cartela
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
                numero = rand() % (fim[coluna] - inicio[coluna] + 1) + inicio[coluna]; //vai de um fim da array fim menos um inicio da array inicio
            } while (usados[numero - inicio[coluna]] == 1); //repete até o numero escolhido não ser repetido
            usados[numero - inicio[coluna]] = 1;
            cartela->numeros[linha][coluna] = numero;
        }
    }
}

// Função para mostrar cartela
void mostraCartela(Cartela* cartela) {
    cout << " B  I  N  G  O\n";
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (cartela->numeros[linha][coluna] == 0)
                cout << " X "; // Marca o 0 no centro da cartela com a letra X
            else if (cartela->marcados[linha][coluna])
                cout << "*" << cartela->numeros[linha][coluna] << " "; // Se o numero foi chamado, exibe com um "*" no lado esquerdo
            else
                cout << cartela->numeros[linha][coluna] << " "; // Se não foi chamado, exibe o número
        }
        cout << endl;
    }
}

// Função para marcar cartela
bool marcarcartela(Cartela* cartela, int numero) {
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (cartela->numeros[linha][coluna] == numero) {
                cartela->marcados[linha][coluna] = true;
                return true;
            }
        }
    }
    return false; // Se não está na cartela, retorna falso
}

// Função para verificar bingo
void verificabingo(Cartela* cartela) {
    // Verificar linhas completas
    for (int linha = 0; linha < 5; linha++) {
        bool linhacompleta = true;
        for (int coluna = 0; coluna < 5; coluna++) {
            if (!cartela->marcados[linha][coluna] && cartela->numeros[linha][coluna] != 0) {
                linhacompleta = false;
                break;
            }
        }
        if (linhacompleta) {
            cout << "LINHA COMPLETA!\n";
            return;
        }
    }

    // Verificar colunas completas
    for (int coluna = 0; coluna < 5; coluna++) {
        bool colunacompleta = true;
        for (int linha = 0; linha < 5; linha++) {
            if (!cartela->marcados[linha][coluna] && cartela->numeros[linha][coluna] != 0) {
                colunacompleta = false;
                break;
            }
        }
        if (colunacompleta) {
            cout << "COLUNA COMPLETA!\n";
            return;
        }
    }

    // Verificar se a cartela está cheia
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
    srand(time(0));  // Inicializa o gerador de números aleatórios
    Cartela cartelas[10];  // Vetor fixo de 10 cartelas
    int opcao;
    int quantidadeDeCartelas = 0;

    do {
        cout << "\nMenu:\n";
        cout << "1. Gerar cartela(s)\n";
        cout << "2. Exibir cartela(s)\n";
        cout << "3. Marcar numero\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            cout << "Digite a quantidade de cartelas a serem geradas (máximo 10): ";
            cin >> quantidadeDeCartelas;
            
            if (quantidadeDeCartelas > 10) {
                cout << "Máximo de 10 cartelas permitidas.\n";
                quantidadeDeCartelas = 10;
            }

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

            bool numeroMarcado = false;
            // Marcar o número em todas as cartelas
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
                cout << "Numero não encontrado em nenhuma cartela.\n";
            }
        }
    } while (opcao != 4);

    cout << "Bingo encerrado\n";
    return 0;
}
