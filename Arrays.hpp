//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами
#pragma once

#include <iostream>
#include <format>
#include <random>
#include <fstream>
                                      
using namespace std;

namespace arr{

void fill_man(size_t size, float* array);

/**
 * @brief Функция выводит массив
 * 
 * @param array массив
 * @param size размер массива
 */
template <typename T>
void print_array(const T* array, size_t size){
    
    for (size_t i = 0; i < size; i++)
        cout << format("a[{}] = {}; ", i+1, array[i]);
    cout << endl;
    
}

/**
 * @brief Функция выводит массив, выводя максимум 10 элементов в строке
 * 
 * @param array массив
 * @param size размер массива
 */
template <typename T>
void print_array_by_10(const T* array, size_t size){
    
    for (size_t i = 0; i < size; i++){
        cout << format("a[{}] = {}", i, array[i]);
        if ((i % 10) == 0)
            cout << endl;
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
float* fill_rand(size_t size, float min = -10.0, float max = 10.0 );

/**
 * @brief Записывает массив в текстовый файл
 * 
 * @param array массив
 * @param size размер массива
 * @param file_name название файла
 * @exception runtime_error, если не удалось открыть файл 
 */
template <typename T>
void print_to_file(const T* array, size_t size, string file_name){
    //Класс потока вывода в файл
    ofstream file(file_name);

    if ( !file.is_open() )
        throw(runtime_error("Ошибка: не удалось открыть файл"));

    //Вывод
    for (size_t i = 0; i < size-1; i++)
         file << array[i] << ' ';
    file << array[size-1];

}

/**
 * @brief Записывает массив в бинарный файл
 * 
 * @param array массив
 * @param size размер массива
 * @param file_name название файла
 * @exception runtime_error, если не удалось открыть файл 
 */
template <typename T>
void print_to_bin_file(const T* array, const size_t size, string file_name){
    //Класс потока вывода в файл
    fstream file(file_name, ios::out | ios::trunc | ios::binary);
    
    if ( !file.is_open() )
    throw(runtime_error("Ошибка: не удалось открыть файл"));
    
    //Запись размера массива
    file.write((char*)&size, sizeof(size_t));
    //Запись массива
    file.write((char*)array, sizeof(T)*size);    
    
    file.close();
}

/**
 * @brief Заполняет массив числами из текстового файла, возвращает размер массива
 * 
 * @param array массив
 * @param file_name название файла
 * @return size_t размер массива
 * @exception runtime_error, если не удалось открыть файл 
 */
template <typename T>
size_t fill_from_file(T* array, string file_name){
    //Класс потока ввода из файла
    ifstream file(file_name);
    if ( !file.is_open() )
        throw(runtime_error("Ошибка: не удалось открыть файл"));


    T tmp;
    size_t size = 0; 
    //Рассчёт размера массива
    while ( !file.eof() ){
        file >> tmp;
        size++;
    }

    //Добавление в массив
    file.seekg(0); //< Установка курсора в начало файла
    for (size_t i = 0; i < size; i++)
        file >> array[i];
    return size;

    return 0;
}

/**
 * @brief Заполняет массив числами из бинарного файла, возвращает размер массива
 * 
 * @param array массив
 * @param file_name название файла
 * @return size_t размер массива
 * @exception runtime_error, если не удалось открыть файл 
 */
template <typename T>
size_t fill_from_bin_file(T*& array, string file_name){
    //Класс потока ввода из файла
    fstream file(file_name, ios::in | ios::binary);
    
    if ( !file.is_open() )
        throw runtime_error("Ошибка: не удалось открыть файл");


    //Рассчёт размера массива
    size_t size = 0; 
    file.read((char*)&size, sizeof(size_t));

    //Добавление в массив
    array = new float[size];
    file.read((char*)array, sizeof(T)*size);
    return size;
    
    return 0;
}


/**
 * @brief Считает корень квадратный модуля произведения всех элементов массива
 * 
 * @param array массив
 * @param size размер массива
 * @return float посчитанное по формуле число
 */
template <typename T>
T get_num(T *array, size_t size){
    T mul = 1; 
    for (size_t i = 0; i < size; i++){
        mul *= array[i];
    }
    return sqrt(abs(mul));
}

}
