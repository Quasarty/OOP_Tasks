//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136
//Компиляция:
//g++ Task2.cpp .\Lib\MyLib.a -o Task.exe -std=c++23
#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"
#include <assert.h>
#include <string>

using namespace std;

float const EPS = 1E-6;
string const BRIEF = "Программа считает корень квадратный модуля произведения введеных чисел";

//Функция для тестов
void test_get_num(){
    float* test_arr1 = new float[3];
    for (size_t i = 0; i < 3; i++ ){
        test_arr1[i] = i+1;
    }
    float* test_arr2 = new float[3];
    for (size_t i = 0; i < 3; i++ ){
        test_arr2[i] = (i+1)*2;
    }    
    float* test_arr3 = new float[3];
    for (size_t i = 0; i < 3; i++ ){
        test_arr3[i] = (i+1)/2.0;
    }
    assert(abs( arr::get_num(test_arr1, 3) - sqrt(6) ) < EPS );
    assert(abs( arr::get_num(test_arr2, 3) - sqrt(48) ) < EPS );
    assert(abs( arr::get_num(test_arr3, 3) - sqrt(0.75) ) < EPS );
}

int main(int argc, char const *argv[]){
    //Тесты
    test_get_num();

    //Проверка аргументов 
    if (argc == 1){
        cout << BRIEF;
        return 0;
    }
    else{
        if (argc > 1)
            if ( (argv[1] == string("help") ) or (argv[1] == string("--help") ) or (argv[1] == string("-h")) ){
                    cout << BRIEF;        
                    return 0;    
            }
    }
    


    float* array; 
    size_t size = 0;
    size = argc-1;
    array = new float[size];
    //Заполнение массива
    for (size_t i = 1; i < argc; i++ ){
        try{
            array[i-1] = stof(string(argv[i]));
        }
        catch(const logic_error error){
            cout << "Error: "<<error.what() << "\n";
            return 1;
        }
    }

    
    cout << arr::get_num(array, size);
    return 0;
}
