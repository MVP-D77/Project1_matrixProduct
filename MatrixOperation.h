//
// Created by 任艺伟 on 2020/11/9.
//

#ifndef PROJECT1_MATRIXPRODUCT_MATRIXOPERATION_H
#define PROJECT1_MATRIXPRODUCT_MATRIXOPERATION_H

#include <iostream>

using namespace std;

struct matrix{
    int rowNumber;
    int columnNumber;
    float * value;
};

void initialization(matrix &matrix,string number);
matrix matrixProduct1(matrix firstMatrix,matrix secondMatrix,matrix matrixResult);
void transposition(matrix matrix1);
void showMatrix(matrix matrix);
bool judge(string data);
void userInput();
void checkSpeed1(matrix matrix1,matrix matrix2,matrix matrixResult);
void checkSpeed2(matrix matrix1,matrix matrix2,matrix matrixResult);
void checkSpeed3(matrix matrix1,matrix matrix2,matrix resultMatrix);
void checkSpeed4(matrix matrix1,matrix matrix2,matrix resultMatrix);

void clear(matrix);
float dotproduct1(const float *p1, const float * p2, size_t n, size_t temp);
float dotproduct2(const float *p1, const float * p2, size_t n,size_t temp);
float dotproduct3(const float *p1, const float * p2, size_t n,size_t temp);
float dotproduct4(const float *p1, const float * p2, size_t n, long long int temp);


#endif //PROJECT1_MATRIXPRODUCT_MATRIXOPERATION_H

