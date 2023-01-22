#include <stdio.h>
#include <stdlib.h>
#define FIL 2
#define COL 3

int main()
{
    int mat[FIL][COL];
    int mat1[FIL][COL]= {1,2,3,4,5,6};
    int mat2[FIL][COL]= {{1,2,3},{4,5,6}};
    int mat3[][COL]= {{1,2,3},{4,5,6}};
    int mat4[FIL][]= {{1,2,3},{4,5,6}};
    int mat5[FIL][COL]= {{1,2},{4}};
    int mat6[FIL][COL]= {};
    int mat7[][]= {{1,2,3,4,5,6},{4,5,6}};
    int mat8[FIL][COL]= {{1,,3},{4,5,6}};
    int mat9[][COL] = {};
    int mat10[FIL][COL] = {1,2,{4}};
    int mat11[][COL] = {1,2,3,4,5,6,7};
    int mat12[FIL][COL] = {{},{4,5,6}}8;
    int mat13[FIL][COL] = {{1,2,3},{}};
    int mat14[FIL][COL] = {0};
    int mat15[][COL] = {0};
    int mat16[][COL]= {{11}, {14, 15, 16}, {17, 18, 19, 20}};
    return 0;
}
