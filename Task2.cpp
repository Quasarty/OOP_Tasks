//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"

using namespace std;


int main(){
    int choise = 0;
    cout << "Выберите способ заполнения массива:\n1. Случайными числами\n2. Ввод массива из файла\n3. Ручной ввод\n";
    cin >> choise;
    
    string file_name;
    float* array; 
    size_t size = 0;

    switch (choise){
    //Случайные числа
    case 1:
        cout << "Введите размер массива: ";
        cin >> size;
        array = arr::fill_rand(size);
        break;
    //Ввод из файла
    case 2:
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
    //Ручной ввод
    case 3:
        cout << "Введите размер массива: ";
        cin >> size;
        array = new float[size];
        for (size_t i = 0; i < size; i++){
            cout << format("a[{}]: ", i+1);
            cin >> array[i];
        }
        break;
    default:
        cout << "Некорректный выбор"; 
        break;
    }

    arr::print_array(array, size);
    cout << arr::get_num(array, size);
}
