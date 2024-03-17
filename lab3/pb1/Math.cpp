#include "Math.h"


int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return a * b;
}

int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum=0, x;
    for (int i = 0; i < count; i++) {
        x = va_arg(args, int);
        sum += x;
    }
    va_end(args);
    return sum;
}

char* Math::Add(const char* nr1, const char* nr2)
{
    if (nr1 == nullptr || nr2 == nullptr) return nullptr;
    int l1, l2, lmax;
    char* sum;
    char tr = '\0';
    char aux;
    l1 = std::strlen(nr1);
    l2 = std::strlen(nr2);
    if (l1 > l2) lmax = l1 + 2;
    else lmax = l2 + 2;

    sum = new char[lmax];
    sum[lmax - 1] = '\0';
    lmax-=2;
    while (l1 > 0 && l2 > 0) {
        aux = (nr1[l1 - 1] + nr2[l2 - 1] - 2*'0' + tr);
        sum[lmax--] = aux % 10 + '0';
        tr = aux / 10;
        l1--; l2--;
    }
    while (l1 > 0) {
        aux = (nr1[l1 - 1] -  '0' + tr);
        sum[lmax--] = aux % 10 + '0';
        tr = aux / 10;
        l1--;
    }
    while (l2 > 0) {
        aux = (nr2[l2 - 1] - '0' + tr);
        sum[lmax--] = aux % 10 + '0';
        tr = aux / 10;
        l2--;
    }
    if (tr) {
        sum[0] = tr + '0';
        return sum;
    }
    return sum + 1;
}
