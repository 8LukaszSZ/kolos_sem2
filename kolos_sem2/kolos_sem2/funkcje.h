#ifndef FUNKCJE_H
#define FUNKCJE_H

int znajdzElement(int tab[], int rozmiar, int szukanyElement);
int znajdzElement(int tab[], int rozmiar, int szukanyElement, bool odKonca);

namespace Testy 
{
	void testZnajdzElementNieZnaleziony();
	void testZnajdzElementJedenWystapienie();
	void testZnajdzElementWieleWystapien();
}


#endif