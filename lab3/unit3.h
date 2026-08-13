#pragma once

const int SIZE = 6;

void fin_to_fbin(FILE *fin, FILE *fbin);
void output_fbin_to_fout(FILE* fbin, FILE* fout);
void transform_bin(FILE *fbin, int position_1, int position_2);