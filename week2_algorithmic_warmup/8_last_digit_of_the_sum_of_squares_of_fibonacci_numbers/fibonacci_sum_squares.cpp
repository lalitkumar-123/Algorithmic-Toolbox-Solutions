#include <iostream>

int fibonacci_sum_squares_naive(long long n)
{
    if (n <= 1)
    {
       return n;
    }
    else
    {
        long long a = 0;
        long long b  = 1;
        long long c;
        long long sum = 1;

        for (long long i = 2; i <= n ; i++)
        {
            c = a + b;
            sum = sum + (c*c);
            a = b;
            b = c;
        }
        return sum % 10;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
