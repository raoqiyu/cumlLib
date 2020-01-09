cimport cython
from libcpp cimport bool

cdef extern from "sort/radix_sort.h" namespace "SORT::RADIX_SORT":
    void radix_sort_kernel(unsigned int*  h_inputVals, unsigned int* h_outputVals, const size_t numElems)

ctypedef fused real:
    cython.short
    cython.ushort
    cython.int
    cython.uint
    cython.long
    cython.ulong
    cython.longlong
    cython.ulonglong
    cython.float
    cython.double

cdef extern from "sort/utils.h" namespace "SORT":
    cdef enum SORT_METHOD:
        BUBBLE_SORT_M,
        INSERTION_SORT_M,
        QUICK_SORT_M,
        SELECTION_SORT_M

cdef extern from "sort/sort.hpp" namespace "SORT":
    cdef void sortKernel[T](T *arr, size_t n, SORT_METHOD method, bool ascending)