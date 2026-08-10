#pragma once
const int NMAX = 15;

void read_from_file(int &m, int &n, double matrix[][NMAX], FILE *file);

void output_to_file(int m, int n, const double matrix[][NMAX], FILE *file);

double find_non_zero_product(int m, int n, const double matrix[][NMAX]);

void fill_avgs_array(int m, int n, double matrix[][NMAX], double avgs_array[]);

void output_avgs(int m, int index, double avgs_array[], FILE* file);