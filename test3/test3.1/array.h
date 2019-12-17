#pragma once

int** createDoubleArray(int stringsNumber, int columnsNumber);
int** extendDoubleArray(int **array, int currentStringsNumber, int columnsNumber, int extendValue);
int **sortDoubleArray(int **array, int stringsNumber, int columnsNumber);
void printDoubleArray(int **array, int stringsNumber, int columnsNumber);
void deleteDoubleArray(int **array, int stringsNumber);