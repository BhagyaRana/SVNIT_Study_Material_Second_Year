//To display different formatting of floating point numbers.
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float num;
    printf("Enter a Number(Float Data Type) : \n");
    scanf("%f", &num); 

    // 1 digits   
    printf("1 Digit Float Form : %0.1f\n", num);

    // 2 digits   
    printf("2 Digit Float Form : %0.2f\n", num);

    // 3 digits   
    printf("3 Digit Float Form : %0.3f\n", num);

    // 4 digits   
    printf("4 Digit Float Form : %0.4f\n", num);

    // 5 digits   
    printf("5 Digit Float Form : %0.5f\n", num);  

    // Exponential Form
    printf("Exponential Form : %e\n", num);  
    

    return 0;
}