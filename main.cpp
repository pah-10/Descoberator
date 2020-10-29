#include <iostream>
using namespace std;

//função que retorna a tentativa do user
void tentativa_User(int *usuario){
	cout<<"Qual número você escolhe? ";
	cin>> *usuario;
	cout<<endl;
}

//função que escolhe um numero aleatoriamente
int escolhe_Num(){
	int escolhido = 0, semente = time(0);

  srand(semente);

	escolhido = 1+rand()%100;

	return escolhido;
}

//função que verifica se a resposta esta correta ou nao
bool verifica_Resposta(bool *resposta, int numEscolhido, int numUsuario){
	if(numUsuario == numEscolhido){
		*resposta = true;
	}else{
		*resposta = false;
	}

	system("clear");

	return *resposta;
}

//função que retorna uma dica sobre o numero correto para o jogador
void verificaValor_Usuario(int numEscolhido, int numUsuario){
	if(numUsuario < numEscolhido){
		cout<<"Que pena você errou!\n\tPS: O número correto é maior que o digitado!"<<endl<<endl;
	}else{
		cout<<"Que pena você errou!\n\tPS: O número correto é menor que o digitado!"<<endl<<endl;
	}
}

int main() {
	bool acerto ;
	char continuar;
	int numEscolhido, numUsuario;

	cout<<"\t===== BEM VINDO AO DESCOBERATOR ====="<<endl<<endl;
	cout<<"A sua missão é tentar descobrir o número que foi escolhido por nosso 'gerador'"<<endl<<endl;
	cout<<"Os números vão de 1 a 100 e você possui várias chances para adivinhar!!"<<endl<<"Boa sorte <3"<<endl<<endl;

	numEscolhido = escolhe_Num();

	do{
		tentativa_User(&numUsuario);
		verifica_Resposta(&acerto, numEscolhido, numUsuario);

		if(acerto == false){
			verificaValor_Usuario(numEscolhido, numUsuario);

			cout<<"Deseja continuar tentando? \n\tDigite 'S' para Sim\n\tDigite 'N' para Não "<<endl;
			cin>>continuar;
			cout<<endl;
		}else{
			break;
		}

	}while (continuar == 'S' || continuar == 's');

	if(acerto == true)
		cout<<"PARABÉNS, você completou a missão com exito <3"<<endl<<endl;
	
	if(continuar == 'N' || continuar == 'n')
		cout<<"NÃO FOI DESSA VEZ"<<endl<<endl;

	cout<<"\t===== JOGUE COMIGO NOVAMENTE ====="<<endl;

  return 0;
}
