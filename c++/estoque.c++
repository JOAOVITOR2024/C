#include <iostream>
using namespace std;

bool cadastro_completo(int matriz[][3], int tamanho, int indice) {
    if (indice < 0 || indice >= tamanho) {
        return false; 
    }

    if (matriz[indice][0] != 0 && matriz[indice][1] != 0 && matriz[indice][2] != 0) {
        return true;  
    } 
    else {
        return false;  
    }
}

int main() {
    int op, tamanho, i = 0, op2, remover, adicionar, produto_escolhido, minima;

    cout << "Quantos produtos podem ser cadastrados?\n";
    cin >> tamanho;

    int matriz[tamanho][3];

    do {
        cout << "1-CADASTRAR PRODUTO\n"
             << "2-ATUALIZAR QUANTIDADE\n"
             << "3-GERAR RELATORIO DE PRODUTOS\n"
             << "4-LISTAR PRODUTOS COM BAIXA QUANTIDADE\n"
             << "5-SAIR\n";

        cin >> op;

        switch (op) {
          case 1:
    if (i < tamanho) {
        int codigoNovo;
        bool codigoJaExiste = false;

        cout << "Digite as seguintes informacoes do produto:\n";
        cout << "Codigo: ";
        cin >> codigoNovo;
        for (int f = 0; f < i; f++) {
            if (matriz[f][0] == codigoNovo) {
                codigoJaExiste = true;
                break;
            }
        }

        if (codigoJaExiste) {
            cout << "Produto com esse codigo ja existe. Cadastro nao realizado." << endl;
        } else {
            cout << "Estoque: ";
            cin >> matriz[i][1];
            cout << "Preco: ";
            cin >> matriz[i][2];

            matriz[i][0] = codigoNovo;

            if (cadastro_completo(matriz, tamanho, i)) {
                cout << "Cadastro realizado com sucesso!" << endl;
                i++;
            } else {
                cout << "Cadastro incompleto. Preencha todas as informações." << endl;
            }
        }
    } 
    else {
        cout << "Estoque cheio\n";
    }
    break;


        case 2:
        cout << "Digite o codigo do produto que deseja atualizar: ";
        cin >> produto_escolhido;

         for (int f = 0; f < i; f++) {
             if (matriz[f][0] == produto_escolhido) {
                cout << "Existem " << matriz[f][1] << " unidades desse produto no estoque\n";
                cout << "1-remover 2-adicionar\n";
                cin >> op2;

        switch (op2) {
                case 1:
                cout << "Quantos produtos serao removidos? ";
                cin >> remover;

                    if (remover <= matriz[f][1]) {
                     matriz[f][1] -= remover;
                    
                    cout << "Quantidade removida\n";
                    cout << "Este produto possui " << matriz[f][1] << " unidades no estoque\n";
                        } 
                    else {
                       cout << "Saldo insuficiente\n";
                        }
                   break;

                case 2:
                    cout << "Quantos produtos serao adicionados? ";
                    cin >> adicionar;
                    matriz[f][1] += adicionar;
                    cout << "Este produto possui " << matriz[f][1] << " unidades no estoque\n";
                    
                    break;

                    default:
                    cout << "Opcao invalida\n";
                    break;
                        }
                    }
                }
                break;

        case 3:
                if (i > 0) {
                    cout << "Relatorio de Produtos:\n";
                    for (int a = 0; a < i; a++) {
                        cout << "|-----------------------------|\n";
                        cout << "|Codigo: " << matriz[a][0] << endl;
                        cout << "|Estoque: " << matriz[a][1] << endl;
                        cout << "|Preco: " << matriz[a][2] << endl;
                        cout << "|------------------------------|\n";
                    }
                } else {
                    cout << "Nenhum produto cadastrado\n";
                }
                break;

        case 4:
          cout << "Digite a quantidade minima de saldo: ";
          cin >> minima;
          
          cout << "Produtos com estoque menor que o minimo:\n";
            for (int f = 0; f < i; f++) {
               if (matriz[f][1] < minima) {
                cout << "Codigo " << matriz[f][0] << endl;
                }
            }
                break;

        case 5:
          cout << "Obrigado por usar nosso sistema!\n";
          break;

        default:
            cout << "Opcao invalida!\n";
            break;
        }

    } while (op != 5);

    return 0;
}
