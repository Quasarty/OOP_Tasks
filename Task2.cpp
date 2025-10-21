//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"

using namespace std;


int main(){
    int choice = 0;
    cout << "Выберите способ заполнения массива:\n1. Случайными числами\n2. Ввод массива из файла\n3. Ручной ввод\n";
    cin >> choice;
    
    string file_name;
    float* array; 
    size_t size = 0;

    switch (choice){
    //Случайные числа
    case 1:{
        cout << "Введите размер массива: ";
        cin >> size;
        array = arr::fill_rand(size);
        break;
    }
    //Ввод из файла
    case 2:{
        cout << "Введите название файла: ";
        cin >> file_name; 
        try{
            size = arr::fill_from_file<float>(array, file_name);
        }
        catch(const runtime_error error){
            cout << error.what() << '\n';
            return 1;
        }
        
        break;
    }
    //Ручной ввод
    case 3:{
        cout << "Введите размер массива: ";
        cin >> size;
        array = new float[size];
        for (size_t i = 0; i < size; i++){
            cout << format("a[{}]: ", i+1);
            cin >> array[i];
        }
        break;
    }
    default:{
        cout << "Некорректный выбор"; 
        return 1;
        break;
    }
    }
    cout << "Массив:\n";
    arr::print_array(array, size);
    
    choice = 0;
    cout << "Что сделать дальше:\n1. Получить корень квадратный модуля произведения всех элементов массива\n2. Записать массив в файл\n3. Выход\n";
    cin >> choice;
    
    switch (choice){
    //Получение ответа
    case 1:{
        cout << arr::get_num(array, size);
        break;
    }
    //Запись в файл
    case 2:{
        int fchoice = 0;
        cout << "1. Запись в текстовый файл\n2. Запись в бинарный файл";
        cin >> fchoice; 
        switch (fchoice){
        case 1:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                arr::print_to_file(array, size, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
            break;
        case 2:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                arr::print_to_bin_file(array, size, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
        default:
            cout << "Некорректный выбор"; 
            break;
        }
        break;
    }

    //Выход
    default: 
        break;
    }

    return 0;
    
    return 0;
}
