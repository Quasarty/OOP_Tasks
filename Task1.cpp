//Автор: Кожевников Андрей
//Задача 6 https://ivtipm.github.io/Programming/Glava01/index01.htm#z6

#include <iostream> //Модуль ввода/вывода
#include <format>   //Модуль формата 
#include "MyUnit.hpp"

//Меняем пространство имен, чтобы не писать везде std::
using namespace std;


int main(){
    float a, b = 0; //< Переменные для катетов
    
    //Тесты 
    triangle::Test_GetHypotenuse();
    triangle::Test_GetSquare();
    
    //Ввод катетов
    cout << "Введите катеты прямоугольного треугольника: ";
    cin >> a >> b;

    //Вывод
    cout << format("Гипотенуза = {}\nПлощадь = {}", triangle::GetHypotenuse(a, b), triangle::GetSquare(a, b));

    return 0;
}