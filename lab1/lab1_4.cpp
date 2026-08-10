#include<cstdio>
#include"unit1_4.h"


/* Определить в каком массиве больше минимум элементов, 
больших заданного числа. Если в двух или трёх массивах минимумы совпадают, 
вывести соответствующее сообщение.*/

int main(){
    double marker;
    double arr1[NMAX], arr2[NMAX], arr3[NMAX];
    int arr1len, arr2len, arr3len;
    double arr1min, arr2min, arr3min;
    FILE *fin, *fout;

    printf("Введите число, с которым будет производиться сравнение:\n");
    scanf("%lf", &marker);

    fin = fopen("input.txt", "r");
    read_array(arr1len, arr1, fin);
    read_array(arr2len, arr2, fin);
    read_array(arr3len, arr3, fin);
    fclose(fin);

    arr1min = get_min_elem(arr1len, arr1, marker);
    arr2min = get_min_elem(arr2len, arr2, marker);
    arr3min = get_min_elem(arr3len, arr3, marker);

    double array_of_mins[3] = {arr1min, arr2min, arr3min};
    double indices_of_mins[3] = {0, 0, 0};
    double buf = arr1min;
    int index = 0;
    for (int i = 1; i < 3; i++){
        if (array_of_mins[i] < buf){
            buf = array_of_mins[i];
            index = i;
        }
    }
    indices_of_mins[index] = 1;
    for (int i = index + 1; i < 3; i++){
        if (array_of_mins[i] == buf)
            indices_of_mins[i] = 1;
    }

    fout = fopen("output.txt", "w");
    fprintf(fout, "Массив(ы) с наименьшим минимумом, большим заданного числа - это");
    for (int i = index; i < 3; i++){
        if (indices_of_mins[i] == 1)
            fprintf(fout, " %d", i + 1);
    }
    fprintf(fout, ".");
    fclose(fout);

    return 0;
}