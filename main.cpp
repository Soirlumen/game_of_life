#include "run_game.h"

int main()
{
    SMatrix pole = read_file("igra.txt");
    test_wymiary_consistency(pole);
    // read_smatrix(pole);
    CMatrix policko = convert_S_toC(pole);
    read_Cmatrix(policko);
    Gra_życia gz(policko);
    CMatrix ok = gz.komórki_pomocnicze();
    gz.liczba_sąsiadów(0, 0);
    wypisywanie("stary", gz.get(1, 2), "\n");
    wypisywanie("novy", gz.nowy_stan(1, 2));
    Game g(gz);
    g.life(20);
    return 0;
}
