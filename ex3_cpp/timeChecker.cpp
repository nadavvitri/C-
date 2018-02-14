//
// Created by nadav vitri on 21/01/2018.
//
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <stack>
#include "Matrix.hpp"

using namespace std;

//std::stack<clock_t> tictoc_stack;
std::stack<std::chrono::time_point<std::chrono::system_clock>> tictoc_stack;

void tic() {
    //tictoc_stack.push(clock());
    tictoc_stack.push(std::chrono::system_clock::now());
}

void toc() {
    // std::cout << "Time elapsed: "
    // 		<< ((double)(clock() - tictoc_stack.top())) / CLOCKS_PER_SEC
    // 		<< std::endl;
    // tictoc_stack.pop();
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "Time elapsed: " << elapsed_seconds.count() << "sec\n";
    tictoc_stack.pop();
}




int main(int argc, char * argv[])
{

    if (argc != 2)
    {
        std::cerr<<"Usage: ParalelChecker <matrix_file>"<<std::endl;
        exit(-1);
    }

    unsigned int dim;
    std::stringstream str(argv[1]);
    str >> dim;
    std::cout << "size " << dim << std::endl;

    std::vector<int> vec1(dim * dim,1);

    Matrix<int> mat(dim, dim, vec1);
    Matrix<int> mat1;

    Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(dim,dim);
    Eigen::MatrixXd m2 = Eigen::MatrixXd::Random(dim,dim);

    tictoc_stack.push(std::chrono::system_clock::now());
    m2 * m1;
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "eigen mult " << elapsed_seconds.count() << "\n";
    tictoc_stack.pop();


    tictoc_stack.push(std::chrono::system_clock::now());
    m2 + m1;
    std::chrono::duration<double> elapsed_seconds1 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "eigen add " << elapsed_seconds1.count() << "\n";
    tictoc_stack.pop();


    tictoc_stack.push(std::chrono::system_clock::now());
    mat * mat;
    std::chrono::duration<double> elapsed_seconds2 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "matlib mult " << elapsed_seconds2.count() << "\n";
    tictoc_stack.pop();


    tictoc_stack.push(std::chrono::system_clock::now());
    mat + mat;
    std::chrono::duration<double> elapsed_seconds3 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "matlib add " << elapsed_seconds3.count() << "\n";
    tictoc_stack.pop();

    Matrix<int>::setParallel(true);

    return 0;
}




