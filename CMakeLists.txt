cmake_minimum_required(VERSION 3.17)
project(Project1_matrixProduct)

set(CMAKE_CXX_STANDARD 14)


# 里面填入include 所在目录
include_directories("/usr/local/Cellar/openblas/0.3.10_2/include")
# 里面填入lib 所在目录
link_directories("/usr/local/Cellar/openblas/0.3.10_2/lib")
#下面这行直接这样写就行
link_libraries(cblas)

add_executable(Project1_matrixProduct main.cpp MatrixOperation.cpp omp_test.cpp omp_test.h)
add_executable(Project1_matrixProductA omp_test.cpp omp_test.h)