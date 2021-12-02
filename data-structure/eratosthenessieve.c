#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int prime_numbers[1000001];

void simple_prime_number(int to)
{
    for (int i = 2; i <= to; i++)
        prime_numbers[i] = 0;

    for (int number = 2; number <= to; number++)
    {
        int prime_number_check = 1;
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                prime_number_check = 0;
                break;
            }
        }
        prime_numbers[number] = prime_number_check;
    }
}

void eratosthenes_sieve(int to)
{
    for (int i = 2; i <= to; i++)
        prime_numbers[i] = 1;

    for (int i = 2; i <= to; i++)
    {
        if (prime_numbers[i] == 1)
        {
            for (int j = 2 * i; j <= to; j += i)
            {
                prime_numbers[j] = 0;
            }
        }
    }
}

int main()
{
    int to;
    printf("어디까지 소수를 구해볼까요?\n");
    scanf("%d", &to);

    clock_t start_simple, start_eratosthenes;
    clock_t end_simple, end_eratosthenes;
    int time_simple, time_eratosthenes;

    start_simple = clock();
    simple_prime_number(to);
    end_simple = clock();
    time_simple = end_simple - start_simple;

    start_eratosthenes = clock();
    eratosthenes_sieve(to);
    end_eratosthenes = clock();
    time_eratosthenes = end_eratosthenes - start_eratosthenes;

    printf("간단하게 구현한 n까지 소수 구하기 : %d ms, %.3f sec\n", time_simple, (float)time_simple / CLOCKS_PER_SEC);
    printf("에라토스테네스의 체로 구현한 n까지 소수 구하기 : %d ms, %.3f sec\n", time_eratosthenes, (float)time_eratosthenes / CLOCKS_PER_SEC);
}