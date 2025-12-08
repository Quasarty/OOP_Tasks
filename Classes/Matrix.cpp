#include <iostream>
#include <vector>
#include <random>
#include <format>

template <typename T>
class Matrix{
    //Двумерный вектор
    std::vector< std::vector<T> > data;

public:
    /**
     * @brief Конструктор по умолчанию
     * @note Ничего не делает
     */
    Matrix(){}       

    /**
     * @brief Создает матрицу rows на cols, заполненную 0
     * 
     * @param rows количество строк
     * @param cols количество столбцов
     * @exception invalid argument, если rows > 0 OR cols > 0
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

    /**
     * @brief Возвращает строку матрицы
     * 
     * @param row строка
     * @return std::vector<T> возвращаемая строка
     */
    const std::vector<T>& operator [](size_t row) const{
       return this->data[row];
    }

    size_t rows() const{
        return data.size();
    }
    
    size_t cols() const{
        if (rows() == 0)
            return 0; 
        return data[0].size();
    }


    void fill(T num){
        for (auto& row : data)
            for (auto& cell : row)
                cell = num;
    }

    void rand_fill(T min, T max){
        std::random_device rd;
        std::mt19937 gen( rd() );
        std::uniform_real_distribution<T> distr(min, max);

        for (auto& row : data)
            for (auto& cell : row)
                cell = distr(gen);
    }

    void resize(size_t rows, size_t cols){
        //Исключение, если кол-во строк/столбцов <= 0
        if ( (cols <= 0) or (rows <= 0) )
            throw std::invalid_argument("rows > 0 OR cols > 0");
        
        data.resize(rows);
        for (auto& row : data){
            row.resize(cols);
        }
    }

    Matrix<T>& operator+=(const Matrix<T>& matr){
        if ( ( rows()!=matr.rows() ) or ( cols()!=matr.cols() ) )
            throw std::invalid_argument("size must match");

        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                (*this)[i][j] += matr[i][j];   
        return *this;
    }

    Matrix<T>& operator-=(const Matrix<T>& matr){
        if ( ( rows()!=matr.rows() ) or ( cols()!=matr.cols() ) )
            throw std::invalid_argument("size must match");
            
        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                (*this)[i][j] -= matr[i][j];   
        return *this;
    }

    Matrix<T>& operator*=(const Matrix<T>& matr){
        if ( cols()!=matr.rows() )
            throw std::invalid_argument("size must match");

        Matrix new_matr(rows(), matr.cols() );
        
        for (size_t i = 0; i < new_matr.rows(); i++)
            for (size_t j = 0; j < new_matr.cols(); j++){
                // Суммируем элементы 
                T sum = 0;
                for (size_t k = 0; k < matr.rows(); k++)
                    sum += (*this)[i][k]*matr[k][j];
                new_matr[i][j] = sum;   
            }

        this->resize(new_matr.rows(), new_matr.cols());
        (*this) = new_matr;
        return *this;
        
    }

    Matrix<T>& operator+=(T num){
        for (auto& row : data)
            for (auto& cell : row)
                cell += num;
        return *this;
    }

    Matrix<T>& operator-=(T num){
        for (auto& row : data)
            for (auto& cell : row)
                cell -= num;
        return *this;
    }

    Matrix<T>& operator*=(T num){
        for (auto& row : data)
            for (auto& cell : row)
                cell *= num;
        return *this;
    }


    /**
     * @brief Возвращает новый экземпляр класса Matrix, полученный путем транспонирования исходной матрицы 
     * 
     * @return Matrix<T> возвращаемая матрица
     */
    Matrix<T> transposed() const{
        Matrix new_matr(cols(), rows());
        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                new_matr[j][i] = (*this)[i][j];
    }


    /**
     * @brief 
     * 
     * @return Matrix<T> 
     */
    static Matrix<T> diagonased(size_t rows, size_t cols){
        Matrix new_matr(rows, cols);
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                if (i == j)
                    new_matr[i][j] = 1;
        return new_matr;

    }

    // если непоулчится никак, то int_print + real_print 
    void print() const{
        for (auto& row : data){
            for (auto& cell : row)
                if (true)
                // if ( ( typeid((*this)[0][0]) == typeid(double) ) or ( typeid((*this)[0][0]) == typeid(float) ) )
                    std::cout << std::format("{:8.2f}", cell);
                else
                    std::cout << std::format("{:5d}", cell);
            std::cout << "\n";
            }
    }

    
};

//Можно и внутри
template <typename T>
Matrix<T> operator+(Matrix<T> matr1, const Matrix<T>& matr2){
    matr1 += matr2;
    return matr1; 
}

template <typename T>
Matrix<T> operator-(Matrix<T> matr1, const Matrix<T>& matr2){
    matr1 -= matr2;
    return matr1; 
}

template <typename T>
Matrix<T> operator*(Matrix<T> matr1, const Matrix<T>& matr2){
    matr1 *= matr2;
    return matr1; 
}

template <typename T>
Matrix<T> operator+(Matrix<T> matr, T num){
    matr += num;
    return matr; 
}

//Здесь нельзя внутрь класса
template <typename T>
Matrix<T> operator+(T num, Matrix<T> matr){
    matr += num;
    return matr; 
}

template <typename T>
Matrix<T> operator-(Matrix<T> matr, T num){
    matr -= num;
    return matr; 
}

template <typename T>
Matrix<T> operator-(T num, Matrix<T> matr){
    matr -= num;
    return matr; 
}

template <typename T>
Matrix<T> operator*(Matrix<T> matr, T num){
    matr *= num;
    return matr; 
}

template <typename T>
Matrix<T> operator*(T num, Matrix<T> matr){
    matr *= num;
    return matr; 
}


int main(){
    Matrix<double> m1(3,3);
    m1.fill(2);
    m1 = m1+3.0;
    m1.print();


}