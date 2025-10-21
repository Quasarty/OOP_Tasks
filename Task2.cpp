//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"

using namespace std;


int main(){    
    //Создание динамического массива
    size_t size = 5; 
    float *array;

    size = arr::fill_from_bin_file(array, "output.bin");

    // array = arr::fill_rand(size);
    // arr::print_to_bin_file(array, size, "output.bin");
    
    arr::print_array(array, size);
    cout << arr::get_num(array, size);
    
}
