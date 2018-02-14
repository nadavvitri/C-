//
// Created by nadav vitri on 19/01/2018.
//

#ifndef EX3_CPP_MATRIX_H
#define EX3_CPP_MATRIX_H
#define ONE_DIMENSION 1
#define ZERO_VALUE 0
#define EXCEPTION_INVALID_ARGS "Invalid arguments"
#define EXCEPTION_OUT_OF_BOUNDS "Out of matrix bounds"
#define TAB_DELIMETER '\t'
#include <iostream>
#include <vector>
#include "Complex.h"

template <class T>
class Matrix
{
private:
    std::vector<T> _matrix;
    unsigned int _rows, _columns;

public:
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    /**
     * Default Constructor
     */
    Matrix(): _rows(ONE_DIMENSION), _columns(ONE_DIMENSION), _matrix(ONE_DIMENSION,(T)ZERO_VALUE){};

    /**
     * Constructor that get's the dimensions of the matrix
     * @param rows number of rows in matrix
     * @param cols number of columns in matrix
     */
    Matrix(unsigned int rows, unsigned int cols);

    /**
     * Copy Constructor
     * @param other Matrix object to copy
     */
    Matrix(const Matrix<T>& other): _rows(other._rows), _columns(other._columns),
                                 _matrix(other._matrix){};

    /**
     * Move Constructor
     * @param other Matrix object
     */
    Matrix(Matrix<T>&& other) noexcept;

    /**
     * Constructor matrix with dimensions and elements of the given vector
     * @param rows number of rows in matrix
     * @param cols number of columns in matrix
     * @param cells other vector
     */
    Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells);

    /**
     * Destructor
     */
    ~Matrix() = default;

    /**
     * Overloading for operator =
     * @param other Matrix object
     * @return reference to our object
     */
    Matrix<T>& operator=(const Matrix<T>& other);

    /**
     * Overloading for operator +
     * @param other Matrix object
     * @return non-const temp Matrix result of the operator
     */
    Matrix<T> operator+(const Matrix<T>& other);

    /**
     * Overloading for operator -
     * @param other Matrix object
     * @return non-const temp Matrix result of the operator
     */
    Matrix<T> operator-(const Matrix<T>& other);

    /**
     * Overloading for operator *
     * @param other Matrix object
     * @return non-const temp Matrix result of the operator
     */
    Matrix<T> operator*(const Matrix<T>& other);

    /**
     * Overloading for operator ==
     * @param other Matrix object
     * @return true iff the Matrix are equal
     */
    bool operator==(const Matrix<T>& other);

    /**
     * Overloading for operator ==
     * @param other Matrix object
     * @return true iff the Matrix are equal
     */
    bool operator!=(const Matrix<T>& other);

    /**
     * Gets the [row,col] element in the matrix
     * @param row row number
     * @param col col number
     * @return reference to matrix[row,col]
     */
    T& operator()(unsigned int row, unsigned col);

    /**
     * Gets the [row,col] element in the matrix
     * @param row row number
     * @param col col number
     * @return copy of matrix[row,col]
     */
    T operator()(unsigned int row, unsigned col) const;

    /**
     * Transpose the matrix (only if the matrix is square matrix)
     * @return transpose of matrix
     */
    Matrix<T> trans() const;

    /**
     * Check if matrix is square matrix
     * @return true if the matrix is square matrix, else false
     */
    bool isSquareMatrix() const { return (this->_rows == this->_columns); }

    /**
     * prints to the os a the matrix
     * @param os stream to write to
     * @param matrix object hold matrix we want to print
     */
    template<class X>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

    /**
     * Access method to number of rows
     * @return number of rows of matrix
     */
    unsigned int rows() const { return _rows; }

    /**
     * Access method to number of cols
     * @return number of columns of matrix
     */
    unsigned int cols() const { return _columns; }

    /**
     * begin iterator
     * @return begin()
     */
    iterator begin() { return _matrix.begin(); }

    /**
     * end iterator
     * @return end()
     */
    iterator end() { return _matrix.end(); }

    /**
     * const begin iterator
     * @return cbegin()
     */
    const_iterator begin() const { return _matrix.cbegin(); }

    /**
     * const end iterator
     * @return cend()
     */
    const_iterator end() const { return _matrix.cend(); }
};

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols):
        _rows(rows), _columns(cols), _matrix(rows * cols,(T)ZERO_VALUE)
{
    if (rows == ZERO_VALUE or cols == ZERO_VALUE)
    {
        throw std::invalid_argument(EXCEPTION_INVALID_ARGS);
    }
}

template <class T>
Matrix<T>::Matrix(Matrix&& other) noexcept
{
    Matrix();
    std::swap(this->_rows, other._rows);
    std::swap(this->_columns, other._columns);
    this->_matrix.swap(other._matrix);
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells):
        _rows(rows), _columns(cols), _matrix(cells)

{
    if (rows * cols != cells.size())
    {
        throw std::invalid_argument(EXCEPTION_INVALID_ARGS);
    }
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    if (this == &other)
    {
        return *this;
    }
    _rows = other._rows;
    _columns = other._columns;
    _matrix = other._matrix;
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
    if (this->_rows != other._rows or this->_columns != other._columns)
    {
        throw std::invalid_argument(EXCEPTION_INVALID_ARGS);
    }
    Matrix *temp = this;
    for (int i = 0; i != this->_matrix.size(); ++i)
    {
        temp->_matrix[i] += other._matrix[i];
    }
    return *temp;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)
{
    if (this->_rows != other._rows or this->_columns != other._columns)
    {
        throw std::invalid_argument(EXCEPTION_INVALID_ARGS);
    }
    Matrix *temp = this;
    for (int i = 0; i != this->_matrix.size(); ++i)
    {
        temp->_matrix[i] -= other._matrix[i];
    }
    return *temp;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{
    if (_columns != other._rows)
    {
        throw std::invalid_argument(EXCEPTION_INVALID_ARGS);
    }
    std::vector<T> vec(this->_rows * other._columns);
    Matrix<T> temp (this->_rows, other._columns, vec);
    for (int i= 0; i < _rows; i++)
    {
        for(int j = 0; j < other.cols(); j++)
        {
            for(int k = 0; k < _columns; k ++)
            {
                temp(i,j) += ((*this)(i,k) * other(k,j));
            }
        }
    }
    return temp;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& other)
{
    if (this->_rows != other._rows or this->_columns != other._columns)
    {
        return false;
    }
    return (_matrix == other._matrix);
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& other)
{
    return !(*this == other);
}

template <class T>
T& Matrix<T>::operator()(const unsigned int row, const unsigned col)
{
    if (row >= this->_rows or col >= this->_columns)
    {
        throw std::out_of_range(EXCEPTION_OUT_OF_BOUNDS);
    }
    int index = (this->_columns * row ) + col;
    return _matrix[index];
}

template <class T>
T Matrix<T>::operator()(const unsigned int row, const unsigned col) const
{
    if (row > this->_rows or col > this->_columns)
    {
        throw std::out_of_range(EXCEPTION_OUT_OF_BOUNDS);
    }
    int index = (this->_columns * row ) + col;
    return _matrix[index];
}

template <class T>
Matrix<T> Matrix<T>::trans() const
{
    if (!isSquareMatrix())
    {
        throw std::out_of_range(EXCEPTION_OUT_OF_BOUNDS);
    }
    Matrix temp (_rows, _columns);
    for (unsigned int row = 0; row != _rows; ++row)
    {
        for (unsigned int col = 0; col < _columns; ++col)
        {
            temp(col, row) = (*this)(row, col);
        }
    }
    return temp;
}

template <>
inline Matrix<Complex> Matrix<Complex>::trans() const
{
    if (!isSquareMatrix())
    {
        throw std::out_of_range(EXCEPTION_OUT_OF_BOUNDS);
    }
    Matrix<Complex> temp (_rows, _columns);
    for (unsigned int row = 0; row != _rows; ++row)
    {
        for (unsigned int col = 0; col < _columns; ++col)
        {
            temp(col, row) = (*this)(row, col).conj();
        }
    }
    return temp;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    for (int row = 0; row != matrix.rows(); ++row)
    {
        for (int col = 0; col < matrix.cols(); ++col)
        {
            os << matrix(row, col) << TAB_DELIMETER;
        }
        os << std::endl;
    }
    return os;
}

#endif //EX3_CPP_MATRIX_H
