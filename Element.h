#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;

class Element
{
	private:
		string tag, inner;
		list<string> attribute;

	public:
							/** 	CONSTRUCTORES	**/
							
		Element (): tag(""), inner(""){};															 /// CONSTRUCTOR
	
		Element (string tag): tag(tag), inner(""){};												 /// CONSTRUCTOR
		
		Element (string tag, list <string> l): tag(tag), attribute(l){};							 /// CONSTRUCTOR
		
		Element (string tag, string inner, list <string> l): tag(tag), inner(inner), attribute(l){}; /// CONSTRUCTOR
		
		Element (const Element &e): tag(e.tag), inner(e.inner), attribute(e.attribute){}			 /// CONSTRUCTOR COPIA
		 
		void operator = (const Element &a)															 /// SOBRECARGA DEL OPERADOR = PARA ASIGNAR UN ELEMENT A OTRO	
		{
			tag = a.tag;
			inner = a.inner;
			attribute = a.attribute;
		}

							/** 	OBSERVADORES	**/
							
		string tagName () const {return (tag);}														 /// OBSERVADOR TAG
		
		list<string> attributeList() {return (attribute);}											 /// OBSERVADOR ATTRIBUTE
	
		string innerHTML() {return (inner);}														 /// OBSERVADOR INNER
	
							/** 	MODIFICADORES	**/
							
		void setTagName(string x) {tag = x;}														 /// NODIFICADOR TAG
		
		void setAttributeList (list<string> x) {attribute = x;}										 /// NODIFICADOR ATTRIBUTE
		
		void setInnerHTML (string x) {inner = x;}												  	 /// NODIFICADOR INNER
};
#endif 
