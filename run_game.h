#ifndef RUN_GAME_H
#define RUN_GAME_H
#include "gra_zycia.h"
class Game
{
private:
Gra_życia pierwszy;
Gra_życia drugi;
public:
    Game(Gra_życia _p);
    void new_generation();
    void life(int czas);
    ~Game();


};


#endif