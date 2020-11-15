#include "MatrixOperation.h"
#include <chrono>
#include <cblas.h>


#define LENGTH 10000


int main() {
    cout<<"Please select which operation do you want!!!"<<endl;
    cout<<"if you want to check large amount`speed please count 1"<<endl
        <<"else if you want to check small amount`s vector multiply please count 2"<<endl;
    int amoutJudge = 0;
    cin>>amoutJudge;
    if(amoutJudge==1){
        matrix matrix1 = {LENGTH,LENGTH,new float [LENGTH*LENGTH]()};
//        matrix1.value = new float [matrix1.rowNumber*matrix1.columnNumber]();
        matrix matrix2 = {LENGTH,LENGTH,new float [LENGTH*LENGTH]()};

        matrix matrixResult = {LENGTH,LENGTH,new float [LENGTH*LENGTH]()};
//
//        checkSpeed1(matrix1,matrix2,matrixResult);
//        checkSpeed1(matrix1,matrix2,matrixResult);

//        auto start = std::chrono::steady_clock::now();
//        checkSpeed1(matrix1,matrix2,matrixResult);
//        auto end = std::chrono::steady_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//        cout << "matrixProduct 1 , duration = " << duration <<" ms"<< std::endl;
//
//        auto start2 = std::chrono::steady_clock::now();
//        checkSpeed2(matrix1,matrix2,matrixResult);
//        auto end2 = std::chrono::steady_clock::now();
//        auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();
//        cout << "matrixProduct 2 , duration = " << duration2 <<" ms"<< std::endl;
////
//        auto start3 = std::chrono::steady_clock::now();
//        checkSpeed3(matrix1,matrix2,matrixResult);
//        auto end3 = std::chrono::steady_clock::now();
//        auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count();
//        cout << "matrixProduct 3 , duration = " << duration3 <<" ms"<< std::endl;

        auto start4 = std::chrono::steady_clock::now();
        checkSpeed4(matrix1,matrix2,matrixResult);
        auto end4 = std::chrono::steady_clock::now();
        auto duration4 = std ::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4).count();
        cout << "matrixProduct 4 , duration = " << duration4 <<" ms"<< std::endl;


        auto start5 = std::chrono::steady_clock::now();
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasTrans, LENGTH, LENGTH, LENGTH, 1.0, matrix1.value, LENGTH, matrix2.value, LENGTH, 0.0, matrixResult.value, LENGTH);
        auto end5 = std::chrono::steady_clock::now();
        auto duration5 = std::chrono::duration_cast<std::chrono::milliseconds>(end5 - start5).count();
        cout << "OpenBlas , duration = " << duration5 <<" ms"<< std::endl;



        delete [] matrix1.value;
        delete [] matrix2.value;
        delete [] matrixResult.value;


//        clear(matrix1);
//        clear(matrix2);
//        clear(matrixResult);
    }else {
        userInput();
    }

    return 0;
}
