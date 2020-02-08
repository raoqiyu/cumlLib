/*
Author: raoqiyu@gmail.com
Date: 2020-01-09 14:55:06
FilePath: /AlgoLibR/cpp/test/AlgoLibR/test_sort.h
Description: 
 */
//#include "AlgoLibR/common/utils.h"
#include "AlgoLibR/sort/utils.h"
#include "AlgoLibR/sort/radix_sort.h"
#include "AlgoLibR/sort/sort.h"
#include <stdio.h>
#define N 5

void test_uints(){
    printf("\nTest sort unsigned int array: radix sort(GPU) and bubble sort\n");
    unsigned int h_in[5] = {71422,72452,54329,77510,80669};
    unsigned int h_outs[N];

    AlgoLibR::sort::radix_sort::radix_sort_kernel(h_in, h_outs,  (size_t) N);

    for(int i = 0; i < N; i++){
        printf("%d ",h_outs[i]);
    }
    printf("\n");

    AlgoLibR::sort::sortKernel<unsigned int>(h_in, (size_t) N, AlgoLibR::sort::BUBBLE_SORT_M, true);

    for(int i = 0; i < 5; i++){
        printf("%d ",h_in[i]);
    }
    printf("\n");
}


void test_float(){
    printf("\nTest sort float array: bubble sort\n");
    float h_in[5] = {16516.1,123.56,14.2,1455.1,14.87};

    for(int i = 0; i < 5; i++){
        printf("%f ",h_in[i]);
    }
    printf("\n");

    AlgoLibR::sort::sortKernel(h_in, (size_t) N, AlgoLibR::sort::BUBBLE_SORT_M, true);

    for(int i = 0; i < 5; i++){
        printf("%f ",h_in[i]);
    }
    printf("\n");
}

void test_sort(){
    test_uints();
    test_float();
}