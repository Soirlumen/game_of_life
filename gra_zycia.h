#ifndef GRA_ZYCIA_H
#define GRA_ZYCIA_H
#include "include.h"

class Gra_życia
{
private:
    CMatrix komórki;
    int width;
    int height;

public:
    Gra_życia(CMatrix _k);
    CMatrix komórki_pomocnicze() const;
    Cell get(int x, int y) const;
    int getW() const;
    int getH() const;
    CMatrix getkomórki() const;
    void set(int x, int y, Cell _c);
    int liczba_sąsiadów(int x, int y) const;
    Cell nowy_stan(int x, int y) const;
};

#endif