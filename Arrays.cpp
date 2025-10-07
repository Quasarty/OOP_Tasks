//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами

#include <iostream>
#include <format>
#include <random>
// #include <time.h>

using namespace std;

namespace arr{

void print_array(float* array, size_t size){
    
    for (size_t i = 0; i < size; i++)
        cout << format("a[{}] = {}", i, array[i]);
    
    
}


void fill_rand(float* array, size_t size, float min = -10.0, float max = 10.0 ){
    random_device rd;
    //Создание экземпляра генератора случайных чисел
    mt19937 gen( rd() );
 
    //Создание экземпляра для границ рандома
    uniform_real_distribution<float> distr(min, max);

    //Генерация чисел
    for (int i = 0; i < size; i++)
        array[i] = distr(gen);
}

}