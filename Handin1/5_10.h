#ifndef H_5_10_H
#define H_5_10_H

void guassian_elimination(double **A, double *b, double *u, int n);

void Pivoter(double **A, double *b, int length);
int FindMax(double **A, int length, int step);
void SwapRows(double **A, double* b, int length, int step, int row);
void MakeTriangular(double **A, double *b, int length);
void NormaliseTriangle(double **A, double *b, int length);
void FindSolution(double **A, double *b, double *u, int n);

double** AllocateMatrixMemory(int numRows, int numCols);
void FreeMatrixMemory(int numRows, double** matrix);

#endif
