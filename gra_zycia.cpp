#include "gra_zycia.h"

Gra_życia::Gra_życia(CMatrix _k) : komórki(_k)
{
    width = komórki.size();
    height = komórki[0].size();
}
CMatrix Gra_życia::komórki_pomocnicze() const
{
    CMatrix result;
    result.push_back(std::vector<Cell>(height + 2, SCHRÖDINGER));
    for (int i = 0; i < width; i++)
    {
        std::vector<Cell> pom;
        pom.push_back(SCHRÖDINGER);
        for (int j = 1; j < height + 1; j++)
        {

            pom.push_back(komórki[i][j - 1]);
        }
        pom.push_back(SCHRÖDINGER);
        result.push_back(pom);
    }
    result.push_back(std::vector<Cell>(height + 2, SCHRÖDINGER));
    return result;
}

Cell Gra_życia::get(int x, int y) const
{
    return komórki[x][y];
}
void Gra_życia::set(int x, int y, Cell _c)
{
    komórki[x].at(y) = _c;
}

int Gra_życia::liczba_sąsiadów(int x, int y) const
{
    CMatrix tymczasowy = komórki_pomocnicze();
    int numer = 0;

    for (int i = x; i < x + 3; i++)
    {

        for (int j = y; j < y + 3; j++)
        {

            if (tymczasowy[i][j] == ALIVE)
            {

                numer++;
            }
        }
    }
    if (tymczasowy[x + 1][y + 1] == ALIVE)
    {
        numer--;
    }
    return numer;
}

Cell Gra_życia::nowy_stan(int x, int y) const
{
    int pepschmi = liczba_sąsiadów(x, y);

    if (get(x, y) == ALIVE)
    {
        if ((pepschmi < 2) || (pepschmi > 3))
        {

            return DEAD;
        }
        return ALIVE;
    }
    if (pepschmi == 3)
    {
        return ALIVE;
    }
    return DEAD;
}
int Gra_życia::getW() const
{
    return width;
}
int Gra_życia::getH() const
{
    return height;
}
CMatrix Gra_życia::getkomórki() const
{
    return komórki;
}
