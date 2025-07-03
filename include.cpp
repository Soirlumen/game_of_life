#include "include.h"


SMatrix read_file(String filename)
{
    // otevreme soubor pro cteni
    std::ifstream file(filename);

    SMatrix result;
    // kontrola chyb pomoci file.good()
    while (file.good())
    {
        // cteni obsahu pomoci funkce getline()
        std::string line;
        std::getline(file, line);
        result.push_back(line);
    }

    if (!file.eof())
    {
        file.close();
        return result = {"neni konec souboru!"};
    }
    // vratit vysledek
    file.close();
    return result;
}

void read_smatrix(SMatrix &board)
{
    // tady bude třeba kontrola vstupu, nebo to bude samostatná fce
    for (int i = 0; i < board.size(); i++)
    {
        for (const char &j : board[i])
        {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}
void read_Cmatrix(CMatrix board)
{
    // tady bude třeba kontrola vstupu, nebo to bude samostatná fce
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}
bool test_wymiary_consistency(SMatrix s)
{
    if (s.empty())
    {
        std::cout << "its not ok\n";
        return false;
    }
    int first_wymiar = s[0].size();
    for (auto linia : s)
    {
        if (linia.size() != first_wymiar)
        {
            std::cout << "its not ok\n";
            return false;
        }
    }
    std::cout << "its ok\n";
    return true;
}

CMatrix convert_S_toC(SMatrix s)
{
    int pom1 = s.size();
    int pom2 = s[0].size();
    CMatrix result; //(pom1,std::vector<Cell>(pom2,DEAD));
    for (int i=0; i < pom1; i++)
    {
        std::vector<Cell> pom;
        for (char &c : s[i])
        {
            if (c == '#')
            {
                pom.push_back(ALIVE);
            }
            else
            {
                pom.push_back(DEAD);
            }
        }
        result.push_back(pom);
    }
    return result;
}
