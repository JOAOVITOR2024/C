#include <iostream>

using namespace std;

int main() {

int op, tamanho, i = 0, op2, remover, adicionar, produto_escolhido, minima;

cout << "quantos produtos podem ser cadastrados?\n";

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

if (i<tamanho) {

cout << "digite as seguintes informacoes do produto:\n";

cout << "codigo: ";

cin >> matriz[i][0];

cout << "estoque: ";

cin >> matriz[i][1];

cout << "preco: ";

cin >> matriz[i][2];

i++;

}

else {

cout << "estoque cheio\n";

}

break;

case 2:

cout << "digite o codigo do produto que deseja atualizar: ";

cin >> produto_escolhido;

for (int f = 0; f < i; f++) {

if (matriz[f][0] == produto_escolhido) {

cout << "existem " << matriz[f][1] << " desse produto no estoque\n";

cout << "1-remover 2-adicionar\n";

cin >> op2;

switch (op2) {

case 1:

cout << "quantos produtos serao removidos? ";

cin >> remover;

if (remover <= matriz[f][1]) {

matriz[f][1] -= remover;

cout << "quantidade removida\n";

cout << "esse produto possui " << matriz[f][1] << " no estoque\n";

} else {

cout << "saldo insuficiente\n";

}

break;

case 2:

cout << "quantos produtos serao adicionados? ";

cin >> adicionar;

matriz[f][1] += adicionar;

cout << "esse produto possui " << matriz[f][1] << " no estoque\n";

break;

default:

cout << "opcao invalida\n";

break;

}

}

}

break;

case 3:

if (i > 0) {

for (int a = 0; a < i; a++) {

cout << "|-----------------------------|\n";

cout << "|codigo:" << matriz[a][0] << endl;

cout << "|estoque:" << matriz[a][1] << endl;

cout << "|preco:" << matriz[a][2] << endl;

cout << "|------------------------------|\n";

}

} else {

cout << "produtos nao cadastrados\n";

}

break;

case 4:

cout << "digite a quantidade minima de saldo: ";

cin >> minima;

cout << "produtos com o estoque menor que o minimo:\n";

for (int f = 0; f < i; f++) {

if (matriz[f][1] < minima) {

cout << "codigo " << matriz[f][0] << endl;

}

}

break;

case 5:

cout << "obrigado por usar nosso sistema!\n";

break;

default:

cout << "opcao invalida!\n

break;

}

} while (op != 5);

return 0;

}
