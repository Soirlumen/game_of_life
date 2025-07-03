#include "run_game.h"

Game::Game(Gra_życia _p) : pierwszy(_p), drugi(_p) {}
void Game::new_generation(){
    
    for(int i=0;i<pierwszy.getW();i++){
        for(int j=0;j<pierwszy.getH();j++){
            drugi.set(i,j,pierwszy.nowy_stan(i,j));
        }
    }
    read_Cmatrix(drugi.getkomórki());
    std::swap(pierwszy,drugi);
}
void Game::life(int czas)
{
for(int i=0;i<czas;i++){
    new_generation();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    system("cls");

}
}
Game::~Game()
{
}