#include <iostream>

using namespace std;


struct Produto
{
	string nome;
	int quantidade;
	Produto * prox;
	Produto * ant;
};

struct Lista
{
	int qte;
	Produto * ultimo;
	Produto * primeiro;

	void criarLista()
	{
		qte = 0;
		ultimo = NULL;
		primeiro = NULL;
	}
	
	bool listaVazia()
	{
		if(qte == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void imprimirLista()
	{
		if(listaVazia())
		{
			return;
		}
		else
		{
			Produto *p = new Produto();
			p = primeiro;
			do
			{
				cout << "\nNome: " << p->nome;
				cout << "\nQuantidade: " << p->quantidade;
				p = p->prox;

			}
			while(p != NULL);

		}

	}
	void inserirFim(string nome, int quantidade)
	{
		Produto *p = new Produto();
		p->nome = nome;
		p->quantidade = quantidade;
		if(listaVazia())
		{
			primeiro = p;
		}
		else
		{
			p->ant = ultimo;
			ultimo->prox = p;
		}

		ultimo = p;
		qte++;



	}
	void inserirInicio(string nome, int quantidade)
	{
		Produto *p = new Produto();
		p->nome = nome;  //(*p).nome = nome;
		p->quantidade = quantidade;

		if(listaVazia())
		{
			primeiro = p;
		}
		else
		{
			primeiro->ant = p;
			p->prox = primeiro;
			primeiro = p;

		}
		ultimo = p;
		qte++;

	}
	void inserirPosi(string nome, int quantidade, int posicao)
	{
		if(qte < posicao)
		{
			cout << "Lista com tamanho insuficiente!" << endl;
			return;
		}
		else
		{
			Produto * p = new Produto();
			p->nome = nome;
			p->quantidade = quantidade;
			Produto* aux = new Produto();
			aux = primeiro;
			int cont = 1;
			while(cont++ < posicao)
			{
				aux = aux->prox;
			}
			aux->ant->prox = p;
			p->ant = aux->ant;
			aux->ant = p;
			p->prox = aux;
			qte++;

		}


	}
	void removerInicio()
	{
		if(listaVazia())
		{
			return;
		}
		else
		{
			if(qte == 1)
			{
				primeiro = NULL;
				ultimo = NULL;
				qte = 0;
			}
			else
			{

				Produto *aux = new Produto();
				aux = primeiro;
				primeiro = aux->prox;
				aux->prox->ant = NULL;
				delete aux;

			}
		}





	}
	void removerFim()
	{
		if(listaVazia())
		{
			return;
		}
		else
		{
			if(qte == 1)
			{
				primeiro = NULL;;
				ultimo = NULL;
				qte = 0;
			}
			else
			{
				ultimo = ultimo->ant;
				ultimo->prox->ant = NULL;
				ultimo->prox = NULL;
				qte--;

			}
		}

	}
	void removerPosi(int posicao)
	{
		if(qte < posicao)
		{
			cout << "\nLista com tamanho insuficiente!" << endl;
			return;

		}
		else
		{
			if(qte == posicao)
			{
				removerFim();

			}
			else
			{
				Produto *aux = new Produto();
				aux = primeiro;
				int cont = 1;
				while(cont++ < posicao)
				{
					aux = aux->prox;

				}

				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				aux->prox = NULL;
				aux->ant = NULL;
				qte--;
				delete aux;


			}
		}

	}
	void buscar(int posicao)
	{
		if(qte < posicao)
		{
			cout << "NÃo foi possivel buscar essa posicao" << endl;
			return;
		}
		else
		{
			Produto *aux = new Produto();
			aux = primeiro;
			int cont = 1;
			while(cont++ < posicao)
			{
				aux = aux->prox;
			}
			cout << "\nElemento econtrado!";
			cout << "\n---------------------------";
			cout << "\nNome: " << aux->nome;
			cout << "\nQuantidade: " << aux->quantidade;

		}



	}




};





int main()
{
	Lista l;
	l.criarLista();
	l.inserirInicio("Arroz", 5);
	l.inserirFim("Macarrao", 2);
	l.inserirFim("Feijao", 5);
	l.imprimirLista();
	cout << "\n----------------------" << endl;
	l.inserirInicio("Suco", 2);
	l.imprimirLista();
	cout << "\n----------------------" << endl;
	l.inserirPosi("Ovo", 6, 3);

	l.imprimirLista();
	cout << "\n----------------------" << endl;
	l.removerInicio();
	l.imprimirLista();
	cout << "\n----------------------" << endl;
	//removerPosi(2);
	l.buscar(2);


	return 0;
}
