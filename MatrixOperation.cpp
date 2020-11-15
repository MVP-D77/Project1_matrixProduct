//
// Created by 任艺伟 on 2020/11/9.
//
#include "MatrixOperation.h"
#include <immintrin.h>
#include <omp.h>
#include <stdlib.h>



bool judgeLength(string text)
{
    int i;
    for(i=0;i<text.length();i++){
        if(!isdigit(text[i])) break;
    }
    if(i == text.length()) return true;
    else return false;
}

void initialization(matrix &matrix,string number){
    cout<<"Please input the row number of "<<number<<" matrix: ";
    string number1;
    cin>>number1;
    while(!judgeLength(number1)){
        cout<<"The row number must be a integer,please check!";
        cin>>number1;
    }
    matrix.rowNumber  = stoi(number1);
    cout<<"Please input the column number of "<<number<<" matrix: ";
    string number2;
    cin>>number2;
    while(!judgeLength(number2)){
        cout<<"The column number must be a integer,please check!";
        cin>>number2;
    }
    matrix.columnNumber  = stoi(number2);

    matrix.value = new float [matrix.rowNumber*matrix.columnNumber]();

    cout<<"Please input the value of "<<number<<" matrix:"<<endl;
    for(int i=0;i<matrix.rowNumber*matrix.columnNumber;i++){
        string temp;
        cin>>temp;
        if(judge(temp))*(matrix.value+i) = stof(temp);
        else{
            cout<<"Your input has illegal items ,Please check!"<<endl;
            exit(0);
        }
//        cout<<*(matrix.value+i);
    }
}


matrix matrixProduct1(matrix firstMatrix,matrix secondMatrix,matrix matrixResult){
    int k=0;
    for(int i=0;i<firstMatrix.rowNumber;i++){
        for(int j=0;j<secondMatrix.columnNumber;j++){
            *(matrixResult.value+k)=
                    dotproduct1(firstMatrix.value+i*firstMatrix.columnNumber,secondMatrix.value+j,
                                firstMatrix.columnNumber,secondMatrix.columnNumber);
            k++;
        }
    }

    return matrixResult;
}


void showMatrix(matrix matrix){
    for(int i=0;i<matrix.columnNumber*matrix.rowNumber;i++){
        cout<<*(matrix.value+i)<<" ";
        if(i%matrix.columnNumber==matrix.columnNumber-1) cout<<endl;
    }
}


bool judge(string data){
    char signal = data[0]=='-'?'-':'+';
    int sigNum =0;
    int pointNum=0;
    int eNum = 0;
    string dara_real = data[0]=='-'?data.substr(1):data;

    for(int i=0;i<dara_real.length();i++){
        if(!isdigit(dara_real[i])&&dara_real[i]!='+'&&dara_real[i]!='-'&&dara_real[i]!='.'&&dara_real[i]!='E'&&dara_real[i]!='e'){
            return false;
        }else if(dara_real[i]=='+'||dara_real[i]=='-'){
            if(sigNum>0) return false;
            else if(i==0||dara_real[i-1]!='E'&&dara_real[i-1]!='e') return false;
            else sigNum++;
        }else if(dara_real[i]=='.'){
            if(pointNum>0) return false;
            else if(i==dara_real.length()-1) return false;
            else pointNum++;
        }else if(dara_real[i]=='E'||dara_real[i]=='e'){
            if(eNum>0) return false;
            else if(i==dara_real.length()-1) return false;
            else eNum++;
        }
    }
    return true;
}

void userInput(){
    cout<<"Ok,let`s do interesting about the dot product of two vectors!!";
    matrix firstMatrix;
    initialization(firstMatrix,"first");
//    showMatrix(firstMatrix);

    matrix secondMatrix;


    initialization(secondMatrix,"second");

    if(firstMatrix.columnNumber!=secondMatrix.rowNumber){
        cout<<"Wrong!! Please input right mxn and nxp matrixes"<<endl;
        return;
    }
//    showMatrix(secondMatrix);


    matrix matrixResult = {firstMatrix.rowNumber,secondMatrix.columnNumber};
    matrixResult.value = new float [matrixResult.rowNumber*matrixResult.columnNumber]();

    matrixResult = matrixProduct1(firstMatrix,secondMatrix,matrixResult);
    showMatrix(matrixResult);

//    clear(matrixResult);
//    clear(firstMatrix);
//    clear(secondMatrix);
    delete [] matrixResult.value;
    delete [] firstMatrix.value;
    delete [] secondMatrix.value;
}


void checkSpeed1(matrix matrix1,matrix matrix2,matrix matrixResult){
    matrixProduct1(matrix1,matrix2,matrixResult);
}

void checkSpeed2(matrix matrix1,matrix matrix2,matrix matrixResult){
    int k=0;
//    for(int i=0 ;i<matrix1.rowNumber*matrix1.columnNumber;i++){
//        *(matrix1.value+i)=1;
//    }
//    for(int i=0 ;i<matrix2.rowNumber*matrix2.columnNumber;i++){
//        *(matrix2.value+i)=1;
//    }

//    showMatrix(matrix1);
//    cout<<"============================"<<endl;
//
//    showMatrix(matrix2);
//    cout<<"============================"<<endl;

    for(int i=0;i<matrix1.rowNumber;i++){
        for(int j=0;j<matrix2.columnNumber;j=j+8){
            *(matrixResult.value+k)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+1)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+1,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+2)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+2,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+3)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+3,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+4)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+4,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+5)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+5,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+6)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+6,
                                matrix1.columnNumber,matrix2.columnNumber);
            *(matrixResult.value+k+7)=
                    dotproduct2(matrix1.value+i*matrix1.columnNumber,matrix2.value+j+7,
                                matrix1.columnNumber,matrix2.columnNumber);
            k=k+8;
        }
    }

//    showMatrix(matrixResult);

}

void checkSpeed3(matrix matrix1,matrix matrix2,matrix resultMatrix){
    int k=0;

//    for(int i=0 ;i<matrix1.rowNumber*matrix1.columnNumber;i++){
//        *(matrix1.value+i)=1;
//        *(matrix2.value+i)=i+1;
//    }

//    showMatrix(matrix2);
//    cout<<"================================"<<endl;
    for(int i=0;i<matrix1.rowNumber;i++){
        for(int j=0;j<matrix2.columnNumber;j++){
            *(resultMatrix.value+k)=
                    dotproduct3(matrix1.value+i*matrix1.columnNumber,matrix2.value+j,
                                matrix1.columnNumber,matrix2.columnNumber);
            k++;
        }
    }
//    showMatrix(resultMatrix);
}

///usr/local/Cellar/gcc/10.2.0/bin/g++-10 main.cpp MatrixOperation.cpp -O3 -fopenmp -mavx2 -std=c++11 -I/usr/local/Cellar/openblas/0.3.10_2/include -L/usr/local/Cellar/openblas/0.3.10_2/lib -lopenBlas


void checkSpeed4(matrix matrix1,matrix matrix2,matrix resultMatrix){

//    for(int i=0 ;i<matrix1.rowNumber*matrix1.columnNumber;i++){
//        *(matrix1.value+i)=1;
//        *(matrix2.value+i)=i+1;
//    }
//    showMatrix(matrix2);
//    cout<<"================================"<<endl;
//
//
    transposition(matrix2);
//
//
//    showMatrix(matrix2);
//    cout<<"================================"<<endl;
//    omp_set_num_threads(4);
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < matrix1.rowNumber; i++) {
            for (int j = 0; j < matrix2.columnNumber; j+=8) {
                *(resultMatrix.value + i*matrix1.rowNumber+j) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + j*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+1) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+1)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+2) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+2)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+3) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+3)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+4) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+4)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+5) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+5)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+6) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+6)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);
                *(resultMatrix.value + i*matrix1.rowNumber+j+7) =
                        dotproduct4(matrix1.value + i * matrix1.columnNumber, matrix2.value + (j+7)*matrix2.columnNumber,
                                    matrix1.columnNumber, matrix2.columnNumber);

            }
        }
    }
//    showMatrix(resultMatrix);
}

inline void clear(matrix matrix){
    delete[ ] matrix.value;
}



float dotproduct1(const float *p1, const float * p2, size_t n, size_t temp)
{
    float sum = 0.0f;
    for (size_t i = 0,j=0; i < n; i++,j += temp)
        sum += (p1[i] * p2[j]);
    return sum;
}


float dotproduct2(const float *p1, const float * p2, size_t n,size_t temp)
{
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float sum = 0.0f;
    for (size_t i = 0 ,j=0; i < n; i+=8,j = j+8*temp)
    {
        sum += (p1[i] * p2[j]);
        sum += (p1[i+1] * p2[j+temp]);
        sum += (p1[i+2] * p2[j+temp]);
        sum += (p1[i+3] * p2[j+temp]);
        sum += (p1[i+4] * p2[j+temp]);
        sum += (p1[i+5] * p2[j+temp]);
        sum += (p1[i+6] * p2[j+temp]);
        sum += (p1[i+7] * p2[j+temp]);
    }
    return sum;
}


float dotproduct3(const float *p1, const float * p2, size_t n,size_t temp)
{
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }

    float * mid = new float [8];
    float sum[8] = {0};
    __m256 a, b;
    __m256 c = _mm256_setzero_ps();

    for (size_t i = 0; i < n; i+=8)
    {
        for(int j=0;j<8;j++){
            mid[j] = *(p2+(j+i)*temp);
        }
        a = _mm256_load_ps(p1+i);
        b = _mm256_load_ps(mid);
        c =  _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }
    _mm256_store_ps(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
}

float dotproduct4(const float *p1, const float * p2, size_t n, long long int temp)
{
    if(n % 8 != 0)
    {
        std::cerr << "The size n must be a multiple of 8." <<std::endl;
        return 0.0f;
    }
    float sum[8] = {0};
    __m256 a, b;
    __m256 c = _mm256_setzero_ps();


//    omp_set_num_threads(4);
//#pragma omp parallel for
    for (size_t i = 0; i < n; i+=8)
    {
        a = _mm256_load_ps(p1+i);
        b = _mm256_load_ps(p2+i);
        c =  _mm256_add_ps(c, _mm256_mul_ps(a, b));
    }
    _mm256_store_ps(sum, c);
    return (sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7]);
}

void transposition(matrix matrix1){
    for(int i=0;i<matrix1.rowNumber;i++){
        for(int j=i+1;j<matrix1.columnNumber;j++){
            float temp = *(matrix1.value+i*matrix1.rowNumber+j);
            *(matrix1.value+i*matrix1.rowNumber+j) = *(matrix1.value+j*matrix1.rowNumber+i);
            *(matrix1.value+j*matrix1.rowNumber+i) = temp;
        }
    }
    int temp = matrix1.columnNumber;
    matrix1.columnNumber = matrix1.rowNumber;
    matrix1.rowNumber = temp;
}
