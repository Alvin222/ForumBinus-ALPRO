#include <stdio.h>
int main() {
    char studyCode [2][30] = {"MATH6184036","COMP6112036"};
    char studyName [2][50] = {"Discrete Mathematics and Linear Algebra","Algorithm and Programming"};
    int sksNumber [2] = {4,4};
    char grade [2] = {'A','B'};
    printf("===================================================================\n                    PROGRAM DAFTAR MATA KULIAH\n===================================================================");
    for (int i = 0; i < 2; ++i) {
        printf("\nMata Kuliah : %s (%s)",studyName[i],studyCode[i]);
        printf("\nJumlah SKS : %d" , sksNumber[i]);
        printf("\nGrade : %c" , grade[i]);
        printf("\n===================================================================");
    }
    return 0;
}