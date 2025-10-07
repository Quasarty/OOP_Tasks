//Автор: Андрей Кожевников
//Модуль для решения задач
#pragma once

#include <cmath>


//Пространство имен для функций этого модуля
namespace triangle{
/**
 * @brief Возвращает гипотенузу прямоугольного треугольника по его катетам
 * 
 * @param a первый катет
 * @param b второй катет
 */
float GetHypotenuse(float a, float b);

/**
 * @brief Возвращает площадь прямоугольного треугольника по его катетам
 * 
 * @param a первый катет
 * @param b второй катет
 */
float GetSquare(float a, float b);

/**
 * @brief Процедура для теста функции GetSquare
 * 
 */
void Test_GetSquare();

/**
 * @brief Процедура для теста функции GetHypotenuse
 * 
 */
void Test_GetHypotenuse();

}