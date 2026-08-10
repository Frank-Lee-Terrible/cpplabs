#include <cstdio>
const int NMAX = 15;

/* Функция считывает размеры матрицы из файла, 
затем в соответствии с этими размерами считывает элементы матрицы.*/
void read_from_file(int &m, int &n, double matrix[][NMAX], FILE *file)
{
    fscanf(file, "%d %d", &m, &n);

    if (m > NMAX)
        m = NMAX;
    if (n > NMAX)
        n = NMAX;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }
    return;
}


void output_to_file(int m, int n, const double matrix[][NMAX], FILE *file)
{
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(file, "%lf ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    return;
}


double find_non_zero_product(int m, int n, const double matrix[][NMAX])
{
    double product = 1;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(matrix[i][j] != 0)
                product *= matrix[i][j]; 
        }
    }
    return product;
}


void fill_avgs_array(int m, int n, double matrix[][NMAX], double avgs_array[])
{
    double sum;
    int count;
    for (int i = 0; i < m; i++){
        sum = 0;
        count = 0;
        for (int j = 0; j < n; j++){
            if(matrix[i][j] != 0){
                sum += matrix[i][j];
                count += 1;
            }
        }

        if(count != 0){
            avgs_array[i] = sum / count;
        }
        else{
            avgs_array[i] = 0;
        }
    }

    return;
}

void output_avgs(int m, int index, double avgs_array[], FILE* file){
    fprintf(file, "В матрице %d произведение больше (не меньше). Массив из средних арифметических:\n", index);
    for (int i = 0; i < m; i++)
        fprintf(file, "%lf ", avgs_array[i]);
    fprintf(file, "\n");
    return;
}