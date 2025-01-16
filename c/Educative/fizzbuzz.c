#include <stdio.h>
 
int fizzbuzz(){
    for (int i = 1; i <= 100; i++)
    {
        
        printf("%d\n", i);
        if (i % 3 == 0)
        {
            printf("Fizz");
        }
        if (i % 5 == 0)
        {
            printf("Buzz");
        }
    }
}

int main(void)
{
    fizzbuzz();
    return 0;
}

