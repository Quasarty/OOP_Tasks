//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136
//Компиляция:
//g++ Task2.cpp .\Lib\MyLib.a -o Task.exe -std=c++23
#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"
#include <assert.h>

using namespace std;

float const EPS = 1E-6;
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

int main(){
    //Тесты
    test_get_num();

    int choice = 0;
    cout << "Выберите способ заполнения массива:\n1. Случайными числами\n2. Ввод массива из файла\n3. Ручной ввод\n";
    cin >> choice;
    
    string file_name;
    float* array; 
    size_t size = 0;

    switch (choice){
    //Случайные числа
    case 1:{
        cout << "Введите размер массива: ";
        cin >> size;
        array = arr::fill_rand(size);
        break;
    }
    //Ввод из файла
    case 2:{
        int fchoice = 0;
        cout << "1. Ввод из текстового файла\n2. Ввод из бинарного файла\n";
        cin >> fchoice; 
        switch (fchoice){
        case 1:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                size = arr::fill_from_file(array, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
            break;
        case 2:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                size = arr::fill_from_bin_file(array, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
            break;
        default:
            cout << "Некорректный ввод";
            return 1;
        }
        break;
    }
    //Ручной ввод
    case 3:{
        cout << "Введите размер массива: ";
        cin >> size;
        array = new float[size];
        arr::fill_man(size, array);
        break;
    }
    default:{
        cout << "Некорректный выбор"; 
        return 1;
    }
    }
    cout << "Массив:\n";
    arr::print_array(array, size);
    cout << "Ответ: " << arr::get_num(array, size) << endl;
    
    choice = 0;
    cout << "Что сделать дальше:\n1. Записать массив в файл\n2. Выход\n";
    cin >> choice;
    
    switch (choice){

    //Запись в файл
    case 1:{
        int fchoice = 0;
        cout << "1. Запись в текстовый файл\n2. Запись в бинарный файл\n";
        cin >> fchoice; 
        switch (fchoice){
        case 1:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                arr::print_to_file(array, size, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
            break;
        case 2:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                arr::print_to_bin_file(array, size, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
            break;
        default:
            cout << "Некорректный выбор"; 
            break;
        }
        break;
    }

    //Выход
    default: 
        break;
    }

    return 0;
}
