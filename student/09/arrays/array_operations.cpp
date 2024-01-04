#include "array_operations.hh"

int greatest_v1(int *itemptr, int size)
{
    int offset = 0; //how many steps from pointer
    int greatest = *itemptr;
    while(offset < size){
        //check if current is greater than greatest
        int current = *(itemptr + offset);
        if(current > greatest){
            greatest = current;
        }
        offset++;
    }
    return greatest;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int greatest = *itemptr;
    while(itemptr < endptr){
        //check if current is greater than greatest
        int current = *(itemptr);
        if(current > greatest){
            greatest = current;
        }
        itemptr++;
    }
    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    while (itemptr < endptr){
        //copy current value to targetptr
        *targetptr = *itemptr;
        itemptr++;
        // shift target ptr
        targetptr++;
    }
}

void reverse(int *leftptr, int *rightptr)
{
    while(leftptr < rightptr){
        rightptr--; //shift to target area
        int temp = *leftptr;
        //switch values
        *leftptr = *rightptr;
        *rightptr = temp;
        leftptr++;
    }
}
