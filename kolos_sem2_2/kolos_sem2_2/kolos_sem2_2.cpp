#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

struct TablicaDynamiczna
{
	double* tablica;
    uint32_t rozmiar;
};

TablicaDynamiczna stworzDynamicznaTab(uint32_t rozmiar)
{
	TablicaDynamiczna dTab;
	dTab.tablica = new double[rozmiar];
    dTab.rozmiar = (rozmiar << 8) | 0;
	return dTab;
}

void zwolnijDynamicznaTab(TablicaDynamiczna& dTab)
{
	delete[] dTab.tablica;
	dTab.tablica = nullptr;
	dTab.rozmiar = 0;
}

int odczytajLiczbeKolumn(const char* nazwaPliku)
{
    FILE* plik = nullptr;
    fopen_s(&plik, nazwaPliku, "r");
    char tekst[1000];
    int liczba_kolumn = 0;
    while (fgets(tekst, sizeof(tekst), plik) != NULL)
    {
        int liczba_separaD = 0;
        for (int i = 0; i < strlen(tekst); i++) {
            if (tekst[i] == ',') {
                liczba_separaD++;
            }
        }
        if (liczba_separaD > liczba_kolumn) {
            liczba_kolumn = liczba_separaD;
        }
    }
    fclose(plik);
    return liczba_kolumn; 
}

void odczytajDaneZPliku(const char* nazwaPliku, double* tablica, int rozmiar)
{
    FILE* plik = nullptr;
    fopen_s(&plik, nazwaPliku, "r");
    char tekst[1000];

    for (int i = 0; i < rozmiar; i++)
    {
        fscanf_s(plik, "%lf,", &tablica[i]);
    }
    fclose(plik);
}

int main()
{
    int rozmiar = odczytajLiczbeKolumn("Dane.txt");
	TablicaDynamiczna dTab = stworzDynamicznaTab(rozmiar);
    odczytajDaneZPliku("Dane.txt", dTab.tablica, rozmiar);

    cout << "Liczba alokacji: " << (dTab.rozmiar & 0xFFFFFF) << endl;
    cout << "Rozmiar tablicy: " << ((dTab.rozmiar >> 8) & 0xFF) << endl;

    cout << "Zawartosc tablicy: " << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        cout << fixed << setprecision(1) << dTab.tablica[i] << ", ";
    }
    cout << endl;

	zwolnijDynamicznaTab(dTab);
	return 0;
}
