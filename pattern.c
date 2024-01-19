#include <stdio.h>

int main()
{
    int r, c;
    printf("Enter row ");
    scanf("%d", &r);
    printf("Enter column ");
    scanf("%d", &c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}