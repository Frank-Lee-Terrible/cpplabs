#include <cstdio>
#include "unit1_4.h"


/*Определить, в каком массиве больше минимум элементов, больших заданного числа. 
Если в двух или трёх массивах минимумы совпадают, вывести соответствующее сообщение.*/
int main(){
    FILE *fin, *fout;
    int length1, length2, length3;
    double array1[NMAX], array2[NMAX], array3[NMAX];
    double marker;

    fin = fopen("input.txt", "r");
    read_array(length1, array1, fin);
    read_array(length2, array2, fin);
    read_array(length3, array3, fin);
    fclose(fin);

    printf("Введите число для сравнения элементов:\n");
    scanf("%lf", &marker);

    double min1 = get_min_elem(length1, array1, marker);
    double min2 = get_min_elem(length2, array2, marker);
    double min3 = get_min_elem(length3, array3, marker);

    double array_of_mins[3] = {min1, min2, min3};
    int indices_of_mins[3] = {0,0,0};
    double min_min = min1;
    int min_index = 0;

    for (int i = 1; i < 3; i++){
        if (array_of_mins[i] < min_min){
            min_min = array_of_mins[i];
            min_index = i;
        }
    }  //нашли индекс и значение наименьшего минимума

    indices_of_mins[min_index] = 1;

    for (int i = min_index + 1; i < 3; i++){
        if (array_of_mins[i] == min_min)
            indices_of_mins[i] = 1;
    }

    fout = fopen("output.txt", "w");
    fprintf(fout, "Массив(ы) с наименьшим минимумом, большим заданного элемента - это ");
    for (int i = 0; i < 3; i++){
        if (indices_of_mins[i] == 1)
            fprintf(fout, " %d", i + 1);
    }
    fprintf(fout, ".");
    fclose(fout);
    return 0;
}