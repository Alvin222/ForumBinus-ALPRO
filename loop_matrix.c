#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
int* AddMatrixLine(char* matrixStringSplit){
    int* matrixLine = malloc(sizeof (int[2]));
    int index = 0;
    char* stringInvalidInput = NULL;
    while (matrixStringSplit != NULL){
        bool isInvalidInput = false;
        int number;
        for (int i = 0; i < strlen(matrixStringSplit); ++i) {
            if(!isdigit(matrixStringSplit[i])) {
                printf("%s bukanlah angka silahkan input ulang");
                isInvalidInput = true;
            }
        }
        while (isInvalidInput){
            scanf("%[^\n]",stringInvalidInput);
            fflush(stdin);
            for (int i = 0; i < strlen(stringInvalidInput); ++i) {
                if(!isdigit(stringInvalidInput[i])) {
                    printf("%s bukanlah angka silahkan input ulang");
                    isInvalidInput = true;
                }
            }
            isInvalidInput = false;
        }
        if (stringInvalidInput == NULL){
            number = atoi(matrixStringSplit);
        } else {
            number = atoi(stringInvalidInput);
        }
        matrixLine[index++] = number;
        matrixStringSplit = strtok(NULL, " ");
    }
    return matrixLine;
}

int** listOfMatrixInput(int inputNumber){
    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }
    printf("Input matrix ke-%d format\n(a b)\n(c d)\n",inputNumber);
    for (int i = 0; i < 2; ++i) {
        int* matrixLine = malloc(sizeof (int[2]));
        char lineInput[30];
        scanf("%[^\n]",lineInput);
        fflush(stdin);
        char* split = strtok(lineInput," ");
        matrixLine = AddMatrixLine(split);
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] = matrixLine[j];
        }
    }
    return matrix;
}

int main() {
    int** firstMatrix;
    int** secondMatrix;
    int result[2][2];
    int inputNumber = 1;
    firstMatrix = listOfMatrixInput(inputNumber++);
    secondMatrix = listOfMatrixInput(inputNumber++);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j]+=firstMatrix[i][k]*secondMatrix[k][j];
            }
        }
    }
    printf("hasil dari matrix adalah : \n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
