//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами
#pragma once

#include <iostream>
#include <format>
#include <random>
#include <fstream>
                                      
using namespace std;

namespace arr{

/**
 * @brief Функция выводит массив
 * 
 * @param array массив
 * @param size размер массива
 */
void print_array(const float* array, size_t size);

/**
 * @brief Функция выводит массив, выводя максимум 10 элементов в строке
 * 
 * @param array массив
 * @param size размер массива
 */
void print_array_by_10(const float* array, size_t size);

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
 */
void print_to_file(const float* array, size_t size, string file_name);

void print_to_bin_file(const float* array, size_t size, string file_name);

/**
 * @brief Заполняет массив числами из файла, возвращает размер массива
 * 
 * @param array массив
 * @param file_name название файла
 * @return size_t размер массива
 */
size_t fill_from_file(float* array, string file_name);

size_t fill_from_bin_file(float*& array, string file_name);

/**
 * @brief Возвращает число, считаемое из массива по некой формуле  
 * 
 * @param array массив
 * @param size размер массива
 * @return float посчитанное по формуле число
 */
float get_num(float *array, size_t size);

}
