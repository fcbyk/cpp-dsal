#include "fcbyk/algo.hpp"
#include "fcbyk/utils.hpp"

class IntArrSortTest{
public:
    static void it01(){
        int a[] = {213,323,43,32,5436,4234,23,23,222};
        fcbyk::IntArrSort::quickSort(a,9);
        fcbyk::print(a);
    }
};