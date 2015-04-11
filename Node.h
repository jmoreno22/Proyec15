#include <iostream>
#include "Element.h"

class Node{
	private:
		Element e;
		Node *hijoi, *hermd;
		
	public:
							/** 	CONSTRUCTORES	**/
							
		Node  (): e(Element()), hijoi(NULL), hermd(NULL){}					/// CONSTRUCTOR
		
		Node  (const Node& n): e(n.e), hijoi(n.hijoi), hermd(n.hermd){}		/// CONSTRUCTOR COPIA
		
		Node  (Element e, Node  *i, Node  *h): e(e), hijoi(i), hermd(h){}   /// CONSTRUCTOR COPIA
		
		void operator = (const Node &a);								/// SOBRECARGA DEL OPERADOR = PARA ASIGNAR UN NODE A OTRO		
		
		
							/** 	OBSERVADORES	**/
							
		Element element(){return (e);}										 /// OBSERVADOR ELEMENT
		
		Node* firstChild(){return(hijoi);}									 /// OBSERVADOR HIJO IZQUIERDO
	
		Node* nextSibling(){return (hermd);}												 /// OBSERVADOR HERMANO DERECHO
	
							/** 	MODIFICADORES	**/
							
		void setElement(Element e){e = e;}									 /// NODIFICADOR ELEMENT
		
		void setFirstChild (Node* aux){hijoi = aux;}						 /// NODIFICADOR HIJO IZQUIERDO
		
		void setNextSibling (Node* aux){hermd = aux;} 						/// NODIFICADOR HIJO DERECHO
};


void Node:: operator = (const Node &a){
	e = a.e;
	hijoi = a.hijoi;
	hermd = a.hermd;	
}
