#include <iostream>
#include "funkcje.h"

using namespace std;

int znajdzElement(int tab[], int rozmiar, int szukanyElement)
{

    for (int i = 0; i < rozmiar; i++)
    {
        if (tab[i] == szukanyElement)
        {
            return i;
        }
    }
    throw std::out_of_range("- Nie znaleziono elementu.");
}

int znajdzElement(int tab[], int rozmiar, int szukanyElement, bool odKonca)
{
    for (int i = rozmiar - 1; i >= 0; i--)
    {
        if (tab[i] == szukanyElement)
        {
            return i;
        }
    }
    throw std::out_of_range("- Nie znaleziono elementu.");
}

namespace Testy
{
    void testZnajdzElementNieZnaleziony()
    {
        int tab[] = { 1, 2, 3, 4, 5 ,3, 6 };
        int rozmiar = sizeof(tab) / sizeof(tab[0]);
        int szukanyElement = 0;
        cerr << "Test element nie wystepuje:\n";
        try
        {
            znajdzElement(tab, rozmiar, szukanyElement);
            cerr << "FAIL\n";
        }
        catch (out_of_range)
        {
            cerr << "OK\n";
        }
    }

    void testZnajdzElementJedenWystapienie()
    {
        int tab[] = { 1, 2, 3, 4, 5 ,3, 6 };
        int rozmiar = sizeof(tab) / sizeof(tab[0]);
        int szukanyElement = 2;
        int wynik = znajdzElement(tab, rozmiar, szukanyElement);
        cerr << "Test tylko jedno wystapienie:\n";
        try
        {
            if (wynik == 1)
            {
                cerr << "OK\n";
            }
            else
            {
                cerr << "FAIL\n";
            }
        }
        catch (out_of_range)
        {
            cerr << "FAIL\n";
        }
    }

    void testZnajdzElementWieleWystapien()
    {
        int tab[] = { 1, 2, 3, 4, 5 ,3, 6 };
        int rozmiar = sizeof(tab) / sizeof(tab[0]);
        int szukanyElement = 3;
        int wynik = znajdzElement(tab, rozmiar, szukanyElement);
        cerr << "Test wiele wystapien:\n";
        try
        {
            if (wynik == 2)
            {
                cerr << "OK\n";
            }
            else
            {
                cerr << "FAIL\n";
            }
        }
        catch (out_of_range)
        {
            cerr << "FAIL\n";
        }
    }
}

