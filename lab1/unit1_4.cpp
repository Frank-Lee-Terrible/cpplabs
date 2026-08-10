#include<cstdio>
//#include"unit1_4.h"

/* Функция read_array считывает из файла в массив.
Положение указателя в файле никак не контролируется.
Подразумевается, что в текстовом файле сначала указано кол-во элементов массива (оно запоминается в переменную), 
затем элементы перечисляются в строчку.
*/
void read_array(int &length, double array[], FILE *fin){
    fscanf(fin, "%d", &length);
    for (int i = 0; i < length; i++){
        fscanf(fin, "%lf", &array[i]);
    }

    return;
}


/* Функция get_min_elem находит минимальный элемент массива, больший данного значения marker
Подразумевается, что хотя бы один такой элемент есть в массиве.
(мне лень делать выдачу индекса и разбор случаев)

*/
double get_min_elem(int length, double array[], double marker){
    int index;
    double buf;

    //первый цикл находит элемент, больший marker
    for (int i = 0; i < length; i++){
        if (array[i] > marker){
            buf = array[i];
            index = i;
            break;
        }
    }

    //второй цикл находит наименьший элемент, больший marker
    for (int i = index + 1; i < length; i++){
        if (array[i] > marker && array[i] < buf){
            buf = array[i];
        }
    }

    return buf;
}