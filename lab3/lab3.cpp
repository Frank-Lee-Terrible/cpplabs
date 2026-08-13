#include <cstdio>
#include "unit3.h"

/*Каждая запись представляет собой 6 чисел типа double. */
int main()
{
    FILE *fin, *fout, *fbin;
    int position_1, position_2;
    fin = fopen ("input.txt", "r");
    fbin = fopen ("fbin.bin", "w+b");
    fout = fopen ("output.txt", "w");

    if (!fin || !fbin || !fout){
        printf("Один из файлов невозможно открыть");
        return -1;
    }

    fin_to_fbin(fin, fbin);
    fprintf(fout, "Бинарный файл до преобразования:\n");
    output_fbin_to_fout(fbin, fout);

    printf("Введите 2 позиции записей, которые необходимо поменять:\n");
    scanf("%d %d", &position_1, &position_2);
    transform_bin(fbin, position_1, position_2);

    fprintf(fout, "Бинарный файл после преобразования:\n");
    output_fbin_to_fout(fbin, fout);

    fclose(fin);
    fclose(fbin);
    fclose(fout);
    printf("Программа завершена");
    return 0;
}