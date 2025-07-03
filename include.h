#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

enum Cell
{
    DEAD = 0,
    ALIVE = 1,
    SCHRÖDINGER = 5
};
using String = std::string;
using SMatrix = std::vector<String>;
using CMatrix = std::vector<std::vector<Cell>>;

SMatrix read_file(String filename);
void read_smatrix(SMatrix &board);
void read_Cmatrix(CMatrix board);
bool test_wymiary_consistency(SMatrix s);
CMatrix convert_S_toC(SMatrix s);

template <typename T>
void wypisywanie(T t) 
{
    std::cout << t << " ";
}

template<typename T, typename... Args>
void wypisywanie(T t, Args... args) // recursive variadic function
{
    std::cout << t <<" ";

    wypisywanie(args...) ;
}