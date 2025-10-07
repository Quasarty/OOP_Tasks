//Автор: Андрей Кожевников
//Модуль для решения задач
#include <cmath>
#include <cassert>

//Пространство имен для функций этого модуля
namespace triangle{
/**
 * @brief Возвращает гипотенузу прямоугольного треугольника по его катетам
 * 
 * @param a первый катет
 * @param b второй катет
 */
float GetHypotenuse(float a, float b){
    return sqrt(a*a + b*b);
}

/**
 * @brief Возвращает площадь прямоугольного треугольника по его катетам
 * 
 * @param a первый катет
 * @param b второй катет
 */
float GetSquare(float a, float b){
    return a*b/2;
}

/**
 * @brief Процедура для теста функции GetSquare
 * 
 */ 
void Test_GetSquare(){
    assert(GetSquare(3, 4) == 6);
    assert(GetSquare(23, 31) == 356.5);
    assert(GetSquare(3.5, 7.25) == 12.6875);
}

/**
 * @brief Процедура для теста функции GetHypotenuse
 * 
 */
void Test_GetHypotenuse(){
    assert(GetHypotenuse(3, 4) == 5);
    assert(GetHypotenuse(30, 40) == 50);
    assert(abs(GetHypotenuse(4.5, 7.25) - sqrt(72.8125)) < 1e-6);
}

}