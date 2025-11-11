//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами

#include <iostream>
#include <format>
#include <random>
#include <fstream>
#include <vector>
                                      
using namespace std;

namespace arr{

/**
 * @brief Заполняет массив случайными числами
 * 
 * @param array массив
 * @param size размер массива
 * @param min минимальный диапозон случайных чисел
 * @param max максимальный диапозон случайных чисел
 * @return float* указатель на первый элемент массива
 */
void fill_rand(float *array, size_t size, float min = -10.0, float max = 10.0 ){
    //Источник для генератора случайных чисел
    random_device rd;
    //Создание экземпляра генератора случайных чисел
    mt19937 gen( rd() );
    // default_random_engine dgen( rd() );
 
    //Создание экземпляра для границ рандома
    uniform_real_distribution<float> distr(min, max);

    //Генерация чисел
    for (int i = 0; i < size; i++)
        array[i] = distr(gen);

}


void fill_rand(vector<float> &array, float min = -10.0, float max = 10.0 ){
    //Источник для генератора случайных чисел
    random_device rd;
    //Создание экземпляра генератора случайных чисел
    mt19937 gen( rd() );
    // default_random_engine dgen( rd() );
 
    //Создание экземпляра для границ рандома
    uniform_real_distribution<float> distr(min, max);

    //Генерация чисел
    for (auto num : array)
        num = distr(gen);
}


void print_array(vector<float> &array){
    for (size_t i = 0; i < array.size(); i++)
        cout << format("a[{}] = {}; ", i+1, array[i]);
}


void print_array_by_10(vector<float> &array){
    
    for (size_t i = 0; i < array.size(); i++){
        cout << format("a[{}] = {}", i, array[i]);
        if ((i % 10) == 0)
            cout << endl;
    }   
}


void print_to_file(vector<float> array, string file_name){
    //Класс потока вывода в файл
    ofstream file(file_name);

    if ( !file.is_open() )
        throw(runtime_error("Ошибка: не удалось открыть файл"));

    //Вывод
    for (size_t i = 0; i < array.size()-1; i++)
         file << array[i] << ' ';
    file << array.back();
}

void print_to_bin_file(const vector<float> &array, string file_name){
    //Класс потока вывода в файл
    fstream file(file_name, ios::out | ios::trunc | ios::binary);
    
    if ( !file.is_open() )
    throw(runtime_error("Ошибка: не удалось открыть файл"));
    
    //Запись массива
    file.write((char*)array.data(), sizeof(float)*array.size());    
    
    file.close();
}


void fill_from_file(vector<float> &array, string file_name){
    //Класс потока ввода из файла
    ifstream file(file_name);
    if ( !file.is_open() )
        throw(runtime_error("Ошибка: не удалось открыть файл"));


    //Добавление в массив
    while (!file.eof()){
        float num;
        file >> num;
        array.push_back(num);
    }
}

//TODO: доделать + проверить
void fill_from_bin_file(vector<float> &array, string file_name){
    //Класс потока ввода из файла
    fstream file(file_name, ios::in | ios::binary);
    
    if ( !file.is_open() )
        throw runtime_error("Ошибка: не удалось открыть файл");


    //Добавление в массив
    file.read((char*)array.data(), sizeof(float)*array.size());
    
}
}