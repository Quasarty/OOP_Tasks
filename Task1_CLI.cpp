//Автор: Кожевников Андрей
//Задача 6 https://ivtipm.github.io/Programming/Glava01/index01.htm#z6

#include <iostream> //Модуль ввода/вывода
#include <format>   //Модуль формата 
#include "MyUnit.hpp"

//Меняем пространство имен, чтобы не писать везде std::
using namespace std;

//Константа текста для help
const string BRIEF = "Программа считает гипотенузу и площадь прямоугольного треугольника по его катетам\nTask1.exe [a] [b]\na - первый катет\nb - второй катет";

int main(int argc, char const *argv[]){

    //Аргумент help; --help; -h или неверное кол-во аргументов
    if (argc > 1)
        if ( (argv[1] == string("help") ) or (argv[1] == string("--help") ) or (argv[1] == string("-h") or (argc != 3) ) ){
            cout << BRIEF;
            
            return 0;
        }

    float a, b = 0; //< Переменные для катетов

    //Если катеты подаются как аргументы
    if (argc == 3){
        //stof - string to float
        a = stof(argv[1]);
        b = stof(argv[2]);
    }

    //Отсутствие аргументов
    if (argc == 1){
        //Ввод катетов
        cout << "Введите катеты прямоугольного треугольника: ";
        cin >> a >> b;
    }

    //Вывод
    cout << format("Гипотенуза = {}\nПлощадь = {}", triangle::GetHypotenuse(a, b), triangle::GetSquare(a, b));

    return 0;
}