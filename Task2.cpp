//Автор: Кожевников Андрей
//Задача 136л https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream>
#include <random>
#include <time.h>
#include "Arrays.hpp"
#include <vector>

using namespace std;

//TOSHOW: комп. мод. + binary files
int main(){
    int choice = 0;
    cout << "Выберите способ заполнения массива:\n1. Случайными числами\n2. Ввод массива из файла\n3. Ручной ввод\n";
    cin >> choice;
    
    string file_name;
    vector<float> array; 
    size_t size = 0;

    switch (choice){
    //Случайные числа
    case 1:{
        cout << "Введите размер массива: ";
        cin >> size;
        array.resize(size);
        arr::fill_rand(array);
        break;
    }
    //Ввод из файла
    case 2:{
        int fchoice = 0;
        cout << "1. Ввод из текстового файла\n2. Ввод из бинарного файла\n";
        cin >> fchoice; 
        switch (fchoice){
        case 1:
            cout << "Введите название файла: ";
            cin >> file_name; 
            try{
                arr::fill_from_file(array, file_name);
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
                size = arr::fill_from_bin_file(array, file_name);
            }
            catch(const runtime_error error){
                cout << error.what() << '\n';
                return 1;
            }
            break;
        default:
            cout << "Некорректный ввод";
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
    }
    }
    cout << "Массив:\n";
    arr::print_array(array, size);
    cout << "Ответ: " << arr::get_num(array, size) << endl;
    
    choice = 0;
    cout << "Что сделать дальше:\n1. Записать массив в файл\n2. Выход\n";
    cin >> choice;
    
    switch (choice){

    //Запись в файл
    case 1:{
        int fchoice = 0;
        cout << "1. Запись в текстовый файл\n2. Запись в бинарный файл\n";
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
            break;
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
}
