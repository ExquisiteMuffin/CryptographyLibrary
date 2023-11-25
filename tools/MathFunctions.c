#include "MathFunctions.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//Alpha function (used in symmetric key algorithm)
int alpha(int num)
{
    int end = (num - 1) * (num - 1) - (num - 2) * (num - 2);
    return end;
}


int beta(int num)
{
    int end = (num - 2) * (num - 2) * (num - 2) - 4;
    return end;
}

//Inverse alpha function (used in symmetric key algorithm)
// int inv_alpha_a(int num)
// {
//     int end = 
// }

int lcf(int n, int k)
{
    int nh = ceil(sqrt(n));
    int kh = ceil(sqrt(k));

    int *n_factors = (int *)malloc(nh); //List for the whole number factors of n
    int c = 0;
    int ln = 0;
    for (int i = 0; i <= nh; i++)
    {
        if (n % i == 0)
        {
            n_factors[c] = i;
            c++;
            n_factors[c] = n / i;
            c++; //Moves the index one further
            ln += 2;
        }
    }

    int *k_factors = (int *)malloc(kh); //List of the whole number factors of k
    c = 0;
    int lk = 0;
    for (int j = 0; j < kh; j++)
    {
        if (n % j == 0)
        {
            k_factors[c] = j;
            c++;
            k_factors[c] = k / j;
            c++;
            lk += 2;
        }
    }

    //Find common factors, if any
    int lcf = 9999;
    bool isFirst = true;
    for (int a = 0; a < ln; a++)
    {
        for (int b = 0; b < lk; b++)
        {
            if (n_factors[a] == k_factors[b] && n_factors[a] < lcf)
            {
                lcf = n_factors[a];
            }
        }
    }
    return lcf;
}

int gcf(int n, int k)
{
    int nh = ceil(sqrt(n));
    int kh = ceil(sqrt(k));

    int *n_factors = (int *)malloc(nh); //List for the whole number factors of n
    int c = 0;
    int ln = 0;
    for (int i = 0; i <= nh; i++)
    {
        if (n % i == 0)
        {
            n_factors[c] = i;
            c++;
            n_factors[c] = n / i;
            c++; //Moves the index one further
            ln += 2;
        }
    }

    int *k_factors = (int *)malloc(kh); //List of the whole number factors of k
    c = 0;
    int lk = 0;
    for (int j = 0; j < kh; j++)
    {
        if (n % j == 0)
        {
            k_factors[c] = j;
            c++;
            k_factors[c] = k / j;
            c++;
            lk += 2;
        }
    }

    //Find common factors, if any
    int gcf = 0;
    for (int a = 0; a < ln; a++)
    {
        for (int b = 0; b < lk; b++)
        {
            if (n_factors[a] == k_factors[b] && n_factors[a] > gcf)
            {
                gcf = n_factors[a];
            }
        }
    }
    return gcf;
}