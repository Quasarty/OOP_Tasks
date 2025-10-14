//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"

using namespace std;


int main(){
    
    //Создание динамического массива
    float *array;
    size_t size = arr::fill_from_file(array, "test.txt");
    arr::print_array(array, size);
    cout << arr::get_num(array, size);
}
