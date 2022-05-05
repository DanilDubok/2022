#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool_array.h"
#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

// ��������� ������
ellipseArray* createArray(int aNumber) {
    ellipseArray* theResult = NULL;
    if (aNumber > 0)

        theResult = (ellipseArray*)malloc(sizeof(ellipseArray));

        if (NULL != theResult) {

            theResult->ellipses = (Ellipse**)malloc(sizeof(Ellipse*) * aNumber);
            
            if (NULL != theResult->ellipses) {
                
                theResult->number = aNumber;
                theResult->count = 0;
            }
            else {   
                free(theResult);
                theResult = NULL;
            }
        }
    return theResult;
}

// ������� �������� ������
void freeArray(ellipseArray* anArray)  {
    if (NULL != anArray) {
        for (int i = 0; i < anArray->count; i++) {
            destroyEllipse(anArray->ellipses[i]);  
        }
        free(anArray->ellipses); 
        free(anArray);  
    }
}

// ������� ��������� �������� �� ������
int addElement(ellipseArray* anArray, Ellipse* aEllipse) {

    int theResult = -1;   // -1, ���� ������� �������
    
    if (NULL != anArray && NULL != aEllipse && anArray->count < anArray->number) {
        anArray->ellipses[anArray->count] = aEllipse;
        theResult = anArray->count;
        anArray->count++;
    }
    return theResult;
}

//  ������� ����� ������ �� �����
void printArray(ellipseArray* anArray) {
    
    if (anArray != NULL) {

        printf("\n ����� �������: %d, �������� ���������� ��������: %d", anArray->number, anArray->count);
        printf(", ������� �����: %d \n", anArray->count);

        for (int i = 0; i < anArray->count; i++) {
            printEllipse(anArray->ellipses[i]);
        }
    }
    else return;
}

// ����� ������ � json
void json(FILE* aFile, ellipseArray* anArray) {

    if (NULL == anArray || NULL == aFile) {
        return;
    }

    fprintf(aFile, "{\n\"����� �������\" : %d, \n\"������� ��������\" : %d, \n", anArray->number, anArray->count);
    fprintf(aFile, "\"������� �����\" : %d\n[\n");

    for (int i = 0; i < anArray->count; i++) {

        ellipsesJson(aFile, anArray->ellipses[i]);
        
        if (i < anArray->count - 1) {
            fprintf(aFile, ",");
        }

        fprintf(aFile, "\n");
    }
    fprintf(aFile, "]\n}");
}