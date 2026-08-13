#include <cstdio>

const int SIZE = 6;
const int NMAX = 75;  //макс длина строки в символах

/*Функция fin_to_fbin считывает данные из текстового файла в двоичный.
Подразумевается, что одна запись - одна строка в текстовом файле.
"Правильные" записи перемещаются в двоичный файл.
Запись считается неправильной, если в ней количество элементов,
которые можно корректно прочитать как double, меньше SIZE (шести).
Всё, что больше шести, отбрасывается.
Лишние символы в строке игнорируются. Т.е. функция написана с расчётом на то,
что sscanf всё сделает за нас.*/
void fin_to_fbin(FILE *fin, FILE *fbin)
{
    double record[SIZE];
    bool flag_eof = false, flag_eol = false;
    bool flag_match_record = false;
    char chr = 0;
    char str[NMAX];
    int index; //для строкИ
    int count; //для записи
    int shift; //для сдвига в строке
    int result; //для присвоения функции fscanf и проверки конца файла
    //char* lookstr; //указатель по движению по строке. Последние 2 идеи подсказаны ИИшкой.

    while (!flag_eof){ 
        // "fgets - небезопасная функция" - Страуструп. Поэтому вручную создаём строку.  
        index = 0;
        flag_eol = false;

        while (!flag_eof && !flag_eol){  //наполнение строки
            result = fscanf(fin, "%c", &chr);
            if(result == EOF){
                flag_eof = true;
            }
            else if (chr == '\n'){
                flag_eol = true;
            }
            else{
                if (index <= NMAX - 2){
                    str[index] = chr;
                    index++;
                }
            }     
        }
        str[index] = '\0';

        /*------------часть 2: работа с str-------------*/
        count = 0;
        flag_match_record = false;
        char *lookstr = str;
        while (*lookstr != '\0'){
            if(sscanf(lookstr, "%lf%n", &record[count], &shift) == 1){
                count++;
                lookstr += shift; //сдвиг на нужное число байт, которые давали число.
                if(count == SIZE){
                    flag_match_record = true;
                    break;
                }
            }
            else{
                lookstr += 1; //сдвиг на 1 плохой символ
            }
        }

        if (flag_match_record){
            fwrite(record, sizeof(double), SIZE, fbin);
        }
    }
    return;
}

/* Вывод каждой новой записи на новой строке*/
void output_fbin_to_fout(FILE* fbin, FILE* fout){
    int filesize;
    int count;
    double record[SIZE];
    fseek(fbin, 0, SEEK_END);
    filesize = ftell(fbin);
    count = filesize / (sizeof(double) * SIZE);
    fseek(fbin, 0, SEEK_SET);

    for (int i = 0; i < count; i++){
        fread(record, sizeof(double), SIZE, fbin);
        for (int j = 0; j < SIZE; j++){
            fprintf(fout, "%lf ", record[j]);
        }
        fprintf(fout, "\n");
    }

    return;
}

void transform_bin(FILE *fbin, int position_1, int position_2){
    int filesize;
    int record_count;
    const int sizeof_record = sizeof(double) * SIZE;
    fseek(fbin, 0, SEEK_END);
    filesize = ftell(fbin);
    fseek(fbin, 0, SEEK_SET);
    record_count = filesize / (sizeof(double) * SIZE);
    if (
    (1 <= position_1) && (position_1 <= filesize) && 
    (1 <= position_2) && (position_2 <= filesize) && 
    (position_1 != position_2)){
        double record[SIZE], record2[SIZE];
        fseek(fbin, sizeof_record * (position_1 - 1), SEEK_SET);
        fread(record, sizeof_record, 1, fbin);

        fseek(fbin, sizeof_record * (position_2 - 1), SEEK_SET);
        fread(record2, sizeof_record, 1, fbin);

        fseek(fbin, sizeof_record * (position_2 - 1), SEEK_SET); //этот fseek обязателен!
        fwrite(record, sizeof_record, 1, fbin);

        fseek(fbin, sizeof_record * (position_1 - 1), SEEK_SET);
        fwrite(record2, sizeof_record, 1, fbin);
    }
    else
        printf("nothing to do here...\n");

    return;

}