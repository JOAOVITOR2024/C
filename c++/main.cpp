#include <iostream>
using namespace std;
int main() {
	int ct, sv, vl1=0, sc1=0, sc2=0, vl2=0;
	string r;
do{	cout << "qual conta deseja usar?\n1 (266574) \n2 (366597)\n";
	cin >> ct;
	cout << "escolha o servico desejado\n1-DEPOSITO \n2-SAQUE \n3-SALDO \n4-ALTERAR CONTA \n5-TRANSFERIR PARA CONTA \n6-SAIR\n";
	cin >> sv;
	switch(sv){
		case 1:
			if(ct==1){
				cout << "digite o valor do deposito: ";
				cin >> vl1;
				cout << "\nvoce depositou " << vl1 <<" reais\n";
				sc1+=vl1;
			}
			if (ct==2){
				cout <<"digite o valor do deposito: ";
				cin >> vl2;
				cout << "\nvoce depositou " <<vl2 <<" reais\n";
				sc2+=vl2;
			}
			break;
		case 2:
			
			if (ct==1){
				cout << "digite o valor do saque: ";
				cin >> vl1;
				if (vl1>sc1) {
					cout << "\nsaldo insuficiente\n";
				}
				else if (sc1>vl1) {
					 sc1-=vl1;
					 cout << "voce sacou " << vl1 << " reais\n";
				}
			}
			if (ct==2){
				cout << "digite o valor do saque: ";
				cin >> vl2;
				sc2-=vl2;
				if (vl2>sc2) {
					cout << "saldo insuficiente";
				}
				else if (vl2<sc2) {
					
						cout << "voce sacou " << vl2 <<" reais";
					}
				}
				break;
			case 3:
				if(ct==1){
				cout << "voce possui " << sc1 << " reais de saldo\n";
			}
			if (ct==2){
				cout << "voce possui " << sc2 << " reais de saldo\n";
			}
				break;
			case 5:
				if (ct==1){
				cout << "\ndigite o valor da transferencia: ";
				cin >> vl1;
				if (vl1>sc1){
					cout << "\nsaldo insuficiente;";
				}
				else if (vl1<sc1){
					cout << "\nvoce depositou " << vl1 << " para a conta 366597\n";
					sc1-=vl1;
					sc2+=vl1;
				}
			}
			if (ct==2){
				cout <<"\n digite o valor da transferencia: ";
				cin >> vl2;
				if (vl2>sc2){
					cout << "\nsaldo insuficiente\n";
				if (vl2<sc2){
					cout << "\nvoce depositou " <<vl2 <<" para a conta 266574\n";
				sc1+=vl1;
				sc2-=vl2;
				}
				}
			}
				
			
			}
	cout <<"\ndeseja continuar? (sim/nao)\n";
			cin >> r;
}while(r!="nao" && sv!=6);
	return 0;
}
