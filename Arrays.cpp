//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами

#include <iostream>
#include <format>
#include <random>
#include <fstream>
                                      
using namespace std;

namespace arr{

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