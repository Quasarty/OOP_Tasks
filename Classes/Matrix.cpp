#include <iostream>
#include <vector>
//todo: const у методов

template <typename T>
class Matrix{
    //Двумерный вектор
    std::vector< std::vector<T> > data;

public:
    // Matrix(): rows(0), cols(0) {}
    /**
     * @brief Конструктор по умолчанию
     * @note Ничего не делает
     */
    Matrix(){
    }   

    //todo: cделать валидацию на 0
    /**
     * @brief Создает матрицу rows на cols, заполненную 0
     * 
     * @param rows количество строк
     * @param cols количество столбцов
     * @ 
     */
    Matrix(size_t rows, size_t cols){
        //Исключение, если кол-во строк/столбцов <= 0
        if ( (cols <= 0) or (rows <= 0) )
            throw std::invalid_argument("rows > 0 OR cols > 0");
        
        data.resize(rows);
        for (auto& row : data){
            row.resize(cols);
        }
    }

    /**
     * @brief Возвращает строку матрицы
     * 
     * @param row строка
     * @return std::vector<T> возвращаемая строка
     */
    std::vector<T>& operator [](size_t row){
        return this->data[row];
    }

    size_t rows() const{
        return data.size();
    }
    
    //todo: проверка всех столбцов?
    size_t cols() const{
        //...
    }

};


main (){
    // mtr[1][1] = 5;

    // std::cout << mtr[1][1];
    return 0;
}