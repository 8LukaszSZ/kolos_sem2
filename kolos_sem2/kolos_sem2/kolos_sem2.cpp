#include <iostream>
#include "funkcje.h"

using namespace std;

int main()
{
    int tab[] = { 1, 2, 3, 4, 5 ,3, 6};
    int rozmiar = sizeof(tab) / sizeof(tab[0]);
    int szukanaLiczba = 3;
    cout << "Widok tablicy:\n";
    for (int i = 0; i < rozmiar; i++)
    {
        cout << tab[i] << " ";
    }
    cout << "\nSzukany element: " << szukanaLiczba << endl << endl;

    try
    {
        cout << "Pierwsze wystapienie liczby - index: " << znajdzElement(tab, rozmiar, szukanaLiczba) << endl;
        cout << "Ostatnie wystapienie liczby - index: " << znajdzElement(tab, rozmiar, szukanaLiczba, true);
    }
    catch (const out_of_range& ex)
    {
        cerr << "FAIL " << ex.what() << endl;
    }

    cout << "\n\nTESTY:\n";
    Testy::testZnajdzElementNieZnaleziony();
    Testy::testZnajdzElementJedenWystapienie();
    Testy::testZnajdzElementWieleWystapien();

    return 0;
}

