//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами
//g++ -o Arrays.o Arrays.cpp -c -std=c++23
//ar rcs .\Lib\MyLib.a Arrays.o
#include <iostream>
#include <format>
#include <random>
#include <fstream>

//todo: если функция кидает искл, то показывать в коментах

using namespace std;

namespace arr{

/**
 * @brief Заполняет массив вручную
 * 
 * @param size размер массива
 * @param array указатель на массив
 */
void fill_man(size_t size, float* array){ 
    for (size_t i = 0; i < size; i++){
        cout << format("a[{}]: ", i+1);
        cin >> array[i];
    }
}

/**
 * @brief Заполняет массив случайными числами
 * 
 * @param size размер массива
 * @param min минимальный диапозон случайных чисел
 * @param max максимальный диапозон случайных чисел
 * @return float* указатель на первый элемент массива
 */
float* fill_rand(size_t size, float min = -10.0, float max = 10.0 ){
    //Источник для генератора случайных чисел
    random_device rd;
    //Создание экземпляра генератора случайных чисел
    mt19937 gen( rd() );
    // default_random_engine dgen( rd() );
 
    //Создание экземпляра для границ рандома
    uniform_real_distribution<float> distr(min, max);

    //Генерация чисел
    float* array = new float[size]; 
    for (int i = 0; i < size; i++)
        array[i] = distr(gen);

    return array;
}

}