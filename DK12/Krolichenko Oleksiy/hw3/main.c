#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool_array.h"
#include "dk_tool.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ellipseArray* theArray = createArray(5);
    Point Centre = { 50,50 };
    int r = 10;
    int R = 20;

    Ellipse* El1 = createEllipse(&Centre, &r, &R);
    addElement(theArray, El1);
    printf("����� 1 ����� = %f\n", SquareOfEllipse(El1));


    r = 30;
    R = 40;

    El1 = createEllipse(&Centre, &r, &R);
    addElement(theArray, El1);
    printf("����� 2 ����� = %f\n", SquareOfEllipse(El1));


    r = 50;
    R = 60;

    El1 = createEllipse(&Centre, &r, &R);
    addElement(theArray, El1);
    printf("����� 3 ����� = %f\n", SquareOfEllipse(El1));


    r = 70;
    R = 80;

    El1 = createEllipse(&Centre, &r, &R);
    addElement(theArray, El1);
    printf("����� 4 ����� = %f\n", SquareOfEllipse(El1));


    r = 90;
    R = 100;

    El1 = createEllipse(&Centre, &r, &R);
    addElement(theArray, El1);
    printf("����� 5 ����� = %f\n", SquareOfEllipse(El1));
    printArray(theArray);

    freeArray(theArray);
}