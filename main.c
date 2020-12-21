#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(0,"Russian");
    srand(time(NULL));
    int M = 100000, i, j, k;
    float a, b, c, d;
    a = b = c = d = 0;
    float n1, n2, n;
    n1 = n2 = n = 0;

    for (i = 0; i < M; i++)
    {
        j = rand()%11; //academic
        k = rand()%11; //sport

        if (j >= 8) a++;
        if (k >= 8)
        {
            b++;
            n1+=j; //сумма академ баллов у спортсменов
        }
        if (j >= 8 || k >= 8) c++;
        if (j >= 8 && k >= 8) d++;
        if (j >= 8 && k < 8)
        {
            n++;
            n2+=j;  //сумма акад баллов у слабых спортсменов
        }
    }

    //printf("a=%.0f   b=%.0f   c=%.0f   d=%.0f\n", a, b, c, d);
    printf("P(A|C) = %.2f\n", a/c);  //P(A|C)
    printf("P(A|B,C) = %.2f\n", d/b);  //P(A|B,C)
    if (a/c > d/b) printf("P(A|C) > P(A|B,C)\n");
    else printf("-\n");

    printf("Средний академический балл спортсменов: %.1f\n", n1/b);
    printf("Средний академичиский балл слабых спортсменов: %.1f\n", n2/n);
    return 0;
}

