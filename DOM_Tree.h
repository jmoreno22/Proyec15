#ifndef DOM_TREE_H
#define DOM_TREE_H

#include <iostream>
#include <list>
#include <queue>
#include "Node.h"
using std::list;
using std::queue;
using std::cout;
using std::endl;

using namespace std;

class DOM_Tree
{
	private:
		Node *raiz;
		
	private:
	    Node* copiar_nodos(Node *p);								/// COPIA LOS NODOS A PARTIR DE UNA RAIZ
		
		static void destruir_nodos(Node *p);							/// DESTRUYE LOS NODOS A PARTIR DE UNA RAIZ
		
		static list<DOM_Tree> hijos(Node *n);							/// DEVUELVE LOS HIJOS DE UN ARBOL

     	void mostrar(Node *p , int cont);		
		
		static void preorden_an(Node *p, list<Element> &l);				///	RECORRIDO EN PREORDE DE UN ARBOL
		
	public:
	
		DOM_Tree ();													/// CONSTRUCTOR
			
		DOM_Tree (Element e, list<DOM_Tree> l);							/// CONSTRUCTOR
		
		DOM_Tree* childNode (int p);										/// DEVUELVE EL HIJO CORRESPONDIENTE A UNA POSICION P
		
		void appendChild (DOM_Tree d, int p);							/// AGREGA UN HIJO EN UNA POSICION P
		
		void removeChild (int p); 										/// ELIMINA UN HIJO EN UNA POSICION P
		
		void replaceChild (DOM_Tree dt, int p);							/// INTERCAMBIA UN SUB ARBOL DE UNA POSICION P
		
		DOM_Tree* getElementByID (Element e);							/// OBTIENE UN SUB ARBOL DESDE UN ID
		
		void operator = (const DOM_Tree &a);							/// SOBRECARGA DEL OPERADOR = 	
		
		friend ostream &operator<<(ostream &out, DOM_Tree d);

		
		~DOM_Tree();													/// DESTRUCTOR
};

											  
/// COPIA LOS NODOS A PARTIR DE UNA RAIZ 
Node* DOM_Tree::copiar_nodos(Node *p)
{
	Node *nuevo;				

	if (p == NULL)
		nuevo = NULL;
	else
	{
		nuevo = new Node;
		nuevo->setElement(p->element());
		nuevo->setFirstChild(copiar_nodos(p->firstChild()));
		nuevo->setNextSibling(copiar_nodos(p->nextSibling()));
	}
	return (nuevo);
}

/// DESTRUYE LOS NODOS A PARTIR DE UNA RAIZ
void DOM_Tree::destruir_nodos(Node *p){
 /*       if (p != NULL)     {
                destruir_nodos(p->firstChild());
                destruir_nodos(p->nextSibling());
                delete p;
                p = NULL;
        }*/
}


/// DEVUELVE LOS HIJOS DE UN ARBOL
list<DOM_Tree> DOM_Tree::hijos(Node *n)
{
	Node *aux;
	DOM_Tree aaux;
	list<DOM_Tree> L;			
			
	if (n != NULL)
	{
		aux = n->firstChild();
			
		while (aux != NULL)
		{
			aaux.raiz = aux;
			L.push_back(aaux);
			aux = aux->nextSibling();
		}
	} 
	return (L);
}

/// RECORRIDO PREORDEN
void DOM_Tree::preorden_an(Node *p, list<Element> &l)		
{
	Node *aux;

	if (p != NULL)
	{
		l.push_back(p->element());
		aux = p->firstChild();

		while (aux != NULL)
		{
			preorden_an(aux, l);
			aux = aux->nextSibling();
		}
	}
}

/// CONSTRUCTOR
DOM_Tree::DOM_Tree ()		
{
	this->raiz = NULL;
}
														
/// CONSTRUCTOR		
DOM_Tree::DOM_Tree (Element e, list<DOM_Tree> l)		
{
	Node *aux;
			
	raiz = new Node(e,NULL,NULL); 
	
	if (!l.empty())
	{
		raiz->setFirstChild(l.front().raiz);
		l.pop_front();
				
		aux = raiz->firstChild();
				
		while (!l.empty())
		{
			aux->setNextSibling(l.front().raiz);
			aux = aux->nextSibling();
			l.pop_front();
		}
	}		
}

/// DEVUELVE EL HIJO CORRESPONDIENTE A UNA POSICION P
DOM_Tree* DOM_Tree::childNode(int po)
{
	DOM_Tree *aux, aux2;
	list<DOM_Tree> l = hijos (raiz);
	list<DOM_Tree>::iterator i1;
	int tam;
	
	tam= l.size();
	
	if (po <= tam)
	{
		if (po == 1)
			aux->raiz = l.front().raiz;
		else
		{
			if (po == tam)
				aux->raiz = l.back().raiz;
			else
			{
				i1=l.begin();
				for (int i = 1; i <= po ; i++)
				{
					i1++;
				}
				aux2 = *i1;
				aux->raiz = aux2.raiz;
			}
		}
	}
	return (aux);
}

/// AGREGA UN HIJO EN UNA POSICION P
void DOM_Tree::appendChild (DOM_Tree d, int p)
{
	DOM_Tree aux;
	list<DOM_Tree> l = hijos (raiz);
	list<DOM_Tree>::iterator i1;
	int tam;
	
	tam= l.size();
	
	if (p <= tam)
	{
		if (p == 1)
		{
			d.raiz->setNextSibling(raiz->firstChild());
			raiz->setFirstChild(d.raiz);
		}
		else
		{
			if (p == tam)
			{
				aux.raiz = raiz->firstChild();
				while (aux.raiz->nextSibling() != NULL)
				{
					aux.raiz = aux.raiz->nextSibling();
				}
				aux.raiz->setNextSibling(d.raiz);
			}
			else
			{
				
				i1=l.begin();
				for (int i = 1; i <= p-1; i++)
				{
					i1++;
				}
				aux = *i1;
				d.raiz->setNextSibling(aux.raiz->nextSibling());
				aux.raiz->setNextSibling(d.raiz);
			}
			
		}
	}
}

/// ELIMINA UN HIJO EN UNA POSICION P
void DOM_Tree::removeChild (int p)
{
	Node *aux, *aux2;
	list <DOM_Tree> l = hijos(raiz);
	int i; 
	int tam;
	
	tam= l.size();
	
	if (p <= tam)
	{
		if (p == 1)
		{
			aux2 = raiz->firstChild();
			raiz->setFirstChild(aux2->nextSibling());
		}
		else
		{
			aux = raiz->firstChild();
			aux2 = aux;
			
			for (i = 1; i < p; i++) 
			{
				if (i < p-1)
				{
					aux = aux->nextSibling();
				}
				aux2 = aux2->nextSibling();
			}
			aux->setNextSibling(aux2->nextSibling());
		}
		delete(aux2);
	}
}

/// INTERCAMBIA UN SUB ARBOL DE UNA POSICION P
void DOM_Tree::replaceChild (DOM_Tree dt, int p)
{
	DOM_Tree d, d1;
	
	d1.raiz = childNode(p)->raiz;
	
	d = d1;
	d1 = dt;
	destruir_nodos(d.raiz);
}
	

/// SOBRECARGA DEL OPERADOR = 	
void DOM_Tree:: operator = (const DOM_Tree &a)	{
	
	this->raiz = copiar_nodos(a.raiz);
}

/// SOBRECARGA DEL OPERADOR <<
ostream& operator<<(ostream &out, DOM_Tree a){
    Node* p;
    Element e;
    int cont = 0;

    if(a.raiz != NULL){
		cout << "<!doctype html" << endl;
    	p = a.raiz;
 		a.mostrar(p, cont);
    }
	return(out);
}
void DOM_Tree::mostrar(Node* p , int cont){
	Node *aux,*aux1;
	Element e;
	list<string> L;
	int i,pos;

	string auxInner,a;
	
	if( p != NULL){
	
			for(i=1;i<=cont;i++){ 
				cout<<"	";
			}
	
			e = p->element();
			
			cout<<"<"<<e.tagName();
			
			L = e.attributeList();
			
			if(!L.empty()){
				while(!L.empty() ){
					cout<<" "<<L.front();
					L.pop_front();
				}
			}
			cout<<">";
			
			auxInner = e.innerHTML();
			if(auxInner[0] != '<'){
				pos = auxInner.find("<");
					auxInner = auxInner.substr(0,pos);
				cout<<auxInner;
			}
			aux1=aux = p->firstChild();
			
			if(aux != NULL){
				cout<<endl;
			}
					
			while(aux != NULL){
				mostrar(aux,cont+1);
				aux = aux->nextSibling();
			} 
				if(aux1 != NULL)
					for(i=1;i<=cont;i++){
					 cout<<"	";
					}
		
			cout<<"</"<<e.tagName();
			cout<<">"<<endl;
			
	}


}

/// DESTRUCTOR
DOM_Tree::~DOM_Tree()
{
        if(raiz!=NULL){
            destruir_nodos(raiz);
        }
}
#endif 									  
