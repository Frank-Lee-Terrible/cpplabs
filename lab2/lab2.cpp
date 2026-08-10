#include <cstdio>
#include "unit2.h"

/*Даны две матрицы разного размера. 
Для той из матриц, в которой больше произведение ненулевых элементов, 
найти среднее арифметическое ненулевых элементов в каждой строке. */

int main(){
    int m1, n1, m2, n2;
    double mat1[NMAX][NMAX], mat2[NMAX][NMAX];
    FILE *fin, *fout;

    fin = fopen("input.txt", "r");
    read_from_file(m1, n1, mat1, fin);
    read_from_file(m2, n2, mat2, fin);
    fclose(fin);

    fout = fopen("output.txt", "w");
    output_to_file(m1, n1, mat1, fout);
    output_to_file(m2, n2, mat2, fout);

    double product1, product2;
    product1 = find_non_zero_product(m1, n1, mat1);
    product2 = find_non_zero_product(m2, n2, mat2);
    printf("%lf %lf", product1, product2);

    /*логика с 2 if, чтобы рассмотреть случай одинакового произведения*/
    if(product1 >= product2){
        double avgs_array[m1];
        fill_avgs_array(m1, n1, mat1, avgs_array);
        output_avgs(m1, 1, avgs_array, fout);
    }
    if(product2 >= product1){
        double avgs_array[m2];
        fill_avgs_array(m2, n2, mat2, avgs_array);
        output_avgs(m2, 2, avgs_array, fout);
    }

    fclose(fout);
    return 0;
}