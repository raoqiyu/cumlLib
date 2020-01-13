#ifndef COMPARATOR_H
#define COMPARATOR_H

#include<stdlib.h>

namespace COMPARATOR{
    namespace ARRAY{
        typedef bool  (*CompareFunc) (void* data, long long i, long long  j);    // Compare data[i] and data[j]

        template<typename T>
        bool greater(void *data, long long  i, long long  j){
            return ((T*)data)[i] > ((T*)data)[j];        
        }
        
        template<typename T>
        bool less(void *data, long long i, long long j){
            return ((T*)data)[i] < ((T*)data)[j];        
        }
    } // array 

    namespace NUMBER{
        template<typename T> using CompareFunc = bool (*) (T x, T y);    // Compare x and y

        template<typename T>
        bool greater(T x, T y){
            return x >= y;        
        }
        
        template<typename T>
        bool less(T x, T y){
            return x < y;        
        }
    } // number 

} // COMPARATOR

#endif