
#ifndef TRIANGLESOLVER_H
#define TRIANGLESOLVER_H

char* analyzeTriangle(int side1, int side2, int side3);
char* classifyTriangle(double side1, double side2, double side3);

int calculateTriangleAngles(double side1, double side2, double side3,
    double* angleA, double* angleB, double* angleC);

#endif