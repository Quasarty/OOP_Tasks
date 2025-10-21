//Автор: Кожевников Андрей
//Модуль для работы с динамическими массивами

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
void print_array(const float* array, size_t size){
    
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
void print_array_by_10(const float* array, size_t size){
    
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

/**
 * @brief Записывает массив в текстовый файл
 * 
 * @param array массив
 * @param size размер массива
 * @param file_name название файла
 */
void print_to_file(const float* array, size_t size, string file_name){
    //Класс потока вывода в файл
    ofstream file(file_name);
    
    //Вывод
    for (size_t i = 0; i < size; i++)
        file << array[i];

}

/**
 * @brief Заполняет массив числами из файла, возвращает размер массива
 * 
 * @param array массив
 * @param file_name название файла
 * @return size_t размер массива
 */
size_t fill_from_file(float* array, string file_name){
    //Класс потока ввода из файла
    ifstream file(file_name);
    if ( !file.is_open() )
        throw(runtime_error("Ошибка: не удалось открыть файл"));


    float tmp;
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
 * @brief Считает корень квадратный модуля произведения всех элементов  
 * 
 * @param array массив
 * @param size размер массива
 * @return float посчитанное по формуле число
 */
float get_num(float *array, size_t size){
    float mul = 1; 
    for (size_t i = 0; i < size; i++){
        mul *= array[i];
    }
    return sqrt(abs(mul));
}

}