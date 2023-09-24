#include <stdio.h>
void swapValue(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swapAddress(int *num1,int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int main() {
    int num1,num2;
    printf("==========[INPUT]==========\n");
    printf("Input First Number :");
    scanf("%d", &num1);

    printf("Input Second Number :");
    scanf("%d", &num2);

    printf("======[SWAP BY VALUE]======");

    swapValue(num1,num2);
    printf("\nFirst Number : %d",num1);
    printf("\nSecond Number : %d",num2);

    printf("\n=====[SWAP BY ADDRESS]=====");

    swapAddress(&num1,&num2);
    printf("\nFirst Number : %d",num1);
    printf("\nSecond Number : %d",num2);

    printf("\n===========[END]===========");

    return 0;
}