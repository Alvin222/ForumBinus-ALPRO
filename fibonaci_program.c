//
// Created by User on 01/10/2023.
//
#include <stdio.h>
#include <time.h>
long loopFibonaci(long sequence){
    long firstNumber = 0;
    long secondNumber = 1;
    for (long i = 0; i < sequence; i++) {
        long temp = secondNumber;
        secondNumber = firstNumber + secondNumber;
        firstNumber = temp;
    }
    return secondNumber;
}

long recursiveFibonaci(long firstNumber, long secondNumber, int currentSequence,int totalSequence){
    if (currentSequence < totalSequence){
        return recursiveFibonaci(secondNumber,firstNumber+secondNumber,++currentSequence,totalSequence);
    } else {
        return secondNumber;
    }
}
int main() {
    int sequence;
    clock_t start, end;
    printf("Ingin mengetahui fibonaci keberapa ?");
    scanf("%d",&sequence);
    start = clock();
    long resultLoopFibonaci = loopFibonaci(sequence);
    end = clock();
    double loopSpeed =  (end * 1000 - start * 1000.0)  / CLOCKS_PER_SEC;
    printf("Hasil dari fibonaci menggunakan loop : %u",resultLoopFibonaci);
    printf("\nKecepatan Menghitung Fibonaci menggunakan loop %f detik",loopSpeed);
    start = clock();
    long resultRecursiveFibonaci = recursiveFibonaci(0,1,0,sequence);
    end = clock();
    double recursiveSpeed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nHasil dari fibonaci menggunakan rekursif : %u",resultRecursiveFibonaci);
    printf("\nKecepatan Menghitung Fibonaci menggunakan rekursif %f detik",recursiveSpeed);
}

